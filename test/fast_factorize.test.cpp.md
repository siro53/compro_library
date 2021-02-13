---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/pollad-rho.hpp
    title: math/pollad-rho.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test/fast_factorize.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n#line 1 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntemplate <class T> inline bool chmax(T &a, T b) {\n    if(a < b) {\n \
    \       a = b;\n        return 1;\n    }\n    return 0;\n}\ntemplate <class T>\
    \ inline bool chmin(T &a, T b) {\n    if(a > b) {\n        a = b;\n        return\
    \ 1;\n    }\n    return 0;\n}\n#define DEBUG\n#ifdef DEBUG\ntemplate <class T,\
    \ class U>\nostream &operator<<(ostream &os, const pair<T, U> &p) {\n    os <<\
    \ '(' << p.first << ',' << p.second << ')';\n    return os;\n}\ntemplate <class\
    \ T> ostream &operator<<(ostream &os, const vector<T> &v) {\n    os << '{';\n\
    \    for(int i = 0; i < (int)v.size(); i++) {\n        if(i) { os << ','; }\n\
    \        os << v[i];\n    }\n    os << '}';\n    return os;\n}\nvoid debugg()\
    \ { cerr << endl; }\ntemplate <class T, class... Args>\nvoid debugg(const T &x,\
    \ const Args &... args) {\n    cerr << \" \" << x;\n    debugg(args...);\n}\n\
    #define debug(...)                                                           \
    \  \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]: \", debugg(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\nstruct Setup\
    \ {\n    Setup() {\n        cin.tie(0);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(15);\n    }\n} __Setup;\n\nusing ll = long\
    \ long;\n#define ALL(v) (v).begin(), (v).end()\n#define RALL(v) (v).rbegin(),\
    \ (v).rend()\n#define repl(i, a, b) for(int i = a; i < int(b); i++)\n#define rep(i,\
    \ n) repl(i, 0, n)\nconst int INF = 1 << 30;\nconst ll LLINF = 1LL << 60;\nconstexpr\
    \ int MOD = 1000000007;\nconst int dx[4] = {1, 0, -1, 0};\nconst int dy[4] = {0,\
    \ 1, 0, -1};\n\n//-------------------------------------\n#line 1 \"math/pollad-rho.hpp\"\
    \nstruct FastFactorize {\n    ll mul(ll a, ll b, ll c) { return (__int128)a *\
    \ b % c; }\n    ll power(ll a, ll b, ll mod) {\n        ll res = 1;\n        while(b)\
    \ {\n            if(b & 1) { res = mul(res, a, mod); }\n            a = mul(a,\
    \ a, mod);\n            b >>= 1;\n        }\n        return res;\n    }\n    bool\
    \ isPrime(ll n) {\n        if(!(n & 1) && n != 2) { return false; }\n        ll\
    \ d = n - 1;\n        int s = __builtin_ctzll(d);\n        d >>= s;\n        vector<int>\
    \ A;\n        if(n <= 1000000000) {\n            A = {2, 3, 5, 7};\n        }\
    \ else {\n            A = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};\n    \
    \    }\n        for(int a : A) {\n            ll p = power(a, d, n);\n       \
    \     int i = s;\n            while(p != 1 && p != n - 1 && a % n && (--i)) {\
    \ p = mul(p, p, n); }\n            if(p != n - 1 && i != s) { return false; }\n\
    \        }\n        return true;\n    }\n    ll rho(ll n) {\n        auto f =\
    \ [&](ll a) { return mul(a, a, n) + 1; };\n        ll x = 0, y = 0, p = 2, q;\n\
    \        int i = 1, t = 0;\n        while((t++) % 40 || gcd(p, n) == 1) {\n  \
    \          if(x == y) {\n                x = ++i;\n                y = f(x);\n\
    \            }\n            if(q = mul(p, abs(y - x), n)) { p = q; }\n       \
    \     x = f(x);\n            y = f(f(y));\n        }\n        return gcd(p, n);\n\
    \    }\n    vector<ll> factor(ll n) {\n        if(n == 1) { return {}; }\n   \
    \     if(isPrime(n)) { return {n}; }\n        ll a = rho(n);\n        assert(a\
    \ != n && a != 1);\n        auto l = factor(a), r = factor(n / a);\n        l.insert(l.end(),\
    \ r.begin(), r.end());\n        return l;\n    }\n    // \u672Averify, \u30D0\u30B0\
    \u3063\u3066\u308B\u304B\u3082\n    vector<ll> divisor(ll n) {\n        vector<ll>\
    \ res;\n        auto v = factor(n);\n        map<ll, int> cnt;\n        for(const\
    \ ll &a : v) cnt[a]++;\n        sort(ALL(v));\n        v.erase(unique(ALL(v)),\
    \ v.end());\n        int sz = int(v.size());\n\n        auto dfs = [&](auto &&dfs,\
    \ int d, ll now) -> void {\n            if(d == sz) {\n                res.emplace_back(now);\n\
    \                return;\n            }\n            ll nxt = now;\n         \
    \   dfs(dfs, d + 1, nxt);\n            rep(i, cnt[v[d]]) {\n                nxt\
    \ *= v[d];\n                dfs(dfs, d + 1, nxt);\n            }\n        };\n\
    \n        dfs(dfs, 0, 1);\n        sort(ALL(res));\n        return res;\n    }\n\
    };\n#line 4 \"test/fast_factorize.test.cpp\"\n\nint main() {\n    int q;\n   \
    \ cin >> q;\n    FastFactorize f;\n    while(q--) {\n        ll a;\n        cin\
    \ >> a;\n        auto v = f.factor(a);\n        sort(ALL(v));\n        cout <<\
    \ v.size() << \" \";\n        for(auto i : v) {\n            cout << i << \" \"\
    ;\n        }\n        cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n#include \"\
    ../template/template.cpp\"\n#include \"../math/pollad-rho.hpp\"\n\nint main()\
    \ {\n    int q;\n    cin >> q;\n    FastFactorize f;\n    while(q--) {\n     \
    \   ll a;\n        cin >> a;\n        auto v = f.factor(a);\n        sort(ALL(v));\n\
    \        cout << v.size() << \" \";\n        for(auto i : v) {\n            cout\
    \ << i << \" \";\n        }\n        cout << \"\\n\";\n    }\n}"
  dependsOn:
  - template/template.cpp
  - math/pollad-rho.hpp
  isVerificationFile: true
  path: test/fast_factorize.test.cpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/fast_factorize.test.cpp
layout: document
redirect_from:
- /verify/test/fast_factorize.test.cpp
- /verify/test/fast_factorize.test.cpp.html
title: test/fast_factorize.test.cpp
---
