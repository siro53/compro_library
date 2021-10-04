---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/LiChaoTree.hpp
    title: Li Chao Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/line_add_get_min.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\
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
    #define REP(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)\n#define UNIQUE(v)\
    \ sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\nconst int INF = 1 << 30;\n\
    const ll LLINF = 1LL << 60;\nconstexpr int MOD = 1000000007;\nconst int dx[4]\
    \ = {1, 0, -1, 0};\nconst int dy[4] = {0, 1, 0, -1};\n\nvoid Case(int i) { cout\
    \ << \"Case #\" << i << \": \"; }\nint popcount(int x) { return __builtin_popcount(x);\
    \ }\nll popcount(ll x) { return __builtin_popcountll(x); }\n#pragma endregion\
    \ Macros\n#line 1 \"data_structure/LiChaoTree.hpp\"\ntemplate <typename T> struct\
    \ LiChaoTree {\n    struct Line {\n        T a, b;\n        Line(T _a, T _b) :\
    \ a(_a), b(_b) {}\n        inline T f(T x) const { return (a * x + b); }\n   \
    \ };\n    vector<T> X;\n    vector<Line> lines;\n    int n;\n    LiChaoTree()\
    \ {}\n    LiChaoTree(const vector<T> &_X, T _INF) : X(_X) {\n        n = 1;\n\
    \        while(n < X.size()) {\n            n <<= 1;\n        }\n        while(X.size()\
    \ < n) {\n            X.emplace_back(X.back() + 1);\n        }\n        lines.assign((n\
    \ << 1) - 1, Line(0, _INF));\n    }\n    void update(Line &line, int k, int l,\
    \ int r) {\n        int mid = (l + r) >> 1;\n        bool flg_l = (line.f(X[l])\
    \ < lines[k].f(X[l]));\n        bool flg_r = (line.f(X[mid]) < lines[k].f(X[mid]));\n\
    \        if(flg_r) {\n            swap(lines[k], line);\n        }\n        if(l\
    \ + 1 >= r) {\n            return;\n        }\n        if(flg_l != flg_r) {\n\
    \            update(line, 2 * k + 1, l, mid);\n        } else {\n            update(line,\
    \ 2 * k + 2, mid, r);\n        }\n    }\n    void add(T a, T b) {\n        Line\
    \ l(a, b);\n        update(l, 0, 0, n);\n    }\n    T query(int k) {\n       \
    \ const T x = X[k];\n        k += n - 1;\n        T ans = lines[k].f(x);\n   \
    \     while(k > 0) {\n            k = (k - 1) >> 1;\n            chmin(ans, lines[k].f(x));\n\
    \        }\n        return ans;\n    }\n};\n#line 4 \"test/line_add_get_min.test.cpp\"\
    \n\nusing PLL = pair<ll, ll>;\n\nint main() {\n    int N, Q;\n    cin >> N >>\
    \ Q;\n    vector<PLL> L(N);\n    for(int i = 0; i < N; i++) {\n        cin >>\
    \ L[i].first >> L[i].second;\n    }\n    vector<int> q_type(Q);\n    vector<PLL>\
    \ q(Q);\n    vector<ll> x;\n    for(int i = 0; i < Q; i++) {\n        cin >> q_type[i];\n\
    \        if(q_type[i] == 0) {\n            cin >> q[i].first >> q[i].second;\n\
    \        } else {\n            cin >> q[i].first;\n            x.emplace_back(q[i].first);\n\
    \        }\n    }\n    sort(ALL(x));\n    LiChaoTree<ll> lichao(x, LLINF);\n \
    \   for(int i = 0; i < N; i++) {\n        lichao.add(L[i].first, L[i].second);\n\
    \    }\n    for(int i = 0; i < Q; i++) {\n        if(q_type[i] == 0) {\n     \
    \       lichao.add(q[i].first, q[i].second);\n        } else {\n            int\
    \ id = lower_bound(ALL(x), q[i].first) - x.begin();\n            cout << lichao.query(id)\
    \ << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#include\
    \ \"../template/template.cpp\"\n#include \"../data_structure/LiChaoTree.hpp\"\n\
    \nusing PLL = pair<ll, ll>;\n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n\
    \    vector<PLL> L(N);\n    for(int i = 0; i < N; i++) {\n        cin >> L[i].first\
    \ >> L[i].second;\n    }\n    vector<int> q_type(Q);\n    vector<PLL> q(Q);\n\
    \    vector<ll> x;\n    for(int i = 0; i < Q; i++) {\n        cin >> q_type[i];\n\
    \        if(q_type[i] == 0) {\n            cin >> q[i].first >> q[i].second;\n\
    \        } else {\n            cin >> q[i].first;\n            x.emplace_back(q[i].first);\n\
    \        }\n    }\n    sort(ALL(x));\n    LiChaoTree<ll> lichao(x, LLINF);\n \
    \   for(int i = 0; i < N; i++) {\n        lichao.add(L[i].first, L[i].second);\n\
    \    }\n    for(int i = 0; i < Q; i++) {\n        if(q_type[i] == 0) {\n     \
    \       lichao.add(q[i].first, q[i].second);\n        } else {\n            int\
    \ id = lower_bound(ALL(x), q[i].first) - x.begin();\n            cout << lichao.query(id)\
    \ << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - template/template.cpp
  - data_structure/LiChaoTree.hpp
  isVerificationFile: true
  path: test/line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2021-10-04 10:02:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/line_add_get_min.test.cpp
- /verify/test/line_add_get_min.test.cpp.html
title: test/line_add_get_min.test.cpp
---
