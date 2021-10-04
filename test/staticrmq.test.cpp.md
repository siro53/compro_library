---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/segtree/segtree.hpp
    title: data_structure/segtree/segtree.hpp
  - icon: ':question:'
    path: template/template.cpp
    title: "\u7AF6\u30D7\u30ED\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    \ i = 0; i < (n); i++)\n#define REP2(i, a, b) for(int i = (a); i < int(b); i++)\n\
    #define REP(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)\n#define UNIQUE(v)\
    \ sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\nconst int INF = 1 << 30;\n\
    const ll LLINF = 1LL << 60;\nconstexpr int MOD = 1000000007;\nconst int dx[4]\
    \ = {1, 0, -1, 0};\nconst int dy[4] = {0, 1, 0, -1};\n\nvoid Case(int i) { cout\
    \ << \"Case #\" << i << \": \"; }\nint popcount(int x) { return __builtin_popcount(x);\
    \ }\nll popcount(ll x) { return __builtin_popcountll(x); }\n#pragma endregion\
    \ Macros\n#line 4 \"test/staticrmq.test.cpp\"\n\n#line 1 \"data_structure/segtree/segtree.hpp\"\
    \ntemplate <typename Monoid> struct SegmentTree {\n    using F = function<Monoid(Monoid,\
    \ Monoid)>;\n\n  private:\n    int n;\n    vector<Monoid> node;\n    Monoid E;\n\
    \    F f;\n\n  public:\n    SegmentTree(vector<Monoid> &v, Monoid e, const F func)\
    \ : f(func), E(e) {\n        int sz = v.size();\n        n = 1;\n        while(n\
    \ < sz) {\n            n *= 2;\n        }\n        node.resize(2 * n - 1, E);\n\
    \        for(int i = 0; i < sz; i++) {\n            node[i + n - 1] = v[i];\n\
    \        }\n        for(int i = n - 2; i >= 0; i--) {\n            node[i] = f(node[2\
    \ * i + 1], node[2 * i + 2]);\n        }\n    }\n\n    void update(int i, Monoid\
    \ val) {\n        i += (n - 1);\n        node[i] = val;\n        while(i > 0)\
    \ {\n            i = (i - 1) / 2;\n            node[i] = f(node[2 * i + 1], node[2\
    \ * i + 2]);\n        }\n    }\n\n    Monoid query(int a, int b, int i = 0, int\
    \ l = 0, int r = -1) {\n        if(r < 0) {\n            r = n;\n        }\n \
    \       if(r <= a || b <= l) {\n            return E;\n        }\n        if(a\
    \ <= l && r <= b) {\n            return node[i];\n        }\n        Monoid vl\
    \ = query(a, b, 2 * i + 1, l, (l + r) / 2);\n        Monoid vr = query(a, b, 2\
    \ * i + 2, (l + r) / 2, r);\n        return f(vl, vr);\n    }\n\n    Monoid operator[](const\
    \ int &i) const { return node[i + n - 1]; }\n};\n#line 6 \"test/staticrmq.test.cpp\"\
    \n\nint main(){\n    int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n  \
    \  for(int i = 0; i < n; i++) {\n        cin >> a[i];\n    }\n    SegmentTree<int>\
    \ seg(a, INF,\n                         [](const int &p, const int &q) { return\
    \ min(p, q); });\n    int l, r;\n    while(q--) {\n        cin >> l >> r;\n  \
    \      cout << seg.query(l, r) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../template/template.cpp\"\n\n#include \"../data_structure/segtree/segtree.hpp\"\
    \n\nint main(){\n    int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n  \
    \  for(int i = 0; i < n; i++) {\n        cin >> a[i];\n    }\n    SegmentTree<int>\
    \ seg(a, INF,\n                         [](const int &p, const int &q) { return\
    \ min(p, q); });\n    int l, r;\n    while(q--) {\n        cin >> l >> r;\n  \
    \      cout << seg.query(l, r) << \"\\n\";\n    }\n}"
  dependsOn:
  - template/template.cpp
  - data_structure/segtree/segtree.hpp
  isVerificationFile: true
  path: test/staticrmq.test.cpp
  requiredBy: []
  timestamp: '2021-10-04 10:02:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/test/staticrmq.test.cpp
- /verify/test/staticrmq.test.cpp.html
title: test/staticrmq.test.cpp
---
