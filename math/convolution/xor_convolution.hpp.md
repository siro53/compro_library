---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/xor_convolution.test.cpp
    title: test/xor_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/convolution/xor_convolution.hpp\"\nnamespace xor_convolution\
    \ {\n    template<class T>\n    void fwt(vector<T> &f, bool isInverse = false)\
    \ {\n        int n = (int)f.size(); // n \u306F\u5FC5\u305A 2 \u3079\u304D\n \
    \       for(int i = 1; i < n; i <<= 1) {\n            for(int j = 0; j < n; j++)\
    \ {\n                if(j & i) continue;\n                T x = f[j], y = f[j\
    \ | i];\n                f[j] = x + y, f[j | i] = x - y;\n                if(isInverse)\
    \ {\n                    f[j] /= 2, f[j | i] /= 2;\n                }\n      \
    \      }\n        }\n    }\n\n    template<class T>\n    vector<T> convolution(vector<T>\
    \ a, vector<T> b) {\n        fwt<T>(a);\n        fwt<T>(b);\n        vector<T>\
    \ c(a.size());\n        for(int i = 0; i < (int)a.size(); i++) {\n           \
    \ c[i] = a[i] * b[i];\n        }\n        fwt<T>(c, true);\n        return c;\n\
    \    }\n};\n"
  code: "namespace xor_convolution {\n    template<class T>\n    void fwt(vector<T>\
    \ &f, bool isInverse = false) {\n        int n = (int)f.size(); // n \u306F\u5FC5\
    \u305A 2 \u3079\u304D\n        for(int i = 1; i < n; i <<= 1) {\n            for(int\
    \ j = 0; j < n; j++) {\n                if(j & i) continue;\n                T\
    \ x = f[j], y = f[j | i];\n                f[j] = x + y, f[j | i] = x - y;\n \
    \               if(isInverse) {\n                    f[j] /= 2, f[j | i] /= 2;\n\
    \                }\n            }\n        }\n    }\n\n    template<class T>\n\
    \    vector<T> convolution(vector<T> a, vector<T> b) {\n        fwt<T>(a);\n \
    \       fwt<T>(b);\n        vector<T> c(a.size());\n        for(int i = 0; i <\
    \ (int)a.size(); i++) {\n            c[i] = a[i] * b[i];\n        }\n        fwt<T>(c,\
    \ true);\n        return c;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/convolution/xor_convolution.hpp
  requiredBy: []
  timestamp: '2022-06-04 11:27:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/xor_convolution.test.cpp
documentation_of: math/convolution/xor_convolution.hpp
layout: document
redirect_from:
- /library/math/convolution/xor_convolution.hpp
- /library/math/convolution/xor_convolution.hpp.html
title: math/convolution/xor_convolution.hpp
---
