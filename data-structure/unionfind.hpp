#pragma once

#include <algorithm>
#include <cassert>
#include <map>
#include <vector>

class UnionFind {
  public:
    UnionFind() = default;
    explicit UnionFind(int n) : N(n), parent_or_size(n, -1) {}
    int leader(int u) {
        assert(0 <= u && u < N);
        if(parent_or_size[u] < 0) return u;
        return (parent_or_size[u] = leader(parent_or_size[u]));
    }
    bool same(int u, int v) { return (leader(u) == leader(v)); }
    bool merge(int u, int v) {
        u = leader(u);
        v = leader(v);
        if(u == v) return false;
        if(-parent_or_size[u] < -parent_or_size[v]) std::swap(u, v);
        parent_or_size[u] += parent_or_size[v];
        parent_or_size[v] = u;
        return true;
    }
    int size(int u) { return (-parent_or_size[leader(u)]); }
    std::vector<std::vector<int>> groups() {
        std::vector<int> leaders(N), group_size(N, 0);
        for(int i = 0; i < N; i++) {
            leaders[i] = leader(i);
            group_size[leaders[i]]++;
        }
        std::vector<std::vector<int>> g(N);
        for(int i = 0; i < N; i++) g[i].reserve(group_size[i]);
        for(int i = 0; i < N; i++) g[leaders[i]].push_back(i);
        g.erase(std::remove_if(
                    g.begin(), g.end(),
                    [&](const std::vector<int> &v) { return v.empty(); }),
                g.end());
        return g;
    }
    std::map<int, std::vector<int>> groups_with_map() {
        std::map<int, std::vector<int>> g;
        for(int i = 0; i < N; i++) {
            int l = leader(i);
            if(!g.count(l)) g[l].push_back(i);
        }
        return g;
    }

  private:
    int N;
    std::vector<int> parent_or_size;
};