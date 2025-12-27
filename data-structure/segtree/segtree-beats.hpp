#pragma once

#include <vector>
#include <cassert>

template<class MonoidAct> class SegtreeBeats {
public:
    using S = typename MonoidAct::value_type_S;
    using F = typename MonoidAct::value_type_F;

    SegtreeBeats(): SegtreeBeats(0) {}
    explicit SegtreeBeats(int n): SegtreeBeats(std::vector<S>(n, MonoidAct::e())) {}
    explicit SegtreeBeats(const std::vector<S> &v): N((int)v.size()), sz(1), lg(0) {
        while(sz < N) {
            sz <<= 1;
            lg++;
        }
        node.resize(sz * 2, MonoidAct::e());
        lazy.resize(sz, MonoidAct::id());
        for(int i = 0; i < N; i++) node[i + sz] = v[i];
        for(int i = sz - 1; i >= 1; i--) update(i);
    }

    void set(int pos, S val) {
        assert(0 <= pos && pos < N);
        pos += sz;
        for(int i = lg; i >= 1; i--) propagate(pos >> i);
        node[pos] = val;
        for(int i = 1; i <= lg; i++) update(pos >> i);
    } 

    S get(int pos) {
        assert(0 <= pos and pos < N);
        pos += sz;
        for(int i = lg; i >= 1; i--) propagate(pos >> i);
        return node[pos];
    }

    S prod(int l, int r) {
        assert(0 <= l and l <= r and r <= N);
        if (l == r) return MonoidAct::e();
        l += sz;
        r += sz;
        for(int i = lg; i >= 1; i--) {
            if (((l >> i) << i) != l) propagate(l >> i);
            if (((r >> i) << i) != r) propagate((r - 1) >> i);
        }   
        S vl = MonoidAct::e(), vr = MonoidAct::e();
        while(l < r) {
            if (l & 1) vl = MonoidAct::op(vl, node[l++]);
            if (r & 1) vr = MonoidAct::op(node[--r], vr);
            l >>= 1;
            r >>= 1;
        }
        return MonoidAct::op(vl, vr);
    }

    S all_prod() const { return node[1]; }

    void apply(int pos, F f) {
        assert(0 <= pos and pos < N);
        pos += sz;
        for(int i = lg; i >= 1; i--) propagate(pos >> i);
        node[pos] = MonoidAct::mapping(f, node[pos]);
        for(int i = 1; i <= lg; i++) update(pos >> i);
    }

    void apply(int l, int r, F f) {
        assert(0 <= l and l <= r and r <= N);
        if (l == r) return;
        l += sz;
        r += sz;
        for(int i = lg; i >= 1; i--) {
            if (((l >> i) << i) != l) propagate(l >> i);
            if (((r >> i) << i) != r) propagate((r - 1) >> i);
        }
        {
            int tmp_l = l, tmp_r = r;
            while(l < r) {
                if (l & 1) apply_node(l++, f);
                if (r & 1) apply_node(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = tmp_l, r = tmp_r;
        }
        for(int i = 1; i <= lg; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <class G> int max_right(int l, G g) {
        assert(0 <= l and l <= N);
        assert(g(MonoidAct::e()));
        if (l == N) return N;
        l += sz;
        for(int i = lg; i >= 1; i--) propagate(l >> i);
        S now = MonoidAct::e();
        do {
            while ((l & 1) == 0) l >>= 1;
            if (!g(MonoidAct::op(now, node[l]))) {
                while (l < sz) {
                    propagate(l);
                    l <<= 1;
                    if (g(MonoidAct::op(now, node[l]))) {
                        now = MonoidAct::op(now, node[l]);
                        l++;
                    }
                }
                return l - sz;
            }
            now = MonoidAct::op(now, node[l]);
        } while ((l & -l) != l);
        return N;
    } 

    template <class G> int min_left(int r, G g) {
        assert(0 <= r and r <= N);
        assert(g(MonoidAct::e()));
        if (r == 0) return 0;
        r += sz;
        for(int i = lg; i >= 1; i--) propagate((r - 1) >> i);
        S now = MonoidAct::e();
        do {
            r--;
            while (r > 1 and (r & 1) == 0) r >>= 1;
            if (!g(MonoidAct::op(node[r], now))) {
                while (r < sz) {
                    propagate(r);
                    r = (r << 1) + 1;
                    if (g(MonoidAct::op(node[r], now))) {
                        now = MonoidAct::op(node[r], now);
                        r--;
                    }
                }
                return r + 1 - sz;
            }
            now = MonoidAct::op(node[r], now);
        } while((r & -r) != r);
        return 0;
    }

private:
    int N, sz, lg;
    std::vector<S> node;
    std::vector<F> lazy;

    void update(int i) {
        node[i] = MonoidAct::op(node[i << 1], node[(i << 1) | 1]);
    }
    
    void apply_node(int i, F f) {
        node[i] = MonoidAct::mapping(f, node[i]);
        if (i < sz) {
            lazy[i] = MonoidAct::composition(f, lazy[i]);
            if (node[i].fail) {
                propagate(i);
                update(i);
            }
        }
    }

    void propagate(int i) {
        apply_node(i << 1, lazy[i]);
        apply_node(i << 1 | 1, lazy[i]);
        lazy[i] = MonoidAct::id();
    }
};