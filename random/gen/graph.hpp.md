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
  - icon: ':heavy_check_mark:'
    path: random/gen/tree.hpp
    title: "\u30E9\u30F3\u30C0\u30E0\u306A\u6728"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: random/gen/all.hpp
    title: "\u751F\u6210\u5668\u30E9\u30A4\u30D6\u30E9\u30EA\u4E00\u5F0F"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/random/gen/all.test.cpp
    title: test/mytest/random/gen/all.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/random/gen/graph.test.cpp
    title: test/mytest/random/gen/graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/gen/graph.hpp\"\n\n#include <cassert>\n#include <tuple>\n\
    #include <type_traits>\n#include <unordered_set>\n#include <utility>\n#include\
    \ <vector>\n\n#line 2 \"random/gen/random.hpp\"\n\n#include <algorithm>\n#line\
    \ 5 \"random/gen/random.hpp\"\n#include <cerrno>\n#include <cmath>\n#include <cstdint>\n\
    #include <cstdlib>\n#include <iostream>\n#include <random>\n#line 14 \"random/gen/random.hpp\"\
    \n\n// seed \u3092\u6307\u5B9A\u3067\u304D\u308B\u3001\u30E9\u30F3\u30C0\u30E0\
    \u30C6\u30B9\u30C8\u306E\u5165\u529B\u751F\u6210\u7528\u306E\u4E71\u6570\nclass\
    \ Random {\n  public:\n    explicit Random(std::uint64_t seed = 0) : mt(seed)\
    \ {}\n    // argv[1] \u3092 seed \u3068\u3057\u3066\u8AAD\u3080\u3002\u5F15\u6570\
    \u304C\u306A\u3051\u308C\u3070 seed = 0\n    Random(int argc, char **argv) : mt(parse_seed(argc,\
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
    \ seed;\n    }\n};\n#line 2 \"random/gen/sequence.hpp\"\n\n#line 6 \"random/gen/sequence.hpp\"\
    \n#include <numeric>\n#line 11 \"random/gen/sequence.hpp\"\n\n#line 13 \"random/gen/sequence.hpp\"\
    \n\n// \u5404\u8981\u7D20\u304C [l, r) \u306E\u4E00\u69D8\u4E71\u6570\u3067\u3042\
    \u308B\u9577\u3055 n \u306E\u6570\u5217\ntemplate <class T, class U>\nstd::vector<std::common_type_t<T,\
    \ U, int>> random_vector(Random &rng, int n,\n                               \
    \                          T l, U r) {\n    assert(n >= 0);\n    std::vector<std::common_type_t<T,\
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
    \ e[1]};\n}\n#line 2 \"random/gen/tree.hpp\"\n\n#line 6 \"random/gen/tree.hpp\"\
    \n\n#line 9 \"random/gen/tree.hpp\"\n\n// \u9802\u70B9\u756A\u53F7\u3092\u4E00\
    \u69D8\u30E9\u30F3\u30C0\u30E0\u306B\u4ED8\u3051\u66FF\u3048\u3001\u5404\u8FBA\
    \u306E\u5411\u304D\u3068\u8FBA\u306E\u9806\u5E8F\u3092\u30B7\u30E3\u30C3\u30D5\
    \u30EB\u3059\u308B\ninline std::vector<std::pair<int, int>>\nrelabel_edges(Random\
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
    \ 1; i < n; i++) par[i] = rng.randint(0, i);\n    return par;\n}\n#line 13 \"\
    random/gen/graph.hpp\"\n\nnamespace random_gen_internal {\n// n \u9802\u70B9\u306E\
    \u7121\u5411\u5358\u7D14\u30B0\u30E9\u30D5\u306E\u8FBA\u306E\u3046\u3061 forbidden\
    \ \u306B\u542B\u307E\u308C\u306A\u3044\u3082\u306E\u304B\u3089 k \u672C\u3092\u4E00\
    \u69D8\u306B\u9078\u3076\n// forbidden \u306F\u76F8\u7570\u306A\u308B\u5358\u7D14\
    \u8FBA\u306E\u5217\u3068\u3059\u308B\ninline std::vector<std::pair<int, int>>\n\
    sample_edges(Random &rng, int n, long long k,\n             const std::vector<std::pair<int,\
    \ int>> &forbidden) {\n    const long long total = (long long)n * (n - 1) / 2;\n\
    \    const long long available = total - (long long)forbidden.size();\n    assert(0\
    \ <= k && k <= available);\n    auto key = [n](int u, int v) {\n        if(u >\
    \ v) std::swap(u, v);\n        return (long long)u * n + v;\n    };\n    std::unordered_set<long\
    \ long> used;\n    for(auto [u, v] : forbidden) used.insert(key(u, v));\n    std::vector<std::pair<int,\
    \ int>> edges;\n    edges.reserve(k);\n    if(2 * k <= available) {\n        //\
    \ \u758E: \u672A\u4F7F\u7528\u306E\u8FBA\u3092\u5F15\u304F\u307E\u3067\u68C4\u5374\
    \u3059\u308B (\u6B8B\u308A\u306E\u5019\u88DC\u306F\u5168\u4F53\u306E 1/2 * available/total\
    \ \u4EE5\u4E0A)\n        while((long long)edges.size() < k) {\n            const\
    \ int u = rng.randint(0, n);\n            int v = rng.randint(0, n - 1);\n   \
    \         if(v >= u) v++;\n            if(used.insert(key(u, v)).second) edges.emplace_back(u,\
    \ v);\n        }\n    } else {\n        // \u5BC6: \u5019\u88DC\u3092\u5217\u6319\
    \u3057\u3066\u90E8\u5206\u7684\u306B Fisher-Yates \u3092\u884C\u3046 (total <\
    \ 2k + |forbidden|)\n        std::vector<std::pair<int, int>> cand;\n        cand.reserve(available);\n\
    \        for(int u = 0; u < n; u++) {\n            for(int v = u + 1; v < n; v++)\
    \ {\n                if(!used.count(key(u, v))) cand.emplace_back(u, v);\n   \
    \         }\n        }\n        for(long long i = 0; i < k; i++) {\n         \
    \   const long long j = i + (long long)rng.uniform(cand.size() - i);\n       \
    \     std::swap(cand[i], cand[j]);\n            edges.push_back(cand[i]);\n  \
    \      }\n    }\n    return edges;\n}\n} // namespace random_gen_internal\n\n\
    // n \u9802\u70B9 m \u8FBA\u306E\u7121\u5411\u5358\u7D14\u30B0\u30E9\u30D5\u3092\
    \u4E00\u69D8\u306B\u9078\u3076 (\u591A\u91CD\u8FBA\u30FB\u81EA\u5DF1\u30EB\u30FC\
    \u30D7\u306A\u3057)\ninline std::vector<std::pair<int, int>> random_simple_graph(Random\
    \ &rng, int n,\n                                                            long\
    \ long m) {\n    assert(n >= 0);\n    assert(0 <= m && m <= (long long)n * (n\
    \ - 1) / 2);\n    return relabel_edges(rng, n,\n                         random_gen_internal::sample_edges(rng,\
    \ n, m, {}));\n}\n\n// n \u9802\u70B9 m \u8FBA\u306E\u9023\u7D50\u306A\u7121\u5411\
    \u5358\u7D14\u30B0\u30E9\u30D5\n// \u4E00\u69D8\u306A\u6728\u306B\u3001\u6728\u306B\
    \u542B\u307E\u308C\u306A\u3044\u8FBA\u3092\u4E00\u69D8\u306B m - n + 1 \u672C\u52A0\
    \u3048\u308B (\u9023\u7D50\u30B0\u30E9\u30D5\u5168\u4F53\u306E\u4E0A\u3067\u4E00\
    \u69D8\u3067\u306F\u306A\u3044)\ninline std::vector<std::pair<int, int>>\nrandom_connected_graph(Random\
    \ &rng, int n, long long m) {\n    assert(n >= 1);\n    assert(n - 1 <= m && m\
    \ <= (long long)n * (n - 1) / 2);\n    std::vector<std::pair<int, int>> edges\
    \ = random_tree(rng, n);\n    const auto extra =\n        random_gen_internal::sample_edges(rng,\
    \ n, m - (n - 1), edges);\n    edges.insert(edges.end(), extra.begin(), extra.end());\n\
    \    return relabel_edges(rng, n, edges);\n}\n\n// n \u9802\u70B9 m \u8FBA\u306E\
    \ DAG (\u6709\u5411\u8FBA (u, v) \u306F u -> v)\n// \u4E00\u69D8\u306A\u5358\u7D14\
    \u30B0\u30E9\u30D5\u306E\u5404\u8FBA\u3092\u3001\u30E9\u30F3\u30C0\u30E0\u306A\
    \u4F4D\u76F8\u9806\u5E8F\u3067\u524D\u304B\u3089\u5F8C\u308D\u3078\u5411\u3051\
    \u308B\ninline std::vector<std::pair<int, int>> random_dag(Random &rng, int n,\n\
    \                                                   long long m) {\n    std::vector<std::pair<int,\
    \ int>> edges = random_simple_graph(rng, n, m);\n    const std::vector<int> rank\
    \ = random_permutation(rng, n);\n    for(auto &[u, v] : edges) {\n        if(rank[u]\
    \ > rank[v]) std::swap(u, v);\n    }\n    return edges;\n}\n\n// \u5404\u8FBA\u306B\
    \ [l, r) \u306E\u4E00\u69D8\u306A\u91CD\u307F\u3092\u4ED8\u3051\u308B\ntemplate\
    \ <class T, class U>\nstd::vector<std::tuple<int, int, std::common_type_t<T, U,\
    \ int>>>\nadd_random_weights(Random &rng, const std::vector<std::pair<int, int>>\
    \ &edges,\n                   T l, U r) {\n    std::vector<std::tuple<int, int,\
    \ std::common_type_t<T, U, int>>> res;\n    res.reserve(edges.size());\n    for(auto\
    \ [u, v] : edges) res.emplace_back(u, v, rng.randint(l, r));\n    return res;\n\
    }\n"
  code: "#pragma once\n\n#include <cassert>\n#include <tuple>\n#include <type_traits>\n\
    #include <unordered_set>\n#include <utility>\n#include <vector>\n\n#include \"\
    random.hpp\"\n#include \"sequence.hpp\"\n#include \"tree.hpp\"\n\nnamespace random_gen_internal\
    \ {\n// n \u9802\u70B9\u306E\u7121\u5411\u5358\u7D14\u30B0\u30E9\u30D5\u306E\u8FBA\
    \u306E\u3046\u3061 forbidden \u306B\u542B\u307E\u308C\u306A\u3044\u3082\u306E\u304B\
    \u3089 k \u672C\u3092\u4E00\u69D8\u306B\u9078\u3076\n// forbidden \u306F\u76F8\
    \u7570\u306A\u308B\u5358\u7D14\u8FBA\u306E\u5217\u3068\u3059\u308B\ninline std::vector<std::pair<int,\
    \ int>>\nsample_edges(Random &rng, int n, long long k,\n             const std::vector<std::pair<int,\
    \ int>> &forbidden) {\n    const long long total = (long long)n * (n - 1) / 2;\n\
    \    const long long available = total - (long long)forbidden.size();\n    assert(0\
    \ <= k && k <= available);\n    auto key = [n](int u, int v) {\n        if(u >\
    \ v) std::swap(u, v);\n        return (long long)u * n + v;\n    };\n    std::unordered_set<long\
    \ long> used;\n    for(auto [u, v] : forbidden) used.insert(key(u, v));\n    std::vector<std::pair<int,\
    \ int>> edges;\n    edges.reserve(k);\n    if(2 * k <= available) {\n        //\
    \ \u758E: \u672A\u4F7F\u7528\u306E\u8FBA\u3092\u5F15\u304F\u307E\u3067\u68C4\u5374\
    \u3059\u308B (\u6B8B\u308A\u306E\u5019\u88DC\u306F\u5168\u4F53\u306E 1/2 * available/total\
    \ \u4EE5\u4E0A)\n        while((long long)edges.size() < k) {\n            const\
    \ int u = rng.randint(0, n);\n            int v = rng.randint(0, n - 1);\n   \
    \         if(v >= u) v++;\n            if(used.insert(key(u, v)).second) edges.emplace_back(u,\
    \ v);\n        }\n    } else {\n        // \u5BC6: \u5019\u88DC\u3092\u5217\u6319\
    \u3057\u3066\u90E8\u5206\u7684\u306B Fisher-Yates \u3092\u884C\u3046 (total <\
    \ 2k + |forbidden|)\n        std::vector<std::pair<int, int>> cand;\n        cand.reserve(available);\n\
    \        for(int u = 0; u < n; u++) {\n            for(int v = u + 1; v < n; v++)\
    \ {\n                if(!used.count(key(u, v))) cand.emplace_back(u, v);\n   \
    \         }\n        }\n        for(long long i = 0; i < k; i++) {\n         \
    \   const long long j = i + (long long)rng.uniform(cand.size() - i);\n       \
    \     std::swap(cand[i], cand[j]);\n            edges.push_back(cand[i]);\n  \
    \      }\n    }\n    return edges;\n}\n} // namespace random_gen_internal\n\n\
    // n \u9802\u70B9 m \u8FBA\u306E\u7121\u5411\u5358\u7D14\u30B0\u30E9\u30D5\u3092\
    \u4E00\u69D8\u306B\u9078\u3076 (\u591A\u91CD\u8FBA\u30FB\u81EA\u5DF1\u30EB\u30FC\
    \u30D7\u306A\u3057)\ninline std::vector<std::pair<int, int>> random_simple_graph(Random\
    \ &rng, int n,\n                                                            long\
    \ long m) {\n    assert(n >= 0);\n    assert(0 <= m && m <= (long long)n * (n\
    \ - 1) / 2);\n    return relabel_edges(rng, n,\n                         random_gen_internal::sample_edges(rng,\
    \ n, m, {}));\n}\n\n// n \u9802\u70B9 m \u8FBA\u306E\u9023\u7D50\u306A\u7121\u5411\
    \u5358\u7D14\u30B0\u30E9\u30D5\n// \u4E00\u69D8\u306A\u6728\u306B\u3001\u6728\u306B\
    \u542B\u307E\u308C\u306A\u3044\u8FBA\u3092\u4E00\u69D8\u306B m - n + 1 \u672C\u52A0\
    \u3048\u308B (\u9023\u7D50\u30B0\u30E9\u30D5\u5168\u4F53\u306E\u4E0A\u3067\u4E00\
    \u69D8\u3067\u306F\u306A\u3044)\ninline std::vector<std::pair<int, int>>\nrandom_connected_graph(Random\
    \ &rng, int n, long long m) {\n    assert(n >= 1);\n    assert(n - 1 <= m && m\
    \ <= (long long)n * (n - 1) / 2);\n    std::vector<std::pair<int, int>> edges\
    \ = random_tree(rng, n);\n    const auto extra =\n        random_gen_internal::sample_edges(rng,\
    \ n, m - (n - 1), edges);\n    edges.insert(edges.end(), extra.begin(), extra.end());\n\
    \    return relabel_edges(rng, n, edges);\n}\n\n// n \u9802\u70B9 m \u8FBA\u306E\
    \ DAG (\u6709\u5411\u8FBA (u, v) \u306F u -> v)\n// \u4E00\u69D8\u306A\u5358\u7D14\
    \u30B0\u30E9\u30D5\u306E\u5404\u8FBA\u3092\u3001\u30E9\u30F3\u30C0\u30E0\u306A\
    \u4F4D\u76F8\u9806\u5E8F\u3067\u524D\u304B\u3089\u5F8C\u308D\u3078\u5411\u3051\
    \u308B\ninline std::vector<std::pair<int, int>> random_dag(Random &rng, int n,\n\
    \                                                   long long m) {\n    std::vector<std::pair<int,\
    \ int>> edges = random_simple_graph(rng, n, m);\n    const std::vector<int> rank\
    \ = random_permutation(rng, n);\n    for(auto &[u, v] : edges) {\n        if(rank[u]\
    \ > rank[v]) std::swap(u, v);\n    }\n    return edges;\n}\n\n// \u5404\u8FBA\u306B\
    \ [l, r) \u306E\u4E00\u69D8\u306A\u91CD\u307F\u3092\u4ED8\u3051\u308B\ntemplate\
    \ <class T, class U>\nstd::vector<std::tuple<int, int, std::common_type_t<T, U,\
    \ int>>>\nadd_random_weights(Random &rng, const std::vector<std::pair<int, int>>\
    \ &edges,\n                   T l, U r) {\n    std::vector<std::tuple<int, int,\
    \ std::common_type_t<T, U, int>>> res;\n    res.reserve(edges.size());\n    for(auto\
    \ [u, v] : edges) res.emplace_back(u, v, rng.randint(l, r));\n    return res;\n\
    }\n"
  dependsOn:
  - random/gen/random.hpp
  - random/gen/sequence.hpp
  - random/gen/tree.hpp
  isVerificationFile: false
  path: random/gen/graph.hpp
  requiredBy:
  - random/gen/all.hpp
  timestamp: '2026-11-13 01:10:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/random/gen/all.test.cpp
  - test/mytest/random/gen/graph.test.cpp
documentation_of: random/gen/graph.hpp
layout: document
title: "\u30E9\u30F3\u30C0\u30E0\u306A\u30B0\u30E9\u30D5"
---

## このライブラリでできること

[`Random`](https://github.com/siro53/compro_library/blob/main/docs/random/gen/random.md) を使って、ランダムテスト用のグラフを生成します。どの関数も多重辺と自己ループを含まない単純グラフを返します。

- `random_simple_graph` は、$n$ 頂点 $m$ 辺の無向単純グラフ $\binom{N}{m}$ 通り（$N=n(n-1)/2$）から1つを一様に選びます。
- `random_connected_graph` は、連結な $n$ 頂点 $m$ 辺の無向単純グラフを作ります。
- `random_dag` は、$n$ 頂点 $m$ 辺の有向非巡回グラフ (DAG) を作ります。
- `add_random_weights` は、辺に一様ランダムな重みを付けます。

辺は0始まりの頂点番号の `pair` で返ります。[木の生成](https://github.com/siro53/compro_library/blob/main/docs/random/gen/tree.md) と同じく、最後に頂点番号の付け替えと、辺の向き・順序のシャッフルを行います。

## 使い方

例では、連結な重み付き無向グラフを1始まりで出力し、続けて DAG が位相順序を持つことを確かめています。$m$ の上限は単純グラフの辺数 $n(n-1)/2$ です。

```cpp
#include "template/template.cpp"
#include "random/gen/graph.hpp"

int main(int argc, char **argv) {
    Random rng(argc, argv);
    int n = rng.size(2, 9);
    long long max_m = (long long)n * (n - 1) / 2;
    long long m = rng.randint(n - 1, max_m + 1);     // n-1 <= m <= max_m
    auto edges = add_random_weights(rng, random_connected_graph(rng, n, m), 1, 10);
    print(n, m);
    for(auto [u, v, w] : edges) print(u + 1, v + 1, w);

    auto dag = random_dag(rng, 5, 4);
    vector<int> indeg(5);
    for(auto [u, v] : dag) indeg[v]++;
    assert(count(indeg.begin(), indeg.end(), 0) >= 1);  // 入次数 0 の頂点がある
}
```

## API・計算量

頂点数を $n$、辺数を $m$、単純グラフの最大辺数を $N=n(n-1)/2$ とします。返り値の辺列に $O(m)$、頂点の置換に $O(n)$、使用済みの辺を記録するハッシュ集合に $O(m)$ の領域を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `random_simple_graph(rng, n, m)` | $n$ 頂点 $m$ 辺の無向単純グラフを一様に選んだ辺列。 | 期待 $O(n+m)$ |
| `random_connected_graph(rng, n, m)` | $n$ 頂点 $m$ 辺の連結な無向単純グラフの辺列。分布は後述。 | 期待 $O(n+m)$ |
| `random_dag(rng, n, m)` | $n$ 頂点 $m$ 辺の DAG。有向辺 $(u,v)$ は $u \to v$ を表す。 | 期待 $O(n+m)$ |
| `add_random_weights(rng, edges, l, r)` | 各辺 $(u,v)$ に $[l,r)$ の一様な重み $w$ を付けた `tuple(u, v, w)` の列。重みの型は `l`, `r`, `int` の共通型。 | 期待 $O(m)$ |

辺の選び方は、選ぶ本数 $k$ と候補の本数 $A$ の大小で切り替えます。$2k \le A$ なら、ランダムな頂点対を引き、未使用ならば採用することを繰り返します。各回で採用される確率は $1/2 \cdot A/N$ 以上です。そうでなければ候補をすべて列挙し、先頭 $k$ 本だけ Fisher-Yates を行います。このとき $N < 2k + (\text{除外する辺の本数})$ なので、列挙の手間も $O(n+m)$ です。

## 利用条件と実装上の注意

- `random_simple_graph` と `random_dag` は $n \ge 0$ かつ $0 \le m \le N$ を要求します。
- `random_connected_graph` は $n \ge 1$ かつ $n-1 \le m \le N$ を要求します。一様な木を作り、木に含まれない辺から $m-n+1$ 本を一様に加えます。連結グラフ全体の上での一様分布ではありません。
- `random_dag` は、一様な無向単純グラフの各辺を、一様ランダムな頂点の順序で前から後ろへ向けます。DAG 全体の上での一様分布ではありません。
- 頂点数 $n$ に対して $N$ を `long long` で計算します。
- 条件を満たさない場合は `assert` で停止します。
