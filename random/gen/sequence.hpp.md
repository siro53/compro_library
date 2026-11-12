---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: random/gen/random.hpp
    title: "\u30C6\u30B9\u30C8\u751F\u6210\u7528\u306E\u4E71\u6570 (Random)"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: random/gen/all.hpp
    title: "\u751F\u6210\u5668\u30E9\u30A4\u30D6\u30E9\u30EA\u4E00\u5F0F"
  - icon: ':heavy_check_mark:'
    path: random/gen/graph.hpp
    title: "\u30E9\u30F3\u30C0\u30E0\u306A\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: random/gen/tree.hpp
    title: "\u30E9\u30F3\u30C0\u30E0\u306A\u6728"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/random/gen/all.test.cpp
    title: test/mytest/random/gen/all.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/random/gen/graph.test.cpp
    title: test/mytest/random/gen/graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/random/gen/sequence.test.cpp
    title: test/mytest/random/gen/sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/random/gen/tree.test.cpp
    title: test/mytest/random/gen/tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/gen/sequence.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cstdint>\n#include <numeric>\n#include <type_traits>\n\
    #include <unordered_set>\n#include <utility>\n#include <vector>\n\n#line 2 \"\
    random/gen/random.hpp\"\n\n#line 5 \"random/gen/random.hpp\"\n#include <cerrno>\n\
    #include <cmath>\n#line 8 \"random/gen/random.hpp\"\n#include <cstdlib>\n#include\
    \ <iostream>\n#include <random>\n#line 14 \"random/gen/random.hpp\"\n\n// seed\
    \ \u3092\u6307\u5B9A\u3067\u304D\u308B\u3001\u30E9\u30F3\u30C0\u30E0\u30C6\u30B9\
    \u30C8\u306E\u5165\u529B\u751F\u6210\u7528\u306E\u4E71\u6570\nclass Random {\n\
    \  public:\n    explicit Random(std::uint64_t seed = 0) : mt(seed) {}\n    //\
    \ argv[1] \u3092 seed \u3068\u3057\u3066\u8AAD\u3080\u3002\u5F15\u6570\u304C\u306A\
    \u3051\u308C\u3070 seed = 0\n    Random(int argc, char **argv) : mt(parse_seed(argc,\
    \ argv)) {}\n\n    // [0, n) \u306E\u4E00\u69D8\u306A\u6574\u6570 (n > 0)\n  \
    \  std::uint64_t uniform(std::uint64_t n) {\n        assert(n > 0);\n        //\
    \ 2^64 mod n \u500B\u306E\u5024\u3092\u68C4\u5374\u3057\u3066\u5270\u4F59\u306E\
    \u504F\u308A\u3092\u306A\u304F\u3059\n        const std::uint64_t threshold =\
    \ (0 - n) % n;\n        std::uint64_t x = mt();\n        while(x < threshold)\
    \ x = mt();\n        return x % n;\n    }\n\n    // [l, r) \u306E\u4E00\u69D8\u306A\
    \u6574\u6570\n    template <class T, class U>\n    std::common_type_t<T, U, int>\
    \ randint(T l, U r) {\n        using C = std::common_type_t<T, U, int>;\n    \
    \    static_assert(std::is_integral<C>::value, \"randint requires integers\");\n\
    \        const C lo = C(l), hi = C(r);\n        assert(lo < hi);\n        using\
    \ UC = std::make_unsigned_t<C>;\n        const std::uint64_t width = std::uint64_t(UC(hi)\
    \ - UC(lo));\n        return C(UC(lo) + UC(uniform(width)));\n    }\n    // [0,\
    \ r) \u306E\u4E00\u69D8\u306A\u6574\u6570\n    template <class T> std::common_type_t<T,\
    \ int> randint(T r) {\n        return randint(T(0), r);\n    }\n\n    // [l, r)\
    \ \u306B\u542B\u307E\u308C\u308B\u5076\u6570\u304B\u3089\u4E00\u69D8\u306B\u9078\
    \u3076 (\u5076\u6570\u304C 1 \u3064\u4EE5\u4E0A\u3042\u308B\u3053\u3068)\n   \
    \ template <class T, class U>\n    std::common_type_t<T, U, int> even(T l, U r)\
    \ {\n        return with_parity(l, r, 0);\n    }\n    // [0, r) \u306B\u542B\u307E\
    \u308C\u308B\u5076\u6570\u304B\u3089\u4E00\u69D8\u306B\u9078\u3076\n    template\
    \ <class T> std::common_type_t<T, int> even(T r) {\n        return even(T(0),\
    \ r);\n    }\n\n    // [l, r) \u306B\u542B\u307E\u308C\u308B\u5947\u6570\u304B\
    \u3089\u4E00\u69D8\u306B\u9078\u3076 (\u5947\u6570\u304C 1 \u3064\u4EE5\u4E0A\u3042\
    \u308B\u3053\u3068)\n    template <class T, class U>\n    std::common_type_t<T,\
    \ U, int> odd(T l, U r) {\n        return with_parity(l, r, 1);\n    }\n    //\
    \ [0, r) \u306B\u542B\u307E\u308C\u308B\u5947\u6570\u304B\u3089\u4E00\u69D8\u306B\
    \u9078\u3076\n    template <class T> std::common_type_t<T, int> odd(T r) {\n \
    \       return odd(T(0), r);\n    }\n\n    // [l, r) \u306E\u5B9F\u6570 (53 bit\
    \ \u306E\u5206\u89E3\u80FD)\n    double real(double l, double r) {\n        assert(l\
    \ < r);\n        const double u = double(mt() >> 11) / double(std::uint64_t(1)\
    \ << 53);\n        const double x = l + (r - l) * u;\n        return x < r ? x\
    \ : std::nextafter(r, l);\n    }\n    double real() { return real(0.0, 1.0); }\n\
    \n    // \u78BA\u7387 p \u3067 true\n    bool coin(double p = 0.5) { return real()\
    \ < p; }\n\n    // \u5C0F\u3055\u3044\u5024\u306B\u504F\u3089\u305B\u305F [l,\
    \ r) \u306E\u6574\u6570\n    // 2 \u51AA\u306E\u30B9\u30B1\u30FC\u30EB 1, 2, 4,\
    \ ... \u3092\u7B49\u78BA\u7387\u3067\u9078\u3073\u3001\u305D\u306E\u7BC4\u56F2\
    \u3067\u4E00\u69D8\u306B\u9078\u3076\n    template <class T, class U>\n    std::common_type_t<T,\
    \ U, int> size(T l, U r) {\n        using C = std::common_type_t<T, U, int>;\n\
    \        const C lo = C(l), hi = C(r);\n        assert(lo < hi);\n        using\
    \ UC = std::make_unsigned_t<C>;\n        const std::uint64_t width = std::uint64_t(UC(hi)\
    \ - UC(lo));\n        int scales = 0;\n        while(scales < 64 && (std::uint64_t(1)\
    \ << scales) < width) scales++;\n        const int k = int(uniform(std::uint64_t(scales\
    \ + 1)));\n        const std::uint64_t w = k >= 64 ? width : std::min(width, std::uint64_t(1)\
    \ << k);\n        return C(UC(lo) + UC(uniform(w)));\n    }\n\n    // v \u306E\
    \u8981\u7D20\u3092\u4E00\u69D8\u306B 1 \u3064\u9078\u3076 (v \u306F\u7A7A\u3067\
    \u306A\u3044)\n    template <class T> const T &choice(const std::vector<T> &v)\
    \ {\n        assert(!v.empty());\n        return v[uniform(v.size())];\n    }\n\
    \n    // Fisher-Yates \u3067 v \u3092\u4E00\u69D8\u306B\u30B7\u30E3\u30C3\u30D5\
    \u30EB\u3059\u308B\n    template <class T> void shuffle(std::vector<T> &v) {\n\
    \        for(std::size_t i = v.size(); i > 1; i--) {\n            std::swap(v[i\
    \ - 1], v[uniform(i)]);\n        }\n    }\n\n    // \u6A19\u6E96\u306E\u5206\u5E03\
    \u3068\u7D44\u307F\u5408\u308F\u305B\u308B\u5834\u5408\u306E\u30A8\u30F3\u30B8\
    \u30F3\n    std::mt19937_64 &engine() { return mt; }\n\n  private:\n    std::mt19937_64\
    \ mt;\n\n    // [l, r) \u306E\u3046\u3061 2 \u3067\u5272\u3063\u305F\u4F59\u308A\
    \u304C parity (\u8CA0\u306E\u6570\u3082\u542B\u3081\u3066\u6570\u5B66\u7684\u306A\
    \u5076\u5947) \u306E\u5024\u304B\u3089\u4E00\u69D8\u306B\u9078\u3076\n    template\
    \ <class T, class U>\n    std::common_type_t<T, U, int> with_parity(T l, U r,\
    \ unsigned parity) {\n        using C = std::common_type_t<T, U, int>;\n     \
    \   static_assert(std::is_integral<C>::value, \"even/odd requires integers\");\n\
    \        using UC = std::make_unsigned_t<C>;\n        const C lo = C(l), hi =\
    \ C(r);\n        assert(lo < hi);\n        const std::uint64_t width = std::uint64_t(UC(hi)\
    \ - UC(lo));\n        // 2 \u306E\u88DC\u6570\u8868\u73FE\u3067\u306F UC \u3078\
    \u306E\u5909\u63DB\u3067\u5076\u5947\u304C\u4FDD\u305F\u308C\u308B\n        const\
    \ std::uint64_t first = (std::uint64_t(UC(lo)) & 1) == parity ? 0 : 1;\n     \
    \   assert(first < width && \"no integer of the requested parity in [l, r)\");\n\
    \        // first, first + 2, ... < width \u306E\u500B\u6570 (width - first +\
    \ 1 \u306E\u3042\u3075\u308C\u3092\u907F\u3051\u308B)\n        const std::uint64_t\
    \ count = (width - first - 1) / 2 + 1;\n        return C(UC(lo) + UC(first + 2\
    \ * uniform(count)));\n    }\n\n    static std::uint64_t parse_seed(int argc,\
    \ char **argv) {\n        if(argc < 2) return 0;\n        const char *s = argv[1];\n\
    \        char *end = nullptr;\n        errno = 0;\n        const unsigned long\
    \ long seed = std::strtoull(s, &end, 10);\n        if(*s == '\\0' || *s == '-'\
    \ || *end != '\\0' || errno == ERANGE) {\n            std::cerr << \"Random: invalid\
    \ seed '\" << s << \"'\\n\";\n            std::exit(2);\n        }\n        return\
    \ seed;\n    }\n};\n#line 13 \"random/gen/sequence.hpp\"\n\n// \u5404\u8981\u7D20\
    \u304C [l, r) \u306E\u4E00\u69D8\u4E71\u6570\u3067\u3042\u308B\u9577\u3055 n \u306E\
    \u6570\u5217\ntemplate <class T, class U>\nstd::vector<std::common_type_t<T, U,\
    \ int>> random_vector(Random &rng, int n,\n                                  \
    \                       T l, U r) {\n    assert(n >= 0);\n    std::vector<std::common_type_t<T,\
    \ U, int>> v(n);\n    for(auto &x : v) x = rng.randint(l, r);\n    return v;\n\
    }\n\n// [l, r) \u304B\u3089\u76F8\u7570\u306A\u308B n \u500B\u3092\u4E00\u69D8\
    \u306B\u9078\u3073\u3001\u30E9\u30F3\u30C0\u30E0\u306A\u9806\u306B\u4E26\u3079\
    \u305F\u6570\u5217\n// (Floyd \u306E\u30B5\u30F3\u30D7\u30EA\u30F3\u30B0)\ntemplate\
    \ <class T, class U>\nstd::vector<std::common_type_t<T, U, int>>\nrandom_distinct_vector(Random\
    \ &rng, int n, T l, U r) {\n    using C = std::common_type_t<T, U, int>;\n   \
    \ using UC = std::make_unsigned_t<C>;\n    const C lo = C(l), hi = C(r);\n   \
    \ assert(n >= 0 && lo <= hi);\n    const std::uint64_t width = std::uint64_t(UC(hi)\
    \ - UC(lo));\n    assert(std::uint64_t(n) <= width);\n    std::unordered_set<std::uint64_t>\
    \ used;\n    used.reserve(std::size_t(n) * 2);\n    std::vector<C> v;\n    v.reserve(n);\n\
    \    for(std::uint64_t j = width - std::uint64_t(n); j < width; j++) {\n     \
    \   std::uint64_t t = rng.uniform(j + 1);\n        if(used.count(t)) t = j;\n\
    \        used.insert(t);\n        v.push_back(C(UC(lo) + UC(t)));\n    }\n   \
    \ rng.shuffle(v);\n    return v;\n}\n\n// (0, 1, ..., n-1) \u306E\u4E00\u69D8\u30E9\
    \u30F3\u30C0\u30E0\u306A\u9806\u5217\ninline std::vector<int> random_permutation(Random\
    \ &rng, int n) {\n    assert(n >= 0);\n    std::vector<int> p(n);\n    std::iota(p.begin(),\
    \ p.end(), 0);\n    rng.shuffle(p);\n    return p;\n}\n\n// {0, 1, ..., n-1} \u306E\
    \u5927\u304D\u3055 k \u306E\u90E8\u5206\u96C6\u5408\u3092\u4E00\u69D8\u306B\u9078\
    \u3073\u3001\u6607\u9806\u3067\u8FD4\u3059\ninline std::vector<int> random_subset(Random\
    \ &rng, int n, int k) {\n    assert(0 <= k && k <= n);\n    std::vector<int> s\
    \ = random_distinct_vector(rng, k, 0, n);\n    std::sort(s.begin(), s.end());\n\
    \    return s;\n}\n\n// l <= a < b <= r \u3092\u6E80\u305F\u3059\u534A\u958B\u533A\
    \u9593 [a, b) \u3092\u4E00\u69D8\u306B\u9078\u3076\ntemplate <class T, class U>\n\
    std::pair<std::common_type_t<T, U, int>, std::common_type_t<T, U, int>>\nrandom_interval(Random\
    \ &rng, T l, U r) {\n    using C = std::common_type_t<T, U, int>;\n    const C\
    \ lo = C(l), hi = C(r);\n    assert(lo < hi);\n    // {lo, ..., hi} \u304B\u3089\
    \u76F8\u7570\u306A\u308B 2 \u70B9\u3092\u9078\u3076\n    std::vector<C> e = random_distinct_vector(rng,\
    \ 2, lo, C(hi + 1));\n    if(e[0] > e[1]) std::swap(e[0], e[1]);\n    return {e[0],\
    \ e[1]};\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <cstdint>\n\
    #include <numeric>\n#include <type_traits>\n#include <unordered_set>\n#include\
    \ <utility>\n#include <vector>\n\n#include \"random.hpp\"\n\n// \u5404\u8981\u7D20\
    \u304C [l, r) \u306E\u4E00\u69D8\u4E71\u6570\u3067\u3042\u308B\u9577\u3055 n \u306E\
    \u6570\u5217\ntemplate <class T, class U>\nstd::vector<std::common_type_t<T, U,\
    \ int>> random_vector(Random &rng, int n,\n                                  \
    \                       T l, U r) {\n    assert(n >= 0);\n    std::vector<std::common_type_t<T,\
    \ U, int>> v(n);\n    for(auto &x : v) x = rng.randint(l, r);\n    return v;\n\
    }\n\n// [l, r) \u304B\u3089\u76F8\u7570\u306A\u308B n \u500B\u3092\u4E00\u69D8\
    \u306B\u9078\u3073\u3001\u30E9\u30F3\u30C0\u30E0\u306A\u9806\u306B\u4E26\u3079\
    \u305F\u6570\u5217\n// (Floyd \u306E\u30B5\u30F3\u30D7\u30EA\u30F3\u30B0)\ntemplate\
    \ <class T, class U>\nstd::vector<std::common_type_t<T, U, int>>\nrandom_distinct_vector(Random\
    \ &rng, int n, T l, U r) {\n    using C = std::common_type_t<T, U, int>;\n   \
    \ using UC = std::make_unsigned_t<C>;\n    const C lo = C(l), hi = C(r);\n   \
    \ assert(n >= 0 && lo <= hi);\n    const std::uint64_t width = std::uint64_t(UC(hi)\
    \ - UC(lo));\n    assert(std::uint64_t(n) <= width);\n    std::unordered_set<std::uint64_t>\
    \ used;\n    used.reserve(std::size_t(n) * 2);\n    std::vector<C> v;\n    v.reserve(n);\n\
    \    for(std::uint64_t j = width - std::uint64_t(n); j < width; j++) {\n     \
    \   std::uint64_t t = rng.uniform(j + 1);\n        if(used.count(t)) t = j;\n\
    \        used.insert(t);\n        v.push_back(C(UC(lo) + UC(t)));\n    }\n   \
    \ rng.shuffle(v);\n    return v;\n}\n\n// (0, 1, ..., n-1) \u306E\u4E00\u69D8\u30E9\
    \u30F3\u30C0\u30E0\u306A\u9806\u5217\ninline std::vector<int> random_permutation(Random\
    \ &rng, int n) {\n    assert(n >= 0);\n    std::vector<int> p(n);\n    std::iota(p.begin(),\
    \ p.end(), 0);\n    rng.shuffle(p);\n    return p;\n}\n\n// {0, 1, ..., n-1} \u306E\
    \u5927\u304D\u3055 k \u306E\u90E8\u5206\u96C6\u5408\u3092\u4E00\u69D8\u306B\u9078\
    \u3073\u3001\u6607\u9806\u3067\u8FD4\u3059\ninline std::vector<int> random_subset(Random\
    \ &rng, int n, int k) {\n    assert(0 <= k && k <= n);\n    std::vector<int> s\
    \ = random_distinct_vector(rng, k, 0, n);\n    std::sort(s.begin(), s.end());\n\
    \    return s;\n}\n\n// l <= a < b <= r \u3092\u6E80\u305F\u3059\u534A\u958B\u533A\
    \u9593 [a, b) \u3092\u4E00\u69D8\u306B\u9078\u3076\ntemplate <class T, class U>\n\
    std::pair<std::common_type_t<T, U, int>, std::common_type_t<T, U, int>>\nrandom_interval(Random\
    \ &rng, T l, U r) {\n    using C = std::common_type_t<T, U, int>;\n    const C\
    \ lo = C(l), hi = C(r);\n    assert(lo < hi);\n    // {lo, ..., hi} \u304B\u3089\
    \u76F8\u7570\u306A\u308B 2 \u70B9\u3092\u9078\u3076\n    std::vector<C> e = random_distinct_vector(rng,\
    \ 2, lo, C(hi + 1));\n    if(e[0] > e[1]) std::swap(e[0], e[1]);\n    return {e[0],\
    \ e[1]};\n}\n"
  dependsOn:
  - random/gen/random.hpp
  isVerificationFile: false
  path: random/gen/sequence.hpp
  requiredBy:
  - random/gen/tree.hpp
  - random/gen/graph.hpp
  - random/gen/all.hpp
  timestamp: '2026-11-13 01:10:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/random/gen/all.test.cpp
  - test/mytest/random/gen/graph.test.cpp
  - test/mytest/random/gen/tree.test.cpp
  - test/mytest/random/gen/sequence.test.cpp
documentation_of: random/gen/sequence.hpp
layout: document
title: "\u30E9\u30F3\u30C0\u30E0\u306A\u6570\u5217\u30FB\u9806\u5217\u30FB\u90E8\u5206\
  \u96C6\u5408\u30FB\u533A\u9593"
---

## このライブラリでできること

ランダムテストの入力でよく使う数列を、[`Random`](https://github.com/siro53/compro_library/blob/main/docs/random/gen/random.md) から生成する関数群です。

- `random_vector` は、各要素を独立に $[l,r)$ から選んだ数列を作ります。
- `random_distinct_vector` は、$[l,r)$ から相異なる $n$ 個を選び、ランダムな順に並べます。要素が相異なるという制約の問題に使えます。
- `random_permutation` は $(0,1,\dots,n-1)$ の順列を、`random_subset` は $\{0,1,\dots,n-1\}$ の $k$ 元部分集合を作ります。
- `random_interval` は、区間クエリの入力として $l \le a < b \le r$ を満たす半開区間 $[a,b)$ を作ります。

どの関数も、取り得る結果の上で一様分布になるように選びます。数列の範囲はすべて右端を含まない半開区間です。

## 使い方

第1引数に `Random` を渡し、続けて長さと値の範囲を渡します。例では、$1$ 以上 $9$ 以下の値からなる長さ $5$ の数列、$0$ 以上 $99$ 以下の相異なる $3$ 個、長さ $4$ の順列、区間を作っています。

```cpp
#include "template/template.cpp"
#include "random/gen/sequence.hpp"

int main(int argc, char **argv) {
    Random rng(argc, argv);
    vector<int> a = random_vector(rng, 5, 1, 10);
    for(int x : a) assert(1 <= x && x < 10);

    vector<int> d = random_distinct_vector(rng, 3, 0, 100);
    assert(set<int>(d.begin(), d.end()).size() == 3);

    vector<int> p = random_permutation(rng, 4);   // 0, 1, 2, 3 の並べ替え
    vector<int> s = random_subset(rng, 10, 3);    // 昇順の 3 要素
    assert(s.size() == 3 && is_sorted(s.begin(), s.end()));

    auto [l, r] = random_interval(rng, 0, 5);     // 0 <= l < r <= 5
    assert(0 <= l && l < r && r <= 5);

    // 1-indexed の順列と閉区間 [l+1, r] で出力する
    for(int &x : p) x++;
    print(p);
    print(l + 1, r);
}
```

順列は0始まりで返すので、1始まりで出力する場合は例のように $1$ を足します。`random_interval` の結果 $[l,r)$ は、閉区間 $[l+1,r]$ と書く1始まりの形式に変換できます。

## API・計算量

以下では、生成する長さを $n$ または $k$、値の範囲の幅を $w=r-l$ とします。各関数は結果の `vector` として $O(n)$ の領域を使い、`random_distinct_vector` は選んだ値を記録するハッシュ集合として追加で $O(n)$ を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `random_vector(rng, n, l, r)` | 各要素が独立に $[l,r)$ の一様乱数である長さ $n$ の `vector`。要素型は `l`, `r`, `int` の共通型。 | 期待 $O(n)$ |
| `random_distinct_vector(rng, n, l, r)` | $[l,r)$ の $n$ 元部分集合を一様に選び、一様ランダムな順に並べた `vector`。 | 期待 $O(n)$ |
| `random_permutation(rng, n)` | $(0,\dots,n-1)$ の一様ランダムな順列。 | 期待 $O(n)$ |
| `random_subset(rng, n, k)` | $\{0,\dots,n-1\}$ の $k$ 元部分集合を一様に選び、昇順で返す。 | 期待 $O(k \log k)$ |
| `random_interval(rng, l, r)` | $l \le a < b \le r$ を満たす $(a,b)$ を一様に選び、`pair` で返す。 | 期待 $O(1)$ |

`random_distinct_vector` は Floyd のサンプリングで値を選びます。$j=w-n,\dots,w-1$ の順に $t \in [0,j]$ を一様に引き、$t$ が選択済みなら代わりに $j$ を選びます。こうすると、$n$ 元部分集合のどれもが等確率で得られます。その後で全体をシャッフルするため、並び順も一様です。ハッシュ集合の操作は期待 $O(1)$ として計算量を示しています。

## 利用条件と実装上の注意

- `random_vector` は $n \ge 0$ かつ $l<r$ を要求します。$n=0$ なら空の `vector` を返します。
- `random_distinct_vector` は $0 \le n \le w$ を要求します。$n=w$ なら $[l,r)$ の全要素の並べ替えになります。$w$ が大きくても、計算量は $w$ に依存しません。
- `random_subset` は $0 \le k \le n$ を要求します。
- `random_interval` は $l<r$ を要求し、空でない区間だけを返します。幅 $w$ に対して $w(w+1)/2$ 通りの区間がそれぞれ等確率で出ます。内部で $r+1$ を計算するため、$r$ が型の最大値のときは使えません。
- 範囲や長さが条件を満たさない場合は `assert` で停止します。
