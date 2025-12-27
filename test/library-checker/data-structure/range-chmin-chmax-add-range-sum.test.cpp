#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#include "../../../template/template.cpp"
#include "../../../data-structure/segtree/segtree-beats.hpp"

const ll inf = 1LL << 61;

struct MonoidAct {
    struct S {
        ll sum;
        int len;
        ll mn;
        ll mn2;
        int mn_cnt;
        ll mx;
        ll mx2;
        int mx_cnt;
        bool fail;
    };
    struct F {
        // f(x) = min(ub, max(x + geta, lb))
        ll lb;
        ll ub;
        ll geta;
    };

    using value_type_S = S;
    using value_type_F = F;
    static S op(const S &a, const S &b) {
        ll sum = a.sum + b.sum;
        int len = a.len + b.len;
        ll mn = min(a.mn, b.mn);
        ll mn2 = (a.mn == b.mn ? min(a.mn2, b.mn2) : a.mn2 <= b.mn ? a.mn2 : b.mn2 <= a.mn ? b.mn2 : max(a.mn, b.mn));
        int mn_cnt = a.mn_cnt * (a.mn <= b.mn) + b.mn_cnt * (b.mn <= a.mn);
        ll mx = max(a.mx, b.mx);
        ll mx2 = (a.mx == b.mx ? max(a.mx2, b.mx2) : a.mx2 >= b.mx ? a.mx2 : b.mx2 >= a.mx ? b.mx2 : min(a.mx, b.mx));
        int mx_cnt = a.mx_cnt * (a.mx >= b.mx) + b.mx_cnt * (b.mx >= a.mx);
        return {sum, len, mn, mn2, mn_cnt, mx, mx2, mx_cnt, false};
    }
    static S e() {
        return {0, 0, inf, inf, 0, -inf, -inf, 0, false};
    }
    static S mapping(const F& f, S x) {
        if (x.len == 0) return e();
        if (x.mn == x.mx or f.lb == f.ub or f.lb >= x.mx or f.ub <= x.mn) {
            ll val = min(max(x.mn, f.lb), f.ub) + f.geta;
            int len = x.len;
            return {val * len, len, val, inf, len, val, -inf, len, false};
        } else if (x.mn2 == x.mx) {
            x.mn = x.mx2 = max(x.mn, f.lb) + f.geta;
            x.mx = x.mn2 = min(x.mx, f.ub) + f.geta;
            x.sum = x.mn * x.mn_cnt + x.mx * x.mx_cnt;
            return x;
        } else if (f.lb < x.mn2 and f.ub > x.mx2) {
            ll mn = max(x.mn, f.lb);
            ll mx = min(x.mx, f.ub);
            x.sum += (mn - x.mn) * x.mn_cnt + (mx - x.mx) * x.mx_cnt + f.geta * x.len;
            x.mn = mn + f.geta;
            x.mx = mx + f.geta;
            x.mn2 += f.geta;
            x.mx2 += f.geta;
            return x;
        }
        x.fail = true;
        return x;
    }
    static F composition(const F& f, const F& g) {
        if (f.lb == -inf and f.ub == inf and f.geta == 0) return g;
        ll geta = f.geta + g.geta;
        ll lb = max(min(g.lb + g.geta, f.ub), f.lb) - g.geta;
        ll ub = min(max(g.ub + g.geta, f.lb), f.ub) - g.geta;
        return {lb, ub, geta};
    }
    static F id() { return {-inf, inf, 0}; }
};

int main() {
    INT(N, Q);
    vector<MonoidAct::S> iv(N);
    REP(i, N) {
        LL(a);
        iv[i] = {a, 1, a, inf, 1, a, -inf, 1, false};
    }
    SegtreeBeats<MonoidAct> seg(iv);
    REP(_, Q) {
        INT(t);
        if (t == 3) {
            INT(l, r);
            print(seg.prod(l, r).sum);
        } else {
            INT(l, r);
            LL(b);
            if (t == 0) {
                seg.apply(l, r, {-inf, b, 0});
            } else if (t == 1) {
                seg.apply(l, r, {b, inf, 0});
            } else {
                seg.apply(l, r, {-inf, inf, b});
            }
        }
    }
}