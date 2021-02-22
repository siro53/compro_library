#include "scc.hpp"

class two_sat {
  private:
    int N;
    vector<vector<int>> G;
    vector<bool> ans;
    int NOT(int i) { return i + (i < N ? N : -N); }

  public:
    two_sat() {}
    two_sat(int N) : N(N), G(2 * N), ans(N) {}
    void add_clause(int i, bool f, int j, bool g) {
        if(!f) i = NOT(i);
        if(!g) j = NOT(j);
        G[i].emplace_back(NOT(j));
        G[j].emplace_back(NOT(i));
    }
    bool satisfiable() {
        SCC scc(G);
        scc.build();
        for(int i = 0; i < N; i++) {
            if(scc[i] == scc[NOT(i)]) return false;
            ans[i] = scc[i] < scc[NOT(i)];
        }
        return true;
    }
    vector<bool> answer() { return ans; }
};