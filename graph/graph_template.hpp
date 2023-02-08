#pragma once

#include <cassert>
#include <vector>

template <class Cost = int> struct Edge {
    int from, to;
    Cost cost;
    int id;
    Edge() = default;
    explicit Edge(int from, int to, Cost cost = 1, int id = -1)
        : from(from), to(to), cost(cost), id(id) {}
};

template <class Cost> struct Graph {
    int N, M;
    std::vector<std::vector<Edge<Cost>>> G;

    Graph() = default;
    explicit Graph(int N) : N(N), M(0), G(N) {}

    void add_directed_edge(int from, int to, Cost cost = 1) {
        assert(0 <= from && from < N);
        assert(0 <= to && to < N);
        G[from].emplace_back(from, to, cost, M++);
    }

    void add_undirected_edge(int from, int to, Cost cost = 1) {
        assert(0 <= from && from < N);
        assert(0 <= to && to < N);
        G[from].emplace_back(from, to, cost, M);
        G[to].emplace_back(to, from, cost, M++);
    }

    inline std::vector<Edge<Cost>> &operator[](const int &i) { return G[i]; }
    inline const std::vector<Edge<Cost>> &operator[](const int &i) const {
        return G[i];
    }
};

template <class Cost> using Edges = std::vector<Edge<Cost>>;