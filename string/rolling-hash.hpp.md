---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/modint_2_61.hpp
    title: modint/modint_2_61.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/monoid/rolling_hash.hpp
    title: data-structure/monoid/rolling_hash.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki2102.test.cpp
    title: test/yukicoder/yuki2102.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki430.test.cpp
    title: test/yukicoder/yuki430.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/rolling-hash.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <random>\n#include <string>\n#include <vector>\n\n#line\
    \ 2 \"modint/modint_2_61.hpp\"\n\n#include <istream>\n#include <utility>\n\n//\
    \ \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u7528 modint\n// https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    class ModInt_2_61 {\n  public:\n    using M = ModInt_2_61;\n    ModInt_2_61()\
    \ : x(0) {}\n    ModInt_2_61(long long y) : x(y >= 0 ? y % mod : (mod - (-y) %\
    \ mod) % mod) {}\n    unsigned long long val() const { return x; }\n    M &operator+=(const\
    \ M &m) {\n        if((x += m.x) >= mod) x -= mod;\n        return *this;\n  \
    \  }\n    M &operator-=(const M &m) {\n        if((x += mod - m.x) >= mod) x -=\
    \ mod;\n        return *this;\n    }\n    M &operator*=(const M &m) {\n      \
    \  __uint128_t t = (__uint128_t)x * m.x;\n        unsigned long long na = t >>\
    \ 61;\n        unsigned long long nb = t & mod;\n        if((na += nb) >= mod)\
    \ na -= mod;\n        x = na;\n        return *this;\n    }\n    M &operator/=(const\
    \ M &m) {\n        *this *= m.inv();\n        return *this;\n    }\n    M operator-()\
    \ const { return M(-(long long)x); }\n    M operator+(const M &m) const { return\
    \ M(*this) += m; }\n    M operator-(const M &m) const { return M(*this) -= m;\
    \ }\n    M operator*(const M &m) const { return M(*this) *= m; }\n    M operator/(const\
    \ M &m) const { return M(*this) /= m; }\n    bool operator==(const M &m) const\
    \ { return (x == m.x); }\n    bool operator!=(const M &m) const { return (x !=\
    \ m.x); }\n    M inv() const {\n        long long a = x, b = mod, u = 1, v = 0,\
    \ t;\n        while(b > 0) {\n            t = a / b;\n            std::swap(a\
    \ -= t * b, b);\n            std::swap(u -= t * v, v);\n        }\n        return\
    \ M(u);\n    }\n    M pow(unsigned long long n) const {\n        M ret(1), mul(x);\n\
    \        while(n > 0) {\n            if(n & 1) ret *= mul;\n            mul *=\
    \ mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const M &p) {\n        return os\
    \ << p.x;\n    }\n    friend std::istream &operator>>(std::istream &is, M &a)\
    \ {\n        long long t;\n        is >> t;\n        a = M(t);\n        return\
    \ (is);\n    }\n    static constexpr unsigned long long get_mod() { return mod;\
    \ }\n\n  private:\n    unsigned long long x;\n    static constexpr unsigned long\
    \ long mod = (1LL << 61) - 1;\n};\n#line 10 \"string/rolling-hash.hpp\"\n\nstruct\
    \ RollingHash {\n    using u64 = unsigned long long;\n    using mint = ModInt_2_61;\n\
    \    static constexpr u64 mod = (1ULL << 61) - 1;\n    const u64 base;\n    std::vector<mint>\
    \ hashed, power;\n\n    explicit RollingHash(const std::vector<int> &v, u64 base)\
    \ : base(base) {\n        int n = (int)v.size();\n        hashed.assign(n + 1,\
    \ 0);\n        power.assign(n + 1, 0);\n        power[0] = 1;\n        for(int\
    \ i = 0; i < n; i++) {\n            power[i + 1] = power[i] * base;\n        \
    \    hashed[i + 1] = (hashed[i] * base) + v[i];\n        }\n    }\n    explicit\
    \ RollingHash(const std::string &s, u64 base) : base(base) {\n        int n =\
    \ (int)s.size();\n        hashed.assign(n + 1, 0);\n        power.assign(n + 1,\
    \ 0);\n        power[0] = 1;\n        for(int i = 0; i < n; i++) {\n         \
    \   power[i + 1] = power[i] * base;\n            hashed[i + 1] = (hashed[i] *\
    \ base) + s[i];\n        }\n    }\n    static inline u64 gen_base() {\n      \
    \  std::random_device seed_gen;\n        std::mt19937_64 engine(seed_gen());\n\
    \        std::uniform_int_distribution<u64> rand(2, mod - 2);\n        return\
    \ rand(engine);\n    }\n    mint get(int l, int r) {\n        assert(0 <= l);\n\
    \        assert(l <= r);\n        assert(r < (int)power.size());\n        return\
    \ (hashed[r] - (hashed[l] * power[r - l]));\n    }\n    mint connect(mint h1,\
    \ mint h2, int h2len) {\n        return (h1 * power[h2len] + h2);\n    }\n   \
    \ int get_lcp(RollingHash &b, int l1, int r1, int l2, int r2) {\n        assert(mod\
    \ == b.mod);\n        int len = std::min(r1 - l1, r2 - l2);\n        int low =\
    \ -1, high = len + 1;\n        while(high - low > 1) {\n            int mid =\
    \ (low + high) >> 1;\n            if(get(l1, l1 + mid) == b.get(l2, l2 + mid))\
    \ {\n                low = mid;\n            } else {\n                high =\
    \ mid;\n            }\n        }\n        return low;\n    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <random>\n\
    #include <string>\n#include <vector>\n\n#include \"../modint/modint_2_61.hpp\"\
    \n\nstruct RollingHash {\n    using u64 = unsigned long long;\n    using mint\
    \ = ModInt_2_61;\n    static constexpr u64 mod = (1ULL << 61) - 1;\n    const\
    \ u64 base;\n    std::vector<mint> hashed, power;\n\n    explicit RollingHash(const\
    \ std::vector<int> &v, u64 base) : base(base) {\n        int n = (int)v.size();\n\
    \        hashed.assign(n + 1, 0);\n        power.assign(n + 1, 0);\n        power[0]\
    \ = 1;\n        for(int i = 0; i < n; i++) {\n            power[i + 1] = power[i]\
    \ * base;\n            hashed[i + 1] = (hashed[i] * base) + v[i];\n        }\n\
    \    }\n    explicit RollingHash(const std::string &s, u64 base) : base(base)\
    \ {\n        int n = (int)s.size();\n        hashed.assign(n + 1, 0);\n      \
    \  power.assign(n + 1, 0);\n        power[0] = 1;\n        for(int i = 0; i <\
    \ n; i++) {\n            power[i + 1] = power[i] * base;\n            hashed[i\
    \ + 1] = (hashed[i] * base) + s[i];\n        }\n    }\n    static inline u64 gen_base()\
    \ {\n        std::random_device seed_gen;\n        std::mt19937_64 engine(seed_gen());\n\
    \        std::uniform_int_distribution<u64> rand(2, mod - 2);\n        return\
    \ rand(engine);\n    }\n    mint get(int l, int r) {\n        assert(0 <= l);\n\
    \        assert(l <= r);\n        assert(r < (int)power.size());\n        return\
    \ (hashed[r] - (hashed[l] * power[r - l]));\n    }\n    mint connect(mint h1,\
    \ mint h2, int h2len) {\n        return (h1 * power[h2len] + h2);\n    }\n   \
    \ int get_lcp(RollingHash &b, int l1, int r1, int l2, int r2) {\n        assert(mod\
    \ == b.mod);\n        int len = std::min(r1 - l1, r2 - l2);\n        int low =\
    \ -1, high = len + 1;\n        while(high - low > 1) {\n            int mid =\
    \ (low + high) >> 1;\n            if(get(l1, l1 + mid) == b.get(l2, l2 + mid))\
    \ {\n                low = mid;\n            } else {\n                high =\
    \ mid;\n            }\n        }\n        return low;\n    }\n};"
  dependsOn:
  - modint/modint_2_61.hpp
  isVerificationFile: false
  path: string/rolling-hash.hpp
  requiredBy:
  - data-structure/monoid/rolling_hash.hpp
  timestamp: '2023-12-05 19:29:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki430.test.cpp
  - test/yukicoder/yuki2102.test.cpp
documentation_of: string/rolling-hash.hpp
layout: document
link: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
---
