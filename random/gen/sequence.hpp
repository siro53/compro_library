#pragma once

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <numeric>
#include <type_traits>
#include <unordered_set>
#include <utility>
#include <vector>

#include "random.hpp"

// 各要素が [l, r) の一様乱数である長さ n の数列
template <class T, class U>
std::vector<std::common_type_t<T, U, int>> random_vector(Random &rng, int n,
                                                         T l, U r) {
    assert(n >= 0);
    std::vector<std::common_type_t<T, U, int>> v(n);
    for(auto &x : v) x = rng.randint(l, r);
    return v;
}

// [l, r) から相異なる n 個を一様に選び、ランダムな順に並べた数列
// (Floyd のサンプリング)
template <class T, class U>
std::vector<std::common_type_t<T, U, int>>
random_distinct_vector(Random &rng, int n, T l, U r) {
    using C = std::common_type_t<T, U, int>;
    using UC = std::make_unsigned_t<C>;
    const C lo = C(l), hi = C(r);
    assert(n >= 0 && lo <= hi);
    const std::uint64_t width = std::uint64_t(UC(hi) - UC(lo));
    assert(std::uint64_t(n) <= width);
    std::unordered_set<std::uint64_t> used;
    used.reserve(std::size_t(n) * 2);
    std::vector<C> v;
    v.reserve(n);
    for(std::uint64_t j = width - std::uint64_t(n); j < width; j++) {
        std::uint64_t t = rng.uniform(j + 1);
        if(used.count(t)) t = j;
        used.insert(t);
        v.push_back(C(UC(lo) + UC(t)));
    }
    rng.shuffle(v);
    return v;
}

// (0, 1, ..., n-1) の一様ランダムな順列
inline std::vector<int> random_permutation(Random &rng, int n) {
    assert(n >= 0);
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    rng.shuffle(p);
    return p;
}

// {0, 1, ..., n-1} の大きさ k の部分集合を一様に選び、昇順で返す
inline std::vector<int> random_subset(Random &rng, int n, int k) {
    assert(0 <= k && k <= n);
    std::vector<int> s = random_distinct_vector(rng, k, 0, n);
    std::sort(s.begin(), s.end());
    return s;
}

// l <= a < b <= r を満たす半開区間 [a, b) を一様に選ぶ
template <class T, class U>
std::pair<std::common_type_t<T, U, int>, std::common_type_t<T, U, int>>
random_interval(Random &rng, T l, U r) {
    using C = std::common_type_t<T, U, int>;
    const C lo = C(l), hi = C(r);
    assert(lo < hi);
    // {lo, ..., hi} から相異なる 2 点を選ぶ
    std::vector<C> e = random_distinct_vector(rng, 2, lo, C(hi + 1));
    if(e[0] > e[1]) std::swap(e[0], e[1]);
    return {e[0], e[1]};
}
