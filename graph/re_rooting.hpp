template<class S, S (*op)(S, int), S (*merge)(S, S), S (*op2)(S, int), S (*e)()>
class re_rooting {
private:
    int N;
    vector<vector<int>> G;
    vector<vector<S>> dp;

    S dfs1(int u, int p) {
        S res = e();
        for(int i = 0; i < (int)G[u].size(); i++) {
            if(G[u][i] == p) continue;
            int v = G[u][i];
            dp[u][i] = dfs1(v, u);
            res = merge(res, op(dp[u][i], v));
        }
        return op2(res, u);
    }

    void dfs2(int u, int p, S from_par) {
        int sz = (int)G[u].size();
        for(int i = 0; i < sz; i++) {
            if(G[u][i] == p) {
                dp[u][i] = from_par;
                break;
            }
        }
        vector<S> rsum(sz + 1);
        rsum[sz] = e();
        for(int i = sz-1; i >= 0; i--) {
            rsum[i] = merge(rsum[i+1], op(dp[u][i], G[u][i]));
        }
        S lsum = e();
        for(int i = 0; i < sz; i++) {
            int v = G[u][i];
            if(v != p) {
                S val = merge(lsum, rsum[i+1]);
                dfs2(v, u, op2(val, u));
            }
            lsum = merge(lsum, op(dp[u][i], v));
        }
    }

    void build(int root) {
        for(int i = 0; i < N; i++) dp[i].resize(G[i].size());
        dfs1(root, -1);
        dfs2(root, -1, e());
    }
    
public:
    re_rooting(int N): N(N), G(N), dp(N) {}
    re_rooting(const vector<vector<int>>& G): N(G.size()), G(G), dp(G.size()) {}

    void add_edge(int u, int v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    vector<S> solve(int root = 0) {
        build(root);
        vector<S> ans(N);
        for(int u = 0; u < N; u++) {
            S res = e();
            for(int i = 0; i < (int)G[u].size(); i++) {
                res = merge(res, op(dp[u][i], G[u][i]));
            }
            ans[u] = op2(res, u);
        }
        return ans;
    }
};

template<class T>
struct Edge {
    int from, to;
    T cost;
    Edge() = default;
    Edge(int from, int to, T cost): from(from), to(to), cost(cost) {}
    operator int() const { return to; }
};

template<class S, class Cost, S (*op)(S, Edge<Cost>), S (*merge)(S, S), S (*op2)(S, int), S (*e)()>
class re_rooting_edge {
private:
    int N;
    vector<vector<Edge<Cost>>> G;
    vector<vector<S>> dp;

    S dfs1(int u, int p) {
        S res = e();
        for(int i = 0; i < (int)G[u].size(); i++) {
            int v = G[u][i];
            if(v == p) continue;
            dp[u][i] = dfs1(v, u);
            res = merge(res, op(dp[u][i], G[u][i]));
        }
        return op2(res, u);
    }

    void dfs2(int u, int p, S from_par) {
        int sz = (int)G[u].size();
        for(int i = 0; i < sz; i++) {
            if(G[u][i] == p) {
                dp[u][i] = from_par;
                break;
            }
        }
        vector<S> rsum(sz + 1);
        rsum[sz] = e();
        for(int i = sz-1; i >= 0; i--) {
            rsum[i] = merge(rsum[i+1], op(dp[u][i], G[u][i]));
        }
        S lsum = e();
        for(int i = 0; i < sz; i++) {
            int v = G[u][i];
            if(v != p) {
                S val = merge(lsum, rsum[i+1]);
                dfs2(v, u, op2(val, u));
            }
            lsum = merge(lsum, op(dp[u][i], G[u][i]));
        }
    }

    void build(int root) {
        for(int i = 0; i < N; i++) dp[i].resize(G[i].size());
        dfs1(root, -1);
        dfs2(root, -1, e());
    }

public:
    re_rooting_edge(int N): N(N), G(N), dp(N) {}
    re_rooting_edge(const vector<vector<Edge<Cost>>>& G): N(G.size()), G(G), dp(G.size()) {}

    void add_edge(int u, int v, Cost cost) {
        G[u].emplace_back(u, v, cost);
        G[v].emplace_back(v, u, cost);
    }

    vector<S> solve(int root = 0) {
        build(root);
        vector<S> ans(N);
        for(int u = 0; u < N; u++) {
            S res = e();
            for(int i = 0; i < (int)G[u].size(); i++) {
                res = merge(res, op(dp[u][i], G[u][i]));
            }
            ans[u] = op2(res, u);
        }
        return ans;
    }
};