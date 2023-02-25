---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind.hpp
    title: data-structure/unionfind.hpp
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/library-checker/data-structure/unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#line 1 \"template/template.cpp\"\
    \n#pragma region Macros\n#include <bits/stdc++.h>\nusing namespace std;\ntemplate\
    \ <class T> inline bool chmax(T &a, T b) {\n    if(a < b) {\n        a = b;\n\
    \        return 1;\n    }\n    return 0;\n}\ntemplate <class T> inline bool chmin(T\
    \ &a, T b) {\n    if(a > b) {\n        a = b;\n        return 1;\n    }\n    return\
    \ 0;\n}\n#ifdef DEBUG\ntemplate <class T, class U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p) {\n    os << '(' << p.first << ',' << p.second <<\
    \ ')';\n    return os;\n}\ntemplate <class T> ostream &operator<<(ostream &os,\
    \ const vector<T> &v) {\n    os << '{';\n    for(int i = 0; i < (int)v.size();\
    \ i++) {\n        if(i) { os << ','; }\n        os << v[i];\n    }\n    os <<\
    \ '}';\n    return os;\n}\nvoid debugg() { cerr << endl; }\ntemplate <class T,\
    \ class... Args>\nvoid debugg(const T &x, const Args &... args) {\n    cerr <<\
    \ \" \" << x;\n    debugg(args...);\n}\n#define debug(...)                   \
    \                                          \\\n    cerr << __LINE__ << \" [\"\
    \ << #__VA_ARGS__ << \"]: \", debugg(__VA_ARGS__)\n#define dump(x) cerr << __LINE__\
    \ << \" \" << #x << \" = \" << (x) << endl\n#else\n#define debug(...) (void(0))\n\
    #define dump(x) (void(0))\n#endif\n\nstruct Setup {\n    Setup() {\n        cin.tie(0);\n\
    \        ios::sync_with_stdio(false);\n        cout << fixed << setprecision(15);\n\
    \    }\n} __Setup;\n\nusing ll = long long;\n#define OVERLOAD3(_1, _2, _3, name,\
    \ ...) name\n#define ALL(v) (v).begin(), (v).end()\n#define RALL(v) (v).rbegin(),\
    \ (v).rend()\n#define REP1(i, n) for(int i = 0; i < int(n); i++)\n#define REP2(i,\
    \ a, b) for(int i = (a); i < int(b); i++)\n#define REP(...) OVERLOAD3(__VA_ARGS__,\
    \ REP2, REP1)(__VA_ARGS__)\n#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)),\
    \ (v).end())\n#define REVERSE(v) reverse(ALL(v))\n#define SZ(v) ((int)(v).size())\n\
    const int INF = 1 << 30;\nconst ll LLINF = 1LL << 60;\nconstexpr int MOD = 1000000007;\n\
    constexpr int MOD2 = 998244353;\nconst int dx[4] = {1, 0, -1, 0};\nconst int dy[4]\
    \ = {0, 1, 0, -1};\n\nvoid Case(int i) { cout << \"Case #\" << i << \": \"; }\n\
    int popcount(int x) { return __builtin_popcount(x); }\nll popcount(ll x) { return\
    \ __builtin_popcountll(x); }\n#pragma endregion Macros\n#line 2 \"data-structure/unionfind.hpp\"\
    \n\n#line 7 \"data-structure/unionfind.hpp\"\n\nclass UnionFind {\n  public:\n\
    \    UnionFind() = default;\n    explicit UnionFind(int n) : N(n), parent_or_size(n,\
    \ -1) {}\n    int leader(int u) {\n        assert(0 <= u && u < N);\n        if(parent_or_size[u]\
    \ < 0) return u;\n        return (parent_or_size[u] = leader(parent_or_size[u]));\n\
    \    }\n    bool same(int u, int v) { return (leader(u) == leader(v)); }\n   \
    \ bool merge(int u, int v) {\n        u = leader(u);\n        v = leader(v);\n\
    \        if(u == v) return false;\n        if(-parent_or_size[u] < -parent_or_size[v])\
    \ std::swap(u, v);\n        parent_or_size[u] += parent_or_size[v];\n        parent_or_size[v]\
    \ = u;\n        return true;\n    }\n    int size(int u) { return (-parent_or_size[leader(u)]);\
    \ }\n    std::vector<std::vector<int>> groups() {\n        std::vector<int> leaders(N),\
    \ group_size(N, 0);\n        for(int i = 0; i < N; i++) {\n            leaders[i]\
    \ = leader(i);\n            group_size[leaders[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ g(N);\n        for(int i = 0; i < N; i++) g[i].reserve(group_size[i]);\n   \
    \     for(int i = 0; i < N; i++) g[leaders[i]].push_back(i);\n        g.erase(std::remove_if(\n\
    \                    g.begin(), g.end(),\n                    [&](const std::vector<int>\
    \ &v) { return v.empty(); }),\n                g.end());\n        return g;\n\
    \    }\n    std::map<int, std::vector<int>> groups_with_map() {\n        std::map<int,\
    \ std::vector<int>> g;\n        for(int i = 0; i < N; i++) {\n            int\
    \ l = leader(i);\n            if(!g.count(l)) g[l].push_back(i);\n        }\n\
    \        return g;\n    }\n\n  private:\n    int N;\n    std::vector<int> parent_or_size;\n\
    };\n#line 4 \"test/library-checker/data-structure/unionfind.test.cpp\"\n\nint\
    \ main() {\n    int N, Q;\n    cin >> N >> Q;\n    UnionFind uf(N);\n    while(Q--)\
    \ {\n        int t, u, v;\n        cin >> t >> u >> v;\n        if(t == 0) {\n\
    \            uf.merge(u, v);\n        } else {\n            cout << (uf.same(u,\
    \ v) ? 1 : 0) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    ../../../template/template.cpp\"\n#include \"../../../data-structure/unionfind.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    UnionFind uf(N);\n  \
    \  while(Q--) {\n        int t, u, v;\n        cin >> t >> u >> v;\n        if(t\
    \ == 0) {\n            uf.merge(u, v);\n        } else {\n            cout <<\
    \ (uf.same(u, v) ? 1 : 0) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template/template.cpp
  - data-structure/unionfind.hpp
  isVerificationFile: true
  path: test/library-checker/data-structure/unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/data-structure/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/data-structure/unionfind.test.cpp
- /verify/test/library-checker/data-structure/unionfind.test.cpp.html
title: test/library-checker/data-structure/unionfind.test.cpp
---
