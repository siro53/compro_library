---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/swag.hpp
    title: SWAG
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: "\u7AF6\u30D7\u30ED\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/queue_operate_all_compose.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\n#line 1 \"\
    template/template.cpp\"\n#pragma region Macros\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\ntemplate <class T> inline bool chmax(T &a, T b) {\n    if(a\
    \ < b) {\n        a = b;\n        return 1;\n    }\n    return 0;\n}\ntemplate\
    \ <class T> inline bool chmin(T &a, T b) {\n    if(a > b) {\n        a = b;\n\
    \        return 1;\n    }\n    return 0;\n}\n#ifdef DEBUG\ntemplate <class T,\
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
    \ long;\n#define OVERLOAD3(_1, _2, _3, name, ...) name\n#define ALL(v) (v).begin(),\
    \ (v).end()\n#define RALL(v) (v).rbegin(), (v).rend()\n#define REP1(i, n) for(int\
    \ i = 0; i < int(n); i++)\n#define REP2(i, a, b) for(int i = (a); i < int(b);\
    \ i++)\n#define REP(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)\n#define\
    \ UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\n#define SZ(v)\
    \ ((int)(v).size())\nconst int INF = 1 << 30;\nconst ll LLINF = 1LL << 60;\nconstexpr\
    \ int MOD = 1000000007;\nconstexpr int MOD2 = 998244353;\nconst int dx[4] = {1,\
    \ 0, -1, 0};\nconst int dy[4] = {0, 1, 0, -1};\n\nvoid Case(int i) { cout << \"\
    Case #\" << i << \": \"; }\nint popcount(int x) { return __builtin_popcount(x);\
    \ }\nll popcount(ll x) { return __builtin_popcountll(x); }\n#pragma endregion\
    \ Macros\n#line 1 \"data_structure/swag.hpp\"\ntemplate <typename T> struct SWAG\
    \ {\n    struct Data {\n        T x, sum;\n        Data() {}\n        Data(T x,\
    \ T sum) : x(x), sum(sum) {}\n    };\n    using F = function<T(T, T)>;\n    stack<Data>\
    \ frontStack, backStack;\n    F f;\n\n    SWAG(F f) : f(f) {}\n\n    bool empty()\
    \ { return (frontStack.empty() && backStack.empty()); }\n\n    size_t size() {\
    \ return frontStack.size() + backStack.size(); }\n\n    void pop() {\n       \
    \ assert(!empty());\n        if(frontStack.empty()) {\n            frontStack.emplace(backStack.top().x,\
    \ backStack.top().x);\n            backStack.pop();\n            while(!backStack.empty())\
    \ {\n                T s = f(backStack.top().x, frontStack.top().sum);\n     \
    \           frontStack.emplace(backStack.top().x, s);\n                backStack.pop();\n\
    \            }\n        }\n        frontStack.pop();\n    }\n\n    void push(T\
    \ val) {\n        if(backStack.empty()) {\n            backStack.emplace(val,\
    \ val);\n        } else {\n            T s = f(backStack.top().sum, val);\n  \
    \          backStack.emplace(val, s);\n        }\n    }\n\n    T fold_all() {\n\
    \        assert(!empty());\n        if(frontStack.empty()) {\n            return\
    \ backStack.top().sum;\n        } else if(backStack.empty()) {\n            return\
    \ frontStack.top().sum;\n        } else {\n            return f(frontStack.top().sum,\
    \ backStack.top().sum);\n        }\n    }\n};\n#line 1 \"math/modint.hpp\"\ntemplate\
    \ <int mod> struct ModInt {\n    int x;\n    ModInt() : x(0) {}\n    ModInt(int64_t\
    \ y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n    ModInt &operator+=(const\
    \ ModInt &p) {\n        if((x += p.x) >= mod)\n            x -= mod;\n       \
    \ return *this;\n    }\n    ModInt &operator-=(const ModInt &p) {\n        if((x\
    \ += mod - p.x) >= mod)\n            x -= mod;\n        return *this;\n    }\n\
    \    ModInt &operator*=(const ModInt &p) {\n        x = (int)(1LL * x * p.x %\
    \ mod);\n        return *this;\n    }\n    ModInt &operator/=(const ModInt &p)\
    \ {\n        *this *= p.inv();\n        return *this;\n    }\n    ModInt operator-()\
    \ const { return ModInt(-x); }\n    ModInt operator+(const ModInt &p) const {\
    \ return ModInt(*this) += p; }\n    ModInt operator-(const ModInt &p) const {\
    \ return ModInt(*this) -= p; }\n    ModInt operator*(const ModInt &p) const {\
    \ return ModInt(*this) *= p; }\n    ModInt operator/(const ModInt &p) const {\
    \ return ModInt(*this) /= p; }\n    bool operator==(const ModInt &p) const { return\
    \ x == p.x; }\n    bool operator!=(const ModInt &p) const { return x != p.x; }\n\
    \    ModInt inv() const {\n        int a = x, b = mod, u = 1, v = 0, t;\n    \
    \    while(b > 0) {\n            t = a / b;\n            swap(a -= t * b, b);\n\
    \            swap(u -= t * v, v);\n        }\n        return ModInt(u);\n    }\n\
    \    ModInt pow(int64_t n) const {\n        ModInt ret(1), mul(x);\n        while(n\
    \ > 0) {\n            if(n & 1)\n                ret *= mul;\n            mul\
    \ *= mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n    friend\
    \ ostream &operator<<(ostream &os, const ModInt &p) {\n        return os << p.x;\n\
    \    }\n    friend istream &operator>>(istream &is, ModInt &a) {\n        int64_t\
    \ t;\n        is >> t;\n        a = ModInt<mod>(t);\n        return (is);\n  \
    \  }\n    static int get_mod() { return mod; }\n};\n#line 5 \"test/queue_operate_all_compose.test.cpp\"\
    \n\nusing mint = ModInt<998244353>;\nusing P = pair<mint, mint>;\n\nint main()\
    \ {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int q;\n    cin >>\
    \ q;\n    auto f = [](const P &a, const P &b) {\n        return P(a.first * b.first,\
    \ b.first * a.second + b.second);\n    };\n    SWAG<P> swag(f);\n    while(q--)\
    \ {\n        int t;\n        cin >> t;\n        if(t == 0) {\n            mint\
    \ A, B;\n            cin >> A >> B;\n            swag.push(P(A, B));\n       \
    \ } else if(t == 1) {\n            swag.pop();\n        } else {\n           \
    \ mint X;\n            cin >> X;\n            if(swag.empty()) {\n           \
    \     cout << X << \"\\n\";\n            } else {\n                P g = swag.fold_all();\n\
    \                cout << g.first * X + g.second << \"\\n\";\n            }\n \
    \       }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#include \"../template/template.cpp\"\n#include \"../data_structure/swag.hpp\"\
    \n#include \"../math/modint.hpp\"\n\nusing mint = ModInt<998244353>;\nusing P\
    \ = pair<mint, mint>;\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int q;\n    cin >> q;\n    auto f = [](const P &a, const P &b) {\n      \
    \  return P(a.first * b.first, b.first * a.second + b.second);\n    };\n    SWAG<P>\
    \ swag(f);\n    while(q--) {\n        int t;\n        cin >> t;\n        if(t\
    \ == 0) {\n            mint A, B;\n            cin >> A >> B;\n            swag.push(P(A,\
    \ B));\n        } else if(t == 1) {\n            swag.pop();\n        } else {\n\
    \            mint X;\n            cin >> X;\n            if(swag.empty()) {\n\
    \                cout << X << \"\\n\";\n            } else {\n               \
    \ P g = swag.fold_all();\n                cout << g.first * X + g.second << \"\
    \\n\";\n            }\n        }\n    }\n}"
  dependsOn:
  - template/template.cpp
  - data_structure/swag.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/queue_operate_all_compose.test.cpp
  requiredBy: []
  timestamp: '2021-11-14 12:43:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/queue_operate_all_compose.test.cpp
layout: document
redirect_from:
- /verify/test/queue_operate_all_compose.test.cpp
- /verify/test/queue_operate_all_compose.test.cpp.html
title: test/queue_operate_all_compose.test.cpp
---
