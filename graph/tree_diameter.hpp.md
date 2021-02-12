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
  bundledCode: "#line 1 \"graph/tree_diameter.hpp\"\nvector<int> get_diameter_path(const\
    \ vector<vector<int>> &G) {\n    int n = (int)G.size();\n    vector<int> depth(n),\
    \ par(n);\n\n    auto dfs = [&](auto &&dfs, int v, int p, int d) -> void {\n \
    \       depth[v] = d;\n        par[v] = p;\n        for(const int &u : G[v]) {\n\
    \            if(u != p) {\n                dfs(dfs, u, v, d + 1);\n          \
    \  }\n        }\n    };\n\n    dfs(dfs, 0, -1, 0);\n    int from = max_element(ALL(depth))\
    \ - depth.begin();\n    dfs(dfs, from, -1, 0);\n    int to = max_element(ALL(depth))\
    \ - depth.begin();\n\n    vector<int> res;\n    int now = to;\n    while(now !=\
    \ from) {\n        res.emplace_back(now);\n        now = par[now];\n    }\n  \
    \  res.emplace_back(now);\n\n    return res;\n}\n"
  code: "vector<int> get_diameter_path(const vector<vector<int>> &G) {\n    int n\
    \ = (int)G.size();\n    vector<int> depth(n), par(n);\n\n    auto dfs = [&](auto\
    \ &&dfs, int v, int p, int d) -> void {\n        depth[v] = d;\n        par[v]\
    \ = p;\n        for(const int &u : G[v]) {\n            if(u != p) {\n       \
    \         dfs(dfs, u, v, d + 1);\n            }\n        }\n    };\n\n    dfs(dfs,\
    \ 0, -1, 0);\n    int from = max_element(ALL(depth)) - depth.begin();\n    dfs(dfs,\
    \ from, -1, 0);\n    int to = max_element(ALL(depth)) - depth.begin();\n\n   \
    \ vector<int> res;\n    int now = to;\n    while(now != from) {\n        res.emplace_back(now);\n\
    \        now = par[now];\n    }\n    res.emplace_back(now);\n\n    return res;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree_diameter.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree_diameter.hpp
layout: document
redirect_from:
- /library/graph/tree_diameter.hpp
- /library/graph/tree_diameter.hpp.html
title: graph/tree_diameter.hpp
---
