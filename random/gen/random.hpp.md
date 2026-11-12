---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: random/gen/all.hpp
    title: "\u751F\u6210\u5668\u30E9\u30A4\u30D6\u30E9\u30EA\u4E00\u5F0F"
  - icon: ':heavy_check_mark:'
    path: random/gen/graph.hpp
    title: "\u30E9\u30F3\u30C0\u30E0\u306A\u30B0\u30E9\u30D5"
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/random/gen/all.test.cpp
    title: test/mytest/random/gen/all.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/random/gen/graph.test.cpp
    title: test/mytest/random/gen/graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/random/gen/random.test.cpp
    title: test/mytest/random/gen/random.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/random/gen/sequence.test.cpp
    title: test/mytest/random/gen/sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/random/gen/string.test.cpp
    title: test/mytest/random/gen/string.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/random/gen/tree.test.cpp
    title: test/mytest/random/gen/tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/gen/random.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cerrno>\n#include <cmath>\n#include <cstdint>\n#include\
    \ <cstdlib>\n#include <iostream>\n#include <random>\n#include <type_traits>\n\
    #include <utility>\n#include <vector>\n\n// seed \u3092\u6307\u5B9A\u3067\u304D\
    \u308B\u3001\u30E9\u30F3\u30C0\u30E0\u30C6\u30B9\u30C8\u306E\u5165\u529B\u751F\
    \u6210\u7528\u306E\u4E71\u6570\nclass Random {\n  public:\n    explicit Random(std::uint64_t\
    \ seed = 0) : mt(seed) {}\n    // argv[1] \u3092 seed \u3068\u3057\u3066\u8AAD\
    \u3080\u3002\u5F15\u6570\u304C\u306A\u3051\u308C\u3070 seed = 0\n    Random(int\
    \ argc, char **argv) : mt(parse_seed(argc, argv)) {}\n\n    // [0, n) \u306E\u4E00\
    \u69D8\u306A\u6574\u6570 (n > 0)\n    std::uint64_t uniform(std::uint64_t n) {\n\
    \        assert(n > 0);\n        // 2^64 mod n \u500B\u306E\u5024\u3092\u68C4\u5374\
    \u3057\u3066\u5270\u4F59\u306E\u504F\u308A\u3092\u306A\u304F\u3059\n        const\
    \ std::uint64_t threshold = (0 - n) % n;\n        std::uint64_t x = mt();\n  \
    \      while(x < threshold) x = mt();\n        return x % n;\n    }\n\n    //\
    \ [l, r) \u306E\u4E00\u69D8\u306A\u6574\u6570\n    template <class T, class U>\n\
    \    std::common_type_t<T, U, int> randint(T l, U r) {\n        using C = std::common_type_t<T,\
    \ U, int>;\n        static_assert(std::is_integral<C>::value, \"randint requires\
    \ integers\");\n        const C lo = C(l), hi = C(r);\n        assert(lo < hi);\n\
    \        using UC = std::make_unsigned_t<C>;\n        const std::uint64_t width\
    \ = std::uint64_t(UC(hi) - UC(lo));\n        return C(UC(lo) + UC(uniform(width)));\n\
    \    }\n    // [0, r) \u306E\u4E00\u69D8\u306A\u6574\u6570\n    template <class\
    \ T> std::common_type_t<T, int> randint(T r) {\n        return randint(T(0), r);\n\
    \    }\n\n    // [l, r) \u306B\u542B\u307E\u308C\u308B\u5076\u6570\u304B\u3089\
    \u4E00\u69D8\u306B\u9078\u3076 (\u5076\u6570\u304C 1 \u3064\u4EE5\u4E0A\u3042\u308B\
    \u3053\u3068)\n    template <class T, class U>\n    std::common_type_t<T, U, int>\
    \ even(T l, U r) {\n        return with_parity(l, r, 0);\n    }\n    // [0, r)\
    \ \u306B\u542B\u307E\u308C\u308B\u5076\u6570\u304B\u3089\u4E00\u69D8\u306B\u9078\
    \u3076\n    template <class T> std::common_type_t<T, int> even(T r) {\n      \
    \  return even(T(0), r);\n    }\n\n    // [l, r) \u306B\u542B\u307E\u308C\u308B\
    \u5947\u6570\u304B\u3089\u4E00\u69D8\u306B\u9078\u3076 (\u5947\u6570\u304C 1 \u3064\
    \u4EE5\u4E0A\u3042\u308B\u3053\u3068)\n    template <class T, class U>\n    std::common_type_t<T,\
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
    \ seed;\n    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <cerrno>\n\
    #include <cmath>\n#include <cstdint>\n#include <cstdlib>\n#include <iostream>\n\
    #include <random>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    \n// seed \u3092\u6307\u5B9A\u3067\u304D\u308B\u3001\u30E9\u30F3\u30C0\u30E0\u30C6\
    \u30B9\u30C8\u306E\u5165\u529B\u751F\u6210\u7528\u306E\u4E71\u6570\nclass Random\
    \ {\n  public:\n    explicit Random(std::uint64_t seed = 0) : mt(seed) {}\n  \
    \  // argv[1] \u3092 seed \u3068\u3057\u3066\u8AAD\u3080\u3002\u5F15\u6570\u304C\
    \u306A\u3051\u308C\u3070 seed = 0\n    Random(int argc, char **argv) : mt(parse_seed(argc,\
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
    \ seed;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: random/gen/random.hpp
  requiredBy:
  - random/gen/tree.hpp
  - random/gen/graph.hpp
  - random/gen/all.hpp
  - random/gen/sequence.hpp
  - random/gen/string.hpp
  timestamp: '2026-11-13 01:10:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/random/gen/all.test.cpp
  - test/mytest/random/gen/random.test.cpp
  - test/mytest/random/gen/graph.test.cpp
  - test/mytest/random/gen/tree.test.cpp
  - test/mytest/random/gen/string.test.cpp
  - test/mytest/random/gen/sequence.test.cpp
documentation_of: random/gen/random.hpp
layout: document
title: "\u30C6\u30B9\u30C8\u751F\u6210\u7528\u306E\u4E71\u6570 (Random)"
---

## このライブラリでできること

`Random` は、ランダムテストの入力生成器 (generator) のための乱数クラスです。seed を指定でき、同じ seed からは常に同じ乱数列が得られます。そのため、ランダムテストで見つけた反例を seed だけから再現できます。

コンストラクタ `Random(argc, argv)` はコマンドライン引数の `argv[1]` を seed として読みます。[`scripts/randtest.py`](https://github.com/siro53/compro_library/blob/main/scripts/randtest.py) が生成器を `gen <seed>` の形で呼ぶので、この規約に合わせて書くだけで反例の保存と再現ができます。

整数乱数の区間は、既存の [`random/rng.hpp`](https://github.com/siro53/compro_library/blob/main/docs/random/rng.md) と同じく右端を含まない半開区間 $[l,r)$ です。`randint(1, 7)` は $1$ 以上 $6$ 以下の整数を返します。偶数だけ・奇数だけが欲しい場合は、`even(l, r)` と `odd(l, r)` が $[l,r)$ に含まれる偶数・奇数から一様に選びます。

`rng.hpp` との違いは次のとおりです。

- 生成器は標準化された `std::mt19937_64` で、`std::uniform_int_distribution` を使わずに一様化しています。このため同じ seed なら、コンパイラや標準ライブラリの実装が違っても同じ値が出ます。
- 返り値の型は引数の型から決まります。`int` 同士なら `int`、`long long` を含めば `long long` です。

木やグラフなどの生成関数は、このクラスを引数に取る別ヘッダにまとめています。一覧は [生成器ライブラリ一式](https://github.com/siro53/compro_library/blob/main/docs/random/gen/all.md) を参照してください。

## 使い方

生成器では `main` の引数を `Random` に渡し、問題の制約を半開区間で書き写して乱数を引きます。`size` は小さい値ほど出やすい長さを返すので、反例が見つかったときに手で追える小さな入力が得やすくなります。

```cpp
#include "template/template.cpp"
#include "random/gen/random.hpp"

int main(int argc, char **argv) {
    Random rng(argc, argv);           // ./gen 42 なら seed = 42
    int n = rng.size(1, 9);           // 1 以上 8 以下。小さい値に偏る
    assert(1 <= n && n <= 8);
    long long x = rng.randint(0, 1000000000000LL);  // long long になる
    assert(0 <= x && x < 1000000000000LL);
    int e = rng.even(1, 11);          // 2, 4, 6, 8, 10 のいずれか
    int o = rng.odd(-3, 4);           // -3, -1, 1, 3 のいずれか
    assert(e % 2 == 0 && 2 <= e && e <= 10);
    assert(o % 2 != 0 && -3 <= o && o <= 3);
    vector<int> p{1, 2, 3};
    rng.shuffle(p);
    int c = rng.choice(p);
    assert(1 <= c && c <= 3);

    // 同じ seed なら同じ列になる
    Random a(7), b(7);
    for(int i = 0; i < 5; i++) assert(a.randint(100) == b.randint(100));
    print(n, x);
}
```

例を実行すると、`n` と `x` が1行に出力されます。値は seed によって決まり、引数なしで実行したときは seed が $0$ になります。

## API・計算量

以下では、選ぶ範囲の幅を $w=r-l$、数列の長さを $n$ とします。乱数エンジンの状態は固定サイズで、クラス全体の空間計算量は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Random(uint64_t seed = 0)` | `seed` でエンジンを初期化する。 | $O(1)$ |
| `Random(int argc, char **argv)` | `argv[1]` を10進の非負整数として読み、seed にする。`argc < 2` なら seed は $0$。 | $O(\lvert \mathtt{argv[1]} \rvert)$ |
| `uniform(uint64_t n)` | $[0,n)$ の一様な整数を返す。$n>0$。 | 期待 $O(1)$ |
| `randint(l, r)` | $[l,r)$ の一様な整数を返す。型は `l`, `r`, `int` の共通型。 | 期待 $O(1)$ |
| `randint(r)` | `randint(0, r)` と同じ。 | 期待 $O(1)$ |
| `even(l, r)` | $[l,r)$ に含まれる偶数から一様に1つ選ぶ。型は `randint` と同じ。 | 期待 $O(1)$ |
| `even(r)` | `even(0, r)` と同じ。 | 期待 $O(1)$ |
| `odd(l, r)` | $[l,r)$ に含まれる奇数から一様に1つ選ぶ。型は `randint` と同じ。 | 期待 $O(1)$ |
| `odd(r)` | `odd(0, r)` と同じ。 | 期待 $O(1)$ |
| `real(l, r)` | $[l,r)$ の `double` を返す。 | $O(1)$ |
| `real()` | `real(0.0, 1.0)` と同じ。 | $O(1)$ |
| `coin(p = 0.5)` | 確率 $p$ で `true` を返す。 | $O(1)$ |
| `size(l, r)` | 小さい値に偏らせた $[l,r)$ の整数を返す。分布は後述。 | 期待 $O(1)$ |
| `choice(v)` | 空でない `vector` の要素を一様に1つ選び、参照を返す。 | 期待 $O(1)$ |
| `shuffle(v)` | `vector` を一様ランダムな順に並べ替える。 | 期待 $O(n)$ |
| `engine()` | 内部の `std::mt19937_64` への参照。標準の分布と組み合わせる場合に使う。 | $O(1)$ |

`uniform` は剰余の偏りを除くため、$2^{64} \bmod n$ 個の値を引いた場合に引き直します。1回で受理される確率は $1/2$ より大きいので、引き直しの回数の期待値は定数です。

## 利用条件と実装上の注意

- `randint` と `size` は $l<r$、`real` は $l<r$ を要求し、満たさない場合は `assert` で停止します。引数は整数型で、`bool` や `char` などは `int` に昇格して計算します。
- `even` と `odd` は、$[l,r)$ に該当する整数が少なくとも1つあることを要求します。例えば `odd(4, 5)` は候補がないので `assert` で停止します。偶奇は負の数も含めて数学的な意味で判定し、$-3$ は奇数、$-4$ は偶数です。候補の最小値 $x_0$ と個数 $c$ を求め、$x_0+2k$（$k$ は $[0,c)$ の一様乱数）を返すので、棄却による引き直しは `uniform` 内部のものだけです。
- `real(l, r)` は $[0,1)$ を $2^{-53}$ 刻みで表した値 $u$ から $l+(r-l)u$ を計算します。丸めで $r$ に等しくなった場合だけ、$r$ より小さい最大の `double` を返します。数学的な連続一様分布ではありません。
- `size(l, r)` は、$2^k \ge w$ となる最小の $k$ を $K$ として、$k \in \{0,1,\dots,K\}$ を等確率に選び、$[l, l+\min(w,2^k))$ から一様に選びます。$k=0$ なら必ず $l$ になるので、$l$ が出る確率は $1/(K+1)$ 以上です。たとえば `size(1, 1001)` では $K=10$ で、$1$ になる確率は約 $0.18$、$10$ 未満になる確率は約 $0.47$ です。$k=K$ のときは範囲全体から一様に選ぶので、最大付近の値も出ます。
- `Random(argc, argv)` は、`argv[1]` が非負整数として読めない場合、標準エラー出力にメッセージを出して終了コード $2$ で終了します。生成器が誤った seed で黙って動くのを防ぐためです。
- 同じ乱数列を得るには、seed だけでなく関数を呼ぶ順序も同じにする必要があります。生成器のコードを書き換えると、同じ seed でも別の入力になります。
- 暗号用途の乱数ではありません。
