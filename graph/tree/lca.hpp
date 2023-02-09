#pragma once

#include <cmath>
#include <vector>

#include "../graph_template.hpp"

template <class Cost = int> class LCA {
  public:
    LCA() = default;
    explicit LCA(const Graph<Cost> &G, int root = 0)
        : G(G), root(root), LOG((int)log2(G.size()) + 1), depth(G.size()),
          parent(LOG, std::vector<int>(G.size())) {
        dfs(root, -1, 0);
        for(int k = 0; k + 1 < LOG; k++) {
            for(int i = 0; i < (int)G.size(); i++) {
                if(parent[k][i] < 0) {
                    parent[k + 1][i] = -1;
                } else {
                    parent[k + 1][i] = parent[k][parent[k][i]];
                }
            }
        }
    }
    int get_lca(int u, int v) {
        if(depth[u] > depth[v]) std::swap(u, v);
        for(int k = 0; k < LOG; k++) {
            if((depth[u] - depth[v]) >> k & 1) v = parent[k][v];
        }
        if(u == v) return u;
        for(int k = LOG - 1; k >= 0; k--) {
            if(parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
    int get_dist(int u, int v) {
        return (depth[u] + depth[v] - 2 * depth[get_lca(u, v)]);
    }

  private:
    Graph<Cost> G;
    const int root;
    const int LOG;
    std::vector<Cost> depth;
    std::vector<std::vector<int>> parent;

    void dfs(int u, int p, Cost d) {
        depth[u] = d;
        parent[0][u] = p;
        for(const auto &e : G[u]) {
            if(e.to == p) continue;
            dfs(e.to, u, d + e.cost);
        }
    }
};