---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/barrett-reduction.hpp
    title: math/barrett-reduction.hpp
  - icon: ':heavy_check_mark:'
    path: modint/dynamic-modint.hpp
    title: modint/dynamic-modint.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc104/tasks/arc104_d
    links:
    - https://atcoder.jp/contests/arc104/tasks/arc104_d
  bundledCode: "#line 1 \"test/atcoder/arc104d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/arc104/tasks/arc104_d\"\
    \n#line 2 \"modint/dynamic-modint.hpp\"\n\n#include <cassert>\n#include <istream>\n\
    #include <ostream>\n\n#line 2 \"math/barrett-reduction.hpp\"\n\n#include <utility>\n\
    \nclass BarrettReduction {\npublic:\n    BarrettReduction(): BarrettReduction(1)\
    \ {}\n    BarrettReduction(unsigned int m)\n        : m(m), m_inv((unsigned long\
    \ long)(-1) / m + 1) {}\n    unsigned int mul(unsigned int a, unsigned int b)\
    \ const {\n        unsigned long long z = (unsigned long long)a * b;\n       \
    \ unsigned long long v =  (unsigned long long)(((__uint128_t)z * m_inv) >> 64);\n\
    \        unsigned int result = (unsigned int)(z - v * m);\n        if(m <= result)\
    \ result += m;\n        return result;\n    }\n    unsigned int quo(unsigned int\
    \ a) const {\n        unsigned int result = (unsigned int)(((__uint128_t)a * m_inv)\
    \ >> 64);\n        return result;\n    }\n    unsigned int rem(unsigned long long\
    \ a) const {\n        unsigned long long v = (unsigned long long)(((__uint128_t)a\
    \ * m_inv) >> 64);\n        unsigned int result = (unsigned int)(a - v * m);\n\
    \        if(m <= result) result += m;\n        return result;\n    }\n    std::pair<unsigned\
    \ int, unsigned int> quorem(unsigned int a) const {\n        unsigned long long\
    \ v =  (unsigned long long)(((__uint128_t)a * m_inv) >> 64);\n        unsigned\
    \ int r = (unsigned int)((unsigned long long)a - v * m);\n        if(m <= r) r\
    \ += m;\n        return {v, r};\n    }\nprivate:\n    unsigned int m;\n    unsigned\
    \ long long m_inv;\n};\n#line 8 \"modint/dynamic-modint.hpp\"\n\nclass DynamicModInt\
    \ {\n  public:\n    DynamicModInt() : x(0) {}\n    DynamicModInt(long long y)\n\
    \        : x(y >= 0\n                ? y % (long long)mod\n                : ((long\
    \ long)mod - (-y) % (long long)mod) % (long long)mod) {}\n    static void set_mod(unsigned\
    \ int m) {\n        assert(m > 0);\n        mod = m;\n        bt = BarrettReduction(m);\n\
    \    }\n    unsigned int val() const { return x; }\n    DynamicModInt &operator+=(const\
    \ DynamicModInt &p) {\n        if((x += p.x) >= mod) x -= mod;\n        return\
    \ *this;\n    }\n    DynamicModInt &operator-=(const DynamicModInt &p) {\n   \
    \     if((x += (mod - p.x)) >= mod) x -= mod;\n        return *this;\n    }\n\
    \    DynamicModInt &operator*=(const DynamicModInt &p) {\n        x = bt.mul(x,\
    \ p.x);\n        return *this;\n    }\n    DynamicModInt &operator/=(const DynamicModInt\
    \ &p) {\n        *this *= p.inv();\n        return *this;\n    }\n    DynamicModInt\
    \ operator-() const { return DynamicModInt(-x); }\n    DynamicModInt operator+(const\
    \ DynamicModInt &p) const {\n        return DynamicModInt(*this) += p;\n    }\n\
    \    DynamicModInt operator-(const DynamicModInt &p) const {\n        return DynamicModInt(*this)\
    \ -= p;\n    }\n    DynamicModInt operator*(const DynamicModInt &p) const {\n\
    \        return DynamicModInt(*this) *= p;\n    }\n    DynamicModInt operator/(const\
    \ DynamicModInt &p) const {\n        return DynamicModInt(*this) /= p;\n    }\n\
    \    bool operator==(const DynamicModInt &p) const { return x == p.x; }\n    bool\
    \ operator!=(const DynamicModInt &p) const { return x != p.x; }\n    DynamicModInt\
    \ inv() const {\n        int a = x, b = mod, u = 1, v = 0, t;\n        while(b\
    \ > 0) {\n            t = a / b;\n            std::swap(a -= t * b, b);\n    \
    \        std::swap(u -= t * v, v);\n        }\n        assert(a == 1 && \"gcd(x,\
    \ mod) must be '1'.\");\n        return DynamicModInt(u);\n    }\n    DynamicModInt\
    \ pow(long long n) const {\n        assert(n >= 0);\n        DynamicModInt ret(1),\
    \ mul(x);\n        while(n > 0) {\n            if(n & 1) ret *= mul;\n       \
    \     mul *= mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n\
    \    friend std::ostream &operator<<(std::ostream &os, const DynamicModInt &p)\
    \ {\n        return os << p.x;\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, DynamicModInt &a) {\n        long long t;\n        is >> t;\n        a\
    \ = DynamicModInt(t);\n        return (is);\n    }\n\n  private:\n    unsigned\
    \ int x;\n    static inline unsigned int mod;\n    static inline BarrettReduction\
    \ bt;\n};\n#line 1 \"template/template.cpp\"\n#pragma region Macros\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\ntemplate <class T> inline bool chmax(T\
    \ &a, T b) {\n    if(a < b) {\n        a = b;\n        return 1;\n    }\n    return\
    \ 0;\n}\ntemplate <class T> inline bool chmin(T &a, T b) {\n    if(a > b) {\n\
    \        a = b;\n        return 1;\n    }\n    return 0;\n}\n#ifdef DEBUG\ntemplate\
    \ <class T, class U>\nostream &operator<<(ostream &os, const pair<T, U> &p) {\n\
    \    os << '(' << p.first << ',' << p.second << ')';\n    return os;\n}\ntemplate\
    \ <class T> ostream &operator<<(ostream &os, const vector<T> &v) {\n    os <<\
    \ '{';\n    for(int i = 0; i < (int)v.size(); i++) {\n        if(i) { os << ',';\
    \ }\n        os << v[i];\n    }\n    os << '}';\n    return os;\n}\nvoid debugg()\
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
    \ }\n#pragma endregion Macros\n#line 4 \"test/atcoder/arc104d.test.cpp\"\n\nusing\
    \ mint = DynamicModInt;\n\nmint dp[101][1000001];\n\nint main() {\n    int N,\
    \ K, mod;\n    cin >> N >> K >> mod;\n    mint::set_mod(mod);\n    dp[0][0] =\
    \ 1;\n    int lim = 0;\n    REP(i, 1, N + 1) {\n        vector<mint> pre(i, 0);\n\
    \        lim += i;\n        REP(j, lim * K + 1) {\n            pre[j % i] += dp[i\
    \ - 1][j];\n            if(j - i * (K + 1) >= 0) pre[j % i] -= dp[i - 1][j - i\
    \ * (K + 1)];\n            dp[i][j] = pre[j % i];\n        }\n    }\n    lim =\
    \ 0;\n    REP(x, 1, N + 1) {\n        lim += x;\n        mint ans = 0;\n     \
    \   REP(j, lim * K + 1) ans += dp[N - x][j] * dp[x - 1][j];\n        ans = (ans\
    \ * (K + 1) - 1);\n        cout << ans << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc104/tasks/arc104_d\"\n#include\
    \ \"../../modint/dynamic-modint.hpp\"\n#include \"../../template/template.cpp\"\
    \n\nusing mint = DynamicModInt;\n\nmint dp[101][1000001];\n\nint main() {\n  \
    \  int N, K, mod;\n    cin >> N >> K >> mod;\n    mint::set_mod(mod);\n    dp[0][0]\
    \ = 1;\n    int lim = 0;\n    REP(i, 1, N + 1) {\n        vector<mint> pre(i,\
    \ 0);\n        lim += i;\n        REP(j, lim * K + 1) {\n            pre[j % i]\
    \ += dp[i - 1][j];\n            if(j - i * (K + 1) >= 0) pre[j % i] -= dp[i -\
    \ 1][j - i * (K + 1)];\n            dp[i][j] = pre[j % i];\n        }\n    }\n\
    \    lim = 0;\n    REP(x, 1, N + 1) {\n        lim += x;\n        mint ans = 0;\n\
    \        REP(j, lim * K + 1) ans += dp[N - x][j] * dp[x - 1][j];\n        ans\
    \ = (ans * (K + 1) - 1);\n        cout << ans << '\\n';\n    }\n}"
  dependsOn:
  - modint/dynamic-modint.hpp
  - math/barrett-reduction.hpp
  - template/template.cpp
  isVerificationFile: true
  path: test/atcoder/arc104d.test.cpp
  requiredBy: []
  timestamp: '2023-02-26 00:21:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/arc104d.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/arc104d.test.cpp
- /verify/test/atcoder/arc104d.test.cpp.html
title: test/atcoder/arc104d.test.cpp
---
