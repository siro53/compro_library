#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"
#include "../../../template/template.cpp"
#include "../../../data-structure/persistent/persistent-unionfind.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    PersistentUnionFind uf(N);
    vector<decltype(uf)::Node*> roots(Q + 1, nullptr);
    roots[0] = uf.get_root();
    REP(i, Q) {
        int t, k, u, v;
        cin >> t >> k >> u >> v;
        auto r = roots[k + 1];
        if(t == 0) {
            uf.merge(u, v, r);
            roots[i + 1] = uf.get_root();
        } else {
            cout << (int)uf.same(u, v, r) << '\n';
        }
    }
}