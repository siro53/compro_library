---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/affine.hpp
    title: data-structure/monoid/affine.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/segtree.hpp
    title: data-structure/segtree/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/hld.hpp
    title: graph/tree/hld.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint.hpp
    title: modint/modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"test/library-checker/data-structure/vertex-set-path-composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
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
    \ i = 0; i < int(n); i++)\n#define REP2(i, a, b) for(int i = (a); i < int(b);\
    \ i++)\n#define REP(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)\n#define\
    \ UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\n#define REVERSE(v)\
    \ reverse(ALL(v))\n#define SZ(v) ((int)(v).size())\nconst int INF = 1 << 30;\n\
    const ll LLINF = 1LL << 60;\nconstexpr int MOD = 1000000007;\nconstexpr int MOD2\
    \ = 998244353;\nconst int dx[4] = {1, 0, -1, 0};\nconst int dy[4] = {0, 1, 0,\
    \ -1};\n\nvoid Case(int i) { cout << \"Case #\" << i << \": \"; }\nint popcount(int\
    \ x) { return __builtin_popcount(x); }\nll popcount(ll x) { return __builtin_popcountll(x);\
    \ }\n#pragma endregion Macros\n#line 2 \"data-structure/monoid/affine.hpp\"\n\n\
    #line 4 \"data-structure/monoid/affine.hpp\"\n\ntemplate <typename T, bool rev\
    \ = false> struct MonoidAffine {\n    using S = std::pair<T, T>;\n    using value_type\
    \ = S;\n    inline static S op(const S &l, const S &r) {\n        if(rev) return\
    \ S(r.first * l.first, r.first * l.second + r.second);\n        return S(l.first\
    \ * r.first, l.first * r.second + l.second);\n    }\n    inline static S e() {\
    \ return S(T(1), T(0)); }\n};\n#line 2 \"data-structure/segtree/segtree.hpp\"\n\
    \n#line 5 \"data-structure/segtree/segtree.hpp\"\n\ntemplate <class Monoid> class\
    \ Segtree {\n  public:\n    using T = typename Monoid::value_type;\n\n    Segtree()\
    \ : Segtree(0) {}\n    explicit Segtree(int n) : Segtree(std::vector<T>(n, Monoid::e()))\
    \ {}\n    explicit Segtree(const std::vector<T> &v) : N((int)v.size()), sz(1)\
    \ {\n        while(sz < N) sz <<= 1;\n        node.resize(sz * 2, Monoid::e());\n\
    \        for(int i = 0; i < N; i++) node[i + sz] = v[i];\n        for(int i =\
    \ sz - 1; i >= 1; i--) {\n            node[i] = Monoid::op(node[i << 1], node[i\
    \ << 1 | 1]);\n        }\n    }\n    void set(int pos, T val) {\n        assert(0\
    \ <= pos && pos < N);\n        pos += sz;\n        node[pos] = val;\n        while(pos\
    \ > 1) {\n            pos >>= 1;\n            node[pos] = Monoid::op(node[pos\
    \ << 1], node[pos << 1 | 1]);\n        }\n    }\n    T get(int pos) const {\n\
    \        assert(0 <= pos && pos < N);\n        return node[pos + sz];\n    }\n\
    \    T prod(int l, int r) const {\n        assert(0 <= l && l <= r && r <= N);\n\
    \        T value_l = Monoid::e(), value_r = Monoid::e();\n        l += sz;\n \
    \       r += sz;\n        while(l < r) {\n            if(l & 1) value_l = Monoid::op(value_l,\
    \ node[l++]);\n            if(r & 1) value_r = Monoid::op(node[--r], value_r);\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n        return Monoid::op(value_l,\
    \ value_r);\n    }\n    T all_prod() const { return node[1]; }\n    template <class\
    \ F> int max_right(int l, F f) const {\n        assert(0 <= l && l <= N);\n  \
    \      assert(f(Monoid::e()));\n        if(l == N) return N;\n        l += sz;\n\
    \        T value_now = Monoid::e();\n        do {\n            while((l & 1) ==\
    \ 0) l >>= 1;\n            if(!f(Monoid::op(value_now, node[l]))) {\n        \
    \        while(l < sz) {\n                    l = 2 * l;\n                   \
    \ if(f(Monoid::op(value_now, node[l]))) {\n                        value_now =\
    \ Monoid::op(value_now, node[l]);\n                        l++;\n            \
    \        }\n                }\n                return (l - sz);\n            }\n\
    \            value_now = Monoid::op(value_now, node[l]);\n            l++;\n \
    \       } while((l & -l) != l);\n        return N;\n    }\n    template <class\
    \ F> int min_left(int r, F f) const {\n        assert(0 <= r && r <= N);\n   \
    \     assert(f(Monoid::e()));\n        if(r == 0) return 0;\n        r += sz;\n\
    \        T value_now = Monoid::e();\n        do {\n            r--;\n        \
    \    while(r > 1 && (r & 1)) r >>= 1;\n            if(!f(Monoid::op(node[r], value_now)))\
    \ {\n                while(r < sz) {\n                    r = 2 * r + 1;\n   \
    \                 if(f(Monoid::op(node[r], value_now))) {\n                  \
    \      value_now = Monoid::op(node[r], value_now);\n                        r--;\n\
    \                    }\n                }\n                return ((r + 1) - sz);\n\
    \            }\n            value_now = Monoid::op(node[r], value_now);\n    \
    \    } while((r & -r) != r);\n        return 0;\n    }\n\n  private:\n    int\
    \ N, sz;\n    std::vector<T> node;\n};\n#line 2 \"graph/tree/hld.hpp\"\n\n#line\
    \ 4 \"graph/tree/hld.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\n\n#line 5\
    \ \"graph/graph_template.hpp\"\n\ntemplate <typename Cost = int> struct Edge {\n\
    \    int from, to;\n    Cost cost;\n    int id;\n    Edge() = default;\n    explicit\
    \ Edge(int from, int to, Cost cost = 1, int id = -1)\n        : from(from), to(to),\
    \ cost(cost), id(id) {}\n};\n\ntemplate <typename Cost = int> class Graph {\n\
    \  public:\n    Graph() = default;\n    explicit Graph(int N) : N(N), M(0), G(N)\
    \ {}\n\n    inline void add_directed_edge(int from, int to, Cost cost = 1) {\n\
    \        assert(0 <= from && from < N);\n        assert(0 <= to && to < N);\n\
    \        G[from].emplace_back(from, to, cost, M++);\n    }\n\n    inline void\
    \ add_undirected_edge(int from, int to, Cost cost = 1) {\n        assert(0 <=\
    \ from && from < N);\n        assert(0 <= to && to < N);\n        G[from].emplace_back(from,\
    \ to, cost, M);\n        G[to].emplace_back(to, from, cost, M++);\n    }\n\n \
    \   inline size_t size() const { return G.size(); }\n    inline std::vector<Edge<Cost>>\
    \ &operator[](const int &i) { return G[i]; }\n    inline const std::vector<Edge<Cost>>\
    \ &operator[](const int &i) const {\n        return G[i];\n    }\n\n  private:\n\
    \    int N, M;\n    std::vector<std::vector<Edge<Cost>>> G;\n};\n\ntemplate <class\
    \ Cost = int> using Edges = std::vector<Edge<Cost>>;\n#line 6 \"graph/tree/hld.hpp\"\
    \n\ntemplate <typename Cost = int> class HeavyLightDecomposition {\n  public:\n\
    \    explicit HeavyLightDecomposition(int N)\n        : G(N), in(N), out(N), sz(N),\
    \ head(N), par(N), dep(N), rev(N),\n          isBuilt(false) {}\n    explicit\
    \ HeavyLightDecomposition(const Graph<Cost> &g)\n        : G(g), in(g.size()),\
    \ out(g.size()), sz(g.size()), head(g.size()),\n          par(g.size()), dep(g.size()),\
    \ rev(g.size()), isBuilt(false) {\n        build();\n    }\n    void add_edge(int\
    \ from, int to, Cost cost = 1) {\n        G.add_undirected_edge(from, to, cost);\n\
    \    }\n    void build(int root = 0) {\n        dfs1(root, -1, 0);\n        head[root]\
    \ = root;\n        int idx = 0;\n        dfs2(root, -1, idx);\n        isBuilt\
    \ = true;\n    }\n\tint lca(int u, int v) const {\n\t\tassert(isBuilt);\n\t\t\
    assert(0 <= u && u < (int)G.size());\n\t\tassert(0 <= v && v < (int)G.size());\n\
    \t\twhile(1) {\n\t\t\tif(in[u] > in[v]) std::swap(u, v);\n\t\t\tif(head[u] ==\
    \ head[v]) return u;\n\t\t\tv = par[head[v]];\n\t\t}\n\t}\n\tint dist(int u, int\
    \ v) const {\n\t\tassert(isBuilt);\n\t\tassert(0 <= u && u < (int)G.size());\n\
    \t\tassert(0 <= v && v < (int)G.size());\n\t\treturn (dep[u] + dep[v] - 2 * dep[lca(u,\
    \ v)]);\n\t}\n\tint la(int u, int k) const {\n\t\tassert(isBuilt);\n\t\tassert(0\
    \ <= u && u < (int)G.size());\n\t\tif(dep[u] < k) return -1;\n\t\twhile(1) {\n\
    \t\t\tif(in[u] - k >= in[head[u]]) {\n\t\t\t\treturn rev[in[u] - k];\n\t\t\t}\n\
    \t\t\tk -= (in[u] - in[head[u]] + 1);\n\t\t\tu = par[head[u]];\n\t\t}\n\t}\n\t\
    template<class F>\n\tvoid path_query(int u, int v, const F& f, bool edge = false)\
    \ const {\n\t\tassert(isBuilt);\n\t\tassert(0 <= u && u < (int)G.size());\n\t\t\
    assert(0 <= v && v < (int)G.size());\n\t\twhile(1) {\n\t\t\tif(in[u] > in[v])\
    \ std::swap(u, v);\n\t\t\tif(head[u] == head[v]) {\n\t\t\t\tf(in[u] + (int)(edge),\
    \ in[v] + 1);\n\t\t\t\tbreak;\n\t\t\t} else {\n\t\t\t\tf(in[head[v]], in[v] +\
    \ 1);\n\t\t\t}\n\t\t\tv = par[head[v]];\n\t\t}\n\t}\n\ttemplate<class F, class\
    \ F_rev>\n\tvoid path_query(int u, int v, const F& f, const F_rev& f_rev, bool\
    \ edge = false) const {\n\t\tassert(isBuilt);\n\t\tassert(0 <= u && u < (int)G.size());\n\
    \t\tassert(0 <= v && v < (int)G.size());\n\t\tint L = lca(u, v);\n\t\tpath_query<F>(u,\
    \ L, f, edge);\n\t\tpath_query<F_rev>(L, v, f_rev, true);\n\t}\n\ttemplate<class\
    \ F>\n\tvoid subtree_query(int u, const F& f) const {\n\t\tassert(isBuilt);\n\t\
    \tassert(0 <= u && u < (int)G.size());\n\t\tf(in[u], out[u]);\n\t}\n\tint operator[](int\
    \ u) const {\n\t\tassert(isBuilt);\n\t\tassert(0 <= u && u < (int)G.size());\n\
    \t\treturn in[u];\n\t}\n\n  private:\n    Graph<Cost> G;\n    std::vector<int>\
    \ in, out, sz, head, par, dep, rev;\n    bool isBuilt;\n\n    void dfs1(int u,\
    \ int p, int d) {\n        dep[u] = d;\n        sz[u] = 1;\n        if(G[u].empty()\
    \ && G[u].front().to == p) {\n            std::swap(G[u].front(), G[u].back());\n\
    \        }\n        for(auto &e : G[u]) {\n            if(e.to == p) continue;\n\
    \            dfs1(e.to, u, d + 1);\n            sz[u] += sz[e.to];\n         \
    \   if(sz[e.to] > sz[G[u].front().to]) { std::swap(G[u].front(), e); }\n     \
    \   }\n    }\n\n    void dfs2(int u, int p, int &idx) {\n        par[u] = p;\n\
    \        in[u] = idx++;\n        rev[in[u]] = u;\n        for(const auto &e :\
    \ G[u]) {\n            if(e.to == p) continue;\n            head[e.to] = (e.to\
    \ == G[u].front().to ? head[u] : e.to);\n            dfs2(e.to, u, idx);\n   \
    \     }\n        out[u] = idx;\n    }\n};\n#line 2 \"modint/modint.hpp\"\n\n#line\
    \ 6 \"modint/modint.hpp\"\n\ntemplate <int mod> class ModInt {\n  public:\n  \
    \  ModInt() : x(0) {}\n    ModInt(long long y)\n        : x(y >= 0 ? y % umod()\
    \ : (umod() - (-y) % umod()) % umod()) {}\n    unsigned int val() const { return\
    \ x; }\n    ModInt &operator+=(const ModInt &p) {\n        if((x += p.x) >= umod())\
    \ x -= umod();\n        return *this;\n    }\n    ModInt &operator-=(const ModInt\
    \ &p) {\n        if((x += umod() - p.x) >= umod()) x -= umod();\n        return\
    \ *this;\n    }\n    ModInt &operator*=(const ModInt &p) {\n        x = (unsigned\
    \ int)(1ULL * x * p.x % umod());\n        return *this;\n    }\n    ModInt &operator/=(const\
    \ ModInt &p) {\n        *this *= p.inv();\n        return *this;\n    }\n    ModInt\
    \ operator-() const { return ModInt(-(long long)x); }\n    ModInt operator+(const\
    \ ModInt &p) const { return ModInt(*this) += p; }\n    ModInt operator-(const\
    \ ModInt &p) const { return ModInt(*this) -= p; }\n    ModInt operator*(const\
    \ ModInt &p) const { return ModInt(*this) *= p; }\n    ModInt operator/(const\
    \ ModInt &p) const { return ModInt(*this) /= p; }\n    bool operator==(const ModInt\
    \ &p) const { return x == p.x; }\n    bool operator!=(const ModInt &p) const {\
    \ return x != p.x; }\n    ModInt inv() const {\n        long long a = x, b = mod,\
    \ u = 1, v = 0, t;\n        while(b > 0) {\n            t = a / b;\n         \
    \   std::swap(a -= t * b, b);\n            std::swap(u -= t * v, v);\n       \
    \ }\n        return ModInt(u);\n    }\n    ModInt pow(unsigned long long n) const\
    \ {\n        ModInt ret(1), mul(x);\n        while(n > 0) {\n            if(n\
    \ & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n\
    \        return ret;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const ModInt &p) {\n        return os << p.x;\n    }\n    friend std::istream\
    \ &operator>>(std::istream &is, ModInt &a) {\n        long long t;\n        is\
    \ >> t;\n        a = ModInt<mod>(t);\n        return (is);\n    }\n    static\
    \ constexpr int get_mod() { return mod; }\n\n  private:\n    unsigned int x;\n\
    \    static constexpr unsigned int umod() { return mod; }\n};\n#line 7 \"test/library-checker/data-structure/vertex-set-path-composite.test.cpp\"\
    \n\nusing mint = ModInt<MOD2>;\nusing AffineLeft = MonoidAffine<mint, false>;\n\
    using AffineRight = MonoidAffine<mint, true>;\n\nint main() {\n    int N, Q;\n\
    \    cin >> N >> Q;\n    vector<pair<mint, mint>> af(N);\n    REP(i, N) {\n  \
    \      mint a, b;\n        cin >> a >> b;\n        af[i] = {a, b};\n    }\n  \
    \  HeavyLightDecomposition hld(N);\n    REP(_, N-1) {\n        int u, v;\n   \
    \     cin >> u >> v;\n        hld.add_edge(u, v);\n    }\n    hld.build();\n \
    \   Segtree<AffineLeft> seg(N);\n    Segtree<AffineRight> seg_rev(N);\n    REP(i,\
    \ N) {\n        seg.set(hld[i], af[i]);\n        seg_rev.set(hld[i], af[i]);\n\
    \    }\n\n    while(Q--) {\n        int type;\n        cin >> type;\n        if(type\
    \ == 0) {\n            int p;\n            mint c, d;\n            cin >> p >>\
    \ c >> d;\n            seg.set(hld[p], make_pair(c, d));\n            seg_rev.set(hld[p],\
    \ make_pair(c, d));\n        } else {\n            int u, v;\n            mint\
    \ x;\n            cin >> u >> v >> x;\n            pair<mint, mint> res_l = AffineLeft::e(),\
    \ res_r = AffineRight::e();\n            auto f = [&](int l, int r) {\n      \
    \          res_l = AffineLeft::op(seg.prod(l, r), res_l);\n            };\n  \
    \          auto f_rev = [&](int l, int r) {\n                res_r = AffineRight::op(seg_rev.prod(l,\
    \ r), res_r);\n            };\n            hld.path_query<decltype(f), decltype(f_rev)>(u,\
    \ v, f, f_rev);\n            auto [a, b] = AffineLeft::op(res_r, res_l);\n   \
    \         mint ans = a * x + b;\n            cout << ans << '\\n';\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include \"../../../template/template.cpp\"\n#include \"../../../data-structure/monoid/affine.hpp\"\
    \n#include \"../../../data-structure/segtree/segtree.hpp\"\n#include \"../../../graph/tree/hld.hpp\"\
    \n#include \"../../../modint/modint.hpp\"\n\nusing mint = ModInt<MOD2>;\nusing\
    \ AffineLeft = MonoidAffine<mint, false>;\nusing AffineRight = MonoidAffine<mint,\
    \ true>;\n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<pair<mint,\
    \ mint>> af(N);\n    REP(i, N) {\n        mint a, b;\n        cin >> a >> b;\n\
    \        af[i] = {a, b};\n    }\n    HeavyLightDecomposition hld(N);\n    REP(_,\
    \ N-1) {\n        int u, v;\n        cin >> u >> v;\n        hld.add_edge(u, v);\n\
    \    }\n    hld.build();\n    Segtree<AffineLeft> seg(N);\n    Segtree<AffineRight>\
    \ seg_rev(N);\n    REP(i, N) {\n        seg.set(hld[i], af[i]);\n        seg_rev.set(hld[i],\
    \ af[i]);\n    }\n\n    while(Q--) {\n        int type;\n        cin >> type;\n\
    \        if(type == 0) {\n            int p;\n            mint c, d;\n       \
    \     cin >> p >> c >> d;\n            seg.set(hld[p], make_pair(c, d));\n   \
    \         seg_rev.set(hld[p], make_pair(c, d));\n        } else {\n          \
    \  int u, v;\n            mint x;\n            cin >> u >> v >> x;\n         \
    \   pair<mint, mint> res_l = AffineLeft::e(), res_r = AffineRight::e();\n    \
    \        auto f = [&](int l, int r) {\n                res_l = AffineLeft::op(seg.prod(l,\
    \ r), res_l);\n            };\n            auto f_rev = [&](int l, int r) {\n\
    \                res_r = AffineRight::op(seg_rev.prod(l, r), res_r);\n       \
    \     };\n            hld.path_query<decltype(f), decltype(f_rev)>(u, v, f, f_rev);\n\
    \            auto [a, b] = AffineLeft::op(res_r, res_l);\n            mint ans\
    \ = a * x + b;\n            cout << ans << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template/template.cpp
  - data-structure/monoid/affine.hpp
  - data-structure/segtree/segtree.hpp
  - graph/tree/hld.hpp
  - graph/graph_template.hpp
  - modint/modint.hpp
  isVerificationFile: true
  path: test/library-checker/data-structure/vertex-set-path-composite.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/data-structure/vertex-set-path-composite.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/data-structure/vertex-set-path-composite.test.cpp
- /verify/test/library-checker/data-structure/vertex-set-path-composite.test.cpp.html
title: test/library-checker/data-structure/vertex-set-path-composite.test.cpp
---
