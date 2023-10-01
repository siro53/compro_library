---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent/persistent-queue.hpp
    title: data-structure/persistent/persistent-queue.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/persistent_queue
    links:
    - https://judge.yosupo.jp/problem/persistent_queue
  bundledCode: "#line 1 \"test/library-checker/data-structure/persistent-queue.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n#line\
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
    \ }\n#pragma endregion Macros\n#line 2 \"data-structure/persistent/persistent-queue.hpp\"\
    \n\ntemplate <class T, int LOG = 20> struct PersistentQueue {\n    struct Node\
    \ {\n        T val;\n        int idx;\n        Node *pre[LOG]; // pre[k] := \u3053\
    \u306E\u30CE\u30FC\u30C9\u306E2^k\u500B\u524D\u306E\u30CE\u30FC\u30C9\n\n    \
    \    Node(T val, int idx) : val(val), idx(idx) {}\n    };\n    Node *front_node;\n\
    \    Node *back_node;\n\n    PersistentQueue() : front_node(nullptr), back_node(nullptr)\
    \ {}\n    explicit PersistentQueue(Node *front_node, Node *back_node)\n      \
    \  : front_node(front_node), back_node(back_node) {}\n    PersistentQueue push(const\
    \ T &x) {\n        Node *new_node = new Node(x, back_node ? back_node->idx + 1\
    \ : 0);\n        new_node->pre[0] = back_node;\n        for(int i = 1; i < LOG;\
    \ i++) {\n            Node *tmp = new_node->pre[i - 1];\n            if(!tmp)\
    \ break;\n            new_node->pre[i] = tmp->pre[i - 1];\n        }\n       \
    \ return PersistentQueue(front_node ? front_node : new_node, new_node);\n    }\n\
    \    PersistentQueue pop() {\n        if(!front_node or !back_node or front_node->idx\
    \ == back_node->idx) {\n            return PersistentQueue();\n        }\n   \
    \     int sz = back_node->idx - front_node->idx - 1;\n        Node *node = back_node;\n\
    \        for(int i = 0; i < LOG; i++)\n            if(sz >> i & 1) node = node->pre[i];\n\
    \        return PersistentQueue(node, back_node);\n    }\n    bool empty() const\
    \ { return (front_node == nullptr and back_node == nullptr); }\n    T front()\
    \ const { return front_node->val; }\n    T back() const { return back_node->val;\
    \ }\n};\n#line 4 \"test/library-checker/data-structure/persistent-queue.test.cpp\"\
    \n\nint main() {\n    int Q;\n    cin >> Q;\n    vector<PersistentQueue<int>>\
    \ ques(Q + 1);\n    REP(i, Q) {\n        int mode, t, x;\n        cin >> mode\
    \ >> t;\n        auto que = ques[t + 1];\n        if(mode == 0) {\n          \
    \  cin >> x;\n            ques[i + 1] = que.push(x);\n        } else {\n     \
    \       cout << que.front() << '\\n';\n            ques[i + 1] = que.pop();\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n#include\
    \ \"../../../template/template.cpp\"\n#include \"../../../data-structure/persistent/persistent-queue.hpp\"\
    \n\nint main() {\n    int Q;\n    cin >> Q;\n    vector<PersistentQueue<int>>\
    \ ques(Q + 1);\n    REP(i, Q) {\n        int mode, t, x;\n        cin >> mode\
    \ >> t;\n        auto que = ques[t + 1];\n        if(mode == 0) {\n          \
    \  cin >> x;\n            ques[i + 1] = que.push(x);\n        } else {\n     \
    \       cout << que.front() << '\\n';\n            ques[i + 1] = que.pop();\n\
    \        }\n    }\n}"
  dependsOn:
  - template/template.cpp
  - data-structure/persistent/persistent-queue.hpp
  isVerificationFile: true
  path: test/library-checker/data-structure/persistent-queue.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/data-structure/persistent-queue.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/data-structure/persistent-queue.test.cpp
- /verify/test/library-checker/data-structure/persistent-queue.test.cpp.html
title: test/library-checker/data-structure/persistent-queue.test.cpp
---
