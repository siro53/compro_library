---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/BIT.hpp
    title: data-structure/BIT.hpp
  - icon: ':heavy_check_mark:'
    path: misc/compress.hpp
    title: misc/compress.hpp
  - icon: ':heavy_check_mark:'
    path: misc/mo.hpp
    title: misc/mo.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/library-checker/data-structure/static-range-inversions-query.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n#line 2 \"data-structure/BIT.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \ntemplate <typename T> class BIT {\n  public:\n    BIT() = default;\n    explicit\
    \ BIT(int N) : N(N), dat(N + 1, 0) {}\n    T sum(int r) {\n        T ret = 0;\n\
    \        for(; r >= 1; r -= lsb(r)) ret += dat[r];\n        return ret;\n    }\n\
    \    T sum(int l, int r) {\n        assert(l <= r);\n        if(l == r) return\
    \ T(0);\n        return (sum(r) - sum(l));\n    }\n    void add(int pos, T val)\
    \ {\n        for(int i = pos + 1; i <= N; i += lsb(i)) dat[i] += val;\n    }\n\
    \    int lower_bound(T val) {\n        int pos = 0;\n        int k = 1;\n    \
    \    while(2 * k <= N) k <<= 1;\n        for(; k >= 1; k >>= 1) {\n          \
    \  if(pos + k <= N and dat[pos + k] < val) {\n                pos += k;\n    \
    \            val -= dat[pos];\n            }\n        }\n        return pos +\
    \ 1;\n    }\n\n  private:\n    int N;\n    std::vector<T> dat;\n\n    inline int\
    \ lsb(int i) { return i & (-i); }\n};\n#line 2 \"misc/compress.hpp\"\n\n#include\
    \ <algorithm>\n#line 5 \"misc/compress.hpp\"\n\ntemplate <typename T> class Compress\
    \ {\n  public:\n    Compress() = default;\n    explicit Compress(const std::vector<T>\
    \ &v) : dat(v) {\n        std::sort(dat.begin(), dat.end());\n        dat.erase(std::unique(dat.begin(),\
    \ dat.end()), dat.end());\n    }\n    int get(T val) const {\n        int pos\
    \ = std::lower_bound(dat.begin(), dat.end(), val) - dat.begin();\n        return\
    \ pos;\n    }\n    T operator[](const int &i) const { return dat[i]; }\n    size_t\
    \ size() const { return dat.size(); }\n\n  private:\n    std::vector<T> dat;\n\
    };\n#line 2 \"misc/mo.hpp\"\n\n#line 5 \"misc/mo.hpp\"\n#include <cmath>\n#include\
    \ <numeric>\n#line 8 \"misc/mo.hpp\"\n\nclass Mo {\n  public:\n    explicit Mo(int\
    \ n)\n        : n(n), l(0), r(0), idx(0), BUCKET_SIZE(std::sqrt(n)), isBuilt(false)\
    \ {}\n    void insert(int l, int r) {\n        assert(0 <= l and l < r and r <=\
    \ n);\n        L.push_back(l);\n        R.push_back(r);\n    }\n    void set_bucketsize(int\
    \ bs) {\n        assert(!isBuilt);\n        BUCKET_SIZE = std::max(1, bs);\n \
    \   }\n    void build() {\n        ord.resize(L.size());\n        std::iota(ord.begin(),\
    \ ord.end(), 0);\n        std::sort(ord.begin(), ord.end(), [&](int a, int b)\
    \ {\n            if(L[a] / BUCKET_SIZE != L[b] / BUCKET_SIZE) {\n            \
    \    return (L[a] < L[b]);\n            }\n            return (R[a] < R[b]);\n\
    \        });\n        isBuilt = true;\n    }\n    template <class AddLeft, class\
    \ AddRight, class DelLeft, class DelRight>\n    int process(const AddLeft &add_left,\
    \ const AddRight &add_right,\n                const DelLeft &del_left, const DelRight\
    \ &del_right) {\n        assert(isBuilt);\n        if(idx == (int)ord.size())\
    \ return -1;\n        int qid = ord[idx++];\n        while(l > L[qid]) add_left(--l);\n\
    \        while(l < L[qid]) del_left(l++);\n        while(r < R[qid]) add_right(r++);\n\
    \        while(r > R[qid]) del_right(--r);\n        return qid;\n    }\n\n  private:\n\
    \    std::vector<int> L, R, ord;\n    int n, l, r, idx;\n    int BUCKET_SIZE;\n\
    \    bool isBuilt;\n};\n#line 1 \"template/template.cpp\"\n#pragma region Macros\n\
    #include <bits/stdc++.h>\nusing namespace std;\ntemplate <class T> inline bool\
    \ chmax(T &a, T b) {\n    if(a < b) {\n        a = b;\n        return 1;\n   \
    \ }\n    return 0;\n}\ntemplate <class T> inline bool chmin(T &a, T b) {\n   \
    \ if(a > b) {\n        a = b;\n        return 1;\n    }\n    return 0;\n}\n#ifdef\
    \ DEBUG\ntemplate <class T, class U>\nostream &operator<<(ostream &os, const pair<T,\
    \ U> &p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return os;\n\
    }\ntemplate <class T> ostream &operator<<(ostream &os, const vector<T> &v) {\n\
    \    os << '{';\n    for(int i = 0; i < (int)v.size(); i++) {\n        if(i) {\
    \ os << ','; }\n        os << v[i];\n    }\n    os << '}';\n    return os;\n}\n\
    void debugg() { cerr << endl; }\ntemplate <class T, class... Args>\nvoid debugg(const\
    \ T &x, const Args &... args) {\n    cerr << \" \" << x;\n    debugg(args...);\n\
    }\n#define debug(...)                                                        \
    \     \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]: \", debugg(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\nstruct Setup\
    \ {\n    Setup() {\n        cin.tie(0);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(15);\n    }\n} __Setup;\n\nusing ll = long\
    \ long;\n#define OVERLOAD3(_1, _2, _3, name, ...) name\n#define ALL(v) (v).begin(),\
    \ (v).end()\n#define RALL(v) (v).rbegin(), (v).rend()\n#define REP1(i, n) for(int\
    \ i = 0; i < int(n); i++)\n#define REP2(i, a, b) for(int i = (a); i < int(b);\
    \ i++)\n#define REP(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)\n#define\
    \ UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\n#define REVERSE(v)\
    \ reverse(ALL(v))\n#define SZ(v) ((int)(v).size())\nconst int INF = 1 << 30;\n\
    const ll LLINF = 1LL << 60;\nconstexpr int MOD = 1000000007;\nconstexpr int MOD2\
    \ = 998244353;\nconst int dx[4] = {1, 0, -1, 0};\nconst int dy[4] = {0, 1, 0,\
    \ -1};\n\nvoid Case(int i) { cout << \"Case #\" << i << \": \"; }\nint popcount(int\
    \ x) { return __builtin_popcount(x); }\nll popcount(ll x) { return __builtin_popcountll(x);\
    \ }\n#pragma endregion Macros\n#line 6 \"test/library-checker/data-structure/static-range-inversions-query.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> a(N);\n \
    \   REP(i, N) cin >> a[i];\n    Compress<int> comp(a);\n    REP(i, N) a[i] = comp.get(a[i]);\n\
    \    int sz = SZ(comp);\n    BIT<ll> bt(sz);\n    vector<ll> ans(Q);\n    Mo mo(N);\n\
    \    REP(_, Q) {\n        int l, r;\n        cin >> l >> r;\n        mo.insert(l,\
    \ r);\n    }\n    mo.set_bucketsize(N / std::sqrt(Q));\n    mo.build();\n    ll\
    \ now_ans = 0;\n    const auto add_right = [&](int id) {\n        now_ans += bt.sum(a[id]\
    \ + 1, sz);\n        bt.add(a[id], 1);\n    };\n    const auto add_left = [&](int\
    \ id) {\n        now_ans += bt.sum(a[id]);\n        bt.add(a[id], 1);\n    };\n\
    \    const auto del_left = [&](int id) {\n        now_ans -= bt.sum(a[id]);\n\
    \        bt.add(a[id], -1);\n    };\n    const auto del_right = [&](int id) {\n\
    \        now_ans -= bt.sum(a[id] + 1, sz);\n        bt.add(a[id], -1);\n    };\n\
    \    REP(_, Q) {\n        int qid = mo.process<decltype(add_left), decltype(add_right),\n\
    \                             decltype(del_left), decltype(del_right)>(\n    \
    \        add_left, add_right, del_left, del_right);\n        ans[qid] = now_ans;\n\
    \    }\n    REP(i, Q) cout << ans[i] << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n#include \"../../../data-structure/BIT.hpp\"\n#include \"../../../misc/compress.hpp\"\
    \n#include \"../../../misc/mo.hpp\"\n#include \"../../../template/template.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> a(N);\n \
    \   REP(i, N) cin >> a[i];\n    Compress<int> comp(a);\n    REP(i, N) a[i] = comp.get(a[i]);\n\
    \    int sz = SZ(comp);\n    BIT<ll> bt(sz);\n    vector<ll> ans(Q);\n    Mo mo(N);\n\
    \    REP(_, Q) {\n        int l, r;\n        cin >> l >> r;\n        mo.insert(l,\
    \ r);\n    }\n    mo.set_bucketsize(N / std::sqrt(Q));\n    mo.build();\n    ll\
    \ now_ans = 0;\n    const auto add_right = [&](int id) {\n        now_ans += bt.sum(a[id]\
    \ + 1, sz);\n        bt.add(a[id], 1);\n    };\n    const auto add_left = [&](int\
    \ id) {\n        now_ans += bt.sum(a[id]);\n        bt.add(a[id], 1);\n    };\n\
    \    const auto del_left = [&](int id) {\n        now_ans -= bt.sum(a[id]);\n\
    \        bt.add(a[id], -1);\n    };\n    const auto del_right = [&](int id) {\n\
    \        now_ans -= bt.sum(a[id] + 1, sz);\n        bt.add(a[id], -1);\n    };\n\
    \    REP(_, Q) {\n        int qid = mo.process<decltype(add_left), decltype(add_right),\n\
    \                             decltype(del_left), decltype(del_right)>(\n    \
    \        add_left, add_right, del_left, del_right);\n        ans[qid] = now_ans;\n\
    \    }\n    REP(i, Q) cout << ans[i] << '\\n';\n}\n"
  dependsOn:
  - data-structure/BIT.hpp
  - misc/compress.hpp
  - misc/mo.hpp
  - template/template.cpp
  isVerificationFile: true
  path: test/library-checker/data-structure/static-range-inversions-query.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/data-structure/static-range-inversions-query.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/data-structure/static-range-inversions-query.test.cpp
- /verify/test/library-checker/data-structure/static-range-inversions-query.test.cpp.html
title: test/library-checker/data-structure/static-range-inversions-query.test.cpp
---
