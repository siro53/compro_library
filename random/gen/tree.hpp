#pragma once

#include <cassert>
#include <utility>
#include <vector>

#include "random.hpp"
#include "sequence.hpp"

// 頂点番号を一様ランダムに付け替え、各辺の向きと辺の順序をシャッフルする
inline std::vector<std::pair<int, int>>
relabel_edges(Random &rng, int n, std::vector<std::pair<int, int>> edges) {
    const std::vector<int> p = random_permutation(rng, n);
    for(auto &[u, v] : edges) {
        assert(0 <= u && u < n && 0 <= v && v < n);
        u = p[u], v = p[v];
        if(rng.coin()) std::swap(u, v);
    }
    rng.shuffle(edges);
    return edges;
}

// n 頂点のラベル付き木を一様に選ぶ (Prüfer 列の復元)
inline std::vector<std::pair<int, int>> random_tree(Random &rng, int n) {
    assert(n >= 1);
    std::vector<std::pair<int, int>> edges;
    if(n == 1) return edges;
    edges.reserve(n - 1);
    std::vector<int> code(n - 2), degree(n, 1);
    for(auto &x : code) x = int(rng.uniform(n)), degree[x]++;
    int ptr = 0;
    while(degree[ptr] != 1) ptr++;
    int leaf = ptr;
    for(int v : code) {
        edges.emplace_back(leaf, v);
        if(--degree[v] == 1 && v < ptr) {
            leaf = v;
        } else {
            ptr++;
            while(degree[ptr] != 1) ptr++;
            leaf = ptr;
        }
    }
    edges.emplace_back(leaf, n - 1);
    return relabel_edges(rng, n, edges);
}

// n 頂点のパスグラフ (頂点の並びは一様ランダム)
inline std::vector<std::pair<int, int>> random_path_tree(Random &rng, int n) {
    assert(n >= 1);
    std::vector<std::pair<int, int>> edges;
    for(int i = 0; i + 1 < n; i++) edges.emplace_back(i, i + 1);
    return relabel_edges(rng, n, edges);
}

// n 頂点のスターグラフ (中心は一様ランダム)
inline std::vector<std::pair<int, int>> random_star_tree(Random &rng, int n) {
    assert(n >= 1);
    std::vector<std::pair<int, int>> edges;
    for(int i = 1; i < n; i++) edges.emplace_back(0, i);
    return relabel_edges(rng, n, edges);
}

// 頂点 0 を根とする親配列。par[0] = -1、i >= 1 では par[i] は [0, i) の一様乱数
inline std::vector<int> random_parent_array(Random &rng, int n) {
    assert(n >= 1);
    std::vector<int> par(n, -1);
    for(int i = 1; i < n; i++) par[i] = rng.randint(0, i);
    return par;
}
