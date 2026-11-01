#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../data-structure/compact-bitvector.hpp"
#include "../../../data-structure/wavelet-matrix.hpp"
#include "../../../data-structure/binary-trie.hpp"

void regression_test() {
    mt19937 rng(53);
    CompactBitVector empty;
    assert(empty.rank(0, 0) == 0 && empty.select(0, 1) == -1);
    for(int n = 0; n <= 130; n++) {
        vector<int> a(n);
        CompactBitVector bits(n);
        for(int i = 0; i < n; i++) bits.set(i, a[i] = rng() % 2);
        bits.build();
        for(int b = 0; b <= 1; b++) {
            vector<int> positions;
            for(int i = 0; i <= n; i++) {
                assert(bits.rank(i, b) == positions.size());
                if(i < n && a[i] == b) positions.push_back(i);
            }
            for(int k = 0; k < (int)positions.size(); k++) assert(bits.select(k, b) == positions[k]);
            assert(bits.select((int)positions.size(), b) == -1);
        }
        for(auto& x : a) x = rng() % 8;
        WaveletMatrix<int, 4> wm(a);
        for(int x = 0; x <= 8; x++) {
            int count = 0;
            for(int i = 0; i <= n; i++) {
                assert(wm.rank(i, x) == count);
                if(i < n && a[i] == x) assert(wm.select(count++, x) == i);
            }
            assert(wm.select(count, x) == -1);
        }
        auto sorted = a;
        sort(sorted.begin(), sorted.end());
        for(int k = 0; k < n; k++) assert(wm.quantile(0, n, k) == sorted[k]);
    }
    BinaryTrie<unsigned, 6> trie;
    vector<unsigned> stored;
    unsigned mask = 0;
    for(int step = 0; step < 200; step++) {
        unsigned x = rng() % 64;
        if(step % 3 == 0) { mask ^= x; trie.all_xor(x); }
        else if(step % 3 == 1) { stored.push_back(x); trie.insert(x); }
        else {
            auto it = find(stored.begin(), stored.end(), x);
            assert(trie.erase(x) == (it != stored.end()));
            if(it != stored.end()) stored.erase(it);
        }
        auto visible = stored;
        for(auto& v : visible) v ^= mask;
        sort(visible.begin(), visible.end());
        for(unsigned q = 0; q < 64; q++) {
            assert(trie.lower_bound(q) == lower_bound(visible.begin(), visible.end(), q) - visible.begin());
            assert(trie.upper_bound(q) == upper_bound(visible.begin(), visible.end(), q) - visible.begin());
        }
    }
}

int main() {
    regression_test();
    INT(a, b);
    print(a + b);
}
