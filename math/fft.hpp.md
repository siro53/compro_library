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
  bundledCode: "#line 1 \"math/fft.hpp\"\nnamespace FFT {\n    using D = double;\n\
    \    struct C {\n        D x, y;\n        C() : x(0), y(0) {}\n        C(D x,\
    \ D y) : x(x), y(y) {}\n        C(complex<D> c) : x(c.real()), y(c.imag()) {}\n\
    \        inline C operator+(const C &c) const { return C(x + c.x, y + c.y); }\n\
    \        inline C operator-(const C &c) const { return C(x - c.x, y - c.y); }\n\
    \        inline C operator*(const C &c) const {\n            return C(x * c.x\
    \ - y * c.y, x * c.y + y * c.x);\n        }\n    };\n    const D PI = acosl(-1);\n\
    \n    vector<C> fft(vector<C> a, bool inv = false) {\n        int n = int(a.size());\n\
    \        int h = 0;\n        for(int i = 0; 1 << i < n; i++) h++;\n        for(int\
    \ i = 0; i < n; i++) {\n            int j = 0;\n            for(int k = 0; k <\
    \ h; k++) j |= (i >> k & 1) << (h - 1 - k);\n            if(i < j) swap(a[i],\
    \ a[j]);\n        }\n        for(int b = 1; b < n; b *= 2) {\n            for(int\
    \ j = 0; j < b; j++) {\n                C w = C(polar<D>(1, (2 * PI) / (2 * b)\
    \ * j * (inv ? 1 : -1)));\n                for(int k = 0; k < n; k += 2 * b) {\n\
    \                    C s = a[j + k], t = a[j + k + b] * w;\n                 \
    \   a[j + k] = s + t, a[j + k + b] = s - t;\n                }\n            }\n\
    \        }\n        if(inv) {\n            for(int i = 0; i < n; i++) a[i] = C(a[i].x\
    \ / n, a[i].y / n);\n        }\n        return a;\n    }\n    vector<C> fft(vector<D>\
    \ a, bool inv = false) {\n        vector<C> A(a.size());\n        for(int i =\
    \ 0; i < int(a.size()); i++) A[i] = C(a[i], 0);\n        return fft(A, inv);\n\
    \    }\n    vector<D> conv(vector<D> a, vector<D> b) {\n        int s = int(a.size()\
    \ + b.size()) - 1;\n        int t = 1;\n        while(t < s) t *= 2;\n       \
    \ a.resize(t), b.resize(t);\n        vector<C> A = fft(a), B = fft(b);\n     \
    \   for(int i = 0; i < t; i++) A[i] = A[i] * B[i];\n        A = fft(A, true);\n\
    \        a.resize(s);\n        for(int i = 0; i < s; i++) a[i] = A[i].x;\n   \
    \     return a;\n    }\n} // namespace FFT\n"
  code: "namespace FFT {\n    using D = double;\n    struct C {\n        D x, y;\n\
    \        C() : x(0), y(0) {}\n        C(D x, D y) : x(x), y(y) {}\n        C(complex<D>\
    \ c) : x(c.real()), y(c.imag()) {}\n        inline C operator+(const C &c) const\
    \ { return C(x + c.x, y + c.y); }\n        inline C operator-(const C &c) const\
    \ { return C(x - c.x, y - c.y); }\n        inline C operator*(const C &c) const\
    \ {\n            return C(x * c.x - y * c.y, x * c.y + y * c.x);\n        }\n\
    \    };\n    const D PI = acosl(-1);\n\n    vector<C> fft(vector<C> a, bool inv\
    \ = false) {\n        int n = int(a.size());\n        int h = 0;\n        for(int\
    \ i = 0; 1 << i < n; i++) h++;\n        for(int i = 0; i < n; i++) {\n       \
    \     int j = 0;\n            for(int k = 0; k < h; k++) j |= (i >> k & 1) <<\
    \ (h - 1 - k);\n            if(i < j) swap(a[i], a[j]);\n        }\n        for(int\
    \ b = 1; b < n; b *= 2) {\n            for(int j = 0; j < b; j++) {\n        \
    \        C w = C(polar<D>(1, (2 * PI) / (2 * b) * j * (inv ? 1 : -1)));\n    \
    \            for(int k = 0; k < n; k += 2 * b) {\n                    C s = a[j\
    \ + k], t = a[j + k + b] * w;\n                    a[j + k] = s + t, a[j + k +\
    \ b] = s - t;\n                }\n            }\n        }\n        if(inv) {\n\
    \            for(int i = 0; i < n; i++) a[i] = C(a[i].x / n, a[i].y / n);\n  \
    \      }\n        return a;\n    }\n    vector<C> fft(vector<D> a, bool inv =\
    \ false) {\n        vector<C> A(a.size());\n        for(int i = 0; i < int(a.size());\
    \ i++) A[i] = C(a[i], 0);\n        return fft(A, inv);\n    }\n    vector<D> conv(vector<D>\
    \ a, vector<D> b) {\n        int s = int(a.size() + b.size()) - 1;\n        int\
    \ t = 1;\n        while(t < s) t *= 2;\n        a.resize(t), b.resize(t);\n  \
    \      vector<C> A = fft(a), B = fft(b);\n        for(int i = 0; i < t; i++) A[i]\
    \ = A[i] * B[i];\n        A = fft(A, true);\n        a.resize(s);\n        for(int\
    \ i = 0; i < s; i++) a[i] = A[i].x;\n        return a;\n    }\n} // namespace\
    \ FFT"
  dependsOn: []
  isVerificationFile: false
  path: math/fft.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fft.hpp
layout: document
redirect_from:
- /library/math/fft.hpp
- /library/math/fft.hpp.html
title: math/fft.hpp
---
