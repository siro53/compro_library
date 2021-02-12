#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "../template/template.cpp"
#include "../graph/dsu.hpp"

int main(){
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    while(q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 0) {
            uf.merge(u, v);
        } else {
            cout << uf.issame(u, v) << endl;
        }
    }
}