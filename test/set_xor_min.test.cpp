#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include "../template/template.cpp"
#include "../data_structure/binary_trie.hpp"

int main(){
    int Q;
    cin >> Q;
    BinaryTrie btrie;
    while(Q--) {
        int t, x;
        cin >> t >> x;
        if(t == 0) {
            btrie.insert(x);
        } else if(t == 1) {
            btrie.erase(x);
        } else {
            cout << btrie.min_element(x) << "\n";
        }
    }
}