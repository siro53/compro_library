#pragma once

#include <cassert>
#include <vector>

template <typename Cost = int> struct Edge {
    int from, to;
    Cost cost;
    int id;
    Edge() = default;
    explicit Edge(int from, int to, Cost cost = 1, int id = -1)
        : from(from), to(to), cost(cost), id(id) {}
    operator int() const { return to; }
};

template <typename Cost = int> class Graph {
  public:
    Graph() = default;
    explicit Graph(int N) : N(N), M(0), G(N) {}

    inline void add_directed_edge(int from, int to, Cost cost = 1) {
        assert(0 <= from && from < N);
        assert(0 <= to && to < N);
        G[from].emplace_back(from, to, cost, M++);
    }

    inline void add_undirected_edge(int from, int to, Cost cost = 1) {
        assert(0 <= from && from < N);
        assert(0 <= to && to < N);
        G[from].emplace_back(from, to, cost, M);
        G[to].emplace_back(to, from, cost, M++);
    }

    inline size_t size() const { return G.size(); }
    inline std::vector<Edge<Cost>> &operator[](const int &i) { return G[i]; }
    inline const std::vector<Edge<Cost>> &operator[](const int &i) const {
        return G[i];
    }

  private:
    int N, M;
    std::vector<std::vector<Edge<Cost>>> G;
};

template <class Cost = int> using Edges = std::vector<Edge<Cost>>;