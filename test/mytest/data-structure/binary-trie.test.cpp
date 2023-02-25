#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../random/rng.hpp"
#include "../../../data-structure/binary-trie.hpp"

void binary_trie_test() {
    REP(testcase_idx, 20) {
        vector<int> a;
        BinaryTrie<int, 30> S;
        RNG32 rng;
        REP(_, 500) {
            int t = rng.randint(0, 7);
            if(a.empty()) t = 0;
            if(t == 0) { // insert
                int x = rng.randint(0, 1 << 30);
                S.insert(x);
                a.push_back(x);
            } else if(t == 1) { // erase;
                int k = rng.randint(0, SZ(a));
                swap(a[k], a.back());
                S.erase(a.back());
                a.pop_back();
            } else if(t == 2) { // min_element
                assert(*min_element(ALL(a)) == S.min_element());
            } else if(t == 3) { // max_element
                assert(*max_element(ALL(a)) == S.max_element());
            } else if(t == 4) { // kth_element
                sort(ALL(a));
                int k = rng.randint(0, SZ(a));
                assert(a[k] == S.get_kth_element(k));
            } else if(t == 5) { // lower_bound
                sort(ALL(a));
                int k = rng.randint(0, SZ(a));
                int id1 = S.lower_bound(a[k]);
                int id2 = lower_bound(ALL(a), a[k]) - a.begin();
                assert(id1 == id2);
            } else if(t == 6) {
                sort(ALL(a));
                int k = rng.randint(0, SZ(a));
                int id1 = S.upper_bound(a[k]);
                int id2 = upper_bound(ALL(a), a[k]) - a.begin();
                assert(id1 == id2);
            }
        }
    }
}

int main() {
    binary_trie_test();
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
}