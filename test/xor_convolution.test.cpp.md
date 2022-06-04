---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/convolution/xor_convolution.hpp
    title: math/convolution/xor_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: "\u7AF6\u30D7\u30ED\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "#line 1 \"test/xor_convolution.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#line 1 \"template/template.cpp\"\n#pragma region Macros\n#include <bits/stdc++.h>\n\
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
    \ UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\n#define SZ(v)\
    \ ((int)(v).size())\nconst int INF = 1 << 30;\nconst ll LLINF = 1LL << 60;\nconstexpr\
    \ int MOD = 1000000007;\nconstexpr int MOD2 = 998244353;\nconst int dx[4] = {1,\
    \ 0, -1, 0};\nconst int dy[4] = {0, 1, 0, -1};\n\nvoid Case(int i) { cout << \"\
    Case #\" << i << \": \"; }\nint popcount(int x) { return __builtin_popcount(x);\
    \ }\nll popcount(ll x) { return __builtin_popcountll(x); }\n#pragma endregion\
    \ Macros\n#line 1 \"math/modint.hpp\"\ntemplate <int mod> struct ModInt {\n  \
    \  int x;\n    ModInt() : x(0) {}\n    ModInt(int64_t y) : x(y >= 0 ? y % mod\
    \ : (mod - (-y) % mod) % mod) {}\n    ModInt &operator+=(const ModInt &p) {\n\
    \        if((x += p.x) >= mod)\n            x -= mod;\n        return *this;\n\
    \    }\n    ModInt &operator-=(const ModInt &p) {\n        if((x += mod - p.x)\
    \ >= mod)\n            x -= mod;\n        return *this;\n    }\n    ModInt &operator*=(const\
    \ ModInt &p) {\n        x = (int)(1LL * x * p.x % mod);\n        return *this;\n\
    \    }\n    ModInt &operator/=(const ModInt &p) {\n        *this *= p.inv();\n\
    \        return *this;\n    }\n    ModInt operator-() const { return ModInt(-x);\
    \ }\n    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p;\
    \ }\n    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p;\
    \ }\n    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p;\
    \ }\n    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p;\
    \ }\n    bool operator==(const ModInt &p) const { return x == p.x; }\n    bool\
    \ operator!=(const ModInt &p) const { return x != p.x; }\n    ModInt inv() const\
    \ {\n        int a = x, b = mod, u = 1, v = 0, t;\n        while(b > 0) {\n  \
    \          t = a / b;\n            swap(a -= t * b, b);\n            swap(u -=\
    \ t * v, v);\n        }\n        return ModInt(u);\n    }\n    ModInt pow(int64_t\
    \ n) const {\n        ModInt ret(1), mul(x);\n        while(n > 0) {\n       \
    \     if(n & 1)\n                ret *= mul;\n            mul *= mul;\n      \
    \      n >>= 1;\n        }\n        return ret;\n    }\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) {\n        return os << p.x;\n    }\n    friend istream\
    \ &operator>>(istream &is, ModInt &a) {\n        int64_t t;\n        is >> t;\n\
    \        a = ModInt<mod>(t);\n        return (is);\n    }\n    static int get_mod()\
    \ { return mod; }\n};\n#line 5 \"test/xor_convolution.test.cpp\"\nusing mint =\
    \ ModInt<MOD2>;\n#line 1 \"math/convolution/xor_convolution.hpp\"\nnamespace xor_convolution\
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
    \    }\n};\n#line 7 \"test/xor_convolution.test.cpp\"\n\nint main() {\n    int\
    \ N;\n    cin >> N;\n    vector<mint> a(1 << N), b(1 << N);\n    REP(i, 1 << N)\
    \ cin >> a[i];\n    REP(i, 1 << N) cin >> b[i];\n    auto c = xor_convolution::convolution<mint>(a,\
    \ b);\n    REP(i, 1 << N) cout << c[i] << \" \\n\"[i == (1 << N) - 1];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include \"../template/template.cpp\"\n#include \"../math/modint.hpp\"\nusing\
    \ mint = ModInt<MOD2>;\n#include \"../math/convolution/xor_convolution.hpp\"\n\
    \nint main() {\n    int N;\n    cin >> N;\n    vector<mint> a(1 << N), b(1 <<\
    \ N);\n    REP(i, 1 << N) cin >> a[i];\n    REP(i, 1 << N) cin >> b[i];\n    auto\
    \ c = xor_convolution::convolution<mint>(a, b);\n    REP(i, 1 << N) cout << c[i]\
    \ << \" \\n\"[i == (1 << N) - 1];\n}"
  dependsOn:
  - template/template.cpp
  - math/modint.hpp
  - math/convolution/xor_convolution.hpp
  isVerificationFile: true
  path: test/xor_convolution.test.cpp
  requiredBy: []
  timestamp: '2022-06-04 11:27:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/xor_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/xor_convolution.test.cpp
- /verify/test/xor_convolution.test.cpp.html
title: test/xor_convolution.test.cpp
---
