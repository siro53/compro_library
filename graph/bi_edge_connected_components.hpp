class BECC {
private:
    int N, sz;
    vector<vector<int>> G;
    vector<int> seen, imos, comp;

    void dfs1(int u, int p) {
        seen[u] = 1;
        bool is_skipped_par = false;
        for(int v : G[u]) {
            if(v == p and !is_skipped_par) {
                is_skipped_par = true;
                continue;
            }
            if(seen[v] == 0) {
                dfs1(v, u);
                imos[u] += imos[v];
            } else if(seen[v] == 1) {
                imos[u]++;
                imos[v]--;
            }
        }
        seen[u] = 2;
    }

    void dfs2(int u) {
        for(int v : G[u]) {
            if(comp[v] != -1) continue;
            comp[v] = (imos[v] == 0 ? sz++ : comp[u]);
            dfs2(v);
        }
    }

public:
    BECC(int N): N(N), G(N), seen(N, 0), imos(N, 0), sz(0), comp(N, -1) {}
    BECC(vector<vector<int>> g) : N(g.size()), G(g), seen(N, 0), imos(N, 0), sz(0), comp(N, -1) {}
    
    void add_edge(int u, int v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    } 

    void build() {
        for(int i = 0; i < N; i++) {
            if(seen[i] != 0) continue;
            dfs1(i, -1);
        }
        for(int i = 0; i < N; i++) {
            if(comp[i] != -1) continue;
            comp[i] = sz++;
            dfs2(i);
        }
    }
    
    // 必ずbuild()した後に呼び出すこと!!!
    vector<vector<int>> get_contract_graph() {
        vector<vector<int>> h(sz);
        for(int u = 0; u < N; u++) {
            for(const int& v : G[u]) {
                int x = comp[u], y = comp[v];
                if(x == y) continue;
                h[x].push_back(y);
                h[y].push_back(x);
            }
        }
        return h;
    }

    int operator[](int k) const { return comp[k]; }
    int size() const { return sz; }
};