#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

#include "graph_template.hpp"

template <class Cost = int> class SCC {
  public:
    explicit SCC(int N)
        : G(N), G_rev(N), comp(N, -1), seen(N, false), isBuilt(false) {}
    explicit SCC(const Graph<Cost> &g)
        : G(g), G_rev(g.size()), comp(g.size(), -1), seen(g.size(), false) {
        for(int i = 0; i < (int)g.size(); i++) {
            for(const auto &e : g[i]) G_rev.add_directed_edge(e.to, i);
        }
        build();
    }
    inline void add_directed_edge(int from, int to) {
        assert(!isBuilt &&
               "This scc_graph is already built, but you tried to add edge.");
        G.add_directed_edge(from, to);
        G_rev.add_directed_edge(to, from);
    }
    void build() {
        assert(!isBuilt && "This scc_graph is already built.");
        for(int i = 0; i < (int)G.size(); i++) {
            if(!seen[i]) dfs(i);
        }
        std::reverse(vs.begin(), vs.end());
        count = 0;
        for(const int v : vs) {
            if(comp[v] == -1) {
                dfs_rev(v, count);
                count++;
            }
        }
        isBuilt = true;
    }
    Graph<Cost> get_contracted_graph() {
        assert(isBuilt && "This scc_graph is not yet built.");
        Graph<Cost> new_g(count);
        for(int i = 0; i < (int)G.size(); i++) {
            for(const auto &e : G[i]) {
                int from = comp[i];
                int to = comp[e.to];
                if(from != to) new_g.add_directed_edge(from, to, e.cost);
            }
        }
        return new_g;
    }
    int operator[](const int &k) const {
        assert(isBuilt && "This scc_graph is not yet built.");
        return comp[k];
    }
    size_t size() { return (size_t)count; }

  private:
    Graph<Cost> G, G_rev;
    std::vector<int> vs, comp;
    std::vector<bool> seen;
    int count;
    bool isBuilt;

    void dfs(int u) {
        seen[u] = true;
        for(const auto &e : G[u]) {
            if(!seen[e.to]) dfs(e.to);
        }
        vs.push_back(u);
    }
    void dfs_rev(int u, int idx) {
        comp[u] = idx;
        for(const auto &e : G_rev[u]) {
            if(comp[e.to] == -1) dfs_rev(e.to, idx);
        }
    }
};