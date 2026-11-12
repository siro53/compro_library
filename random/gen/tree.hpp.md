---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: random/gen/random.hpp
    title: "\u30C6\u30B9\u30C8\u751F\u6210\u7528\u306E\u4E71\u6570 (Random)"
  - icon: ':heavy_check_mark:'
    path: random/gen/sequence.hpp
    title: "\u30E9\u30F3\u30C0\u30E0\u306A\u6570\u5217\u30FB\u9806\u5217\u30FB\u90E8\
      \u5206\u96C6\u5408\u30FB\u533A\u9593"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: random/gen/all.hpp
    title: "\u751F\u6210\u5668\u30E9\u30A4\u30D6\u30E9\u30EA\u4E00\u5F0F"
  - icon: ':heavy_check_mark:'
    path: random/gen/graph.hpp
    title: "\u30E9\u30F3\u30C0\u30E0\u306A\u30B0\u30E9\u30D5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/random/gen/all.test.cpp
    title: test/mytest/random/gen/all.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/random/gen/graph.test.cpp
    title: test/mytest/random/gen/graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/random/gen/tree.test.cpp
    title: test/mytest/random/gen/tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/gen/tree.hpp\"\n\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\n#line 2 \"random/gen/random.hpp\"\n\n#include <algorithm>\n\
    #line 5 \"random/gen/random.hpp\"\n#include <cerrno>\n#include <cmath>\n#include\
    \ <cstdint>\n#include <cstdlib>\n#include <iostream>\n#include <random>\n#include\
    \ <type_traits>\n#line 14 \"random/gen/random.hpp\"\n\n// seed \u3092\u6307\u5B9A\
    \u3067\u304D\u308B\u3001\u30E9\u30F3\u30C0\u30E0\u30C6\u30B9\u30C8\u306E\u5165\
    \u529B\u751F\u6210\u7528\u306E\u4E71\u6570\nclass Random {\n  public:\n    explicit\
    \ Random(std::uint64_t seed = 0) : mt(seed) {}\n    // argv[1] \u3092 seed \u3068\
    \u3057\u3066\u8AAD\u3080\u3002\u5F15\u6570\u304C\u306A\u3051\u308C\u3070 seed\
    \ = 0\n    Random(int argc, char **argv) : mt(parse_seed(argc, argv)) {}\n\n \
    \   // [0, n) \u306E\u4E00\u69D8\u306A\u6574\u6570 (n > 0)\n    std::uint64_t\
    \ uniform(std::uint64_t n) {\n        assert(n > 0);\n        // 2^64 mod n \u500B\
    \u306E\u5024\u3092\u68C4\u5374\u3057\u3066\u5270\u4F59\u306E\u504F\u308A\u3092\
    \u306A\u304F\u3059\n        const std::uint64_t threshold = (0 - n) % n;\n   \
    \     std::uint64_t x = mt();\n        while(x < threshold) x = mt();\n      \
    \  return x % n;\n    }\n\n    // [l, r) \u306E\u4E00\u69D8\u306A\u6574\u6570\n\
    \    template <class T, class U>\n    std::common_type_t<T, U, int> randint(T\
    \ l, U r) {\n        using C = std::common_type_t<T, U, int>;\n        static_assert(std::is_integral<C>::value,\
    \ \"randint requires integers\");\n        const C lo = C(l), hi = C(r);\n   \
    \     assert(lo < hi);\n        using UC = std::make_unsigned_t<C>;\n        const\
    \ std::uint64_t width = std::uint64_t(UC(hi) - UC(lo));\n        return C(UC(lo)\
    \ + UC(uniform(width)));\n    }\n    // [0, r) \u306E\u4E00\u69D8\u306A\u6574\u6570\
    \n    template <class T> std::common_type_t<T, int> randint(T r) {\n        return\
    \ randint(T(0), r);\n    }\n\n    // [l, r) \u306B\u542B\u307E\u308C\u308B\u5076\
    \u6570\u304B\u3089\u4E00\u69D8\u306B\u9078\u3076 (\u5076\u6570\u304C 1 \u3064\u4EE5\
    \u4E0A\u3042\u308B\u3053\u3068)\n    template <class T, class U>\n    std::common_type_t<T,\
    \ U, int> even(T l, U r) {\n        return with_parity(l, r, 0);\n    }\n    //\
    \ [0, r) \u306B\u542B\u307E\u308C\u308B\u5076\u6570\u304B\u3089\u4E00\u69D8\u306B\
    \u9078\u3076\n    template <class T> std::common_type_t<T, int> even(T r) {\n\
    \        return even(T(0), r);\n    }\n\n    // [l, r) \u306B\u542B\u307E\u308C\
    \u308B\u5947\u6570\u304B\u3089\u4E00\u69D8\u306B\u9078\u3076 (\u5947\u6570\u304C\
    \ 1 \u3064\u4EE5\u4E0A\u3042\u308B\u3053\u3068)\n    template <class T, class\
    \ U>\n    std::common_type_t<T, U, int> odd(T l, U r) {\n        return with_parity(l,\
    \ r, 1);\n    }\n    // [0, r) \u306B\u542B\u307E\u308C\u308B\u5947\u6570\u304B\
    \u3089\u4E00\u69D8\u306B\u9078\u3076\n    template <class T> std::common_type_t<T,\
    \ int> odd(T r) {\n        return odd(T(0), r);\n    }\n\n    // [l, r) \u306E\
    \u5B9F\u6570 (53 bit \u306E\u5206\u89E3\u80FD)\n    double real(double l, double\
    \ r) {\n        assert(l < r);\n        const double u = double(mt() >> 11) /\
    \ double(std::uint64_t(1) << 53);\n        const double x = l + (r - l) * u;\n\
    \        return x < r ? x : std::nextafter(r, l);\n    }\n    double real() {\
    \ return real(0.0, 1.0); }\n\n    // \u78BA\u7387 p \u3067 true\n    bool coin(double\
    \ p = 0.5) { return real() < p; }\n\n    // \u5C0F\u3055\u3044\u5024\u306B\u504F\
    \u3089\u305B\u305F [l, r) \u306E\u6574\u6570\n    // 2 \u51AA\u306E\u30B9\u30B1\
    \u30FC\u30EB 1, 2, 4, ... \u3092\u7B49\u78BA\u7387\u3067\u9078\u3073\u3001\u305D\
    \u306E\u7BC4\u56F2\u3067\u4E00\u69D8\u306B\u9078\u3076\n    template <class T,\
    \ class U>\n    std::common_type_t<T, U, int> size(T l, U r) {\n        using\
    \ C = std::common_type_t<T, U, int>;\n        const C lo = C(l), hi = C(r);\n\
    \        assert(lo < hi);\n        using UC = std::make_unsigned_t<C>;\n     \
    \   const std::uint64_t width = std::uint64_t(UC(hi) - UC(lo));\n        int scales\
    \ = 0;\n        while(scales < 64 && (std::uint64_t(1) << scales) < width) scales++;\n\
    \        const int k = int(uniform(std::uint64_t(scales + 1)));\n        const\
    \ std::uint64_t w = k >= 64 ? width : std::min(width, std::uint64_t(1) << k);\n\
    \        return C(UC(lo) + UC(uniform(w)));\n    }\n\n    // v \u306E\u8981\u7D20\
    \u3092\u4E00\u69D8\u306B 1 \u3064\u9078\u3076 (v \u306F\u7A7A\u3067\u306A\u3044\
    )\n    template <class T> const T &choice(const std::vector<T> &v) {\n       \
    \ assert(!v.empty());\n        return v[uniform(v.size())];\n    }\n\n    // Fisher-Yates\
    \ \u3067 v \u3092\u4E00\u69D8\u306B\u30B7\u30E3\u30C3\u30D5\u30EB\u3059\u308B\n\
    \    template <class T> void shuffle(std::vector<T> &v) {\n        for(std::size_t\
    \ i = v.size(); i > 1; i--) {\n            std::swap(v[i - 1], v[uniform(i)]);\n\
    \        }\n    }\n\n    // \u6A19\u6E96\u306E\u5206\u5E03\u3068\u7D44\u307F\u5408\
    \u308F\u305B\u308B\u5834\u5408\u306E\u30A8\u30F3\u30B8\u30F3\n    std::mt19937_64\
    \ &engine() { return mt; }\n\n  private:\n    std::mt19937_64 mt;\n\n    // [l,\
    \ r) \u306E\u3046\u3061 2 \u3067\u5272\u3063\u305F\u4F59\u308A\u304C parity (\u8CA0\
    \u306E\u6570\u3082\u542B\u3081\u3066\u6570\u5B66\u7684\u306A\u5076\u5947) \u306E\
    \u5024\u304B\u3089\u4E00\u69D8\u306B\u9078\u3076\n    template <class T, class\
    \ U>\n    std::common_type_t<T, U, int> with_parity(T l, U r, unsigned parity)\
    \ {\n        using C = std::common_type_t<T, U, int>;\n        static_assert(std::is_integral<C>::value,\
    \ \"even/odd requires integers\");\n        using UC = std::make_unsigned_t<C>;\n\
    \        const C lo = C(l), hi = C(r);\n        assert(lo < hi);\n        const\
    \ std::uint64_t width = std::uint64_t(UC(hi) - UC(lo));\n        // 2 \u306E\u88DC\
    \u6570\u8868\u73FE\u3067\u306F UC \u3078\u306E\u5909\u63DB\u3067\u5076\u5947\u304C\
    \u4FDD\u305F\u308C\u308B\n        const std::uint64_t first = (std::uint64_t(UC(lo))\
    \ & 1) == parity ? 0 : 1;\n        assert(first < width && \"no integer of the\
    \ requested parity in [l, r)\");\n        // first, first + 2, ... < width \u306E\
    \u500B\u6570 (width - first + 1 \u306E\u3042\u3075\u308C\u3092\u907F\u3051\u308B\
    )\n        const std::uint64_t count = (width - first - 1) / 2 + 1;\n        return\
    \ C(UC(lo) + UC(first + 2 * uniform(count)));\n    }\n\n    static std::uint64_t\
    \ parse_seed(int argc, char **argv) {\n        if(argc < 2) return 0;\n      \
    \  const char *s = argv[1];\n        char *end = nullptr;\n        errno = 0;\n\
    \        const unsigned long long seed = std::strtoull(s, &end, 10);\n       \
    \ if(*s == '\\0' || *s == '-' || *end != '\\0' || errno == ERANGE) {\n       \
    \     std::cerr << \"Random: invalid seed '\" << s << \"'\\n\";\n            std::exit(2);\n\
    \        }\n        return seed;\n    }\n};\n#line 2 \"random/gen/sequence.hpp\"\
    \n\n#line 6 \"random/gen/sequence.hpp\"\n#include <numeric>\n#line 8 \"random/gen/sequence.hpp\"\
    \n#include <unordered_set>\n#line 11 \"random/gen/sequence.hpp\"\n\n#line 13 \"\
    random/gen/sequence.hpp\"\n\n// \u5404\u8981\u7D20\u304C [l, r) \u306E\u4E00\u69D8\
    \u4E71\u6570\u3067\u3042\u308B\u9577\u3055 n \u306E\u6570\u5217\ntemplate <class\
    \ T, class U>\nstd::vector<std::common_type_t<T, U, int>> random_vector(Random\
    \ &rng, int n,\n                                                         T l,\
    \ U r) {\n    assert(n >= 0);\n    std::vector<std::common_type_t<T, U, int>>\
    \ v(n);\n    for(auto &x : v) x = rng.randint(l, r);\n    return v;\n}\n\n// [l,\
    \ r) \u304B\u3089\u76F8\u7570\u306A\u308B n \u500B\u3092\u4E00\u69D8\u306B\u9078\
    \u3073\u3001\u30E9\u30F3\u30C0\u30E0\u306A\u9806\u306B\u4E26\u3079\u305F\u6570\
    \u5217\n// (Floyd \u306E\u30B5\u30F3\u30D7\u30EA\u30F3\u30B0)\ntemplate <class\
    \ T, class U>\nstd::vector<std::common_type_t<T, U, int>>\nrandom_distinct_vector(Random\
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
    \ e[1]};\n}\n#line 9 \"random/gen/tree.hpp\"\n\n// \u9802\u70B9\u756A\u53F7\u3092\
    \u4E00\u69D8\u30E9\u30F3\u30C0\u30E0\u306B\u4ED8\u3051\u66FF\u3048\u3001\u5404\
    \u8FBA\u306E\u5411\u304D\u3068\u8FBA\u306E\u9806\u5E8F\u3092\u30B7\u30E3\u30C3\
    \u30D5\u30EB\u3059\u308B\ninline std::vector<std::pair<int, int>>\nrelabel_edges(Random\
    \ &rng, int n, std::vector<std::pair<int, int>> edges) {\n    const std::vector<int>\
    \ p = random_permutation(rng, n);\n    for(auto &[u, v] : edges) {\n        assert(0\
    \ <= u && u < n && 0 <= v && v < n);\n        u = p[u], v = p[v];\n        if(rng.coin())\
    \ std::swap(u, v);\n    }\n    rng.shuffle(edges);\n    return edges;\n}\n\n//\
    \ n \u9802\u70B9\u306E\u30E9\u30D9\u30EB\u4ED8\u304D\u6728\u3092\u4E00\u69D8\u306B\
    \u9078\u3076 (Pr\xFCfer \u5217\u306E\u5FA9\u5143)\ninline std::vector<std::pair<int,\
    \ int>> random_tree(Random &rng, int n) {\n    assert(n >= 1);\n    std::vector<std::pair<int,\
    \ int>> edges;\n    if(n == 1) return edges;\n    edges.reserve(n - 1);\n    std::vector<int>\
    \ code(n - 2), degree(n, 1);\n    for(auto &x : code) x = int(rng.uniform(n)),\
    \ degree[x]++;\n    int ptr = 0;\n    while(degree[ptr] != 1) ptr++;\n    int\
    \ leaf = ptr;\n    for(int v : code) {\n        edges.emplace_back(leaf, v);\n\
    \        if(--degree[v] == 1 && v < ptr) {\n            leaf = v;\n        } else\
    \ {\n            ptr++;\n            while(degree[ptr] != 1) ptr++;\n        \
    \    leaf = ptr;\n        }\n    }\n    edges.emplace_back(leaf, n - 1);\n   \
    \ return relabel_edges(rng, n, edges);\n}\n\n// n \u9802\u70B9\u306E\u30D1\u30B9\
    \u30B0\u30E9\u30D5 (\u9802\u70B9\u306E\u4E26\u3073\u306F\u4E00\u69D8\u30E9\u30F3\
    \u30C0\u30E0)\ninline std::vector<std::pair<int, int>> random_path_tree(Random\
    \ &rng, int n) {\n    assert(n >= 1);\n    std::vector<std::pair<int, int>> edges;\n\
    \    for(int i = 0; i + 1 < n; i++) edges.emplace_back(i, i + 1);\n    return\
    \ relabel_edges(rng, n, edges);\n}\n\n// n \u9802\u70B9\u306E\u30B9\u30BF\u30FC\
    \u30B0\u30E9\u30D5 (\u4E2D\u5FC3\u306F\u4E00\u69D8\u30E9\u30F3\u30C0\u30E0)\n\
    inline std::vector<std::pair<int, int>> random_star_tree(Random &rng, int n) {\n\
    \    assert(n >= 1);\n    std::vector<std::pair<int, int>> edges;\n    for(int\
    \ i = 1; i < n; i++) edges.emplace_back(0, i);\n    return relabel_edges(rng,\
    \ n, edges);\n}\n\n// \u9802\u70B9 0 \u3092\u6839\u3068\u3059\u308B\u89AA\u914D\
    \u5217\u3002par[0] = -1\u3001i >= 1 \u3067\u306F par[i] \u306F [0, i) \u306E\u4E00\
    \u69D8\u4E71\u6570\ninline std::vector<int> random_parent_array(Random &rng, int\
    \ n) {\n    assert(n >= 1);\n    std::vector<int> par(n, -1);\n    for(int i =\
    \ 1; i < n; i++) par[i] = rng.randint(0, i);\n    return par;\n}\n"
  code: "#pragma once\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \n#include \"random.hpp\"\n#include \"sequence.hpp\"\n\n// \u9802\u70B9\u756A\u53F7\
    \u3092\u4E00\u69D8\u30E9\u30F3\u30C0\u30E0\u306B\u4ED8\u3051\u66FF\u3048\u3001\
    \u5404\u8FBA\u306E\u5411\u304D\u3068\u8FBA\u306E\u9806\u5E8F\u3092\u30B7\u30E3\
    \u30C3\u30D5\u30EB\u3059\u308B\ninline std::vector<std::pair<int, int>>\nrelabel_edges(Random\
    \ &rng, int n, std::vector<std::pair<int, int>> edges) {\n    const std::vector<int>\
    \ p = random_permutation(rng, n);\n    for(auto &[u, v] : edges) {\n        assert(0\
    \ <= u && u < n && 0 <= v && v < n);\n        u = p[u], v = p[v];\n        if(rng.coin())\
    \ std::swap(u, v);\n    }\n    rng.shuffle(edges);\n    return edges;\n}\n\n//\
    \ n \u9802\u70B9\u306E\u30E9\u30D9\u30EB\u4ED8\u304D\u6728\u3092\u4E00\u69D8\u306B\
    \u9078\u3076 (Pr\xFCfer \u5217\u306E\u5FA9\u5143)\ninline std::vector<std::pair<int,\
    \ int>> random_tree(Random &rng, int n) {\n    assert(n >= 1);\n    std::vector<std::pair<int,\
    \ int>> edges;\n    if(n == 1) return edges;\n    edges.reserve(n - 1);\n    std::vector<int>\
    \ code(n - 2), degree(n, 1);\n    for(auto &x : code) x = int(rng.uniform(n)),\
    \ degree[x]++;\n    int ptr = 0;\n    while(degree[ptr] != 1) ptr++;\n    int\
    \ leaf = ptr;\n    for(int v : code) {\n        edges.emplace_back(leaf, v);\n\
    \        if(--degree[v] == 1 && v < ptr) {\n            leaf = v;\n        } else\
    \ {\n            ptr++;\n            while(degree[ptr] != 1) ptr++;\n        \
    \    leaf = ptr;\n        }\n    }\n    edges.emplace_back(leaf, n - 1);\n   \
    \ return relabel_edges(rng, n, edges);\n}\n\n// n \u9802\u70B9\u306E\u30D1\u30B9\
    \u30B0\u30E9\u30D5 (\u9802\u70B9\u306E\u4E26\u3073\u306F\u4E00\u69D8\u30E9\u30F3\
    \u30C0\u30E0)\ninline std::vector<std::pair<int, int>> random_path_tree(Random\
    \ &rng, int n) {\n    assert(n >= 1);\n    std::vector<std::pair<int, int>> edges;\n\
    \    for(int i = 0; i + 1 < n; i++) edges.emplace_back(i, i + 1);\n    return\
    \ relabel_edges(rng, n, edges);\n}\n\n// n \u9802\u70B9\u306E\u30B9\u30BF\u30FC\
    \u30B0\u30E9\u30D5 (\u4E2D\u5FC3\u306F\u4E00\u69D8\u30E9\u30F3\u30C0\u30E0)\n\
    inline std::vector<std::pair<int, int>> random_star_tree(Random &rng, int n) {\n\
    \    assert(n >= 1);\n    std::vector<std::pair<int, int>> edges;\n    for(int\
    \ i = 1; i < n; i++) edges.emplace_back(0, i);\n    return relabel_edges(rng,\
    \ n, edges);\n}\n\n// \u9802\u70B9 0 \u3092\u6839\u3068\u3059\u308B\u89AA\u914D\
    \u5217\u3002par[0] = -1\u3001i >= 1 \u3067\u306F par[i] \u306F [0, i) \u306E\u4E00\
    \u69D8\u4E71\u6570\ninline std::vector<int> random_parent_array(Random &rng, int\
    \ n) {\n    assert(n >= 1);\n    std::vector<int> par(n, -1);\n    for(int i =\
    \ 1; i < n; i++) par[i] = rng.randint(0, i);\n    return par;\n}\n"
  dependsOn:
  - random/gen/random.hpp
  - random/gen/sequence.hpp
  isVerificationFile: false
  path: random/gen/tree.hpp
  requiredBy:
  - random/gen/graph.hpp
  - random/gen/all.hpp
  timestamp: '2026-11-13 01:10:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/random/gen/all.test.cpp
  - test/mytest/random/gen/graph.test.cpp
  - test/mytest/random/gen/tree.test.cpp
documentation_of: random/gen/tree.hpp
layout: document
title: "\u30E9\u30F3\u30C0\u30E0\u306A\u6728"
---

## このライブラリでできること

[`Random`](https://github.com/siro53/compro_library/blob/main/docs/random/gen/random.md) を使って、ランダムテスト用の木を生成します。

- `random_tree` は、頂点 $0,\dots,n-1$ 上のラベル付き木 $n^{n-2}$ 通りから1つを一様に選びます。
- `random_path_tree` と `random_star_tree` は、それぞれパスグラフとスターグラフを作ります。直径が最大・最小になる極端な形で、再帰の深さや次数の偏りを試すのに使います。
- `random_parent_array` は、「頂点 $i$ の親 $p_i$ は $p_i<i$ を満たす」という形式の入力を作ります。
- `relabel_edges` は、与えた辺集合の頂点番号を一様ランダムに付け替え、辺の向きと順序をシャッフルします。

辺の列を返す関数は、すべて最後に `relabel_edges` を通します。生成アルゴリズムの癖として「辺 $(u,v)$ が常に $u<v$」「辺が親から子の順に並ぶ」といった規則性が残ると、解答がそれに依存していてもバグが見つかりません。それを防ぐための処理です。

## 使い方

辺は0始まりの頂点番号の `pair` で返ります。1始まりの入力形式なら、出力時に $1$ を足します。例では、木の辺を1行ずつ出力し、続けて親配列を $p_2,\dots,p_n$ の形式で出力します。

```cpp
#include "template/template.cpp"
#include "random/gen/tree.hpp"

int main(int argc, char **argv) {
    Random rng(argc, argv);
    int n = rng.size(2, 9);
    vector<pair<int, int>> edges = random_tree(rng, n);
    assert((int)edges.size() == n - 1);
    print(n);
    for(auto [u, v] : edges) print(u + 1, v + 1);

    vector<int> par = random_parent_array(rng, n);
    assert(par[0] == -1);
    vector<int> p;
    for(int i = 1; i < n; i++) p.push_back(par[i] + 1);  // p_i < i (1-indexed)
    print(p);
}
```

`random_parent_array` は頂点 $0$ を根とし、`par[0]` に $-1$ を入れます。

## API・計算量

頂点数を $n$、`relabel_edges` に渡す辺の本数を $m$ とします。返り値の領域は $O(n)$ または $O(m)$ で、`relabel_edges` は頂点の置換のために追加で $O(n)$ を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `random_tree(rng, n)` | 一様ランダムなラベル付き木の辺 $n-1$ 本。 | 期待 $O(n)$ |
| `random_path_tree(rng, n)` | パスグラフの辺 $n-1$ 本。頂点の並びは一様ランダム。 | 期待 $O(n)$ |
| `random_star_tree(rng, n)` | スターグラフの辺 $n-1$ 本。中心は一様ランダム。 | 期待 $O(n)$ |
| `random_parent_array(rng, n)` | 長さ $n$ の `vector<int>`。`par[0] = -1`、$i \ge 1$ では `par[i]` は $[0,i)$ の一様乱数。 | 期待 $O(n)$ |
| `relabel_edges(rng, n, edges)` | 一様ランダムな頂点の置換 $\sigma$ で各辺 $(u,v)$ を $(\sigma(u),\sigma(v))$ に写し、確率 $1/2$ で向きを反転し、辺の順序をシャッフルした辺列。 | 期待 $O(n+m)$ |

`random_tree` は、各項が $[0,n)$ の一様乱数である長さ $n-2$ の Prüfer 列を作り、線形時間で木に復元します。Prüfer 列とラベル付き木は一対一に対応するので、得られる木は一様分布に従います。

## 利用条件と実装上の注意

- すべての木生成関数は $n \ge 1$ を要求します。$n=1$ なら辺は空です。
- `relabel_edges` の各端点は $[0,n)$ に含まれる必要があります。辺集合が木でなくても使えます。
- `random_parent_array` が作る木はランダム再帰木で、深さの期待値は $O(\log n)$ です。この形式で深い木を試したい場合は、`random_path_tree` などとは別に、`par[i] = i - 1` に近い値を混ぜる生成を自分で書いてください。
- `random_tree` が作る一様な木の直径は、期待値で $\Theta(\sqrt{n})$ 程度です。直径の大きい木や次数の大きい頂点は出にくいので、パスやスターも併用すると極端なケースを試せます。
- 条件を満たさない場合は `assert` で停止します。
