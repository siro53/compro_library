---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/segtree/segtree.hpp
    title: data_structure/segtree/segtree.hpp
  - icon: ':question:'
    path: graph/hld.hpp
    title: "Heavy Light Decomposition (HL\u5206\u89E3)"
  - icon: ':question:'
    path: math/modint.hpp
    title: ModInt
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"test/vertex_set_path_composite.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\n#line 1 \"template/template.cpp\"\
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
    \ (v).end())\n#define SZ(v) ((int)(v).size())\nconst int INF = 1 << 30;\nconst\
    \ ll LLINF = 1LL << 60;\nconstexpr int MOD = 1000000007;\nconstexpr int MOD2 =\
    \ 998244353;\nconst int dx[4] = {1, 0, -1, 0};\nconst int dy[4] = {0, 1, 0, -1};\n\
    \nvoid Case(int i) { cout << \"Case #\" << i << \": \"; }\nint popcount(int x)\
    \ { return __builtin_popcount(x); }\nll popcount(ll x) { return __builtin_popcountll(x);\
    \ }\n#pragma endregion Macros\n#line 3 \"test/vertex_set_path_composite.test.cpp\"\
    \n\n#line 1 \"math/modint.hpp\"\ntemplate <int mod> struct ModInt {\n    int x;\n\
    \    ModInt() : x(0) {}\n    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y)\
    \ % mod) % mod) {}\n    ModInt &operator+=(const ModInt &p) {\n        if((x +=\
    \ p.x) >= mod)\n            x -= mod;\n        return *this;\n    }\n    ModInt\
    \ &operator-=(const ModInt &p) {\n        if((x += mod - p.x) >= mod)\n      \
    \      x -= mod;\n        return *this;\n    }\n    ModInt &operator*=(const ModInt\
    \ &p) {\n        x = (int)(1LL * x * p.x % mod);\n        return *this;\n    }\n\
    \    ModInt &operator/=(const ModInt &p) {\n        *this *= p.inv();\n      \
    \  return *this;\n    }\n    ModInt operator-() const { return ModInt(-x); }\n\
    \    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }\n\
    \    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }\n\
    \    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }\n\
    \    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }\n\
    \    bool operator==(const ModInt &p) const { return x == p.x; }\n    bool operator!=(const\
    \ ModInt &p) const { return x != p.x; }\n    ModInt inv() const {\n        int\
    \ a = x, b = mod, u = 1, v = 0, t;\n        while(b > 0) {\n            t = a\
    \ / b;\n            swap(a -= t * b, b);\n            swap(u -= t * v, v);\n \
    \       }\n        return ModInt(u);\n    }\n    ModInt pow(int64_t n) const {\n\
    \        ModInt ret(1), mul(x);\n        while(n > 0) {\n            if(n & 1)\n\
    \                ret *= mul;\n            mul *= mul;\n            n >>= 1;\n\
    \        }\n        return ret;\n    }\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) {\n        return os << p.x;\n    }\n    friend istream\
    \ &operator>>(istream &is, ModInt &a) {\n        int64_t t;\n        is >> t;\n\
    \        a = ModInt<mod>(t);\n        return (is);\n    }\n    static int get_mod()\
    \ { return mod; }\n};\n#line 5 \"test/vertex_set_path_composite.test.cpp\"\nusing\
    \ mint = ModInt<MOD2>;\n#line 1 \"graph/hld.hpp\"\nclass HeavyLightDecomposition\
    \ {\n    int N;\n    vector<vector<int>> G;\n    vector<int> in, out, sz, head,\
    \ par, dep, rev;\n    bool isBuilt;\n\n    void dfs_sz(int u, int p, int d) {\n\
    \        dep[u] = d;\n        if(!G[u].empty() and G[u].front() == p) swap(G[u].front(),\
    \ G[u].back());\n        for(int& v : G[u]) {\n            if(v == p) continue;\n\
    \            dfs_sz(v, u, d+1);\n            sz[u] += sz[v];\n            if(sz[v]\
    \ > sz[G[u].front()]) swap(v, G[u].front());\n        }\n    }\n\n    void dfs_hld(int\
    \ u, int p, int &k) {\n        par[u] = p;\n        in[u] = k++;\n        rev[in[u]]\
    \ = u;\n        for(const int& v : G[u]) {\n            if(v == p) continue;\n\
    \            head[v] = (v == G[u].front() ? head[u] : v);\n            dfs_hld(v,\
    \ u, k);\n        }\n        out[u] = k;\n    }\n\n  public:\n    HeavyLightDecomposition(int\
    \ N)\n        : N(N), G(N), in(N, -1), out(N, -1), sz(N, 1), head(N), par(N, -1),\
    \ dep(N), rev(N), isBuilt(false) {}\n\n    HeavyLightDecomposition(const vector<vector<int>>\
    \ &g)\n        : N((int)g.size()), G(N), in(N, -1), out(N, -1), sz(N, 1), head(N),\n\
    \          par(N, -1), dep(N), rev(N), isBuilt(false) {}\n\n    inline void add_edge(int\
    \ u, int v) {\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n\
    \    }\n\n    void build(int root = 0) {\n        dfs_sz(root, -1, 0);\n     \
    \   head[root] = root;\n        int k = 0;\n        dfs_hld(root, -1, k);\n  \
    \      isBuilt = true;\n        // debug(in, head);\n    }\n\n    int operator[](int\
    \ u) {\n        assert(isBuilt and 0 <= u and u < N);\n        return in[u];\n\
    \    }\n\n    int lca(int u, int v) {\n        assert(isBuilt and 0 <= u and u\
    \ < N and 0 <= v and v < N);\n        while(true) {\n            if(in[u] > in[v])\
    \ swap(u, v);\n            if(head[u] == head[v]) return u;\n            v = par[head[v]];\n\
    \        }\n    }\n\n    int dist(int u, int v) {\n        assert(isBuilt and\
    \ 0 <= u and u < N and 0 <= v and v < N);\n        return dep[u] + dep[v] - 2\
    \ * dep[lca(u, v)];\n    }\n\n    // \u9802\u70B9u\u304B\u3089\u89AA\u65B9\u5411\
    \u306B\u8DDD\u96E2k\u767B\u3063\u305F\u9802\u70B9\u3092\u8FD4\u3059\n    int la(int\
    \ u, int k) {\n        assert(isBuilt and 0 <= u and u < N);\n        if(dep[u]\
    \ < k) return -1; \n        while(true) {\n            if(in[u] - k >= in[head[u]])\
    \ return rev[in[u] - k];\n            k -= (in[u] - in[head[u]] + 1);\n      \
    \      u = par[head[u]];\n        }\n    }   \n\n    // \u9802\u70B9\u5C5E\u6027\
    \n    vector<pair<int, int>> path(int u, int v) {\n        assert(isBuilt and\
    \ 0 <= u and u < N and 0 <= v and v < N);\n        // u -> v\u306E\u5411\u304D\
    \u306B\u306A\u308B\u3088\u3046\u306B\u8FD4\u3059\n        vector<pair<int, int>>\
    \ ret;\n        while(true) {\n            if(in[u] > in[v]) swap(u, v);\n   \
    \         if(head[u] == head[v]) {\n                ret.emplace_back(in[u], in[v]\
    \ + 1);\n                break;\n            } else {\n                ret.emplace_back(in[head[v]],\
    \ in[v] + 1);\n                v = par[head[v]];\n            }\n        }\n \
    \       return ret;\n    }\n\n    // \u8FBA\u5C5E\u6027\n    vector<pair<int,\
    \ int>> path_edge(int u, int v) {\n        assert(isBuilt and 0 <= u and u < N\
    \ and 0 <= v and v < N);\n        vector<pair<int, int>> ret;\n        while(true)\
    \ {\n            if(in[u] > in[v]) swap(u, v);\n            if(head[u] == head[v])\
    \ {\n                if(u != v) ret.emplace_back(in[u] + 1, in[v] + 1);\n    \
    \            break;\n            } else {\n                ret.emplace_back(in[head[v]],\
    \ in[v] + 1);\n                v = par[head[v]];\n            }\n        }\n \
    \       return ret;\n    }\n\n    pair<int, int> subtree(int u) { \n        assert(isBuilt\
    \ and 0 <= u and u < N);\n        return {in[u], out[u]};\n    }\n};\n#line 1\
    \ \"data_structure/segtree/segtree.hpp\"\ntemplate <class S, S (*op)(S, S), S\
    \ (*e)()> class segtree {\n    int N, sz;\n    vector<S> node;\n\n  public:\n\
    \    segtree() {}\n    segtree(vector<S> v) : N(int(v.size())) {\n        sz =\
    \ 1;\n        while(sz < N) sz <<= 1;\n        node.resize(2 * sz, e());\n   \
    \     for(int i = 0; i < N; i++) node[i + sz] = v[i];\n        for(int i = sz\
    \ - 1; i >= 1; i--)\n            node[i] = op(node[2 * i], node[2 * i + 1]);\n\
    \    }\n    segtree(int n) : segtree(vector<S>(n, e())) {}\n    void set(int p,\
    \ S val) {\n        p += sz;\n        node[p] = val;\n        while(p >>= 1) node[p]\
    \ = op(node[2 * p], node[2 * p + 1]);\n    }\n    S get(int p) { return node[p\
    \ + sz]; }\n    S prod(int l, int r) {\n        S vl = e(), vr = e();\n      \
    \  for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {\n            if(l & 1) vl\
    \ = op(vl, node[l++]);\n            if(r & 1) vr = op(vr, node[--r]);\n      \
    \  }\n        return op(vl, vr);\n    }\n    S all_prod() { return node[1]; }\n\
    };\n#line 8 \"test/vertex_set_path_composite.test.cpp\"\n\nstruct S {\n    mint\
    \ a, b;\n    S() {}\n    S(mint a, mint b): a(a), b(b) {}\n    inline mint eval(mint\
    \ x) { return a*x + b; }\n};\nS op(S x, S y) { // fx(fy())\n    return S(x.a *\
    \ y.a, x.a * y.b + x.b);\n}\nS op_rev(S x, S y) { // fy(fx())\n    return S(y.a\
    \ * x.a, y.a * x.b + y.b);\n}\nS e() {\n    return S(1, 0);\n}\n\nint main() {\n\
    \    int N, Q;\n    cin >> N >> Q;\n    vector<pair<int, int>> fs(N);\n    for(auto&\
    \ [a, b]: fs) cin >> a >> b;\n    HeavyLightDecomposition hld(N);\n    REP(_,\
    \ N-1) {\n        int u, v;\n        cin >> u >> v;\n        hld.add_edge(u, v);\n\
    \    }\n    hld.build();\n    segtree<S, op, e> seg(N);\n    segtree<S, op_rev,\
    \ e> seg_rev(N);\n    REP(i, N) {\n        auto [a, b] = fs[i];\n        int id\
    \ = hld[i];\n        seg.set(id, S(a, b));\n        seg_rev.set(id, S(a, b));\n\
    \    }\n    REP(_, Q) {\n        int t;\n        cin >> t;\n        if(t == 0)\
    \ {\n            int p, c, d;\n            cin >> p >> c >> d;\n            int\
    \ id = hld[p];\n            seg.set(id, S(c, d));\n            seg_rev.set(id,\
    \ S(c, d));\n        } else {\n            int u, v, x;\n            cin >> u\
    \ >> v >> x;\n            int LCA = hld.lca(u, v);\n            S resl = e(),\
    \ resr = e();\n            for(const auto& [l, r] : hld.path(u, LCA)) {\n    \
    \            resl = op(seg.prod(l, r), resl);\n            }\n            for(const\
    \ auto& [l, r] : hld.path_edge(LCA, v)) {\n                resr = op_rev(seg_rev.prod(l,\
    \ r), resr);\n            }\n            auto res = op(resr, resl);\n        \
    \    cout << res.eval(x) << '\\n'; \n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include \"../template/template.cpp\"\n\n#include \"../math/modint.hpp\"\nusing\
    \ mint = ModInt<MOD2>;\n#include \"../graph/hld.hpp\"\n#include \"../data_structure/segtree/segtree.hpp\"\
    \n\nstruct S {\n    mint a, b;\n    S() {}\n    S(mint a, mint b): a(a), b(b)\
    \ {}\n    inline mint eval(mint x) { return a*x + b; }\n};\nS op(S x, S y) { //\
    \ fx(fy())\n    return S(x.a * y.a, x.a * y.b + x.b);\n}\nS op_rev(S x, S y) {\
    \ // fy(fx())\n    return S(y.a * x.a, y.a * x.b + y.b);\n}\nS e() {\n    return\
    \ S(1, 0);\n}\n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<pair<int,\
    \ int>> fs(N);\n    for(auto& [a, b]: fs) cin >> a >> b;\n    HeavyLightDecomposition\
    \ hld(N);\n    REP(_, N-1) {\n        int u, v;\n        cin >> u >> v;\n    \
    \    hld.add_edge(u, v);\n    }\n    hld.build();\n    segtree<S, op, e> seg(N);\n\
    \    segtree<S, op_rev, e> seg_rev(N);\n    REP(i, N) {\n        auto [a, b] =\
    \ fs[i];\n        int id = hld[i];\n        seg.set(id, S(a, b));\n        seg_rev.set(id,\
    \ S(a, b));\n    }\n    REP(_, Q) {\n        int t;\n        cin >> t;\n     \
    \   if(t == 0) {\n            int p, c, d;\n            cin >> p >> c >> d;\n\
    \            int id = hld[p];\n            seg.set(id, S(c, d));\n           \
    \ seg_rev.set(id, S(c, d));\n        } else {\n            int u, v, x;\n    \
    \        cin >> u >> v >> x;\n            int LCA = hld.lca(u, v);\n         \
    \   S resl = e(), resr = e();\n            for(const auto& [l, r] : hld.path(u,\
    \ LCA)) {\n                resl = op(seg.prod(l, r), resl);\n            }\n \
    \           for(const auto& [l, r] : hld.path_edge(LCA, v)) {\n              \
    \  resr = op_rev(seg_rev.prod(l, r), resr);\n            }\n            auto res\
    \ = op(resr, resl);\n            cout << res.eval(x) << '\\n'; \n        }\n \
    \   }\n}"
  dependsOn:
  - template/template.cpp
  - math/modint.hpp
  - graph/hld.hpp
  - data_structure/segtree/segtree.hpp
  isVerificationFile: true
  path: test/vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2022-04-06 16:19:19+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_set_path_composite.test.cpp
- /verify/test/vertex_set_path_composite.test.cpp.html
title: test/vertex_set_path_composite.test.cpp
---
