#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../graph/tree/lca.hpp"
#include "../../../math/two_sat.hpp"

void regression_test() {
    LCA<> empty;
    TwoSat<> sat;
    assert(sat.satisfiable() && sat.get_answer().empty());
    mt19937 rng(53);
    for(int n = 1; n <= 50; n++) {
        Graph<> g(n);
        vector<int> p(n, -1), d(n);
        for(int i = 1; i < n; i++) { p[i] = rng() % i; d[i] = d[p[i]] + 1; g.add_undirected_edge(p[i], i); }
        LCA<> lca(g);
        for(int u = 0; u < n; u++) for(int v = 0; v < n; v++) {
            int a = u, b = v;
            while(d[a] > d[b]) a = p[a];
            while(d[b] > d[a]) b = p[b];
            while(a != b) { a = p[a]; b = p[b]; }
            assert(lca.get_lca(u, v) == a);
        }
    }
}

int main() {
    regression_test();
    INT(a, b);
    print(a + b);
}
