#pragma once

#include <functional>
#include <limits>
#include <queue>
#include <utility>

#include "../graph_template.hpp"

template <typename Cost = int>
std::pair<std::vector<Cost>, std::vector<int>>
bfs(const Graph<Cost> &G, int start, Cost iv = 0,
    Cost inf = std::numeric_limits<Cost>::max()) {
    using Data = std::pair<Cost, int>;
    int N = (int)G.size();
    std::vector<Cost> dist(N, inf);
    std::vector<int> prev(N, -1);

    dist[start] = iv;
    std::queue<int> que;
    que.emplace(start);
    while(!que.empty()) {
        int u = que.front();
        que.pop();
        for(const auto &e : G[u]) {
            if(dist[e.to] > dist[u] + 1) {
                dist[e.to] = dist[u] + 1;
                prev[e.to] = u;
                que.emplace(e.to);
            }
        }
    }

    return std::make_pair(dist, prev);
}