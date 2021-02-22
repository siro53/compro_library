class SCC {
  private:
    vector<vector<int>> G;
    vector<vector<int>> revG;
    vector<int> vs, comp;
    vector<bool> seen;
    int cnt;
    void dfs(int v) {
        seen[v] = true;
        for(const int &u : G[v]) {
            if(!seen[u]) { dfs(u); }
        }
        vs.emplace_back(v);
    }
    void rev_dfs(int v, int id) {
        seen[v] = true;
        comp[v] = id;
        for(const int &u : revG[v]) {
            if(comp[u] == -1) { rev_dfs(u, id); }
        }
    }

  public:
    SCC(int N) : G(N), revG(N), comp(N, -1), seen(N, false) {}
    SCC(vector<vector<int>> g)
        : G(g), revG(g.size()), comp(g.size(), -1), seen(g.size(), false) {
        int n = (int)g.size();
        for(int i = 0; i < n; i++) {
            for(const auto &u : g[i]) { revG[u].emplace_back(i); }
        }
    }
    void add_edge(int i, int j) {
        G[i].emplace_back(j);
        revG[j].emplace_back(i);
    }
    void build() {
        int n = (int)G.size();
        for(int i = 0; i < n; i++) {
            if(!seen[i]) { dfs(i); }
        }
        reverse(ALL(vs));
        cnt = 0;
        for(const int &v : vs) {
            if(comp[v] == -1) {
                rev_dfs(v, cnt);
                cnt++;
            }
        }
    }
    int operator[](int k) const { return comp[k]; }
    int size() const { return cnt; }
};