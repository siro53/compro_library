---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki117.test.cpp
    title: test/yukicoder/yuki117.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/binom.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n\ntemplate <class mint> class Binomial {\n  public:\n    explicit\
    \ Binomial(): Binomial(1) {}\n    explicit Binomial(int MAX) : f(MAX, mint(1)),\
    \ f_inv(MAX, mint(1)) {\n        for(int i = 1; i < MAX; i++) f[i] = f[i-1] *\
    \ mint(i);\n        f_inv[MAX - 1] = f[MAX - 1].inv();\n        for(int i = MAX\
    \ - 2; i >= 1; i--) {\n            f_inv[i] = f_inv[i + 1] * mint(i + 1);\n  \
    \      } \n    }\n    void extend() {\n        int n = (int)f.size();\n      \
    \  f.resize(n * 2);\n        f_inv.resize(n * 2);\n        for(int i = n; i <\
    \ n * 2; i++) f[i] = f[i - 1] * mint(i);\n        f_inv[n * 2 - 1] = f[n * 2 -\
    \ 1].inv();\n        for(int i = n * 2 - 2; i >= n; i--) {\n            f_inv[i]\
    \ = f_inv[i + 1] * mint(i + 1);\n        }\n    }\n    mint fac(int n) {\n   \
    \     if(n < 0) return mint(0);\n        while(n >= (int)f.size()) extend();\n\
    \        return f[n];\n    }\n    mint fac_inv(int n) {\n        if(n < 0) return\
    \ mint(0);\n        while(n >= (int)f_inv.size()) extend();\n        return f_inv[n];\n\
    \    }\n    mint inv(int n) {\n        if(n < 0) return -mint(-n);\n        assert(n\
    \ != 0);\n        while(n >= (int)f_inv.size()) extend();\n        return (f_inv[n]\
    \ * f[n - 1]);\n    }\n    mint binom(int n, int k) {\n        if(n < k || n <\
    \ 0 || k < 0) return mint(0);\n        return (fac(n) * fac_inv(k) * fac_inv(n\
    \ - k));\n    }\n    mint binom_naive(long long n, long long k) {\n        if(n\
    \ < k || n < 0 || k < 0) return mint(0);\n        mint res(1);\n        k = std::min(k,\
    \ n - k);\n        for(int i = 0; i < k; i++) res *= inv(i + 1) * mint(n - i);\n\
    \        return res;\n    }\n    mint perm(int n, int k) {\n        if(n < k ||\
    \ n < 0 || k < 0) return mint(0);\n        return (fac(n) * fac_inv(n - k));\n\
    \    }\n    mint hom(int n, int k) {\n        if(n < 0 || k < 0) return mint(0);\n\
    \        return (k == 0 ? mint(1) : binom(n + k - 1, k));\n    }\n\n  private:\n\
    \    std::vector<mint> f, f_inv;\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \ntemplate <class mint> class Binomial {\n  public:\n    explicit Binomial():\
    \ Binomial(1) {}\n    explicit Binomial(int MAX) : f(MAX, mint(1)), f_inv(MAX,\
    \ mint(1)) {\n        for(int i = 1; i < MAX; i++) f[i] = f[i-1] * mint(i);\n\
    \        f_inv[MAX - 1] = f[MAX - 1].inv();\n        for(int i = MAX - 2; i >=\
    \ 1; i--) {\n            f_inv[i] = f_inv[i + 1] * mint(i + 1);\n        } \n\
    \    }\n    void extend() {\n        int n = (int)f.size();\n        f.resize(n\
    \ * 2);\n        f_inv.resize(n * 2);\n        for(int i = n; i < n * 2; i++)\
    \ f[i] = f[i - 1] * mint(i);\n        f_inv[n * 2 - 1] = f[n * 2 - 1].inv();\n\
    \        for(int i = n * 2 - 2; i >= n; i--) {\n            f_inv[i] = f_inv[i\
    \ + 1] * mint(i + 1);\n        }\n    }\n    mint fac(int n) {\n        if(n <\
    \ 0) return mint(0);\n        while(n >= (int)f.size()) extend();\n        return\
    \ f[n];\n    }\n    mint fac_inv(int n) {\n        if(n < 0) return mint(0);\n\
    \        while(n >= (int)f_inv.size()) extend();\n        return f_inv[n];\n \
    \   }\n    mint inv(int n) {\n        if(n < 0) return -mint(-n);\n        assert(n\
    \ != 0);\n        while(n >= (int)f_inv.size()) extend();\n        return (f_inv[n]\
    \ * f[n - 1]);\n    }\n    mint binom(int n, int k) {\n        if(n < k || n <\
    \ 0 || k < 0) return mint(0);\n        return (fac(n) * fac_inv(k) * fac_inv(n\
    \ - k));\n    }\n    mint binom_naive(long long n, long long k) {\n        if(n\
    \ < k || n < 0 || k < 0) return mint(0);\n        mint res(1);\n        k = std::min(k,\
    \ n - k);\n        for(int i = 0; i < k; i++) res *= inv(i + 1) * mint(n - i);\n\
    \        return res;\n    }\n    mint perm(int n, int k) {\n        if(n < k ||\
    \ n < 0 || k < 0) return mint(0);\n        return (fac(n) * fac_inv(n - k));\n\
    \    }\n    mint hom(int n, int k) {\n        if(n < 0 || k < 0) return mint(0);\n\
    \        return (k == 0 ? mint(1) : binom(n + k - 1, k));\n    }\n\n  private:\n\
    \    std::vector<mint> f, f_inv;\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/binom.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki117.test.cpp
documentation_of: math/binom.hpp
layout: document
redirect_from:
- /library/math/binom.hpp
- /library/math/binom.hpp.html
title: math/binom.hpp
---
