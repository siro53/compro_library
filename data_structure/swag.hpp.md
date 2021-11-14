---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/queue_operate_all_compose.test.cpp
    title: test/queue_operate_all_compose.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/swag.hpp\"\ntemplate <typename T> struct\
    \ SWAG {\n    struct Data {\n        T x, sum;\n        Data() {}\n        Data(T\
    \ x, T sum) : x(x), sum(sum) {}\n    };\n    using F = function<T(T, T)>;\n  \
    \  stack<Data> frontStack, backStack;\n    F f;\n\n    SWAG(F f) : f(f) {}\n\n\
    \    bool empty() { return (frontStack.empty() && backStack.empty()); }\n\n  \
    \  size_t size() { return frontStack.size() + backStack.size(); }\n\n    void\
    \ pop() {\n        assert(!empty());\n        if(frontStack.empty()) {\n     \
    \       frontStack.emplace(backStack.top().x, backStack.top().x);\n          \
    \  backStack.pop();\n            while(!backStack.empty()) {\n               \
    \ T s = f(backStack.top().x, frontStack.top().sum);\n                frontStack.emplace(backStack.top().x,\
    \ s);\n                backStack.pop();\n            }\n        }\n        frontStack.pop();\n\
    \    }\n\n    void push(T val) {\n        if(backStack.empty()) {\n          \
    \  backStack.emplace(val, val);\n        } else {\n            T s = f(backStack.top().sum,\
    \ val);\n            backStack.emplace(val, s);\n        }\n    }\n\n    T fold_all()\
    \ {\n        assert(!empty());\n        if(frontStack.empty()) {\n           \
    \ return backStack.top().sum;\n        } else if(backStack.empty()) {\n      \
    \      return frontStack.top().sum;\n        } else {\n            return f(frontStack.top().sum,\
    \ backStack.top().sum);\n        }\n    }\n};\n"
  code: "template <typename T> struct SWAG {\n    struct Data {\n        T x, sum;\n\
    \        Data() {}\n        Data(T x, T sum) : x(x), sum(sum) {}\n    };\n   \
    \ using F = function<T(T, T)>;\n    stack<Data> frontStack, backStack;\n    F\
    \ f;\n\n    SWAG(F f) : f(f) {}\n\n    bool empty() { return (frontStack.empty()\
    \ && backStack.empty()); }\n\n    size_t size() { return frontStack.size() + backStack.size();\
    \ }\n\n    void pop() {\n        assert(!empty());\n        if(frontStack.empty())\
    \ {\n            frontStack.emplace(backStack.top().x, backStack.top().x);\n \
    \           backStack.pop();\n            while(!backStack.empty()) {\n      \
    \          T s = f(backStack.top().x, frontStack.top().sum);\n               \
    \ frontStack.emplace(backStack.top().x, s);\n                backStack.pop();\n\
    \            }\n        }\n        frontStack.pop();\n    }\n\n    void push(T\
    \ val) {\n        if(backStack.empty()) {\n            backStack.emplace(val,\
    \ val);\n        } else {\n            T s = f(backStack.top().sum, val);\n  \
    \          backStack.emplace(val, s);\n        }\n    }\n\n    T fold_all() {\n\
    \        assert(!empty());\n        if(frontStack.empty()) {\n            return\
    \ backStack.top().sum;\n        } else if(backStack.empty()) {\n            return\
    \ frontStack.top().sum;\n        } else {\n            return f(frontStack.top().sum,\
    \ backStack.top().sum);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/swag.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/queue_operate_all_compose.test.cpp
documentation_of: data_structure/swag.hpp
layout: document
title: SWAG
---
