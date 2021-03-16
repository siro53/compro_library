#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2748"
#include "../template/template.cpp"
#include "../graph/scc.hpp"

#define ERROR 1e-5

bool solve() {
    int N; cin >> N;
    if(N == 0) return false;
    vector<vector<int>> G(N); vector<double> p(N);
    REP(i, N) {
        cin >> p[i];
        int m; cin >> m;
        REP(_, m) {
            int to; cin >> to; to--;
            G[i].push_back(to);
        }
    }

    SCC scc(G);
    scc.build();
    vector<double> probs(scc.size(), 1.0);
    auto new_G = scc.get_contract_graph();

    REP(i, N) {
        probs[scc[i]] *= p[i];
    }
    REP(i, probs.size()) probs[i] = 1.0 - probs[i];

    // topological sort
    vector<int> tps;
    {
        stack<int> st;
        vector<int> in(scc.size(), 0);
        REP(u, new_G.size()) {
            for(int v : new_G[u]) in[v]++;
        }
        REP(i, new_G.size()) if(in[i] == 0) st.push(i);

        while(!st.empty()) {
            int u = st.top(); st.pop();
            tps.push_back(u);
            for(int v : new_G[u]) {
                in[v]--;
                if(in[v] == 0) st.push(v);
            }
        }
    }

    double ans = 1.0;
    vector<bool> seen(tps.size(), false);
    REP(i, tps.size()) {
        int u = tps[i];
        if(!seen[u]) ans *= probs[u];
        for(int v : new_G[u]) {
            seen[v] = true;
        }
    }

    cout << ans << "\n";
    return true;
}

int main() {
    while(solve());
}