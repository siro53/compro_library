#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../data-structure/wavelet-matrix.hpp"
#include "../../../data-structure/compact-bitvector.hpp"


int main() {
    mt19937 rng(67);
    for(int n : {0, 1, 7, 63, 64, 65, 128}) {
        CompactBitVector bits(n); vector<int> a(n);
        for(int pass = 0; pass < 2; ++pass) {
            for(int i = 0; i < n; ++i) { a[i] = rng() % 2; bits.set(i, a[i]); }
            bits.build(); const auto& view = bits;
            for(int i = 0; i < n; ++i) assert(view.access(i) == a[i] && view[i] == a[i]);
            for(int b : {0, 1}) {
                assert(view.select(-1, b) == -1);
                for(int i = 0; i <= n; ++i) assert(view.rank(i, b) == unsigned(count(a.begin(), a.begin() + i, b)));
            }
        }
    }
    for(int n = 0; n <= 20; ++n) {
        vector<int> a(n); for(auto& x : a) x = rng() % 15;
        WaveletMatrix<int, 4> wm; wm = WaveletMatrix<int, 4>(a);
        const auto& view = wm;
        for(int i = 0; i < n; ++i) assert(view.access(i) == a[i] && view[i] == a[i]);
        for(int x = 0; x < 16; ++x) assert(wm.select(-1, x) == -1);
        for(int l = 0; l <= n; ++l) for(int r = l; r <= n; ++r) {
            vector<int> sorted(a.begin() + l, a.begin() + r); sort(sorted.begin(), sorted.end());
            for(int k = 0; k < r - l; ++k) assert(wm.quantile(l, r, k) == sorted[k]);
            for(int x = 0; x < 16; ++x) {
                auto it = lower_bound(sorted.begin(), sorted.end(), x);
                assert(wm.rangefreq(l, r, x) == it - sorted.begin());
                assert(wm.prev_value(l, r, x) == (it == sorted.begin() ? -1 : *prev(it)));
                assert(wm.next_value(l, r, x) == (it == sorted.end() ? -1 : *it));
                for(int y = x; y < 16; ++y) {
                    int count = 0; for(int value : sorted) count += x <= value && value < y;
                    assert(wm.rangefreq(l, r, x, y) == count);
                }
            }
        }
    }
    INT(a, b); print(a + b);
}
