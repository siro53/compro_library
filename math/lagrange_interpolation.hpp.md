---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/modint.hpp
    title: math/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/modint.hpp\"\ntemplate <int mod> struct ModInt {\n\
    \    using M = ModInt;\n    int x;\n    ModInt() : x(0) {}\n    ModInt(int64_t\
    \ y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n    M &operator+=(const\
    \ M &p) {\n        if((x += p.x) >= mod) x -= mod;\n        return *this;\n  \
    \  }\n    M &operator-=(const M &p) {\n        if((x += mod - p.x) >= mod) x -=\
    \ mod;\n        return *this;\n    }\n    M &operator*=(const M &p) {\n      \
    \  x = (int)(1LL * x * p.x % mod);\n        return *this;\n    }\n    M &operator/=(const\
    \ M &p) {\n        *this *= p.inverse();\n        return *this;\n    }\n    M\
    \ operator-() const { return M(-x); }\n    M operator+(const M &p) const { return\
    \ M(*this) += p; }\n    M operator-(const M &p) const { return M(*this) -= p;\
    \ }\n    M operator*(const M &p) const { return M(*this) *= p; }\n    M operator/(const\
    \ M &p) const { return M(*this) /= p; }\n    M inverse() const {\n        int\
    \ a = x, b = mod, u = 1, v = 0, t;\n        while(b > 0) {\n            t = a\
    \ / b;\n            swap(a -= t * b, b);\n            swap(u -= t * v, v);\n \
    \       }\n        return M(u);\n    }\n    M pow(int64_t n) const {\n       \
    \ M ret(1), mul(x);\n        while(n > 0) {\n            if(n & 1) ret *= mul;\n\
    \            mul *= mul;\n            n >>= 1;\n        }\n        return ret;\n\
    \    }\n    friend ostream &operator<<(ostream &os, const M &p) { return os <<\
    \ p.x; }\n    friend istream &operator>>(istream &is, M &a) {\n        int64_t\
    \ t;\n        is >> t;\n        a = M<mod>(t);\n        return (is);\n    }\n\
    \    static int get_mod() { return mod; }\n};\n#line 2 \"math/lagrange_interpolation.hpp\"\
    \n\nusing mint = ModInt<MOD>;\n\n// - \u591A\u9805\u5F0F\u88DC\u9593\uFF1An\u6B21\
    \u4EE5\u4E0B\u306E\u591A\u9805\u5F0Ff\u3092\u5177\u4F53\u7684\u306B\u6C42\u3081\
    \u308B\u306E\u304C\u96E3\u3057\u3044\u3068\u304D\u306B\u7528\u3044\u308B\u30C6\
    \u30AF\n\n// N\u6B21\u4EE5\u4E0B\u306E\u591A\u9805\u5F0Ff\u306B\u3064\u3044\u3066\
    \u3001\n// \u76F8\u7570\u306A\u308Bn+1\u500B\u306E\u70B9(x_i, y_i)\u304Cf\u3092\
    \u901A\u308B(f(x_i)=y_i\u3092\u6E80\u305F\u3059)\u3068\u304D\u3001\n// f(T)\u306E\
    \u5024\u3092\u8FD4\u3059\n// O(N^2)\nmint LagrangeInterPolation(vector<mint> x,\
    \ vector<mint> y, mint T) {\n    int N = x.size();\n    N--;\n    mint res = 0;\n\
    \    for(int i = 0; i <= N; i++) {\n        mint t = 1;\n        for(int j = 0;\
    \ j <= N; j++) {\n            if(i == j) {\n                continue;\n      \
    \      }\n            t *= T - x[j];\n            t /= (x[i] - x[j]);\n      \
    \  }\n        res += t * y[i];\n    }\n    return res;\n}\n\n// N\u6B21\u4EE5\u4E0B\
    \u306E\u591A\u9805\u5F0Ff\u306B\u3064\u3044\u3066\u3001\n// \u76F8\u7570\u306A\
    \u308Bn+1\u500B\u306E\u70B9(x_i, y_i)\u304Cf\u3092\u901A\u308B(f(x_i)=y_i\u3092\
    \u6E80\u305F\u3059)\u3068\u304D\u3001\n// f(x)\u3092\u8FD4\u3059(f(x)\u306E\u4FC2\
    \u6570\u3092\u8FD4\u3059)\n// O(N^2)\nvector<mint> LagrangeInterPolationCoef(vector<mint>\
    \ x, vector<mint> y) {\n    int N = x.size();\n    N--;\n    for(int i = 0; i\
    \ <= N; i++) {\n        mint t = 1;\n        for(int j = 0; j <= N; j++) {\n \
    \           if(i == j) {\n                continue;\n            }\n         \
    \   t *= (x[i] - x[j]);\n        }\n        y[i] /= t;\n    }\n    int now = 0;\n\
    \    int next = 1;\n    vector<vector<mint>> dp(2, vector<mint>(N + 2));\n   \
    \ dp[0][0] = -x[0];\n    dp[0][1] = 1;\n    for(int i = 1; i <= N; i++) {\n  \
    \      for(int j = 0; j <= N + 1; j++) {\n            dp[next][j] = dp[now][j]\
    \ * (-x[i]);\n            if(j >= 1) {\n                dp[next][j] += dp[now][j\
    \ - 1];\n            }\n        }\n        swap(next, now);\n    }\n    vector<mint>\
    \ xinv(N + 1);\n    for(int i = 0; i <= N; i++) {\n        xinv[i] = x[i].inverse();\n\
    \    }\n    vector<mint> res(N + 1); // f(x)\n    for(int i = 0; i <= N; i++)\
    \ {\n        if(y[i] == 0) {\n            continue;\n        }\n        // 0\u3067\
    \u5272\u3089\u306A\u3044\u3088\u3046\u306B\u5834\u5408\u5206\u3051\n        if(x[i]\
    \ == 0) {\n            for(int j = 0; j <= N; j++) {\n                res[j] +=\
    \ dp[now][j + 1] * y[i];\n            }\n        } else {\n            res[0]\
    \ -= dp[now][0] * xinv[i] * y[i];\n            mint prev = -dp[now][0] * xinv[i];\n\
    \            for(int j = 1; j <= N; j++) {\n                res[j] -= (dp[now][j]\
    \ - prev) * xinv[i] * y[i];\n                prev = (-dp[now][j] + prev) * xinv[i];\n\
    \            }\n        }\n    }\n    return res;\n}\n\n// N\u6B21\u4EE5\u4E0B\
    \u306E\u591A\u9805\u5F0Ff\u306B\u3064\u3044\u3066\u3001\n// \u76F8\u7570\u306A\
    \u308Bn+1\u500B\u306E\u70B9(x_i, y_i)\u304Cf\u3092\u901A\u308B(f(x_i)=y_i\u3092\
    \u6E80\u305F\u3059)\u3068\u304D\u3001\n// f(T)\u306E\u5024\u3092\u8FD4\u3059\n\
    // \u305F\u3060\u3057\u3001x_i = a + i * d (0<=i<=N)\u306E\u3088\u3046\u306Bx_i\u304C\
    \u7B49\u5DEE\u6570\u5217\u306B\u306A\u3063\u3066\u3044\u308B\u3068\u304D\u3001\
    \n// O(Nlog(mod)) \u3067\u6C42\u3081\u3089\u308C\u308B\n\nmint LagrangeInterPolationArithmetic(mint\
    \ a, mint d, vector<mint> y, mint T) {\n    int N = y.size();\n    N--;\n    mint\
    \ res = 0, ft = 1;\n    for(int i = 0; i <= N; i++) {\n        ft *= (T - (a +\
    \ mint(i) * d));\n    }\n    mint f = 1;\n    for(int i = 1; i <= N; i++) {\n\
    \        f *= -d * mint(i);\n    }\n    res += y[0] * ft / (T - a);\n    for(int\
    \ i = 0; i < N; i++) {\n        f *= d * mint(i + 1) / (d * mint(i - N));\n  \
    \      res += y[i + 1] / f * ft / (T - a - d * mint(i + 1));\n    }\n    return\
    \ res;\n}\n"
  code: "#include \"modint.hpp\"\n\nusing mint = ModInt<MOD>;\n\n// - \u591A\u9805\
    \u5F0F\u88DC\u9593\uFF1An\u6B21\u4EE5\u4E0B\u306E\u591A\u9805\u5F0Ff\u3092\u5177\
    \u4F53\u7684\u306B\u6C42\u3081\u308B\u306E\u304C\u96E3\u3057\u3044\u3068\u304D\
    \u306B\u7528\u3044\u308B\u30C6\u30AF\n\n// N\u6B21\u4EE5\u4E0B\u306E\u591A\u9805\
    \u5F0Ff\u306B\u3064\u3044\u3066\u3001\n// \u76F8\u7570\u306A\u308Bn+1\u500B\u306E\
    \u70B9(x_i, y_i)\u304Cf\u3092\u901A\u308B(f(x_i)=y_i\u3092\u6E80\u305F\u3059)\u3068\
    \u304D\u3001\n// f(T)\u306E\u5024\u3092\u8FD4\u3059\n// O(N^2)\nmint LagrangeInterPolation(vector<mint>\
    \ x, vector<mint> y, mint T) {\n    int N = x.size();\n    N--;\n    mint res\
    \ = 0;\n    for(int i = 0; i <= N; i++) {\n        mint t = 1;\n        for(int\
    \ j = 0; j <= N; j++) {\n            if(i == j) {\n                continue;\n\
    \            }\n            t *= T - x[j];\n            t /= (x[i] - x[j]);\n\
    \        }\n        res += t * y[i];\n    }\n    return res;\n}\n\n// N\u6B21\u4EE5\
    \u4E0B\u306E\u591A\u9805\u5F0Ff\u306B\u3064\u3044\u3066\u3001\n// \u76F8\u7570\
    \u306A\u308Bn+1\u500B\u306E\u70B9(x_i, y_i)\u304Cf\u3092\u901A\u308B(f(x_i)=y_i\u3092\
    \u6E80\u305F\u3059)\u3068\u304D\u3001\n// f(x)\u3092\u8FD4\u3059(f(x)\u306E\u4FC2\
    \u6570\u3092\u8FD4\u3059)\n// O(N^2)\nvector<mint> LagrangeInterPolationCoef(vector<mint>\
    \ x, vector<mint> y) {\n    int N = x.size();\n    N--;\n    for(int i = 0; i\
    \ <= N; i++) {\n        mint t = 1;\n        for(int j = 0; j <= N; j++) {\n \
    \           if(i == j) {\n                continue;\n            }\n         \
    \   t *= (x[i] - x[j]);\n        }\n        y[i] /= t;\n    }\n    int now = 0;\n\
    \    int next = 1;\n    vector<vector<mint>> dp(2, vector<mint>(N + 2));\n   \
    \ dp[0][0] = -x[0];\n    dp[0][1] = 1;\n    for(int i = 1; i <= N; i++) {\n  \
    \      for(int j = 0; j <= N + 1; j++) {\n            dp[next][j] = dp[now][j]\
    \ * (-x[i]);\n            if(j >= 1) {\n                dp[next][j] += dp[now][j\
    \ - 1];\n            }\n        }\n        swap(next, now);\n    }\n    vector<mint>\
    \ xinv(N + 1);\n    for(int i = 0; i <= N; i++) {\n        xinv[i] = x[i].inverse();\n\
    \    }\n    vector<mint> res(N + 1); // f(x)\n    for(int i = 0; i <= N; i++)\
    \ {\n        if(y[i] == 0) {\n            continue;\n        }\n        // 0\u3067\
    \u5272\u3089\u306A\u3044\u3088\u3046\u306B\u5834\u5408\u5206\u3051\n        if(x[i]\
    \ == 0) {\n            for(int j = 0; j <= N; j++) {\n                res[j] +=\
    \ dp[now][j + 1] * y[i];\n            }\n        } else {\n            res[0]\
    \ -= dp[now][0] * xinv[i] * y[i];\n            mint prev = -dp[now][0] * xinv[i];\n\
    \            for(int j = 1; j <= N; j++) {\n                res[j] -= (dp[now][j]\
    \ - prev) * xinv[i] * y[i];\n                prev = (-dp[now][j] + prev) * xinv[i];\n\
    \            }\n        }\n    }\n    return res;\n}\n\n// N\u6B21\u4EE5\u4E0B\
    \u306E\u591A\u9805\u5F0Ff\u306B\u3064\u3044\u3066\u3001\n// \u76F8\u7570\u306A\
    \u308Bn+1\u500B\u306E\u70B9(x_i, y_i)\u304Cf\u3092\u901A\u308B(f(x_i)=y_i\u3092\
    \u6E80\u305F\u3059)\u3068\u304D\u3001\n// f(T)\u306E\u5024\u3092\u8FD4\u3059\n\
    // \u305F\u3060\u3057\u3001x_i = a + i * d (0<=i<=N)\u306E\u3088\u3046\u306Bx_i\u304C\
    \u7B49\u5DEE\u6570\u5217\u306B\u306A\u3063\u3066\u3044\u308B\u3068\u304D\u3001\
    \n// O(Nlog(mod)) \u3067\u6C42\u3081\u3089\u308C\u308B\n\nmint LagrangeInterPolationArithmetic(mint\
    \ a, mint d, vector<mint> y, mint T) {\n    int N = y.size();\n    N--;\n    mint\
    \ res = 0, ft = 1;\n    for(int i = 0; i <= N; i++) {\n        ft *= (T - (a +\
    \ mint(i) * d));\n    }\n    mint f = 1;\n    for(int i = 1; i <= N; i++) {\n\
    \        f *= -d * mint(i);\n    }\n    res += y[0] * ft / (T - a);\n    for(int\
    \ i = 0; i < N; i++) {\n        f *= d * mint(i + 1) / (d * mint(i - N));\n  \
    \      res += y[i + 1] / f * ft / (T - a - d * mint(i + 1));\n    }\n    return\
    \ res;\n}"
  dependsOn:
  - math/modint.hpp
  isVerificationFile: false
  path: math/lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/lagrange_interpolation.hpp
layout: document
redirect_from:
- /library/math/lagrange_interpolation.hpp
- /library/math/lagrange_interpolation.hpp.html
title: math/lagrange_interpolation.hpp
---
