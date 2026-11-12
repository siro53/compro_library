---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: random/gen/graph.hpp
    title: "\u30E9\u30F3\u30C0\u30E0\u306A\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: random/gen/random.hpp
    title: "\u30C6\u30B9\u30C8\u751F\u6210\u7528\u306E\u4E71\u6570 (Random)"
  - icon: ':heavy_check_mark:'
    path: random/gen/sequence.hpp
    title: "\u30E9\u30F3\u30C0\u30E0\u306A\u6570\u5217\u30FB\u9806\u5217\u30FB\u90E8\
      \u5206\u96C6\u5408\u30FB\u533A\u9593"
  - icon: ':heavy_check_mark:'
    path: random/gen/string.hpp
    title: "\u30E9\u30F3\u30C0\u30E0\u306A\u6587\u5B57\u5217"
  - icon: ':heavy_check_mark:'
    path: random/gen/tree.hpp
    title: "\u30E9\u30F3\u30C0\u30E0\u306A\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/random/gen/all.test.cpp
    title: test/mytest/random/gen/all.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/gen/all.hpp\"\n\n#line 2 \"random/gen/random.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <cerrno>\n#include <cmath>\n\
    #include <cstdint>\n#include <cstdlib>\n#include <iostream>\n#include <random>\n\
    #include <type_traits>\n#include <utility>\n#include <vector>\n\n// seed \u3092\
    \u6307\u5B9A\u3067\u304D\u308B\u3001\u30E9\u30F3\u30C0\u30E0\u30C6\u30B9\u30C8\
    \u306E\u5165\u529B\u751F\u6210\u7528\u306E\u4E71\u6570\nclass Random {\n  public:\n\
    \    explicit Random(std::uint64_t seed = 0) : mt(seed) {}\n    // argv[1] \u3092\
    \ seed \u3068\u3057\u3066\u8AAD\u3080\u3002\u5F15\u6570\u304C\u306A\u3051\u308C\
    \u3070 seed = 0\n    Random(int argc, char **argv) : mt(parse_seed(argc, argv))\
    \ {}\n\n    // [0, n) \u306E\u4E00\u69D8\u306A\u6574\u6570 (n > 0)\n    std::uint64_t\
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
    \ e[1]};\n}\n#line 2 \"random/gen/string.hpp\"\n\n#line 4 \"random/gen/string.hpp\"\
    \n#include <string>\n\n#line 7 \"random/gen/string.hpp\"\n\n// \u5404\u6587\u5B57\
    \u3092 alphabet \u304B\u3089\u4E00\u69D8\u306B\u9078\u3093\u3060\u9577\u3055 n\
    \ \u306E\u6587\u5B57\u5217\ninline std::string random_string(Random &rng, int\
    \ n,\n                                 const std::string &alphabet) {\n    assert(n\
    \ >= 0);\n    assert(n == 0 || !alphabet.empty());\n    std::string s(n, '\\0');\n\
    \    for(auto &c : s) c = alphabet[rng.uniform(alphabet.size())];\n    return\
    \ s;\n}\n\n// \u82F1\u5C0F\u6587\u5B57\u306E\u5148\u982D k \u7A2E\u985E ('a' \u304B\
    \u3089 k \u6587\u5B57) \u304B\u3089\u306A\u308B\u9577\u3055 n \u306E\u6587\u5B57\
    \u5217\ninline std::string random_lowercase(Random &rng, int n, int k = 26) {\n\
    \    assert(1 <= k && k <= 26);\n    std::string alphabet(k, 'a');\n    for(int\
    \ i = 0; i < k; i++) alphabet[i] = char('a' + i);\n    return random_string(rng,\
    \ n, alphabet);\n}\n#line 2 \"random/gen/tree.hpp\"\n\n#line 6 \"random/gen/tree.hpp\"\
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
    \ 1; i < n; i++) par[i] = rng.randint(0, i);\n    return par;\n}\n#line 2 \"random/gen/graph.hpp\"\
    \n\n#line 4 \"random/gen/graph.hpp\"\n#include <tuple>\n#line 9 \"random/gen/graph.hpp\"\
    \n\n#line 13 \"random/gen/graph.hpp\"\n\nnamespace random_gen_internal {\n// n\
    \ \u9802\u70B9\u306E\u7121\u5411\u5358\u7D14\u30B0\u30E9\u30D5\u306E\u8FBA\u306E\
    \u3046\u3061 forbidden \u306B\u542B\u307E\u308C\u306A\u3044\u3082\u306E\u304B\u3089\
    \ k \u672C\u3092\u4E00\u69D8\u306B\u9078\u3076\n// forbidden \u306F\u76F8\u7570\
    \u306A\u308B\u5358\u7D14\u8FBA\u306E\u5217\u3068\u3059\u308B\ninline std::vector<std::pair<int,\
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
    }\n#line 8 \"random/gen/all.hpp\"\n"
  code: '#pragma once


    #include "random.hpp"

    #include "sequence.hpp"

    #include "string.hpp"

    #include "tree.hpp"

    #include "graph.hpp"

    '
  dependsOn:
  - random/gen/random.hpp
  - random/gen/sequence.hpp
  - random/gen/string.hpp
  - random/gen/tree.hpp
  - random/gen/graph.hpp
  isVerificationFile: false
  path: random/gen/all.hpp
  requiredBy: []
  timestamp: '2026-11-13 01:10:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/random/gen/all.test.cpp
documentation_of: random/gen/all.hpp
layout: document
title: "\u751F\u6210\u5668\u30E9\u30A4\u30D6\u30E9\u30EA\u4E00\u5F0F"
---

## このライブラリでできること

ランダムテストの入力生成器 (generator) で使うヘッダを、まとめて読み込むための集約ヘッダです。コンテスト中は、このヘッダだけを include すれば次の機能をすべて使えます。

| ヘッダ | 主な機能 |
| --- | --- |
| [`random.hpp`](https://github.com/siro53/compro_library/blob/main/docs/random/gen/random.md) | seed 付きの乱数クラス `Random`。整数・偶数・奇数・実数・確率判定・選択・シャッフル |
| [`sequence.hpp`](https://github.com/siro53/compro_library/blob/main/docs/random/gen/sequence.md) | 数列、相異なる値の数列、順列、部分集合、区間 |
| [`string.hpp`](https://github.com/siro53/compro_library/blob/main/docs/random/gen/string.md) | 文字集合を指定した文字列、英小文字の文字列 |
| [`tree.hpp`](https://github.com/siro53/compro_library/blob/main/docs/random/gen/tree.md) | 一様な木、パス、スター、親配列、頂点番号の付け替え |
| [`graph.hpp`](https://github.com/siro53/compro_library/blob/main/docs/random/gen/graph.md) | 単純グラフ、連結グラフ、DAG、辺の重み |

生成器は提出しないので、`oj-bundle` で展開する必要はありません。[`scripts/randtest.py`](https://github.com/siro53/compro_library/blob/main/scripts/randtest.py) はライブラリのルートを include パスに加えてコンパイルします。このため、生成器にはそのまま `#include "random/gen/all.hpp"` と書けます。

## 使い方

生成器は `gen <seed>` として呼ばれ、1つの入力を標準出力に書く約束です。例は「$n$ 頂点の木と、各頂点の値」を入力に持つ問題の生成器です。`randtest --init` で作られる雛形も同じ形をしています。

```cpp
#include "template/template.cpp"
#include "random/gen/all.hpp"

int main(int argc, char **argv) {
    Random rng(argc, argv);                  // argv[1] が seed
    int n = rng.size(1, 9);                  // 1 <= n <= 8
    vector<int> a = random_vector(rng, n, 1, 11);  // 1 <= a_i <= 10
    print(n);
    print(a);
    for(auto [u, v] : random_tree(rng, n)) print(u + 1, v + 1);
}
```

この生成器を `gen.cpp`、提出する解を `main.cpp`、愚直解を `naive.cpp` として保存し、次のように実行します。

```sh
randtest main.cpp naive.cpp gen.cpp
```

`main` と `naive` の出力が食い違うか、どちらかが実行時エラーや時間切れになると、そのときの入力と seed が `randtest_fail/` に保存されます。`randtest main.cpp naive.cpp gen.cpp --replay <seed>` で同じ入力を再現できます。ツールの詳しい使い方は README の「ランダムテスト」の節を参照してください。

## API・計算量

このヘッダ自体は関数や型を定義しません。各機能の計算量と領域は、上の表のリンク先のページを参照してください。読み込むのは標準ライブラリのヘッダと上記5つのヘッダだけで、静的な領域は確保しません。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `#include "random/gen/all.hpp"` | `random.hpp`, `sequence.hpp`, `string.hpp`, `tree.hpp`, `graph.hpp` を読み込む。 | 実行時の処理なし |

## 利用条件と実装上の注意

- 区間はすべて右端を含まない半開区間 $[l,r)$ で、頂点番号と添字は0始まりです。1始まりの入力形式では出力時に $1$ を足してください。
- 同じ seed で同じ入力を得るには、乱数を使う関数を同じ順序で呼ぶ必要があります。生成器を書き換えた後は、以前の seed で同じ入力になるとは限りません。
- ランダムテストでは、小さな入力を大量に試すと手で追える反例が得やすくなります。制約の上限ではなく、`rng.size` などで小さめの値を使うのがおすすめです。
