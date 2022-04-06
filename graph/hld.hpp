class HeavyLightDecomposition {
    int N;
    vector<vector<int>> G;
    vector<int> in, out, sz, head, par, dep, rev;
    bool isBuilt;

    void dfs_sz(int u, int p, int d) {
        dep[u] = d;
        if(!G[u].empty() and G[u].front() == p) swap(G[u].front(), G[u].back());
        for(int& v : G[u]) {
            if(v == p) continue;
            dfs_sz(v, u, d+1);
            sz[u] += sz[v];
            if(sz[v] > sz[G[u].front()]) swap(v, G[u].front());
        }
    }

    void dfs_hld(int u, int p, int &k) {
        par[u] = p;
        in[u] = k++;
        rev[in[u]] = u;
        for(const int& v : G[u]) {
            if(v == p) continue;
            head[v] = (v == G[u].front() ? head[u] : v);
            dfs_hld(v, u, k);
        }
        out[u] = k;
    }

  public:
    HeavyLightDecomposition(int N)
        : N(N), G(N), in(N, -1), out(N, -1), sz(N, 1), head(N), par(N, -1), dep(N), rev(N), isBuilt(false) {}

    HeavyLightDecomposition(const vector<vector<int>> &g)
        : N((int)g.size()), G(N), in(N, -1), out(N, -1), sz(N, 1), head(N),
          par(N, -1), dep(N), rev(N), isBuilt(false) {}

    inline void add_edge(int u, int v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    void build(int root = 0) {
        dfs_sz(root, -1, 0);
        head[root] = root;
        int k = 0;
        dfs_hld(root, -1, k);
        isBuilt = true;
        // debug(in, head);
    }

    int operator[](int u) {
        assert(isBuilt and 0 <= u and u < N);
        return in[u];
    }

    int lca(int u, int v) {
        assert(isBuilt and 0 <= u and u < N and 0 <= v and v < N);
        while(true) {
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }

    int dist(int u, int v) {
        assert(isBuilt and 0 <= u and u < N and 0 <= v and v < N);
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    // 頂点uから親方向に距離k登った頂点を返す
    int la(int u, int k) {
        assert(isBuilt and 0 <= u and u < N);
        if(dep[u] < k) return -1; 
        while(true) {
            if(in[u] - k >= in[head[u]]) return rev[in[u] - k];
            k -= (in[u] - in[head[u]] + 1);
            u = par[head[u]];
        }
    }   

    // 頂点属性
    vector<pair<int, int>> path(int u, int v) {
        assert(isBuilt and 0 <= u and u < N and 0 <= v and v < N);
        // u -> vの向きになるように返す
        vector<pair<int, int>> ret;
        while(true) {
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) {
                ret.emplace_back(in[u], in[v] + 1);
                break;
            } else {
                ret.emplace_back(in[head[v]], in[v] + 1);
                v = par[head[v]];
            }
        }
        return ret;
    }

    // 辺属性
    vector<pair<int, int>> path_edge(int u, int v) {
        assert(isBuilt and 0 <= u and u < N and 0 <= v and v < N);
        vector<pair<int, int>> ret;
        while(true) {
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) {
                if(u != v) ret.emplace_back(in[u] + 1, in[v] + 1);
                break;
            } else {
                ret.emplace_back(in[head[v]], in[v] + 1);
                v = par[head[v]];
            }
        }
        return ret;
    }

    pair<int, int> subtree(int u) { 
        assert(isBuilt and 0 <= u and u < N);
        return {in[u], out[u]};
    }
};