struct BipartiteMatching {
    int L, R;
    vector<int> l, r, d;
    vector<bool> seen;
    vector<vector<int>> G;

    BipartiteMatching(int L, int R)
        : L(L), R(R), l(L, -1), r(R, -1), d(L), seen(L), G(L) {}

    void add_edge(int _l, int _r) { G[_l].emplace_back(_r); }

    void bfs() {
        vector<int> que;
        int head = 0, tail = 0;
        fill(d.begin(), d.end(), -1);
        for(int i = 0; i < L; i++) {
            if(l[i] == -1) {
                que.emplace_back(i), tail++;
                d[i] = 0;
            }
        }
        while(head != tail) {
            int v = que[head++];
            for(const auto &u : G[v]) {
                if(r[u] != -1 && d[r[u]] == -1) {
                    d[r[u]] = d[v] + 1;
                    que.emplace_back(r[u]), tail++;
                }
            }
        }
    }

    bool dfs(int v) {
        if(seen[v]) return false;
        seen[v] = true;
        for(const auto &u : G[v]) {
            if(r[u] == -1 || (d[r[u]] == d[v] + 1 && dfs(r[u]))) {
                l[v] = u;
                r[u] = v;
                return true;
            }
        }
        return false;
    }

    int matching() {
        int res = 0;
        while(1) {
            bfs();
            fill(seen.begin(), seen.end(), false);
            int f = 0;
            for(int i = 0; i < L; i++) {
                if(l[i] == -1 && dfs(i)) f++;
            }
            if(f == 0) return res;
            res += f;
        }
    }
};
