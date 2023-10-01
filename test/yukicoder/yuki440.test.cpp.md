---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/convolution/fft.hpp
    title: math/convolution/fft.hpp
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
    PROBLEM: https://yukicoder.me/problems/no/206
    links:
    - https://yukicoder.me/problems/no/206
  bundledCode: "#line 1 \"test/yukicoder/yuki440.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/206\"\
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
    \ }\n#pragma endregion Macros\n#line 2 \"math/convolution/fft.hpp\"\n\n#line 7\
    \ \"math/convolution/fft.hpp\"\n\nnamespace fft {\n    template <typename D> struct\
    \ Complex {\n        D x, y;\n        Complex(): x(0), y(0) {};\n        Complex(D\
    \ x, D y) : x(x), y(y) {}\n        Complex &operator+=(const Complex &c) {\n \
    \           x += c.x;\n            y += c.y;\n            return (*this);\n  \
    \      }\n        Complex &operator-=(const Complex &c) {\n            x -= c.x;\n\
    \            y -= c.y;\n            return (*this);\n        }\n        Complex\
    \ &operator*=(const Complex &c) {\n            D nx = x * c.x - y * c.y;\n   \
    \         D ny = x * c.y + y * c.x;\n            x = nx, y = ny;\n           \
    \ return (*this);\n        }\n        Complex &operator/=(const Complex& c) {\n\
    \            D nx = (x * c.x + y * c.y) / (c.x * c.x + c.y * c.y);\n         \
    \   D ny = (y * c.x - x * c.y) / (c.x * c.x + c.y * c.y);\n            x = nx,\
    \ y = ny;\n            return (*this);\n        }\n        Complex operator-()\
    \ const { return Complex(-x, -y); }\n        Complex operator+(const Complex &c)\
    \ const { return Complex(*this) += c; }\n        Complex operator-(const Complex\
    \ &c) const { return Complex(*this) -= c; }\n        Complex operator*(const Complex\
    \ &c) const { return Complex(*this) *= c; }\n        Complex operator/(const Complex\
    \ &c) const { return Complex(*this) /= c; }\n    };\n\n    template<typename D>\n\
    \    constexpr const D PI = std::acos(D(-1));\n\n    template<typename D>\n  \
    \  inline Complex<D> omega(int k, int n) {\n        return Complex<D>(std::cos(D(k)\
    \ * 2 * PI<D> / n), std::sin(D(k) * 2 * PI<D> / n));\n    }\n\n    inline int\
    \ revbit(int mask, int bitlen) {\n        int res = 0;\n        while(bitlen--)\
    \ {\n            res = (res << 1) | (mask & 1);\n            mask >>= 1;\n   \
    \     }\n        return res;\n    }\n\n    template<typename D>\n    void fft(std::vector<Complex<D>>&\
    \ a, int bitlen) {\n        int n = (int)a.size();\n        int len = n;\n   \
    \     while(len > 1) {\n            for(int i = 0; i < n; i += len) {\n      \
    \          int t = len >> 1;\n                for(int j = 0; j < t; j++) {\n \
    \                   int p = i + j;\n                    auto l = a[p] + a[p +\
    \ t];\n                    auto r = (a[p] - a[p + t]) * omega<D>(j, len);\n  \
    \                  a[p] = l;\n                    a[p + t] = r;\n            \
    \    }\n            }\n            len >>= 1;\n        }\n        for(int i =\
    \ 0; i < n; i++) {\n            int j = revbit(i, bitlen);\n            if(i <\
    \ j) std::swap(a[i], a[j]);\n        }\n    }\n\n    template<typename D>\n  \
    \  void ifft(std::vector<Complex<D>>& a, int bitlen) {\n        int n = (int)a.size();\n\
    \        for(int i = 0; i < n; i++) {\n            int j = revbit(i, bitlen);\n\
    \            if(i < j) std::swap(a[i], a[j]);\n        }\n        int len = 2;\n\
    \        while(len <= n) {\n            for(int i = 0; i < n; i += len) {\n  \
    \              int t = len >> 1;\n                for(int j = 0; j < t; j++) {\n\
    \                    int p = i + j;\n                    auto l = a[p] + a[p +\
    \ t] * omega<D>(-j, len);\n                    auto r = a[p] - a[p + t] * omega<D>(-j,\
    \ len);\n                    a[p] = l;\n                    a[p + t] = r;\n  \
    \              }\n            }\n            len <<= 1;\n        }\n        for(int\
    \ i = 0; i < n; i++) a[i] /= Complex<D>(n, 0);\n    }\n\n    template<typename\
    \ D>\n    std::vector<D> convolution(const std::vector<D>& a, const std::vector<D>&\
    \ b) {\n        int m = (int)a.size() + (int)b.size() - 1;\n        int n = 1,\
    \ bitlen = 0;\n        while(n < m) {\n            n <<= 1;\n            bitlen++;\n\
    \        }\n        std::vector<Complex<D>> A(n), B(n);\n        for(int i = 0;\
    \ i < (int)a.size(); i++) A[i] = Complex<D>(a[i], 0);\n        for(int i = 0;\
    \ i < (int)b.size(); i++) B[i] = Complex<D>(b[i], 0);\n        fft<D>(A, bitlen);\n\
    \        fft<D>(B, bitlen);\n        for(int i = 0; i < n; i++) A[i] *= B[i];\n\
    \        ifft<D>(A, bitlen);\n        std::vector<D> res(m);\n        for(int\
    \ i = 0; i < m; i++) res[i] = A[i].x;\n        return res;\n    } \n}; // namespace\
    \ fft\n#line 4 \"test/yukicoder/yuki440.test.cpp\"\n\nint main() {\n    int L,\
    \ M, N;\n    cin >> L >> M >> N;\n    vector<double> fa(N+1, 0), fb(N+1, 0);\n\
    \    REP(i, L) {\n        int a;\n        cin >> a;\n        fa[a] += 1;\n   \
    \ }\n    REP(i, M) {\n        int b;\n        cin >> b;\n        fb[N - b] +=\
    \ 1;\n    }\n    auto c = fft::convolution<double>(fa, fb);\n    int Q;\n    cin\
    \ >> Q;\n    REP(v, Q) cout << (ll)(c[N + v] + 0.5) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/206\"\n#include \"../../template/template.cpp\"\
    \n#include \"../../math/convolution/fft.hpp\"\n\nint main() {\n    int L, M, N;\n\
    \    cin >> L >> M >> N;\n    vector<double> fa(N+1, 0), fb(N+1, 0);\n    REP(i,\
    \ L) {\n        int a;\n        cin >> a;\n        fa[a] += 1;\n    }\n    REP(i,\
    \ M) {\n        int b;\n        cin >> b;\n        fb[N - b] += 1;\n    }\n  \
    \  auto c = fft::convolution<double>(fa, fb);\n    int Q;\n    cin >> Q;\n   \
    \ REP(v, Q) cout << (ll)(c[N + v] + 0.5) << '\\n';\n}"
  dependsOn:
  - template/template.cpp
  - math/convolution/fft.hpp
  isVerificationFile: true
  path: test/yukicoder/yuki440.test.cpp
  requiredBy: []
  timestamp: '2023-09-26 00:54:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/yuki440.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/yuki440.test.cpp
- /verify/test/yukicoder/yuki440.test.cpp.html
title: test/yukicoder/yuki440.test.cpp
---
