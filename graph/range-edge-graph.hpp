#pragma once

#include "graph_template.hpp"

template <typename Cost = int> class RangeEdgeGraph {
  public:
    explicit RangeEdgeGraph(int n, int m) : N(n), M(0), G(3 * N + m) {
        for(int i = 1; i < N; i++) {
            G.add_directed_edge(i, (i << 1 | 0), 0);
            G.add_directed_edge(i, (i << 1 | 1), 0);
            G.add_directed_edge((i << 1 | 0) + N * 2, i + N * 2, 0);
            G.add_directed_edge((i << 1 | 1) + N * 2, i + N * 2, 0);
        }
    }
    void add_edge(int from_l, int from_r, int to_l, int to_r, Cost cost) {
        assert(0 <= from_l and from_l < from_r and from_r <= N);
        assert(0 <= to_l and to_l < to_r and to_r <= N);
        assert(3 * N + M < (int)G.size());
        int id = 3 * N + M;
        M++;
        from_l += N;
        from_r += N;
        while(from_l < from_r) {
            if(from_l & 1) G.add_directed_edge(from_l + 2*N, id, 0), from_l++;
            if(from_r & 1) from_r--, G.add_directed_edge(from_r + 2*N, id, 0);
            from_l <<= 1;
            from_r <<= 1;
        }
        to_l += N;
        to_r += N;
        while(to_l < to_r) {
            if(to_l & 1) G.add_directed_edge(id, to_l, cost), to_l++;
            if(to_r & 1) to_r--, G.add_directed_edge(id, to_r, cost);
            to_l <<= 1;
            to_r <<= 1;
        }
    }
    operator Graph<Cost>() const { return G; }

  private:
    int N, M;
    Graph<Cost> G;
};