template<class S, S (*op)(S, S), S (*e)(), S (*inv)(S)>
struct WeightedUnionFind {
    vector<int> par;
    vector<S> weight;

    WeightedUnionFind(int n): par(n, -1), weight(n, e()) {}
    int root(int u) {
        if(par[u] < 0) return u;
        int r = root(par[u]);
        weight[u] = op(weight[u], weight[par[u]]);
        return (par[u] = r);
    }
    bool same(int u, int v) { return (root(u) == root(v)); }
    int size(int u) { return (-par[root(u)]); }
    S get_weight(int u) {
        root(u);
        return weight[u];
    }
    // weight[v] = weight[u] + w
    bool merge(int u, int v, S w) {
        w = op(get_weight(u), w);
        w = op(inv(get_weight(v)), w);
        u = root(u);
        v = root(v);
        if(u == v) return false;
        if(par[u] > par[v]) {
            swap(u, v);
            w = inv(w);
        }
        par[u] += par[v];
        par[v] = u;
        weight[v] = w;
        return true;
    }
    // weight[v] - weight[u]
    S get_diff(int u, int v) {
        assert(same(u, v));
        return (op(inv(get_weight(u)), get_weight(v)));
    }
};