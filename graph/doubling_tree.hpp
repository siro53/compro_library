#include "lca.hpp"

template <class T> struct doubling_tree : LCA {
    vector<vector<T>> db;
    bool edge;
    function<T(T, T)> f;
    T E;
    doubling_tree(const vector<vector<int>> &g, int root, function<T(T, T)> f,
                  T E)
        : LCA::LCA(g, root), f(f), E(E), db(log2_n, vector<T>(n, E)) {}
    void build(const vector<T> &init, bool is_edge) {
        edge = is_edge;
        for(int i = 0; i < n; i++) db[0][i] = init[i];
        for(int k = 0; k < log2_n - 1; k++) {
            for(int i = 0; i < n; i++) {
                if(par[k][i] < 0) {
                    db[k + 1][i] = db[k][i];
                } else {
                    db[k + 1][i] = f(db[k][i], db[k][par[k][i]]);
                }
            }
        }
    }
    T query(int u, int v) {
        if(depth[u] > depth[v]) swap(u, v);
        T res = E;
        for(int k = 0; k < log2_n; k++) {
            if((depth[v] - depth[u]) >> k & 1) {
                res = f(res, db[k][v]), v = par[k][v];
            }
        }
        if(u == v) return res;
        for(int k = log2_n - 1; k >= 0; k--) {
            if(par[k][u] != par[k][v]) {
                res = f(res, f(db[k][u], db[k][v]));
                v = par[k][v], u = par[k][u];
            }
        }
        res = f(res, f(db[0][u], db[0][v]));
        if(!edge) res = f(res, db[0][par[0][u]]);
        return res;
    }
};