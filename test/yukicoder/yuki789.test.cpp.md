---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/add.hpp
    title: data-structure/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/dynamic-segtree.hpp
    title: Dynamic Segment Tree
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
    PROBLEM: https://yukicoder.me/problems/no/789
    links:
    - https://yukicoder.me/problems/no/789
  bundledCode: "#line 1 \"test/yukicoder/yuki789.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/789\"\
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
    \ }\n#pragma endregion Macros\n#line 2 \"data-structure/segtree/dynamic-segtree.hpp\"\
    \n\n#line 6 \"data-structure/segtree/dynamic-segtree.hpp\"\n\ntemplate <class\
    \ Monoid, long long id_min, long long id_max>\nclass DynamicSegtree {\n  public:\n\
    \    using T = typename Monoid::value_type;\n\n    explicit DynamicSegtree() :\
    \ root(nullptr) {}\n\n    void set(long long p, T val) { set(root, id_min, id_max,\
    \ p, val); }\n    T get(long long p) { return get(root, id_min, id_max, p); }\n\
    \    T prod(long long l, long long r) { return prod(root, id_min, id_max, l, r);\
    \ }\n \n  private:\n    struct Node {\n        T val;\n        std::array<Node\
    \ *, 2> ch;\n        Node() : val(Monoid::e()), ch({nullptr, nullptr}) {}\n  \
    \      Node(T val) : val(val), ch({nullptr, nullptr}) {}\n    };\n\n    Node *root;\n\
    \n    void set(Node *&node, long long l, long long r, long long p, T val) {\n\
    \        if(node == nullptr) node = new Node();\n        if(r - l == 1) {\n  \
    \          node->val = val;\n            return;\n        }\n        long long\
    \ mid = (l + r) / 2;\n        if(p < mid)\n            set(node->ch[0], l, mid,\
    \ p, val);\n        else\n            set(node->ch[1], mid, r, p, val);\n    \
    \    node->val =\n            Monoid::op(node->ch[0] == nullptr ? Monoid::e()\
    \ : node->ch[0]->val,\n                       node->ch[1] == nullptr ? Monoid::e()\
    \ : node->ch[1]->val);\n    }\n\n    T get(Node *&node, long long l, long long\
    \ r, long long p) {\n        if(node == nullptr) return Monoid::e();\n       \
    \ if(r - l == 1) return node->val;\n        long long mid = (l + r) / 2;\n   \
    \     if(p < mid)\n            return get(node->ch[0], l, mid, p);\n        else\n\
    \            return get(node->ch[1], mid, r, p);\n    }\n\n    T prod(Node *&node,\
    \ long long l, long long r, long long ql, long long qr) {\n        if(node ==\
    \ nullptr or (qr <= l or r <= ql)) return Monoid::e();\n        if(ql <= l and\
    \ r <= qr) return node->val;\n        long long mid = (l + r) / 2;\n        return\
    \ Monoid::op(prod(node->ch[0], l, mid, ql, qr),\n                          prod(node->ch[1],\
    \ mid, r, ql, qr));\n    }\n};\n#line 2 \"data-structure/monoid/add.hpp\"\n\n\
    template <typename T> struct MonoidAdd {\n    using value_type = T;\n    inline\
    \ static T op(const T &l, const T &r) { return (l + r); }\n    inline static T\
    \ e() { return T(0); }\n};\n#line 5 \"test/yukicoder/yuki789.test.cpp\"\n\nint\
    \ main() {\n    int Q;\n    cin >> Q;\n    DynamicSegtree<MonoidAdd<ll>, 0, 1000000002>\
    \ seg;\n    ll ans = 0;\n    while(Q--) {\n        int type;\n        cin >> type;\n\
    \        if(type == 0) {\n            ll x, y;\n            cin >> x >> y;\n \
    \           seg.set(x, seg.get(x) + y);\n        } else {\n            ll l, r;\n\
    \            cin >> l >> r;\n            r++;\n            ans += seg.prod(l,\
    \ r);\n        }\n    }\n    cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/789\"\n#include \"../../template/template.cpp\"\
    \n#include \"../../data-structure/segtree/dynamic-segtree.hpp\"\n#include \"../../data-structure/monoid/add.hpp\"\
    \n\nint main() {\n    int Q;\n    cin >> Q;\n    DynamicSegtree<MonoidAdd<ll>,\
    \ 0, 1000000002> seg;\n    ll ans = 0;\n    while(Q--) {\n        int type;\n\
    \        cin >> type;\n        if(type == 0) {\n            ll x, y;\n       \
    \     cin >> x >> y;\n            seg.set(x, seg.get(x) + y);\n        } else\
    \ {\n            ll l, r;\n            cin >> l >> r;\n            r++;\n    \
    \        ans += seg.prod(l, r);\n        }\n    }\n    cout << ans << endl;\n}"
  dependsOn:
  - template/template.cpp
  - data-structure/segtree/dynamic-segtree.hpp
  - data-structure/monoid/add.hpp
  isVerificationFile: true
  path: test/yukicoder/yuki789.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/yuki789.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/yuki789.test.cpp
- /verify/test/yukicoder/yuki789.test.cpp.html
title: test/yukicoder/yuki789.test.cpp
---
