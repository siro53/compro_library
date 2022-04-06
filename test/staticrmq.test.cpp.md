---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree/segtree.hpp
    title: data_structure/segtree/segtree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/staticrmq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#line 1 \"template/template.cpp\"\n#pragma region Macros\n#include <bits/stdc++.h>\n\
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
    \ i = 0; i < int(n); i++)\n#define REP2(i, a, b) for(int i = (a); i < int(b);\
    \ i++)\n#define REP(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)\n#define\
    \ UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\n#define SZ(v)\
    \ ((int)(v).size())\nconst int INF = 1 << 30;\nconst ll LLINF = 1LL << 60;\nconstexpr\
    \ int MOD = 1000000007;\nconstexpr int MOD2 = 998244353;\nconst int dx[4] = {1,\
    \ 0, -1, 0};\nconst int dy[4] = {0, 1, 0, -1};\n\nvoid Case(int i) { cout << \"\
    Case #\" << i << \": \"; }\nint popcount(int x) { return __builtin_popcount(x);\
    \ }\nll popcount(ll x) { return __builtin_popcountll(x); }\n#pragma endregion\
    \ Macros\n#line 1 \"data_structure/segtree/segtree.hpp\"\ntemplate <class S, S\
    \ (*op)(S, S), S (*e)()> class segtree {\n    int N, sz;\n    vector<S> node;\n\
    \n  public:\n    segtree() {}\n    segtree(vector<S> v) : N(int(v.size())) {\n\
    \        sz = 1;\n        while(sz < N) sz <<= 1;\n        node.resize(2 * sz,\
    \ e());\n        for(int i = 0; i < N; i++) node[i + sz] = v[i];\n        for(int\
    \ i = sz - 1; i >= 1; i--)\n            node[i] = op(node[2 * i], node[2 * i +\
    \ 1]);\n    }\n    segtree(int n) : segtree(vector<S>(n, e())) {}\n    void set(int\
    \ p, S val) {\n        p += sz;\n        node[p] = val;\n        while(p >>= 1)\
    \ node[p] = op(node[2 * p], node[2 * p + 1]);\n    }\n    S get(int p) { return\
    \ node[p + sz]; }\n    S prod(int l, int r) {\n        S vl = e(), vr = e();\n\
    \        for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {\n            if(l &\
    \ 1) vl = op(vl, node[l++]);\n            if(r & 1) vr = op(node[--r], vr);\n\
    \        }\n        return op(vl, vr);\n    }\n    S all_prod() { return node[1];\
    \ }\n};\n#line 5 \"test/staticrmq.test.cpp\"\n\nint op(int a, int b) { return\
    \ min(a, b); }\nint e() { return INF; }\n\nint main(){\n    int n, q;\n    cin\
    \ >> n >> q;\n    vector<int> a(n);\n    for(int i = 0; i < n; i++) {\n      \
    \  cin >> a[i];\n    }\n    segtree<int, op, e> seg(a);\n    while(q--) {\n  \
    \      int l, r;\n        cin >> l >> r;\n        cout << seg.prod(l, r) << '\\\
    n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../template/template.cpp\"\n#include \"../data_structure/segtree/segtree.hpp\"\
    \n\nint op(int a, int b) { return min(a, b); }\nint e() { return INF; }\n\nint\
    \ main(){\n    int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n    for(int\
    \ i = 0; i < n; i++) {\n        cin >> a[i];\n    }\n    segtree<int, op, e> seg(a);\n\
    \    while(q--) {\n        int l, r;\n        cin >> l >> r;\n        cout <<\
    \ seg.prod(l, r) << '\\n';\n    }\n}"
  dependsOn:
  - template/template.cpp
  - data_structure/segtree/segtree.hpp
  isVerificationFile: true
  path: test/staticrmq.test.cpp
  requiredBy: []
  timestamp: '2022-04-06 16:25:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/test/staticrmq.test.cpp
- /verify/test/staticrmq.test.cpp.html
title: test/staticrmq.test.cpp
---
