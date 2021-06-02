---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/BIT.hpp
    title: data_structure/BIT.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/inversion_number.test.cpp
    title: test/inversion_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/BIT.hpp\"\ntemplate <typename T> struct BIT\
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
    \    }\n};\n#line 2 \"data_structure/inversion_number.hpp\"\n\n// v\u306F {0,\
    \ 1, ... , N-1} \u304B\u3089\u306A\u308B\u91CD\u8907\u3092\u8A31\u3057\u305F\u6570\
    \u5217\n// \u3053\u306E\u6570\u5217\u306E\u8EE2\u5012\u6570\u3092\u8FD4\u3059\n\
    template<class T>\nT inversion_number(const vector<int>& v) {\n    int N = (int)v.size();\n\
    \    BIT<int> bt(N);\n    T res = 0;\n    for(int i = 0; i < N; i++) {\n     \
    \   res += i - bt.sum(v[i]+1);\n        bt.add(v[i], 1);\n    }\n    return res;\n\
    }\n"
  code: "#include \"BIT.hpp\"\n\n// v\u306F {0, 1, ... , N-1} \u304B\u3089\u306A\u308B\
    \u91CD\u8907\u3092\u8A31\u3057\u305F\u6570\u5217\n// \u3053\u306E\u6570\u5217\u306E\
    \u8EE2\u5012\u6570\u3092\u8FD4\u3059\ntemplate<class T>\nT inversion_number(const\
    \ vector<int>& v) {\n    int N = (int)v.size();\n    BIT<int> bt(N);\n    T res\
    \ = 0;\n    for(int i = 0; i < N; i++) {\n        res += i - bt.sum(v[i]+1);\n\
    \        bt.add(v[i], 1);\n    }\n    return res;\n}"
  dependsOn:
  - data_structure/BIT.hpp
  isVerificationFile: false
  path: data_structure/inversion_number.hpp
  requiredBy: []
  timestamp: '2021-06-02 11:19:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/inversion_number.test.cpp
documentation_of: data_structure/inversion_number.hpp
layout: document
redirect_from:
- /library/data_structure/inversion_number.hpp
- /library/data_structure/inversion_number.hpp.html
title: data_structure/inversion_number.hpp
---
