vector<int> get_diameter_path(const vector<vector<int>> &G) {
    int n = (int)G.size();
    vector<int> depth(n), par(n);

    auto dfs = [&](auto &&dfs, int v, int p, int d) -> void {
        depth[v] = d;
        par[v] = p;
        for(const int &u : G[v]) {
            if(u != p) {
                dfs(dfs, u, v, d + 1);
            }
        }
    };

    dfs(dfs, 0, -1, 0);
    int from = max_element(ALL(depth)) - depth.begin();
    dfs(dfs, from, -1, 0);
    int to = max_element(ALL(depth)) - depth.begin();

    vector<int> res;
    int now = to;
    while(now != from) {
        res.emplace_back(now);
        now = par[now];
    }
    res.emplace_back(now);

    return res;
}