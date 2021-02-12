---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/trie.hpp\"\nstruct Trie {\n    const char base;\n\
    \    struct Node {\n        vector<int> child; // \u5B50\u306E\u9802\u70B9\u756A\
    \u53F7 \u5B58\u5728\u3057\u306A\u3051\u308C\u3070-1\n        vector<int> ac; \
    \   // \u53D7\u7406\u72B6\u614B\u306B\u306A\u308B\u6587\u5B57\u5217\u306Eid\u96C6\
    \u5408\n        char c;            // \u9802\u70B9\u3092\u8868\u3059\u6587\u5B57\
    \n        int common;        // \u3053\u306Enode\u3092\u5171\u6709\u3059\u308B\
    \u6587\u5B57\u5217\u306E\u500B\u6570\n        Node(char c) : c(c), common(0) {\
    \ child.assign(26, -1); }\n    };\n    vector<Node> nodes;\n    char root;\n \
    \   Trie(char base) : root(0), base(base) { nodes.emplace_back(Node(root)); }\n\
    \    void insert(const string &s, int wid) {\n        int now = 0;\n        for(int\
    \ i = 0; i < (int)s.size(); i++) {\n            int &nxt = nodes[now].child[s[i]\
    \ - base];\n            if(nxt == -1) {\n                nxt = (int)nodes.size();\n\
    \                nodes.emplace_back(Node(s[i]));\n            }\n            nodes[now].common++;\n\
    \            now = nxt;\n        }\n        nodes[now].common++;\n        nodes[now].ac.emplace_back(wid);\n\
    \    }\n    void insert(const string &s) { insert(s, nodes[0].common); }\n   \
    \ // prefix\u3092\u6301\u3064\u6587\u5B57\u5217\u304C\u3042\u308B\u304B\u3069\u3046\
    \u304B\u8ABF\u3079\u305F\u3044\u5834\u5408\u306F\u3001\u5F15\u6570prefix\u306B\
    true\u3092\u30BB\u30C3\u30C8\u3059\u308B\n    bool search(const string &s, bool\
    \ prefix = false) {\n        int now = 0;\n        for(int i = 0; i < (int)s.size();\
    \ i++) {\n            int &nxt = nodes[now].child[s[i] - base];\n            if(nxt\
    \ == -1) {\n                return false;\n            }\n            now = nxt;\n\
    \        }\n        return (prefix ? true : (nodes[now].ac.size() > 0));\n   \
    \ }\n    int count() const { return (nodes[0].common); }\n    int size() const\
    \ { return ((int)nodes.size()); }\n};\n"
  code: "struct Trie {\n    const char base;\n    struct Node {\n        vector<int>\
    \ child; // \u5B50\u306E\u9802\u70B9\u756A\u53F7 \u5B58\u5728\u3057\u306A\u3051\
    \u308C\u3070-1\n        vector<int> ac;    // \u53D7\u7406\u72B6\u614B\u306B\u306A\
    \u308B\u6587\u5B57\u5217\u306Eid\u96C6\u5408\n        char c;            // \u9802\
    \u70B9\u3092\u8868\u3059\u6587\u5B57\n        int common;        // \u3053\u306E\
    node\u3092\u5171\u6709\u3059\u308B\u6587\u5B57\u5217\u306E\u500B\u6570\n     \
    \   Node(char c) : c(c), common(0) { child.assign(26, -1); }\n    };\n    vector<Node>\
    \ nodes;\n    char root;\n    Trie(char base) : root(0), base(base) { nodes.emplace_back(Node(root));\
    \ }\n    void insert(const string &s, int wid) {\n        int now = 0;\n     \
    \   for(int i = 0; i < (int)s.size(); i++) {\n            int &nxt = nodes[now].child[s[i]\
    \ - base];\n            if(nxt == -1) {\n                nxt = (int)nodes.size();\n\
    \                nodes.emplace_back(Node(s[i]));\n            }\n            nodes[now].common++;\n\
    \            now = nxt;\n        }\n        nodes[now].common++;\n        nodes[now].ac.emplace_back(wid);\n\
    \    }\n    void insert(const string &s) { insert(s, nodes[0].common); }\n   \
    \ // prefix\u3092\u6301\u3064\u6587\u5B57\u5217\u304C\u3042\u308B\u304B\u3069\u3046\
    \u304B\u8ABF\u3079\u305F\u3044\u5834\u5408\u306F\u3001\u5F15\u6570prefix\u306B\
    true\u3092\u30BB\u30C3\u30C8\u3059\u308B\n    bool search(const string &s, bool\
    \ prefix = false) {\n        int now = 0;\n        for(int i = 0; i < (int)s.size();\
    \ i++) {\n            int &nxt = nodes[now].child[s[i] - base];\n            if(nxt\
    \ == -1) {\n                return false;\n            }\n            now = nxt;\n\
    \        }\n        return (prefix ? true : (nodes[now].ac.size() > 0));\n   \
    \ }\n    int count() const { return (nodes[0].common); }\n    int size() const\
    \ { return ((int)nodes.size()); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie.hpp
layout: document
redirect_from:
- /library/string/trie.hpp
- /library/string/trie.hpp.html
title: string/trie.hpp
---
