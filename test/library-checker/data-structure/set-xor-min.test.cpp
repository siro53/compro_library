#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include "../../../template/template.cpp"
#include "../../../data-structure/binary-trie.hpp"

int main() {
    BinaryTrie<int, 30> S;
    int Q;
    cin >> Q;
    while(Q--) {
        unsigned int t, x;
        cin >> t >> x;
        if(t == 0) {
            if(S.count(x) > 0) continue;
            S.insert(x);
            assert(S.count(x) > 0);
        } else if(t == 1) {
            S.erase(x);
            assert(S.count(x) == 0);
        } else {
            S.all_xor(x);
            cout << S.min_element() << '\n';
            S.all_xor(x);
        }
    }
}