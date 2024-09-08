---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/pow_mod.hpp
    title: math/pow_mod.hpp
  - icon: ':heavy_check_mark:'
    path: math/primitive-root.hpp
    title: math/primitive-root.hpp
  - icon: ':question:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/convolution/convolution-mod.test.cpp
    title: test/library-checker/convolution/convolution-mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/convolution/ntt.hpp\"\n\n#include <array>\n#include\
    \ <utility>\n#include <vector>\n\n#line 2 \"modint/modint.hpp\"\n\n#include <istream>\n\
    #include <ostream>\n#line 6 \"modint/modint.hpp\"\n\ntemplate <int mod> class\
    \ ModInt {\n  public:\n    ModInt() : x(0) {}\n    ModInt(long long y)\n     \
    \   : x(y >= 0 ? y % umod() : (umod() - (-y) % umod()) % umod()) {}\n    unsigned\
    \ int val() const { return x; }\n    ModInt &operator+=(const ModInt &p) {\n \
    \       if((x += p.x) >= umod()) x -= umod();\n        return *this;\n    }\n\
    \    ModInt &operator-=(const ModInt &p) {\n        if((x += umod() - p.x) >=\
    \ umod()) x -= umod();\n        return *this;\n    }\n    ModInt &operator*=(const\
    \ ModInt &p) {\n        x = (unsigned int)(1ULL * x * p.x % umod());\n       \
    \ return *this;\n    }\n    ModInt &operator/=(const ModInt &p) {\n        *this\
    \ *= p.inv();\n        return *this;\n    }\n    ModInt operator-() const { return\
    \ ModInt(-(long long)x); }\n    ModInt operator+(const ModInt &p) const { return\
    \ ModInt(*this) += p; }\n    ModInt operator-(const ModInt &p) const { return\
    \ ModInt(*this) -= p; }\n    ModInt operator*(const ModInt &p) const { return\
    \ ModInt(*this) *= p; }\n    ModInt operator/(const ModInt &p) const { return\
    \ ModInt(*this) /= p; }\n    bool operator==(const ModInt &p) const { return x\
    \ == p.x; }\n    bool operator!=(const ModInt &p) const { return x != p.x; }\n\
    \    ModInt inv() const {\n        long long a = x, b = mod, u = 1, v = 0, t;\n\
    \        while(b > 0) {\n            t = a / b;\n            std::swap(a -= t\
    \ * b, b);\n            std::swap(u -= t * v, v);\n        }\n        return ModInt(u);\n\
    \    }\n    ModInt pow(unsigned long long n) const {\n        ModInt ret(1), mul(x);\n\
    \        while(n > 0) {\n            if(n & 1) ret *= mul;\n            mul *=\
    \ mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const ModInt &p) {\n        return\
    \ os << p.x;\n    }\n    friend std::istream &operator>>(std::istream &is, ModInt\
    \ &a) {\n        long long t;\n        is >> t;\n        a = ModInt<mod>(t);\n\
    \        return (is);\n    }\n    static constexpr int get_mod() { return mod;\
    \ }\n\n  private:\n    unsigned int x;\n    static constexpr unsigned int umod()\
    \ { return mod; }\n};\n#line 2 \"math/primitive-root.hpp\"\n\n#line 2 \"math/pow_mod.hpp\"\
    \n\nconstexpr long long pow_mod(long long x, long long k, long long m) {\n   \
    \ long long res = 1;\n    long long mul = (x >= 0 ? x % m : x % m + m);\n    while(k)\
    \ {\n        if(k & 1) res = (__int128_t)res * mul % m;\n        mul = (__int128_t)mul\
    \ * mul % m;\n        k >>= 1;\n    }\n    return res;\n}\n#line 4 \"math/primitive-root.hpp\"\
    \n\nconstexpr int primitive_root(int p) {\n    if(p == 2) return 1;\n    if(p\
    \ == 998244353) return 3;\n    int primes[31] = {};\n    int sz = 0, t = p - 1;\n\
    \    for(int i = 2; i * i <= t; i++) {\n        if(t % i == 0) {\n           \
    \ primes[sz++] = i;\n            while(t % i == 0) t /= i;\n        }\n    }\n\
    \    if(t > 1) primes[sz++] = t;\n    for(int g = 2;;g++) {\n        bool f =\
    \ true;\n        for(int i = 0; i < sz; i++) {\n            if(pow_mod(g, (p -\
    \ 1) / primes[i], p) == 1) {\n                f = false;\n                break;\n\
    \            }\n        }   \n        if(f) return g;\n    }\n}\n#line 9 \"math/convolution/ntt.hpp\"\
    \n\nnamespace ntt {\n    constexpr int exp_limit(int mod) { return __builtin_ctz(mod\
    \ - 1); }\n\n    template <class mint, int mod = mint::get_mod(),\n          \
    \    int g = primitive_root(mod)>\n    struct ntt_info {\n        static constexpr\
    \ int limit = exp_limit(mod);\n        std::array<mint, limit + 1> root;\n   \
    \     std::array<mint, limit + 1> iroot;\n\n        ntt_info() {\n           \
    \ root[limit] = mint(g).pow((mod - 1) >> limit);\n            iroot[limit] = root[limit].inv();\n\
    \            for(int i = limit - 1; i >= 0; i--) {\n                root[i] =\
    \ root[i + 1] * root[i + 1];\n                iroot[i] = iroot[i + 1] * iroot[i\
    \ + 1];\n            }\n        }\n    };\n\n    inline uint64_t revbit(uint64_t\
    \ mask) {\n        int b = __builtin_clzll(mask);\n        uint64_t x = mask;\n\
    \        x = (x >> 32) | (x << 32);\n        x = ((x >> 16) & 0x0000FFFF0000FFFF)\
    \ | ((x << 16) & 0xFFFF0000FFFF0000);\n        x = ((x >> 8) & 0x00FF00FF00FF00FF)\
    \ | ((x << 8) & 0xFF00FF00FF00FF00);\n        x = ((x >> 4) & 0x0F0F0F0F0F0F0F0F)\
    \ | ((x << 4) & 0xF0F0F0F0F0F0F0F0);\n        x = ((x >> 2) & 0x3333333333333333)\
    \ | ((x << 2) & 0xCCCCCCCCCCCCCCCC);\n        x = ((x >> 1) & 0x5555555555555555)\
    \ | ((x << 1) & 0xAAAAAAAAAAAAAAAA);\n        return (x >> b);\n    }\n\n    template<class\
    \ mint>\n    void ntt(std::vector<mint>& a) {\n        int n = (int)a.size();\n\
    \        int bitlen = __builtin_ctz(n);\n        static const ntt_info<mint> info;\n\
    \        for(int len = n, b = bitlen; len > 1; len >>= 1, b--) {\n           \
    \ for(int i = 0; i < n; i += len) {\n                int t = len >> 1;\n     \
    \           mint wj = 1;\n                for(int j = 0; j < t; j++) {\n     \
    \               int p = i + j;\n                    mint l = a[p] + a[p + t];\n\
    \                    mint r = (a[p] - a[p + t]) * wj;\n                    a[p]\
    \ = l, a[p + t] = r;\n                    wj *= info.root[b];\n              \
    \  }\n            }\n        }\n        for(int i = 0; i < n; i++) {\n       \
    \     int j = revbit(i);\n            if(i < j) std::swap(a[i], a[j]);\n     \
    \   }\n    }\n\n    template<class mint>\n    void intt(std::vector<mint>& a)\
    \ {\n        int n = (int)a.size();\n        static const ntt_info<mint> info;\n\
    \        for(int i = 0; i < n; i++) {\n            int j = revbit(i);\n      \
    \      if(i < j) std::swap(a[i], a[j]);\n        }\n        for(int len = 2, b\
    \ = 1; len <= n; len <<= 1, b++) {\n            for(int i = 0; i < n; i += len)\
    \ {\n                int t = len >> 1;\n                mint wj = 1;\n       \
    \         for(int j = 0; j < t; j++) {\n                    int p = i + j;\n \
    \                   auto l = a[p] + a[p + t] * wj;\n                    auto r\
    \ = a[p] - a[p + t] * wj;\n                    a[p] = l, a[p + t] = r;\n     \
    \               wj *= info.iroot[b];\n                }\n            }\n     \
    \   }\n        mint invn = mint(n).inv();\n        for(int i = 0; i < n; i++)\
    \ a[i] *= invn;\n    }\n\n    template<class mint>\n    std::vector<mint> convolution(std::vector<mint>\
    \ a, std::vector<mint> b) {\n        int m = (int)a.size() + (int)b.size() - 1;\n\
    \        int n = 1;\n        while(n < m) n <<= 1;\n        a.resize(n), b.resize(n);\n\
    \        ntt<mint>(a);\n        ntt<mint>(b);\n        for(int i = 0; i < n; i++)\
    \ a[i] *= b[i];\n        intt<mint>(a);\n        a.resize(m);\n        return\
    \ a;\n    }\n}; // namespace ntt\n"
  code: "#pragma once\n\n#include <array>\n#include <utility>\n#include <vector>\n\
    \n#include \"../../modint/modint.hpp\"\n#include \"../primitive-root.hpp\"\n\n\
    namespace ntt {\n    constexpr int exp_limit(int mod) { return __builtin_ctz(mod\
    \ - 1); }\n\n    template <class mint, int mod = mint::get_mod(),\n          \
    \    int g = primitive_root(mod)>\n    struct ntt_info {\n        static constexpr\
    \ int limit = exp_limit(mod);\n        std::array<mint, limit + 1> root;\n   \
    \     std::array<mint, limit + 1> iroot;\n\n        ntt_info() {\n           \
    \ root[limit] = mint(g).pow((mod - 1) >> limit);\n            iroot[limit] = root[limit].inv();\n\
    \            for(int i = limit - 1; i >= 0; i--) {\n                root[i] =\
    \ root[i + 1] * root[i + 1];\n                iroot[i] = iroot[i + 1] * iroot[i\
    \ + 1];\n            }\n        }\n    };\n\n    inline uint64_t revbit(uint64_t\
    \ mask) {\n        int b = __builtin_clzll(mask);\n        uint64_t x = mask;\n\
    \        x = (x >> 32) | (x << 32);\n        x = ((x >> 16) & 0x0000FFFF0000FFFF)\
    \ | ((x << 16) & 0xFFFF0000FFFF0000);\n        x = ((x >> 8) & 0x00FF00FF00FF00FF)\
    \ | ((x << 8) & 0xFF00FF00FF00FF00);\n        x = ((x >> 4) & 0x0F0F0F0F0F0F0F0F)\
    \ | ((x << 4) & 0xF0F0F0F0F0F0F0F0);\n        x = ((x >> 2) & 0x3333333333333333)\
    \ | ((x << 2) & 0xCCCCCCCCCCCCCCCC);\n        x = ((x >> 1) & 0x5555555555555555)\
    \ | ((x << 1) & 0xAAAAAAAAAAAAAAAA);\n        return (x >> b);\n    }\n\n    template<class\
    \ mint>\n    void ntt(std::vector<mint>& a) {\n        int n = (int)a.size();\n\
    \        int bitlen = __builtin_ctz(n);\n        static const ntt_info<mint> info;\n\
    \        for(int len = n, b = bitlen; len > 1; len >>= 1, b--) {\n           \
    \ for(int i = 0; i < n; i += len) {\n                int t = len >> 1;\n     \
    \           mint wj = 1;\n                for(int j = 0; j < t; j++) {\n     \
    \               int p = i + j;\n                    mint l = a[p] + a[p + t];\n\
    \                    mint r = (a[p] - a[p + t]) * wj;\n                    a[p]\
    \ = l, a[p + t] = r;\n                    wj *= info.root[b];\n              \
    \  }\n            }\n        }\n        for(int i = 0; i < n; i++) {\n       \
    \     int j = revbit(i);\n            if(i < j) std::swap(a[i], a[j]);\n     \
    \   }\n    }\n\n    template<class mint>\n    void intt(std::vector<mint>& a)\
    \ {\n        int n = (int)a.size();\n        static const ntt_info<mint> info;\n\
    \        for(int i = 0; i < n; i++) {\n            int j = revbit(i);\n      \
    \      if(i < j) std::swap(a[i], a[j]);\n        }\n        for(int len = 2, b\
    \ = 1; len <= n; len <<= 1, b++) {\n            for(int i = 0; i < n; i += len)\
    \ {\n                int t = len >> 1;\n                mint wj = 1;\n       \
    \         for(int j = 0; j < t; j++) {\n                    int p = i + j;\n \
    \                   auto l = a[p] + a[p + t] * wj;\n                    auto r\
    \ = a[p] - a[p + t] * wj;\n                    a[p] = l, a[p + t] = r;\n     \
    \               wj *= info.iroot[b];\n                }\n            }\n     \
    \   }\n        mint invn = mint(n).inv();\n        for(int i = 0; i < n; i++)\
    \ a[i] *= invn;\n    }\n\n    template<class mint>\n    std::vector<mint> convolution(std::vector<mint>\
    \ a, std::vector<mint> b) {\n        int m = (int)a.size() + (int)b.size() - 1;\n\
    \        int n = 1;\n        while(n < m) n <<= 1;\n        a.resize(n), b.resize(n);\n\
    \        ntt<mint>(a);\n        ntt<mint>(b);\n        for(int i = 0; i < n; i++)\
    \ a[i] *= b[i];\n        intt<mint>(a);\n        a.resize(m);\n        return\
    \ a;\n    }\n}; // namespace ntt"
  dependsOn:
  - modint/modint.hpp
  - math/primitive-root.hpp
  - math/pow_mod.hpp
  isVerificationFile: false
  path: math/convolution/ntt.hpp
  requiredBy: []
  timestamp: '2023-10-01 12:06:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/convolution/convolution-mod.test.cpp
documentation_of: math/convolution/ntt.hpp
layout: document
redirect_from:
- /library/math/convolution/ntt.hpp
- /library/math/convolution/ntt.hpp.html
title: math/convolution/ntt.hpp
---
