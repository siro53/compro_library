#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#define IGNORE 
#include "../../../template/template.cpp"
#include "../../../data-structure/binary-trie.hpp"

int main() {
    BinaryTrie<int> S(500010);
    int Q;
    cin >> Q;
    while(Q--) {
        int t, x;
        cin >> t >> x;
        if(t == 0) {
            if(S.count(x) > 0) continue;
            S.insert(x);
            assert(S.count(x) > 0);
        } else if(t == 1) {
            S.erase(x);
        } else {
            cout << S.set_xor_min(x) << '\n';
        }
    }
}