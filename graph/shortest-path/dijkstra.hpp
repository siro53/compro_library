#pragma once

#include <functional>
#include <limits>
#include <queue>
#include <utility>

#include "../graph_template.hpp"

template <typename Cost>
std::pair<std::vector<Cost>, std::vector<int>>
dijkstra(const Graph<Cost> &G, int start, Cost iv = 0,
         Cost inf = std::numeric_limits<Cost>::max()) {
    using Data = std::pair<Cost, int>;
    int N = G.N;
    std::vector<Cost> dist(N, inf);
    std::vector<int> prev(N, -1);

    dist[start] = iv;
    std::priority_queue<Data, std::vector<Data>, std::greater<Data>> que;
    que.emplace(iv, start);
    while(!que.empty()) {
        auto [d, u] = que.top();
        que.pop();
        if(d > dist[u]) continue;
        for(const auto &e : G[u]) {
            if(dist[e.to] > d + e.cost) {
                dist[e.to] = d + e.cost;
                prev[e.to] = u;
                que.emplace(dist[e.to], e.to);
            }
        }
    }

    return std::make_pair(dist, prev);
}