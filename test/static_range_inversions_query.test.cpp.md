---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/BIT.hpp
    title: data_structure/BIT.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/compress.hpp
    title: data_structure/compress.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/mo.hpp
    title: Mo's Algorithm
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/static_range_inversions_query.test.cpp\"\n#pragma GCC\
    \ target(\"avx2\")\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
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
    \ long;\n#define ALL(v) (v).begin(), (v).end()\n#define RALL(v) (v).rbegin(),\
    \ (v).rend()\n#define FOR(i, a, b) for(int i = (a); i < int(b); i++)\n#define\
    \ REP(i, n) FOR(i, 0, n)\nconst int INF = 1 << 30;\nconst ll LLINF = 1LL << 60;\n\
    constexpr int MOD = 1000000007;\nconst int dx[4] = {1, 0, -1, 0};\nconst int dy[4]\
    \ = {0, 1, 0, -1};\n\nvoid Case(int i) { cout << \"Case #\" << i << \": \"; }\n\
    int popcount(int x) { return __builtin_popcount(x); }\nll popcount(ll x) { return\
    \ __builtin_popcountll(x); }\n#pragma endregion Macros\n#line 1 \"data_structure/mo.hpp\"\
    \nclass Mo {\n  private:\n    vector<int> L, R, ord;\n    int BUCKET_SIZE;// bucket\
    \ size\n    int nl, nr, ptr;\n\n  public:\n    Mo(int N) : BUCKET_SIZE(sqrt(N)),\
    \ nl(0), nr(0), ptr(0) {}\n\n    // [l, r)\n    void insert(int l, int r) {\n\
    \        L.push_back(l);\n        R.push_back(r);\n    }\n    // \u30AF\u30A8\u30EA\
    \u3092sort\u3059\u308B\n    void build() {\n        ord.resize(L.size());\n  \
    \      iota(ALL(ord), 0);\n        sort(ALL(ord), [&](int l, int r) {\n      \
    \      if(L[l] / BUCKET_SIZE != L[r] / BUCKET_SIZE)\n                return (L[l]\
    \ < L[r]);\n            else\n                return (R[l] < R[r]);\n        });\n\
    \    }\n    // \u30AF\u30A8\u30EA\u30921\u3064\u9032\u3081\u308B, \u8FD4\u308A\
    \u5024\u306F\u30AF\u30A8\u30EA\u306Eid\n    int process() {\n        if(ptr ==\
    \ ord.size()) return -1;\n        int qid = ord[ptr];\n        while(nl > L[qid])\
    \ add_left(--nl);\n        while(nr < R[qid]) add_right(nr++);\n        while(nl\
    \ < L[qid]) del_left(nl++);\n        while(nr > R[qid]) del_right(--nr);\n   \
    \     return ord[ptr++];\n    }\n\n    void add_left(int id);\n    void add_right(int\
    \ id);\n    void del_left(int id);\n    void del_right(int id);\n};\n#line 1 \"\
    data_structure/compress.hpp\"\ntemplate <typename T> struct Compress {\n    vector<T>\
    \ v;\n    Compress() {}\n    Compress(vector<T> vv) : v(vv) {\n        sort(ALL(v));\n\
    \        v.erase(unique(ALL(v)), end(v));\n    }\n    void build(vector<T> vv)\
    \ {\n        v = vv;\n        sort(ALL(v));\n        v.erase(unique(ALL(v)), end(v));\n\
    \    }\n    int get(T x) { return (int)(lower_bound(ALL(v), x) - v.begin()); }\n\
    \    T &operator[](int i) { return v[i]; }\n    size_t size() { return v.size();\
    \ }\n};\n#line 1 \"data_structure/BIT.hpp\"\ntemplate <typename T> struct BIT\
    \ {\n    int n;\n    vector<T> bit;\n    BIT(int _n) { init(_n); }\n    void init(int\
    \ _n) {\n        n = _n + 1;\n        bit.resize(n + 1, 0);\n    }\n    // [0,\
    \ k)\n    T sum(int k) {\n        T res = 0;\n        for(int i = k - 1; i >=\
    \ 0; i = (i & (i + 1)) - 1) { res += bit[i]; }\n        return res;\n    }\n \
    \   // [l, r)\n    T sum(int l, int r) { return (l < r ? sum(r) - sum(l) : 0);\
    \ }\n    // bit[k] += x\n    void add(int k, T x) {\n        for(int i = k; i\
    \ < n; i |= i + 1) { bit[i] += x; }\n    }\n    // v[0] + ... + v[res] >= x\n\
    \    int lower_bound(T x) {\n        int res = -1;\n        int k = 1;\n     \
    \   while(2 * k <= n) { k <<= 1; }\n        for(; k > 0; k >>= 1) {\n        \
    \    if(res + k < n && bit[res + k] < x) {\n                x -= bit[res + k];\n\
    \                res += k;\n            }\n        }\n        return res + 1;\n\
    \    }\n};\n#line 9 \"test/static_range_inversions_query.test.cpp\"\n\nint N,\
    \ Q;\nvector<int> a;\nvector<ll> ans;\nCompress<int> comp;\nBIT<int> bt(1);\n\
    ll now_ans;\n\nvoid Mo::add_right(int id) {\n    int p = a[id];\n    now_ans +=\
    \ bt.sum(p+1, comp.size());\n    bt.add(p, 1);\n}\n\nvoid Mo::add_left(int id)\
    \ {\n    int p = a[id];\n    now_ans += bt.sum(0, p);\n    bt.add(p, 1);\n}\n\n\
    void Mo::del_left(int id) {\n    int p = a[id];\n    now_ans -= bt.sum(0, p);\n\
    \    bt.add(p, -1);\n}\n\nvoid Mo::del_right(int id) {\n    int p = a[id];\n \
    \   now_ans -= bt.sum(p+1, comp.size());\n    bt.add(p, -1);\n}\n\nint main()\
    \ {\n    cin >> N >> Q;\n    a.resize(N);\n    REP(i, N) cin >> a[i];\n    comp\
    \ = Compress<int>(a);\n    REP(i, N) a[i] = comp.get(a[i]);\n    bt.init(comp.size());\n\
    \n    ans.resize(Q);\n    Mo mo(N);\n    REP(_, Q) {\n        int l, r;\n    \
    \    cin >> l >> r;\n        mo.insert(l, r);\n    }\n    mo.build();\n    now_ans\
    \ = 0;\n    REP(i, Q) {\n        int qid = mo.process();\n        ans[qid] = now_ans;\n\
    \    }\n\n    REP(i, Q) cout << ans[i] << \"\\n\";\n}\n"
  code: "#pragma GCC target(\"avx2\")\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"\
    unroll-loops\")\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n#include \"../template/template.cpp\"\n#include \"../data_structure/mo.hpp\"\
    \n#include \"../data_structure/compress.hpp\"\n#include \"../data_structure/BIT.hpp\"\
    \n\nint N, Q;\nvector<int> a;\nvector<ll> ans;\nCompress<int> comp;\nBIT<int>\
    \ bt(1);\nll now_ans;\n\nvoid Mo::add_right(int id) {\n    int p = a[id];\n  \
    \  now_ans += bt.sum(p+1, comp.size());\n    bt.add(p, 1);\n}\n\nvoid Mo::add_left(int\
    \ id) {\n    int p = a[id];\n    now_ans += bt.sum(0, p);\n    bt.add(p, 1);\n\
    }\n\nvoid Mo::del_left(int id) {\n    int p = a[id];\n    now_ans -= bt.sum(0,\
    \ p);\n    bt.add(p, -1);\n}\n\nvoid Mo::del_right(int id) {\n    int p = a[id];\n\
    \    now_ans -= bt.sum(p+1, comp.size());\n    bt.add(p, -1);\n}\n\nint main()\
    \ {\n    cin >> N >> Q;\n    a.resize(N);\n    REP(i, N) cin >> a[i];\n    comp\
    \ = Compress<int>(a);\n    REP(i, N) a[i] = comp.get(a[i]);\n    bt.init(comp.size());\n\
    \n    ans.resize(Q);\n    Mo mo(N);\n    REP(_, Q) {\n        int l, r;\n    \
    \    cin >> l >> r;\n        mo.insert(l, r);\n    }\n    mo.build();\n    now_ans\
    \ = 0;\n    REP(i, Q) {\n        int qid = mo.process();\n        ans[qid] = now_ans;\n\
    \    }\n\n    REP(i, Q) cout << ans[i] << \"\\n\";\n}"
  dependsOn:
  - template/template.cpp
  - data_structure/mo.hpp
  - data_structure/compress.hpp
  - data_structure/BIT.hpp
  isVerificationFile: true
  path: test/static_range_inversions_query.test.cpp
  requiredBy: []
  timestamp: '2021-09-04 15:32:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/static_range_inversions_query.test.cpp
layout: document
redirect_from:
- /verify/test/static_range_inversions_query.test.cpp
- /verify/test/static_range_inversions_query.test.cpp.html
title: test/static_range_inversions_query.test.cpp
---
