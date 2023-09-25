---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/li-chao-tree.hpp
    title: Li Chao Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"test/library-checker/data-structure/segment-add-get-min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n#line\
    \ 1 \"template/template.cpp\"\n#pragma region Macros\n#include <bits/stdc++.h>\n\
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
    \ UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\n#define REVERSE(v)\
    \ reverse(ALL(v))\n#define SZ(v) ((int)(v).size())\nconst int INF = 1 << 30;\n\
    const ll LLINF = 1LL << 60;\nconstexpr int MOD = 1000000007;\nconstexpr int MOD2\
    \ = 998244353;\nconst int dx[4] = {1, 0, -1, 0};\nconst int dy[4] = {0, 1, 0,\
    \ -1};\n\nvoid Case(int i) { cout << \"Case #\" << i << \": \"; }\nint popcount(int\
    \ x) { return __builtin_popcount(x); }\nll popcount(ll x) { return __builtin_popcountll(x);\
    \ }\n#pragma endregion Macros\n#line 2 \"data-structure/segtree/li-chao-tree.hpp\"\
    \n\n#line 7 \"data-structure/segtree/li-chao-tree.hpp\"\n\ntemplate <typename\
    \ T, T inf>\nclass LiChaoTree {\npublic:\n    LiChaoTree() = default;\n    explicit\
    \ LiChaoTree(const std::vector<T>& x): xs(x) {\n        std::sort(xs.begin(),\
    \ xs.end());\n        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n\
    \        n = (int)xs.size();\n        sz = 1;\n        while(sz < n) sz <<= 1;\n\
    \        while((int)xs.size() < sz) xs.emplace_back(xs.back() + 1);\n        node.resize(sz\
    \ * 2, Line(T(0), inf));\n    }\n    // \u76F4\u7DDA ax + b \u3092\u8FFD\u52A0\
    \n    void add_line(T a, T b) {\n        update(a, b, 0, sz, 1);\n    }\n    //\
    \ \u7DDA\u5206 ax + b (x_l <= x < x_r) \u3092\u8FFD\u52A0\n    void add_segment(T\
    \ a, T b, T x_l, T x_r) {\n        int l = std::lower_bound(xs.begin(), xs.end(),\
    \ x_l) - xs.begin();\n        int r = std::lower_bound(xs.begin(), xs.end(), x_r)\
    \ - xs.begin();\n        l += sz;\n        r += sz;\n        int width = 1, seg_idx_left\
    \ = sz;\n        while(l < r) {\n            if(l & 1) {\n                int\
    \ L = (l - seg_idx_left) * width;\n                int R = L + width;\n      \
    \          update(a, b, L, R, l);\n                l++;\n            }\n     \
    \       if(r & 1) {\n                r--;\n                int L = (r - seg_idx_left)\
    \ * width;\n                int R = L + width;\n                update(a, b, L,\
    \ R, r);\n            }\n            l >>= 1;\n            r >>= 1;\n        \
    \    width <<= 1;\n            seg_idx_left >>= 1;\n        }\n    }\n    // min_{i}\
    \ (a_i * x + b) \u3092\u6C42\u3081\u308B\n    T get_min(T x) {\n        int pos\
    \ = std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n        assert(0\
    \ <= pos and pos < sz);\n        pos += sz;\n        T ret = node[pos].eval(x);\n\
    \        while(pos > 1) {\n            pos >>= 1;\n            ret = std::min(ret,\
    \ node[pos].eval(x));\n        }\n        return ret;\n    }\nprivate:\n    struct\
    \ Line {\n        T a, b;\n        Line(T a, T b): a(a), b(b) {}\n        inline\
    \ T eval(T x) const { return (a * x + b); }\n    };\n    std::vector<T> xs;\n\
    \    std::vector<Line> node;\n    int n, sz;\n\n    void update(T a, T b, int\
    \ l, int r, int pos) {\n        Line new_line(a, b);\n        while(1) {\n   \
    \         bool is_over_l = (new_line.eval(xs[l]) >= node[pos].eval(xs[l]));\n\
    \            bool is_over_r = (new_line.eval(xs[r-1]) >= node[pos].eval(xs[r-1]));\n\
    \            if(is_over_l == is_over_r) {\n                if(!is_over_l) node[pos]\
    \ = new_line;\n                break;\n            }\n            int mid = (l\
    \ + r) >> 1;\n            bool is_over_mid = (new_line.eval(xs[mid]) >= node[pos].eval(xs[mid]));\n\
    \            if(!is_over_l and is_over_r) {\n                if(is_over_mid) {\n\
    \                    r = mid;\n                    pos = (pos << 1);\n       \
    \         } else {\n                    std::swap(new_line, node[pos]);\n    \
    \                l = mid;\n                    pos = (pos << 1) | 1;\n       \
    \         }\n            } else {\n                if(is_over_mid) {\n       \
    \             l = mid;\n                    pos = (pos << 1) | 1;\n          \
    \      } else {\n                    std::swap(new_line, node[pos]);\n       \
    \             r = mid;\n                    pos = (pos << 1);\n              \
    \  }\n            }\n        }\n    }\n};\n#line 4 \"test/library-checker/data-structure/segment-add-get-min.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<ll> xs;\n    vector<tuple<ll,\
    \ ll, ll, ll>> segs(N);\n    REP(i, N) {\n        ll l, r, a, b;\n        cin\
    \ >> l >> r >> a >> b;\n        segs[i] = {l, r, a, b};\n        xs.push_back(l);\n\
    \        xs.push_back(r);\n    }\n    vector<tuple<int, ll, ll, ll, ll>> qs(Q);\n\
    \    REP(i, Q) {\n        int t;\n        cin >> t;\n        if(t == 0) {\n  \
    \          ll l, r, a, b;\n            cin >> l >> r >> a >> b;\n            qs[i]\
    \ = {t, l, r, a, b};\n            xs.push_back(l);\n            xs.push_back(r);\n\
    \        } else {\n            ll x;\n            cin >> x;\n            qs[i]\
    \ = {t, x, -1, -1, -1};\n            xs.push_back(x);\n        }\n    }\n    LiChaoTree<ll,\
    \ LLINF> lc(xs);\n    for(const auto& [l, r, a, b] : segs) lc.add_segment(a, b,\
    \ l, r);\n    for(const auto& [t, l, r, a, b] : qs) {\n        if(t == 0) {\n\
    \            lc.add_segment(a, b, l, r);\n        } else {\n            ll ans\
    \ = lc.get_min(l);\n            if(ans == LLINF) {\n                cout << \"\
    INFINITY\\n\";\n            } else {\n                cout << lc.get_min(l) <<\
    \ '\\n';\n            }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    #include \"../../../template/template.cpp\"\n#include \"../../../data-structure/segtree/li-chao-tree.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<ll> xs;\n    vector<tuple<ll,\
    \ ll, ll, ll>> segs(N);\n    REP(i, N) {\n        ll l, r, a, b;\n        cin\
    \ >> l >> r >> a >> b;\n        segs[i] = {l, r, a, b};\n        xs.push_back(l);\n\
    \        xs.push_back(r);\n    }\n    vector<tuple<int, ll, ll, ll, ll>> qs(Q);\n\
    \    REP(i, Q) {\n        int t;\n        cin >> t;\n        if(t == 0) {\n  \
    \          ll l, r, a, b;\n            cin >> l >> r >> a >> b;\n            qs[i]\
    \ = {t, l, r, a, b};\n            xs.push_back(l);\n            xs.push_back(r);\n\
    \        } else {\n            ll x;\n            cin >> x;\n            qs[i]\
    \ = {t, x, -1, -1, -1};\n            xs.push_back(x);\n        }\n    }\n    LiChaoTree<ll,\
    \ LLINF> lc(xs);\n    for(const auto& [l, r, a, b] : segs) lc.add_segment(a, b,\
    \ l, r);\n    for(const auto& [t, l, r, a, b] : qs) {\n        if(t == 0) {\n\
    \            lc.add_segment(a, b, l, r);\n        } else {\n            ll ans\
    \ = lc.get_min(l);\n            if(ans == LLINF) {\n                cout << \"\
    INFINITY\\n\";\n            } else {\n                cout << lc.get_min(l) <<\
    \ '\\n';\n            }\n        }\n    }\n}"
  dependsOn:
  - template/template.cpp
  - data-structure/segtree/li-chao-tree.hpp
  isVerificationFile: true
  path: test/library-checker/data-structure/segment-add-get-min.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/data-structure/segment-add-get-min.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/data-structure/segment-add-get-min.test.cpp
- /verify/test/library-checker/data-structure/segment-add-get-min.test.cpp.html
title: test/library-checker/data-structure/segment-add-get-min.test.cpp
---
