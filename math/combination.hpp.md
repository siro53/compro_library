---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/modint.hpp
    title: math/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/modint.hpp\"\ntemplate <int mod> struct ModInt {\n\
    \    using M = ModInt;\n    int x;\n    ModInt() : x(0) {}\n    ModInt(int64_t\
    \ y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n    M &operator+=(const\
    \ M &p) {\n        if((x += p.x) >= mod) x -= mod;\n        return *this;\n  \
    \  }\n    M &operator-=(const M &p) {\n        if((x += mod - p.x) >= mod) x -=\
    \ mod;\n        return *this;\n    }\n    M &operator*=(const M &p) {\n      \
    \  x = (int)(1LL * x * p.x % mod);\n        return *this;\n    }\n    M &operator/=(const\
    \ M &p) {\n        *this *= p.inverse();\n        return *this;\n    }\n    M\
    \ operator-() const { return M(-x); }\n    M operator+(const M &p) const { return\
    \ M(*this) += p; }\n    M operator-(const M &p) const { return M(*this) -= p;\
    \ }\n    M operator*(const M &p) const { return M(*this) *= p; }\n    M operator/(const\
    \ M &p) const { return M(*this) /= p; }\n    M inverse() const {\n        int\
    \ a = x, b = mod, u = 1, v = 0, t;\n        while(b > 0) {\n            t = a\
    \ / b;\n            swap(a -= t * b, b);\n            swap(u -= t * v, v);\n \
    \       }\n        return M(u);\n    }\n    M pow(int64_t n) const {\n       \
    \ M ret(1), mul(x);\n        while(n > 0) {\n            if(n & 1) ret *= mul;\n\
    \            mul *= mul;\n            n >>= 1;\n        }\n        return ret;\n\
    \    }\n    friend ostream &operator<<(ostream &os, const M &p) { return os <<\
    \ p.x; }\n    friend istream &operator>>(istream &is, M &a) {\n        int64_t\
    \ t;\n        is >> t;\n        a = M<mod>(t);\n        return (is);\n    }\n\
    \    static int get_mod() { return mod; }\n};\n#line 2 \"math/combination.hpp\"\
    \n\nusing mint = ModInt<MOD>;\n\nstruct Combination {\n    int MAX;\n    vector<mint>\
    \ fac, finv;\n    Combination(int _MAX) : fac(_MAX), finv(_MAX), MAX(_MAX) {\n\
    \        fac[0] = fac[1] = 1;\n        for(int i = 2; i < MAX; i++) { fac[i] =\
    \ fac[i - 1] * i; }\n        finv[MAX - 1] = fac[MAX - 1].inverse();\n       \
    \ for(int i = MAX - 1; i >= 1; i--) { finv[i - 1] = finv[i] * i; }\n    }\n  \
    \  mint COM(int n, int k) {\n        if(n < k || n < 0 || k < 0) { return 0; }\n\
    \        return fac[n] * finv[k] * finv[n - k];\n    }\n};\n"
  code: "#include \"modint.hpp\"\n\nusing mint = ModInt<MOD>;\n\nstruct Combination\
    \ {\n    int MAX;\n    vector<mint> fac, finv;\n    Combination(int _MAX) : fac(_MAX),\
    \ finv(_MAX), MAX(_MAX) {\n        fac[0] = fac[1] = 1;\n        for(int i = 2;\
    \ i < MAX; i++) { fac[i] = fac[i - 1] * i; }\n        finv[MAX - 1] = fac[MAX\
    \ - 1].inverse();\n        for(int i = MAX - 1; i >= 1; i--) { finv[i - 1] = finv[i]\
    \ * i; }\n    }\n    mint COM(int n, int k) {\n        if(n < k || n < 0 || k\
    \ < 0) { return 0; }\n        return fac[n] * finv[k] * finv[n - k];\n    }\n\
    };"
  dependsOn:
  - math/modint.hpp
  isVerificationFile: false
  path: math/combination.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combination.hpp
layout: document
redirect_from:
- /library/math/combination.hpp
- /library/math/combination.hpp.html
title: math/combination.hpp
---
