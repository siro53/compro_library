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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/random/gen/all.test.cpp
    title: test/mytest/random/gen/all.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/random/gen/string.test.cpp
    title: test/mytest/random/gen/string.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/gen/string.hpp\"\n\n#include <cassert>\n#include\
    \ <string>\n\n#line 2 \"random/gen/random.hpp\"\n\n#include <algorithm>\n#line\
    \ 5 \"random/gen/random.hpp\"\n#include <cerrno>\n#include <cmath>\n#include <cstdint>\n\
    #include <cstdlib>\n#include <iostream>\n#include <random>\n#include <type_traits>\n\
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
    \ seed;\n    }\n};\n#line 7 \"random/gen/string.hpp\"\n\n// \u5404\u6587\u5B57\
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
    \ n, alphabet);\n}\n"
  code: "#pragma once\n\n#include <cassert>\n#include <string>\n\n#include \"random.hpp\"\
    \n\n// \u5404\u6587\u5B57\u3092 alphabet \u304B\u3089\u4E00\u69D8\u306B\u9078\u3093\
    \u3060\u9577\u3055 n \u306E\u6587\u5B57\u5217\ninline std::string random_string(Random\
    \ &rng, int n,\n                                 const std::string &alphabet)\
    \ {\n    assert(n >= 0);\n    assert(n == 0 || !alphabet.empty());\n    std::string\
    \ s(n, '\\0');\n    for(auto &c : s) c = alphabet[rng.uniform(alphabet.size())];\n\
    \    return s;\n}\n\n// \u82F1\u5C0F\u6587\u5B57\u306E\u5148\u982D k \u7A2E\u985E\
    \ ('a' \u304B\u3089 k \u6587\u5B57) \u304B\u3089\u306A\u308B\u9577\u3055 n \u306E\
    \u6587\u5B57\u5217\ninline std::string random_lowercase(Random &rng, int n, int\
    \ k = 26) {\n    assert(1 <= k && k <= 26);\n    std::string alphabet(k, 'a');\n\
    \    for(int i = 0; i < k; i++) alphabet[i] = char('a' + i);\n    return random_string(rng,\
    \ n, alphabet);\n}\n"
  dependsOn:
  - random/gen/random.hpp
  isVerificationFile: false
  path: random/gen/string.hpp
  requiredBy:
  - random/gen/all.hpp
  timestamp: '2026-11-13 01:10:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/random/gen/all.test.cpp
  - test/mytest/random/gen/string.test.cpp
documentation_of: random/gen/string.hpp
layout: document
title: "\u30E9\u30F3\u30C0\u30E0\u306A\u6587\u5B57\u5217"
---

## このライブラリでできること

[`Random`](https://github.com/siro53/compro_library/blob/main/docs/random/gen/random.md) を使って、ランダムテスト用の文字列を生成します。`random_string` は指定した文字の集合から、`random_lowercase` は英小文字のうち先頭の $k$ 種類から、各文字を独立に一様に選びます。

文字列の問題では、文字の種類が少ないほど同じ部分文字列や周期が現れやすく、境界の処理のバグが見つかりやすくなります。`random_lowercase(rng, n, 2)` のように種類を絞って使うのがおすすめです。

## 使い方

例では、`a` と `b` だけからなる長さ $8$ の文字列と、`0` と `1` からなる長さ $5$ の文字列を作ります。

```cpp
#include "template/template.cpp"
#include "random/gen/string.hpp"

int main(int argc, char **argv) {
    Random rng(argc, argv);
    string s = random_lowercase(rng, 8, 2);
    assert(s.size() == 8 && s.find_first_not_of("ab") == string::npos);
    string t = random_string(rng, 5, "01");
    assert(t.find_first_not_of("01") == string::npos);
    print(s);
    print(t);
}
```

## API・計算量

生成する文字列の長さを $n$ とします。返り値の文字列のために $O(n)$ の領域を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `random_string(rng, n, alphabet)` | 各文字を `alphabet` から一様に選んだ長さ $n$ の `string`。 | 期待 $O(n)$ |
| `random_lowercase(rng, n, k = 26)` | 各文字を `'a'` から始まる $k$ 種類の英小文字から一様に選んだ長さ $n$ の `string`。 | 期待 $O(n+k)$ |

## 利用条件と実装上の注意

- $n \ge 0$ を要求します。$n=0$ なら空文字列を返します。
- `random_string` は、$n>0$ のとき `alphabet` が空でないことを要求します。`alphabet` に同じ文字が複数回現れると、その文字は回数に比例して選ばれやすくなります。
- `random_lowercase` は $1 \le k \le 26$ を要求します。
- 条件を満たさない場合は `assert` で停止します。
