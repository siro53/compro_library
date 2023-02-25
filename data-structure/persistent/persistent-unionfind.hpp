#pragma once

#include <algorithm>
#include <tuple>

#include "persistent-array.hpp"

struct PersistentUnionFind {
    PersistentArray<int> par;
    using Node = decltype(par)::Node;
    Node* root;

    explicit PersistentUnionFind(int n): par(std::vector<int>(n, -1)) {
        root = par.root;
    }
    // (leader, size)
    std::pair<int, int> leader_and_size(int u, Node* r) {
        int p = par.get(r, u);
        return (p < 0 ? std::make_pair(u, -p) : leader_and_size(p, r));
    }
    std::pair<int, int> leader_and_size(int u) {
        return leader_and_size(u, root);
    }
    inline int leader(int u, Node* r) { return leader_and_size(u, r).first; }
    inline int leader(int u) { return leader_and_size(u, root).first; }
    inline int size(int u, Node* r) { return leader_and_size(u, r).second; }
    inline int size(int u) { return leader_and_size(u, root).second; }
    inline bool same(int u, int v, Node* r) { return (leader(u, r) == leader(v, r)); }
    inline bool same(int u, int v) { return same(u, v, root); }
    bool merge(int u, int v, Node* r) {
        int sz_u, sz_v;
        std::tie(u, sz_u) = leader_and_size(u, r);
        std::tie(v, sz_v) = leader_and_size(v, r);
        if(u == v) return false;
        if(sz_u < sz_v) {
            std::swap(u, v);
            std::swap(sz_u, sz_v);
        }
        r = par.set(r, u, -(sz_u + sz_v));
        r = par.set(r, v, u);
        root = r;
        return true;
    }
    bool merge(int u, int v) { return merge(u, v, root); }
    Node* get_root() const { return root; }
};