#pragma once

#include "../graph_template.hpp"

// TODO: 良いインターフェイスを模索する
struct CentroidDecomposition {
    const Graph<int>& G;
    std::vector<int> subtree_size, parent;
    std::vector<bool> removed;

    explicit CentroidDecomposition(const Graph<int>& g): G(g), subtree_size(g.size(), 0), parent(g.size(), -1), removed(g.size(), false) {}

    void get_subtree_size(int u, int p) {
        subtree_size[u] = 1;
        for(int v : G[u]) {
            if(v == p or removed[v]) continue;
            get_subtree_size(v, u);
            subtree_size[u] += subtree_size[v];
        }
    }

    void decomp(int u, int p) {
        get_subtree_size(u, -1);
        int sz = subtree_size[u];
        int pre = -1;
        while(1) {
            int mx = -1, mx_v = -1;
            for(int v : G[u]) {
                if(v == pre or removed[v]) continue;
                if(mx < subtree_size[v]) {
                    mx = subtree_size[v];
                    mx_v = v;
                }
            }
            if(mx * 2 <= sz) break;
            pre = u;
            u = mx_v;
        }
        removed[u] = true;
        parent[u] = p;
        for(int v : G[u]) {
            if(removed[v]) continue;
            decomp(v, u);
        }
    }
};