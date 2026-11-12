#pragma once

#include <cassert>
#include <tuple>
#include <type_traits>
#include <unordered_set>
#include <utility>
#include <vector>

#include "random.hpp"
#include "sequence.hpp"
#include "tree.hpp"

namespace random_gen_internal {
// n 頂点の無向単純グラフの辺のうち forbidden に含まれないものから k 本を一様に選ぶ
// forbidden は相異なる単純辺の列とする
inline std::vector<std::pair<int, int>>
sample_edges(Random &rng, int n, long long k,
             const std::vector<std::pair<int, int>> &forbidden) {
    const long long total = (long long)n * (n - 1) / 2;
    const long long available = total - (long long)forbidden.size();
    assert(0 <= k && k <= available);
    auto key = [n](int u, int v) {
        if(u > v) std::swap(u, v);
        return (long long)u * n + v;
    };
    std::unordered_set<long long> used;
    for(auto [u, v] : forbidden) used.insert(key(u, v));
    std::vector<std::pair<int, int>> edges;
    edges.reserve(k);
    if(2 * k <= available) {
        // 疎: 未使用の辺を引くまで棄却する (残りの候補は全体の 1/2 * available/total 以上)
        while((long long)edges.size() < k) {
            const int u = rng.randint(0, n);
            int v = rng.randint(0, n - 1);
            if(v >= u) v++;
            if(used.insert(key(u, v)).second) edges.emplace_back(u, v);
        }
    } else {
        // 密: 候補を列挙して部分的に Fisher-Yates を行う (total < 2k + |forbidden|)
        std::vector<std::pair<int, int>> cand;
        cand.reserve(available);
        for(int u = 0; u < n; u++) {
            for(int v = u + 1; v < n; v++) {
                if(!used.count(key(u, v))) cand.emplace_back(u, v);
            }
        }
        for(long long i = 0; i < k; i++) {
            const long long j = i + (long long)rng.uniform(cand.size() - i);
            std::swap(cand[i], cand[j]);
            edges.push_back(cand[i]);
        }
    }
    return edges;
}
} // namespace random_gen_internal

// n 頂点 m 辺の無向単純グラフを一様に選ぶ (多重辺・自己ループなし)
inline std::vector<std::pair<int, int>> random_simple_graph(Random &rng, int n,
                                                            long long m) {
    assert(n >= 0);
    assert(0 <= m && m <= (long long)n * (n - 1) / 2);
    return relabel_edges(rng, n,
                         random_gen_internal::sample_edges(rng, n, m, {}));
}

// n 頂点 m 辺の連結な無向単純グラフ
// 一様な木に、木に含まれない辺を一様に m - n + 1 本加える (連結グラフ全体の上で一様ではない)
inline std::vector<std::pair<int, int>>
random_connected_graph(Random &rng, int n, long long m) {
    assert(n >= 1);
    assert(n - 1 <= m && m <= (long long)n * (n - 1) / 2);
    std::vector<std::pair<int, int>> edges = random_tree(rng, n);
    const auto extra =
        random_gen_internal::sample_edges(rng, n, m - (n - 1), edges);
    edges.insert(edges.end(), extra.begin(), extra.end());
    return relabel_edges(rng, n, edges);
}

// n 頂点 m 辺の DAG (有向辺 (u, v) は u -> v)
// 一様な単純グラフの各辺を、ランダムな位相順序で前から後ろへ向ける
inline std::vector<std::pair<int, int>> random_dag(Random &rng, int n,
                                                   long long m) {
    std::vector<std::pair<int, int>> edges = random_simple_graph(rng, n, m);
    const std::vector<int> rank = random_permutation(rng, n);
    for(auto &[u, v] : edges) {
        if(rank[u] > rank[v]) std::swap(u, v);
    }
    return edges;
}

// 各辺に [l, r) の一様な重みを付ける
template <class T, class U>
std::vector<std::tuple<int, int, std::common_type_t<T, U, int>>>
add_random_weights(Random &rng, const std::vector<std::pair<int, int>> &edges,
                   T l, U r) {
    std::vector<std::tuple<int, int, std::common_type_t<T, U, int>>> res;
    res.reserve(edges.size());
    for(auto [u, v] : edges) res.emplace_back(u, v, rng.randint(l, r));
    return res;
}
