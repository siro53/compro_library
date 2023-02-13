#pragma once

#include <cassert>
#include <vector>

/*
    テンプレート引数にモノイドを受け取る
    モノイドには静的メンバ関数 op(), e() が実装されている必要がある
*/
template <class Monoid> class Segtree {
  public:
    using T = typename Monoid::value_type;

    Segtree() : Segtree(0) {}
    explicit Segtree(int n) : Segtree(std::vector<T>(n, Monoid::e())) {}
    explicit Segtree(const std::vector<T> &v) : N((int)v.size()), sz(1) {
        while(sz < N) sz <<= 1;
        node.resize(sz * 2, Monoid::e());
        for(int i = 0; i < N; i++) node[i + sz] = v[i];
        for(int i = sz - 1; i >= 1; i--) {
            node[i] = Monoid::op(node[i << 1], node[i << 1 | 1]);
        }
    }
    void set(int pos, T val) {
        assert(0 <= pos && pos < N);
        pos += sz;
        node[pos] = val;
        while(pos > 1) {
            pos >>= 1;
            node[pos] = Monoid::op(node[pos << 1], node[pos << 1 | 1]);
        }
    }
    T get(int pos) const {
        assert(0 <= pos && pos < N);
        return node[pos + sz];
    }
    T prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= N);
        T value_l = Monoid::e(), value_r = Monoid::e();
        l += sz;
        r += sz;
        while(l < r) {
            if(l & 1) value_l = Monoid::op(value_l, node[l++]);
            if(r & 1) value_r = Monoid::op(node[--r], value_r);
            l >>= 1;
            r >>= 1;
        }
        return Monoid::op(value_l, value_r);
    }
    T all_prod() const { return node[1]; }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= N);
        assert(f(Monoid::e()));
        if(l == N) return N;
        l += sz;
        T value_now = Monoid::e();
        do {
            while((l & 1) == 0) l >>= 1;
            if(!f(Monoid::op(value_now, node[l]))) {
                while(l < sz) {
                    l = 2 * l;
                    if(f(Monoid::op(value_now, node[l]))) {
                        value_now = Monoid::op(value_now, node[l]);
                        l++;
                    }
                }
                return (l - sz);
            }
            value_now = Monoid::op(value_now, node[l]);
            l++;
        } while((l & -l) != l);
        return N;
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= N);
        assert(f(Monoid::e()));
        if(r == 0) return 0;
        r += sz;
        T value_now = Monoid::e();
        do {
            r--;
            while(r > 1 && (r & 1)) r >>= 1;
            if(!f(Monoid::op(node[r], value_now))) {
                while(r < sz) {
                    r = 2 * r + 1;
                    if(f(Monoid::op(node[r], value_now))) {
                        value_now = Monoid::op(node[r], value_now);
                        r--;
                    }
                }
                return ((r + 1) - sz);
            }
            value_now = Monoid::op(node[r], value_now);
        } while((r & -r) != r);
        return 0;
    }

  private:
    int N, sz;
    std::vector<T> node;
};