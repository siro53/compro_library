#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../data-structure/segtree/lazy-segtree.hpp"
#include "../../../data-structure/segtree/segtree-beats.hpp"

struct RangeAddSum {
    struct S { long long sum; int len; bool fail = false; };
    using value_type_S = S;
    using value_type_F = int;
    static S op(S a, S b) { return {a.sum + b.sum, a.len + b.len}; }
    static S e() { return {0, 0}; }
    static int id() { return 0; }
    static S mapping(int f, S s) { return {s.sum + (long long)f * s.len, s.len}; }
    static int composition(int f, int g) { return f + g; }
};
template<class Tree> void check_tree() {
    for(int n = 0; n <= 20; n++) {
        vector<RangeAddSum::S> init(n, {1, 1});
        vector<int> a(n, 1);
        Tree seg(init);
        for(int step = 0; step < 5; step++) {
            if(n) {
                int l = step % n;
                seg.apply(l, n, 1);
                for(int i = l; i < n; i++) a[i]++;
            }
            for(int limit = 0; limit <= 6 * n; limit++) {
                auto pred = [&](auto s) { return s.sum <= limit; };
                for(int l = 0; l <= n; l++) {
                    int r = l, sum = 0;
                    while(r < n && sum + a[r] <= limit) sum += a[r++];
                    assert(seg.max_right(l, pred) == r);
                }
                for(int r = 0; r <= n; r++) {
                    int l = r, sum = 0;
                    while(l > 0 && sum + a[l - 1] <= limit) sum += a[--l];
                    assert(seg.min_left(r, pred) == l);
                }
            }
        }
    }
}
void regression_test() {
    check_tree<LazySegtree<RangeAddSum>>();
    check_tree<SegtreeBeats<RangeAddSum>>();
}

int main() {
    regression_test();
    INT(a, b);
    print(a + b);
}
