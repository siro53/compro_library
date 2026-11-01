#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../data-structure/persistent/persistent-array.hpp"
#include "../../../data-structure/monoid/and.hpp"
#include "../../../data-structure/monoid/kadane.hpp"
#include "../../../data-structure/segtree/segtree.hpp"

void regression_test() {
    for(int n : {1, 2, 16, 17, 64}) {
        PersistentArray<int> a(n, 7);
        auto initial = a.root;
        auto first = a.set(0, 3);
        auto last = a.set(initial, n - 1, 9);
        for(int i = 0; i < n; i++) {
            assert(a.get(initial, i) == 7);
            assert(a.get(first, i) == (i == 0 ? 3 : 7));
            assert(a.get(last, i) == (i == n - 1 ? 9 : 7));
        }
        typename PersistentArray<int>::Node copy(*first);
        assert(copy.val == first->val);
    }
    using And = MonoidAND<unsigned>;
    for(unsigned v : {0U, 1U, 2U, 0x80000000U, ~0U}) {
        assert(And::op(v, And::e()) == v);
        assert(And::op(And::e(), v) == v);
    }
    using K = MonoidKadane<int>;
    assert(K::op(K::e(), K::e()).sum == 0);
    K::S smallest(INT_MIN, INT_MIN, INT_MIN, INT_MIN);
    assert(K::op(K::e(), smallest).allmax == INT_MIN);
    mt19937 rng(53);
    for(int n = 0; n <= 20; n++) {
        vector<int> a(n);
        vector<K::S> init;
        for(auto& x : a) { x = (int)(rng() % 21) - 10; init.emplace_back(x, x, x, x); }
        Segtree<K> seg(init);
        for(int l = 0; l <= n; l++) for(int r = l; r <= n; r++) {
            int best = INT_MIN;
            for(int i = l; i < r; i++) {
                int sum = 0;
                for(int j = i; j < r; j++) { sum += a[j]; best = max(best, sum); }
            }
            assert(seg.prod(l, r).allmax == best);
        }
    }
    using D = MonoidKadane<double>;
    assert(D::op(D::e(), D::S(-2, -2, -2, -2)).allmax == -2);
}

int main() {
    regression_test();
    INT(a, b);
    print(a + b);
}
