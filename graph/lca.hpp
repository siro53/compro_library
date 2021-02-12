struct LCA {
    const int n = 0;
    const int log2_n = 0;
    vector<vector<int>> par;
    vector<int> depth;

    LCA(const vector<vector<int>> &g, int root)
        : n(g.size()), log2_n(log2(n) + 1), par(log2_n, vector<int>(n)),
          depth(n) {
        dfs(g, root, -1, 0);
        for(int k = 0; k + 1 < log2_n; k++) {
            for(int v = 0; v < n; v++) {
                if(par[k][v] < 0) {
                    par[k + 1][v] = -1;
                } else {
                    par[k + 1][v] = par[k][par[k][v]];
                }
            }
        }
    }

    void dfs(const vector<vector<int>> &g, int v, int p, int d) {
        par[0][v] = p;
        depth[v] = d;
        for(auto &u : g[v]) {
            if(u != p) {
                dfs(g, u, v, d + 1);
            }
        }
    }

    int get_lca(int u, int v) {
        // uとvの深さが同じになるまで辿る
        if(depth[u] > depth[v]) {
            swap(u, v);
        }
        for(int k = 0; k < log2_n; k++) {
            if(((depth[v] - depth[u]) >> k) & 1) {
                v = par[k][v];
            }
        }

        if(u == v) {
            return u;
        }

        for(int k = log2_n - 1; k >= 0; k--) {
            if(par[k][u] != par[k][v]) {
                u = par[k][u];
                v = par[k][v];
            }
        }
        return par[0][u];
    }
};
