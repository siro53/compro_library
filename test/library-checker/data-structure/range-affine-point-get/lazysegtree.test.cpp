#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"
#include "../../../template/template.cpp"
#include "../../../data-structure/segtree/lazy-segtree.hpp"
#include "../../../modint/modint.hpp"

using mint = ModInt<MOD2>;

struct MonoidAct {
    struct S {
        mint sum;
        int len;
        S() {}
        S(mint sum, int len): sum(sum), len(len) {}
    };
    using F = pair<mint, mint>;

    using value_type_S = S;
    using value_type_F = F;
    inline static S op(const S &a, const S &b) {
        return S(a.sum + b.sum, a.len + b.len);
    }
    inline static S e() { return S(0, 0); }
    inline static S mapping(const F &f, const S &x) {
        return S(f.first * x.sum + f.second * x.len, x.len);
    }
    inline static F composition(const F &f, const F &g) {
        return {f.first * g.first, f.first * g.second + f.second};
    }
    inline static F id() { return {1, 0}; }
};

int main() {
    INT(N, Q);
    LazySegtree<MonoidAct> seg(N);
    REP(i, N) {
        INT(a);
        seg.set(i, MonoidAct::S(a, 1));
    }
    REP(qid, Q) {
        INT(type);
        if (type == 0) {
            INT(l, r, b, c);
            seg.apply(l, r, {b, c});
        } else {
            INT(i);
            print(seg.get(i).sum);
        }
    }
}