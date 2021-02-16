---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/fast_factorize.test.cpp
    title: test/fast_factorize.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/pollad-rho.hpp\"\nstruct FastFactorize {\n    ll mul(ll\
    \ a, ll b, ll c) { return (__int128)a * b % c; }\n    ll power(ll a, ll b, ll\
    \ mod) {\n        ll res = 1;\n        while(b) {\n            if(b & 1) { res\
    \ = mul(res, a, mod); }\n            a = mul(a, a, mod);\n            b >>= 1;\n\
    \        }\n        return res;\n    }\n    bool isPrime(ll n) {\n        if(!(n\
    \ & 1) && n != 2) { return false; }\n        ll d = n - 1;\n        int s = __builtin_ctzll(d);\n\
    \        d >>= s;\n        vector<int> A;\n        if(n <= 1000000000) {\n   \
    \         A = {2, 3, 5, 7};\n        } else {\n            A = {2, 3, 5, 7, 11,\
    \ 13, 17, 19, 23, 29, 31, 37};\n        }\n        for(int a : A) {\n        \
    \    ll p = power(a, d, n);\n            int i = s;\n            while(p != 1\
    \ && p != n - 1 && a % n && (--i)) { p = mul(p, p, n); }\n            if(p !=\
    \ n - 1 && i != s) { return false; }\n        }\n        return true;\n    }\n\
    \    ll rho(ll n) {\n        auto f = [&](ll a) { return mul(a, a, n) + 1; };\n\
    \        ll x = 0, y = 0, p = 2, q;\n        int i = 1, t = 0;\n        while((t++)\
    \ % 40 || gcd(p, n) == 1) {\n            if(x == y) {\n                x = ++i;\n\
    \                y = f(x);\n            }\n            if(q = mul(p, abs(y - x),\
    \ n)) { p = q; }\n            x = f(x);\n            y = f(f(y));\n        }\n\
    \        return gcd(p, n);\n    }\n    vector<ll> factor(ll n) {\n        if(n\
    \ == 1) { return {}; }\n        if(isPrime(n)) { return {n}; }\n        ll a =\
    \ rho(n);\n        assert(a != n && a != 1);\n        auto l = factor(a), r =\
    \ factor(n / a);\n        l.insert(l.end(), r.begin(), r.end());\n        return\
    \ l;\n    }\n    // \u672Averify, \u30D0\u30B0\u3063\u3066\u308B\u304B\u3082\n\
    \    vector<ll> divisor(ll n) {\n        vector<ll> res;\n        auto v = factor(n);\n\
    \        map<ll, int> cnt;\n        for(const ll &a : v) cnt[a]++;\n        sort(ALL(v));\n\
    \        v.erase(unique(ALL(v)), v.end());\n        int sz = int(v.size());\n\n\
    \        auto dfs = [&](auto &&dfs, int d, ll now) -> void {\n            if(d\
    \ == sz) {\n                res.emplace_back(now);\n                return;\n\
    \            }\n            ll nxt = now;\n            dfs(dfs, d + 1, nxt);\n\
    \            rep(i, cnt[v[d]]) {\n                nxt *= v[d];\n             \
    \   dfs(dfs, d + 1, nxt);\n            }\n        };\n\n        dfs(dfs, 0, 1);\n\
    \        sort(ALL(res));\n        return res;\n    }\n};\n"
  code: "struct FastFactorize {\n    ll mul(ll a, ll b, ll c) { return (__int128)a\
    \ * b % c; }\n    ll power(ll a, ll b, ll mod) {\n        ll res = 1;\n      \
    \  while(b) {\n            if(b & 1) { res = mul(res, a, mod); }\n           \
    \ a = mul(a, a, mod);\n            b >>= 1;\n        }\n        return res;\n\
    \    }\n    bool isPrime(ll n) {\n        if(!(n & 1) && n != 2) { return false;\
    \ }\n        ll d = n - 1;\n        int s = __builtin_ctzll(d);\n        d >>=\
    \ s;\n        vector<int> A;\n        if(n <= 1000000000) {\n            A = {2,\
    \ 3, 5, 7};\n        } else {\n            A = {2, 3, 5, 7, 11, 13, 17, 19, 23,\
    \ 29, 31, 37};\n        }\n        for(int a : A) {\n            ll p = power(a,\
    \ d, n);\n            int i = s;\n            while(p != 1 && p != n - 1 && a\
    \ % n && (--i)) { p = mul(p, p, n); }\n            if(p != n - 1 && i != s) {\
    \ return false; }\n        }\n        return true;\n    }\n    ll rho(ll n) {\n\
    \        auto f = [&](ll a) { return mul(a, a, n) + 1; };\n        ll x = 0, y\
    \ = 0, p = 2, q;\n        int i = 1, t = 0;\n        while((t++) % 40 || gcd(p,\
    \ n) == 1) {\n            if(x == y) {\n                x = ++i;\n           \
    \     y = f(x);\n            }\n            if(q = mul(p, abs(y - x), n)) { p\
    \ = q; }\n            x = f(x);\n            y = f(f(y));\n        }\n       \
    \ return gcd(p, n);\n    }\n    vector<ll> factor(ll n) {\n        if(n == 1)\
    \ { return {}; }\n        if(isPrime(n)) { return {n}; }\n        ll a = rho(n);\n\
    \        assert(a != n && a != 1);\n        auto l = factor(a), r = factor(n /\
    \ a);\n        l.insert(l.end(), r.begin(), r.end());\n        return l;\n   \
    \ }\n    // \u672Averify, \u30D0\u30B0\u3063\u3066\u308B\u304B\u3082\n    vector<ll>\
    \ divisor(ll n) {\n        vector<ll> res;\n        auto v = factor(n);\n    \
    \    map<ll, int> cnt;\n        for(const ll &a : v) cnt[a]++;\n        sort(ALL(v));\n\
    \        v.erase(unique(ALL(v)), v.end());\n        int sz = int(v.size());\n\n\
    \        auto dfs = [&](auto &&dfs, int d, ll now) -> void {\n            if(d\
    \ == sz) {\n                res.emplace_back(now);\n                return;\n\
    \            }\n            ll nxt = now;\n            dfs(dfs, d + 1, nxt);\n\
    \            rep(i, cnt[v[d]]) {\n                nxt *= v[d];\n             \
    \   dfs(dfs, d + 1, nxt);\n            }\n        };\n\n        dfs(dfs, 0, 1);\n\
    \        sort(ALL(res));\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/pollad-rho.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/fast_factorize.test.cpp
documentation_of: math/pollad-rho.hpp
layout: document
redirect_from:
- /library/math/pollad-rho.hpp
- /library/math/pollad-rho.hpp.html
title: math/pollad-rho.hpp
---
