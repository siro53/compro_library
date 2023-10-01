---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/convolution/ntt.hpp
    title: math/convolution/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: math/pow_mod.hpp
    title: math/pow_mod.hpp
  - icon: ':heavy_check_mark:'
    path: math/primitive-root.hpp
    title: math/primitive-root.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint.hpp
    title: modint/modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"test/library-checker/convolution/convolution-mod.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n#line 1\
    \ \"template/template.cpp\"\n#pragma region Macros\n#include <bits/stdc++.h>\n\
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
    \ }\n#pragma endregion Macros\n#line 2 \"modint/modint.hpp\"\n\n#line 6 \"modint/modint.hpp\"\
    \n\ntemplate <int mod> class ModInt {\n  public:\n    ModInt() : x(0) {}\n   \
    \ ModInt(long long y)\n        : x(y >= 0 ? y % umod() : (umod() - (-y) % umod())\
    \ % umod()) {}\n    unsigned int val() const { return x; }\n    ModInt &operator+=(const\
    \ ModInt &p) {\n        if((x += p.x) >= umod()) x -= umod();\n        return\
    \ *this;\n    }\n    ModInt &operator-=(const ModInt &p) {\n        if((x += umod()\
    \ - p.x) >= umod()) x -= umod();\n        return *this;\n    }\n    ModInt &operator*=(const\
    \ ModInt &p) {\n        x = (unsigned int)(1ULL * x * p.x % umod());\n       \
    \ return *this;\n    }\n    ModInt &operator/=(const ModInt &p) {\n        *this\
    \ *= p.inv();\n        return *this;\n    }\n    ModInt operator-() const { return\
    \ ModInt(-(long long)x); }\n    ModInt operator+(const ModInt &p) const { return\
    \ ModInt(*this) += p; }\n    ModInt operator-(const ModInt &p) const { return\
    \ ModInt(*this) -= p; }\n    ModInt operator*(const ModInt &p) const { return\
    \ ModInt(*this) *= p; }\n    ModInt operator/(const ModInt &p) const { return\
    \ ModInt(*this) /= p; }\n    bool operator==(const ModInt &p) const { return x\
    \ == p.x; }\n    bool operator!=(const ModInt &p) const { return x != p.x; }\n\
    \    ModInt inv() const {\n        long long a = x, b = mod, u = 1, v = 0, t;\n\
    \        while(b > 0) {\n            t = a / b;\n            std::swap(a -= t\
    \ * b, b);\n            std::swap(u -= t * v, v);\n        }\n        return ModInt(u);\n\
    \    }\n    ModInt pow(unsigned long long n) const {\n        ModInt ret(1), mul(x);\n\
    \        while(n > 0) {\n            if(n & 1) ret *= mul;\n            mul *=\
    \ mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const ModInt &p) {\n        return\
    \ os << p.x;\n    }\n    friend std::istream &operator>>(std::istream &is, ModInt\
    \ &a) {\n        long long t;\n        is >> t;\n        a = ModInt<mod>(t);\n\
    \        return (is);\n    }\n    static constexpr int get_mod() { return mod;\
    \ }\n\n  private:\n    unsigned int x;\n    static constexpr unsigned int umod()\
    \ { return mod; }\n};\n#line 2 \"math/convolution/ntt.hpp\"\n\n#line 6 \"math/convolution/ntt.hpp\"\
    \n\n#line 2 \"math/primitive-root.hpp\"\n\n#line 2 \"math/pow_mod.hpp\"\n\nconstexpr\
    \ long long pow_mod(long long x, long long k, long long m) {\n    long long res\
    \ = 1;\n    long long mul = (x >= 0 ? x % m : x % m + m);\n    while(k) {\n  \
    \      if(k & 1) res = (__int128_t)res * mul % m;\n        mul = (__int128_t)mul\
    \ * mul % m;\n        k >>= 1;\n    }\n    return res;\n}\n#line 4 \"math/primitive-root.hpp\"\
    \n\nconstexpr int primitive_root(int p) {\n    if(p == 2) return 1;\n    if(p\
    \ == 998244353) return 3;\n    int primes[31] = {};\n    int sz = 0, t = p - 1;\n\
    \    for(int i = 2; i * i <= t; i++) {\n        if(t % i == 0) {\n           \
    \ primes[sz++] = i;\n            while(t % i == 0) t /= i;\n        }\n    }\n\
    \    if(t > 1) primes[sz++] = t;\n    for(int g = 2;;g++) {\n        bool f =\
    \ true;\n        for(int i = 0; i < sz; i++) {\n            if(pow_mod(g, (p -\
    \ 1) / primes[i], p) == 1) {\n                f = false;\n                break;\n\
    \            }\n        }   \n        if(f) return g;\n    }\n}\n#line 9 \"math/convolution/ntt.hpp\"\
    \n\nnamespace ntt {\n    constexpr int exp_limit(int mod) { return __builtin_ctz(mod\
    \ - 1); }\n\n    template <class mint, int mod = mint::get_mod(),\n          \
    \    int g = primitive_root(mod)>\n    struct ntt_info {\n        static constexpr\
    \ int limit = exp_limit(mod);\n        std::array<mint, limit + 1> root;\n   \
    \     std::array<mint, limit + 1> iroot;\n\n        ntt_info() {\n           \
    \ root[limit] = mint(g).pow((mod - 1) >> limit);\n            iroot[limit] = root[limit].inv();\n\
    \            for(int i = limit - 1; i >= 0; i--) {\n                root[i] =\
    \ root[i + 1] * root[i + 1];\n                iroot[i] = iroot[i + 1] * iroot[i\
    \ + 1];\n            }\n        }\n    };\n\n    inline uint64_t revbit(uint64_t\
    \ mask) {\n        int b = __builtin_clzll(mask);\n        uint64_t x = mask;\n\
    \        x = (x >> 32) | (x << 32);\n        x = ((x >> 16) & 0x0000FFFF0000FFFF)\
    \ | ((x << 16) & 0xFFFF0000FFFF0000);\n        x = ((x >> 8) & 0x00FF00FF00FF00FF)\
    \ | ((x << 8) & 0xFF00FF00FF00FF00);\n        x = ((x >> 4) & 0x0F0F0F0F0F0F0F0F)\
    \ | ((x << 4) & 0xF0F0F0F0F0F0F0F0);\n        x = ((x >> 2) & 0x3333333333333333)\
    \ | ((x << 2) & 0xCCCCCCCCCCCCCCCC);\n        x = ((x >> 1) & 0x5555555555555555)\
    \ | ((x << 1) & 0xAAAAAAAAAAAAAAAA);\n        return (x >> b);\n    }\n\n    template<class\
    \ mint>\n    void ntt(std::vector<mint>& a) {\n        int n = (int)a.size();\n\
    \        int bitlen = __builtin_ctz(n);\n        static const ntt_info<mint> info;\n\
    \        for(int len = n, b = bitlen; len > 1; len >>= 1, b--) {\n           \
    \ for(int i = 0; i < n; i += len) {\n                int t = len >> 1;\n     \
    \           mint wj = 1;\n                for(int j = 0; j < t; j++) {\n     \
    \               int p = i + j;\n                    mint l = a[p] + a[p + t];\n\
    \                    mint r = (a[p] - a[p + t]) * wj;\n                    a[p]\
    \ = l, a[p + t] = r;\n                    wj *= info.root[b];\n              \
    \  }\n            }\n        }\n        for(int i = 0; i < n; i++) {\n       \
    \     int j = revbit(i);\n            if(i < j) std::swap(a[i], a[j]);\n     \
    \   }\n    }\n\n    template<class mint>\n    void intt(std::vector<mint>& a)\
    \ {\n        int n = (int)a.size();\n        static const ntt_info<mint> info;\n\
    \        for(int i = 0; i < n; i++) {\n            int j = revbit(i);\n      \
    \      if(i < j) std::swap(a[i], a[j]);\n        }\n        for(int len = 2, b\
    \ = 1; len <= n; len <<= 1, b++) {\n            for(int i = 0; i < n; i += len)\
    \ {\n                int t = len >> 1;\n                mint wj = 1;\n       \
    \         for(int j = 0; j < t; j++) {\n                    int p = i + j;\n \
    \                   auto l = a[p] + a[p + t] * wj;\n                    auto r\
    \ = a[p] - a[p + t] * wj;\n                    a[p] = l, a[p + t] = r;\n     \
    \               wj *= info.iroot[b];\n                }\n            }\n     \
    \   }\n        mint invn = mint(n).inv();\n        for(int i = 0; i < n; i++)\
    \ a[i] *= invn;\n    }\n\n    template<class mint>\n    std::vector<mint> convolution(std::vector<mint>\
    \ a, std::vector<mint> b) {\n        int m = (int)a.size() + (int)b.size() - 1;\n\
    \        int n = 1;\n        while(n < m) n <<= 1;\n        a.resize(n), b.resize(n);\n\
    \        ntt<mint>(a);\n        ntt<mint>(b);\n        for(int i = 0; i < n; i++)\
    \ a[i] *= b[i];\n        intt<mint>(a);\n        a.resize(m);\n        return\
    \ a;\n    }\n}; // namespace ntt\n#line 5 \"test/library-checker/convolution/convolution-mod.test.cpp\"\
    \n\nint main() {\n    int N, M;\n    cin >> N >> M;\n    using mint = ModInt<MOD2>;\n\
    \    vector<mint> a(N), b(M);\n    REP(i, N) cin >> a[i];\n    REP(i, M) cin >>\
    \ b[i];\n    auto c = ntt::convolution<mint>(a, b);\n    REP(i, N + M - 1) cout\
    \ << c[i] << \" \\n\"[i == N + M - 2];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n#include\
    \ \"../../../template/template.cpp\"\n#include \"../../../modint/modint.hpp\"\n\
    #include \"../../../math/convolution/ntt.hpp\"\n\nint main() {\n    int N, M;\n\
    \    cin >> N >> M;\n    using mint = ModInt<MOD2>;\n    vector<mint> a(N), b(M);\n\
    \    REP(i, N) cin >> a[i];\n    REP(i, M) cin >> b[i];\n    auto c = ntt::convolution<mint>(a,\
    \ b);\n    REP(i, N + M - 1) cout << c[i] << \" \\n\"[i == N + M - 2];\n}"
  dependsOn:
  - template/template.cpp
  - modint/modint.hpp
  - math/convolution/ntt.hpp
  - math/primitive-root.hpp
  - math/pow_mod.hpp
  isVerificationFile: true
  path: test/library-checker/convolution/convolution-mod.test.cpp
  requiredBy: []
  timestamp: '2023-10-01 12:06:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/convolution/convolution-mod.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/convolution/convolution-mod.test.cpp
- /verify/test/library-checker/convolution/convolution-mod.test.cpp.html
title: test/library-checker/convolution/convolution-mod.test.cpp
---
