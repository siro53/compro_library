template<typename Cost>
class range_edge_graph {
private:
    struct E {
        int to;
        Cost cost;
        E() {}
        E(int to, Cost cost): to(to), cost(cost) {}
    };
    int N;
    vector<vector<E>> G;
 
    // map [3n, 4n) -> [n, 2n)
    void add_edge(int from, int to, Cost cost) {
        if(3*N <= from) from -= 2*N;
        G[from].emplace_back(to, cost);
    }
 
public:
    range_edge_graph(int N): N(N) {
        G.resize(3*N);
        for(int i = 1; i < N; i++) {
            int chl = (i << 1) | 0, chr = (i << 1) | 1;
            // 上側, 根 -> 葉
            add_edge(i, chl, 0);
            add_edge(i, chr, 0);
            // 下側, 葉 -> 根
            add_edge(chl+2*N, i+2*N, 0);
            add_edge(chr+2*N, i+2*N, 0);
        }
    }
    
    void add_edge(int l1, int r1, int l2, int r2, Cost cost) {
        int id = (int)G.size();
        // 下側の[l1, r1) -> id
        for(l1 += N, r1 += N; l1 < r1; l1 >>= 1, r1 >>= 1) {
            if(l1 & 1) add_edge(l1+2*N, id, 0), l1++;
            if(r1 & 1) r1--, add_edge(r1+2*N, id, 0);
        }
        vector<E> ad;
        // id -> 上側の[l2, r2)
        for(l2 += N, r2 += N; l2 < r2; l2 >>= 1, r2 >>= 1) {
            if(l2 & 1) ad.emplace_back(l2++, cost);
            if(r2 & 1) ad.emplace_back(--r2, cost);
        }
        G.emplace_back(ad);
    }
 
    vector<Cost> dijkstra(int s) {
        s += N;
        vector<Cost> dist(G.size(), numeric_limits<Cost>::max());
        dist[s] = 0;
        using P = pair<Cost, int>;
        priority_queue<P, vector<P>, greater<P>> que;
        que.emplace(0, s);
        while(!que.empty()) {
            auto [d, u] = que.top();
            que.pop();
            if(d > dist[u]) continue;
            for(const auto& [to, cost] : G[u]) {
                if(dist[to] > d + cost) {
                    dist[to] = d + cost;
                    que.emplace(dist[to], to);
                }
            }
        }
        vector<Cost> ret(dist.begin() + N, dist.begin() + 2*N);
        return ret;
    }

    pair<vector<Cost>, vector<int>> restore(int s, int g) {
        s += N;
        vector<Cost> dist(G.size(), numeric_limits<Cost>::max());
        vector<int> pre(G.size(), -1);
        dist[s] = 0;
        using P = pair<Cost, int>;
        priority_queue<P, vector<P>, greater<P>> que;
        que.emplace(0, s);
        while(!que.empty()) {
            auto [d, u] = que.top();
            que.pop();
            if(d > dist[u]) continue;
            for(const auto& [to, cost] : G[u]) {
                if(dist[to] > d + cost) {
                    dist[to] = d + cost;
                    pre[to] = u; 
                    que.emplace(dist[to], to);
                }
            }
        }
        vector<int> path;
        {
            int now = g + N;
            while(now != -1) {
                if(N <= now and now < 2*N) path.emplace_back(now - N);
                now = pre[now];
            }
            reverse(ALL(path));
        }
        vector<Cost> dist_ret(dist.begin() + N, dist.begin() + 2*N);
        return {dist_ret, path};
    }
};