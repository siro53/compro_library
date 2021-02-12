template <class Cap> class Dinic {
  private:
    struct edge {
        int to, rev;
        Cap cap;
    };
    vector<vector<edge>> G;
    vector<int> level, iter;
    vector<pair<int, int>> pos;

    void bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        vector<int> que;
        int head = 0, tail = 0;
        level[s] = 0;
        que.emplace_back(s), tail++; // push
        while(head != tail) {
            int v = que[head++]; // pop
            for(const auto &e : G[v]) {
                if(e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    if(e.to == t) return;
                    que.emplace_back(e.to), tail++; // push
                }
            }
        }
    }

    Cap dfs(const int &v, const int &s, Cap now) {
        if(v == s || now == 0) return now;
        Cap res = 0;
        int sz = (int)G[v].size();
        for(int &i = iter[v]; i < sz; i++) {
            edge &e = G[v][i], &re = G[e.to][e.rev];
            if(level[v] <= level[e.to] || re.cap <= 0) continue;
            Cap d = dfs(e.to, s, min(now - res, re.cap));
            if(d > 0) {
                e.cap += d;
                re.cap -= d;
                res += d;
                if(res == now) break;
            }
        }
        return res;
    }

  public:
    Dinic(int n) : G(n), level(n), iter(n) {}

    int add_edge(int from, int to, Cap cap) {
        int n = (int)G.size();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        assert(0 <= cap);
        int m = (int)pos.size();
        pos.emplace_back(from, (int)G[from].size());
        G[from].emplace_back(edge{to, (int)G[to].size(), cap});
        G[to].emplace_back(edge{from, (int)G[from].size() - 1, 0});
        return m;
    }

    struct res_edge {
        int from, to;
        Cap cap, flow;
    };

    res_edge get_edge(int i) {
        int m = (int)pos.size();
        assert(0 <= i && i < m);
        auto e = G[pos[i].first][pos[i].second];
        auto re = G[e.to][e.rev];
        return res_edge{pos[i].first, e.to, e.cap + re.cap, re.cap};
    }

    vector<res_edge> edges() {
        int m = (int)pos.size();
        vector<res_edge> res;
        for(int i = 0; i < m; i++) res.emplace_back(get_edge(i));
        return res;
    }

    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = (int)pos.size();
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto &e = G[pos[i].first][pos[i].second];
        auto &re = G[e.to][e.rev];
        e.cap = new_cap - new_flow;
        re.cap = new_flow;
    }

    Cap max_flow(int s, int t, Cap limit = numeric_limits<Cap>::max()) {
        Cap flow = 0;
        while(flow < limit) {
            bfs(s, t);
            if(level[t] < 0) return flow;
            fill(iter.begin(), iter.end(), 0);
            while(flow < limit) {
                Cap f = dfs(t, s, limit - flow);
                if(f == 0) break;
                flow += f;
            }
        }
        return flow;
    }
};