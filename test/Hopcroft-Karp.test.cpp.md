---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bipartite_matching.hpp
    title: "Hopcroft-Karp algorithm(\u4E8C\u90E8\u30DE\u30C3\u30C1\u30F3\u30B0)"
  - icon: ':question:'
    path: template/template.cpp
    title: "\u7AF6\u30D7\u30ED\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/Hopcroft-Karp.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\
    \n#line 1 \"template/template.cpp\"\n#pragma region Macros\n#include <bits/stdc++.h>\n\
    using namespace std;\ntemplate <class T> inline bool chmax(T &a, T b) {\n    if(a\
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
    \ i = 0; i < (n); i++)\n#define REP2(i, a, b) for(int i = (a); i < int(b); i++)\n\
    #define REP(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)\nconst int INF\
    \ = 1 << 30;\nconst ll LLINF = 1LL << 60;\nconstexpr int MOD = 1000000007;\nconst\
    \ int dx[4] = {1, 0, -1, 0};\nconst int dy[4] = {0, 1, 0, -1};\n\nvoid Case(int\
    \ i) { cout << \"Case #\" << i << \": \"; }\nint popcount(int x) { return __builtin_popcount(x);\
    \ }\nll popcount(ll x) { return __builtin_popcountll(x); }\n#pragma endregion\
    \ Macros\n#line 1 \"graph/bipartite_matching.hpp\"\nstruct BipartiteMatching {\n\
    \    int L, R;\n    vector<int> l, r, d;\n    vector<bool> seen;\n    vector<vector<int>>\
    \ G;\n\n    BipartiteMatching(int L, int R)\n        : L(L), R(R), l(L, -1), r(R,\
    \ -1), d(L), seen(L), G(L) {}\n\n    void add_edge(int _l, int _r) { G[_l].emplace_back(_r);\
    \ }\n\n    void bfs() {\n        vector<int> que;\n        int head = 0, tail\
    \ = 0;\n        fill(d.begin(), d.end(), -1);\n        for(int i = 0; i < L; i++)\
    \ {\n            if(l[i] == -1) {\n                que.emplace_back(i), tail++;\n\
    \                d[i] = 0;\n            }\n        }\n        while(head != tail)\
    \ {\n            int v = que[head++];\n            for(const auto &u : G[v]) {\n\
    \                if(r[u] != -1 && d[r[u]] == -1) {\n                    d[r[u]]\
    \ = d[v] + 1;\n                    que.emplace_back(r[u]), tail++;\n         \
    \       }\n            }\n        }\n    }\n\n    bool dfs(int v) {\n        if(seen[v])\
    \ return false;\n        seen[v] = true;\n        for(const auto &u : G[v]) {\n\
    \            if(r[u] == -1 || (d[r[u]] == d[v] + 1 && dfs(r[u]))) {\n        \
    \        l[v] = u;\n                r[u] = v;\n                return true;\n\
    \            }\n        }\n        return false;\n    }\n\n    int matching()\
    \ {\n        int res = 0;\n        while(1) {\n            bfs();\n          \
    \  fill(seen.begin(), seen.end(), false);\n            int f = 0;\n          \
    \  for(int i = 0; i < L; i++) {\n                if(l[i] == -1 && dfs(i)) f++;\n\
    \            }\n            if(f == 0) return res;\n            res += f;\n  \
    \      }\n    }\n};\n#line 4 \"test/Hopcroft-Karp.test.cpp\"\n\nint main() {\n\
    \    int L, R, M;\n    cin >> L >> R >> M;\n    BipartiteMatching G(L, R);\n \
    \   for(int i = 0; i < M; i++) {\n        int a, b;\n        cin >> a >> b;\n\
    \        G.add_edge(a, b);\n    }\n    cout << G.matching() << \"\\n\";\n    for(int\
    \ i = 0; i < L; i++) {\n        if(G.l[i] != -1) {\n            cout << i << \"\
    \ \" << G.l[i] << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
    \ \"../template/template.cpp\"\n#include \"../graph/bipartite_matching.hpp\"\n\
    \nint main() {\n    int L, R, M;\n    cin >> L >> R >> M;\n    BipartiteMatching\
    \ G(L, R);\n    for(int i = 0; i < M; i++) {\n        int a, b;\n        cin >>\
    \ a >> b;\n        G.add_edge(a, b);\n    }\n    cout << G.matching() << \"\\\
    n\";\n    for(int i = 0; i < L; i++) {\n        if(G.l[i] != -1) {\n         \
    \   cout << i << \" \" << G.l[i] << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - template/template.cpp
  - graph/bipartite_matching.hpp
  isVerificationFile: true
  path: test/Hopcroft-Karp.test.cpp
  requiredBy: []
  timestamp: '2021-10-01 13:55:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Hopcroft-Karp.test.cpp
layout: document
redirect_from:
- /verify/test/Hopcroft-Karp.test.cpp
- /verify/test/Hopcroft-Karp.test.cpp.html
title: test/Hopcroft-Karp.test.cpp
---
