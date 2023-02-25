#pragma once

#include <algorithm>
#include <utility>
#include <vector>

#include "../graph_template.hpp"

template <typename Cost = int>
std::pair<Cost, std::vector<int>> get_diameter(const Graph<Cost> &G) {
    std::vector<Cost> depth(G.size());
    std::vector<int> par(G.size(), -1);
    auto dfs = [&](auto &&self, int u, int p, Cost d) -> void {
        depth[u] = d;
        par[u] = p;
        for(const auto &e : G[u]) {
            if(e.to == p) continue;
            self(self, e.to, u, d + e.cost);
        }
    };
    dfs(dfs, 0, -1, 0);
    int from = std::max_element(depth.begin(), depth.end()) - depth.begin();
    dfs(dfs, from, -1, 0);
    int to = std::max_element(depth.begin(), depth.end()) - depth.begin();
    std::vector<int> path = {to};
    while(1) {
        int nxt = par[path.back()];
        if(nxt == -1) break;
        path.push_back(nxt);
    }
    return std::make_pair(depth[to], path);
}