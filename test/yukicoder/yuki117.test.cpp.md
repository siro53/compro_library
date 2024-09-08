---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/binom.hpp
    title: "\u4E8C\u9805\u4FC2\u6570"
  - icon: ':question:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/117
    links:
    - https://yukicoder.me/problems/no/117
  bundledCode: "#line 1 \"test/yukicoder/yuki117.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/117\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#line 2 \"modint/modint.hpp\"\
    \n\n#line 6 \"modint/modint.hpp\"\n\ntemplate <int mod> class ModInt {\n  public:\n\
    \    ModInt() : x(0) {}\n    ModInt(long long y)\n        : x(y >= 0 ? y % umod()\
    \ : (umod() - (-y) % umod()) % umod()) {}\n    unsigned int val() const { return\
    \ x; }\n    ModInt &operator+=(const ModInt &p) {\n        if((x += p.x) >= umod())\
    \ x -= umod();\n        return *this;\n    }\n    ModInt &operator-=(const ModInt\
    \ &p) {\n        if((x += umod() - p.x) >= umod()) x -= umod();\n        return\
    \ *this;\n    }\n    ModInt &operator*=(const ModInt &p) {\n        x = (unsigned\
    \ int)(1ULL * x * p.x % umod());\n        return *this;\n    }\n    ModInt &operator/=(const\
    \ ModInt &p) {\n        *this *= p.inv();\n        return *this;\n    }\n    ModInt\
    \ operator-() const { return ModInt(-(long long)x); }\n    ModInt operator+(const\
    \ ModInt &p) const { return ModInt(*this) += p; }\n    ModInt operator-(const\
    \ ModInt &p) const { return ModInt(*this) -= p; }\n    ModInt operator*(const\
    \ ModInt &p) const { return ModInt(*this) *= p; }\n    ModInt operator/(const\
    \ ModInt &p) const { return ModInt(*this) /= p; }\n    bool operator==(const ModInt\
    \ &p) const { return x == p.x; }\n    bool operator!=(const ModInt &p) const {\
    \ return x != p.x; }\n    ModInt inv() const {\n        long long a = x, b = mod,\
    \ u = 1, v = 0, t;\n        while(b > 0) {\n            t = a / b;\n         \
    \   std::swap(a -= t * b, b);\n            std::swap(u -= t * v, v);\n       \
    \ }\n        return ModInt(u);\n    }\n    ModInt pow(unsigned long long n) const\
    \ {\n        ModInt ret(1), mul(x);\n        while(n > 0) {\n            if(n\
    \ & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n\
    \        return ret;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const ModInt &p) {\n        return os << p.x;\n    }\n    friend std::istream\
    \ &operator>>(std::istream &is, ModInt &a) {\n        long long t;\n        is\
    \ >> t;\n        a = ModInt<mod>(t);\n        return (is);\n    }\n    static\
    \ constexpr int get_mod() { return mod; }\n\n  private:\n    unsigned int x;\n\
    \    static constexpr unsigned int umod() { return mod; }\n};\n#line 2 \"math/binom.hpp\"\
    \n\n#line 6 \"math/binom.hpp\"\n\ntemplate <class mint> class Binomial {\n  public:\n\
    \    explicit Binomial(): Binomial(1) {}\n    explicit Binomial(int MAX) : f(MAX,\
    \ mint(1)), f_inv(MAX, mint(1)) {\n        for(int i = 1; i < MAX; i++) f[i] =\
    \ f[i-1] * mint(i);\n        f_inv[MAX - 1] = f[MAX - 1].inv();\n        for(int\
    \ i = MAX - 2; i >= 1; i--) {\n            f_inv[i] = f_inv[i + 1] * mint(i +\
    \ 1);\n        } \n    }\n    void extend() {\n        int n = (int)f.size();\n\
    \        f.resize(n * 2);\n        f_inv.resize(n * 2);\n        for(int i = n;\
    \ i < n * 2; i++) f[i] = f[i - 1] * mint(i);\n        f_inv[n * 2 - 1] = f[n *\
    \ 2 - 1].inv();\n        for(int i = n * 2 - 2; i >= n; i--) {\n            f_inv[i]\
    \ = f_inv[i + 1] * mint(i + 1);\n        }\n    }\n    mint fac(int n) {\n   \
    \     if(n < 0) return mint(0);\n        while(n >= (int)f.size()) extend();\n\
    \        return f[n];\n    }\n    mint fac_inv(int n) {\n        if(n < 0) return\
    \ mint(0);\n        while(n >= (int)f_inv.size()) extend();\n        return f_inv[n];\n\
    \    }\n    mint inv(int n) {\n        if(n < 0) return -mint(-n);\n        assert(n\
    \ != 0);\n        while(n >= (int)f_inv.size()) extend();\n        return (f_inv[n]\
    \ * f[n - 1]);\n    }\n    mint binom(int n, int k) {\n        if(n < k || n <\
    \ 0 || k < 0) return mint(0);\n        return (fac(n) * fac_inv(k) * fac_inv(n\
    \ - k));\n    }\n    mint binom_naive(long long n, long long k) {\n        if(n\
    \ < k || n < 0 || k < 0) return mint(0);\n        mint res(1);\n        k = std::min(k,\
    \ n - k);\n        for(int i = 0; i < k; i++) res *= inv(i + 1) * mint(n - i);\n\
    \        return res;\n    }\n    mint perm(int n, int k) {\n        if(n < k ||\
    \ n < 0 || k < 0) return mint(0);\n        return (fac(n) * fac_inv(n - k));\n\
    \    }\n    mint hom(int n, int k) {\n        if(n < 0 || k < 0) return mint(0);\n\
    \        return (k == 0 ? mint(1) : binom(n + k - 1, k));\n    }\n\n  private:\n\
    \    std::vector<mint> f, f_inv;\n};\n#line 6 \"test/yukicoder/yuki117.test.cpp\"\
    \n\nusing mint = ModInt<1000000007>;\n\nint main() {\n    int T;\n    scanf(\"\
    %d\\n\", &T);\n    Binomial<mint> binom;\n    while(T--) {\n        char t;\n\
    \        int N, K;\n        scanf(\"%c(%d,%d)\\n\", &t, &N, &K);\n        if(t\
    \ == 'C') {\n            printf(\"%u\\n\", binom.binom(N, K).val());\n       \
    \ } else if(t == 'P') {\n            printf(\"%u\\n\", binom.perm(N, K).val());\n\
    \        } else if(t == 'H') {\n            printf(\"%u\\n\", binom.hom(N, K).val());\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/117\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#include \"../../modint/modint.hpp\"\n#include \"../../math/binom.hpp\"\
    \n\nusing mint = ModInt<1000000007>;\n\nint main() {\n    int T;\n    scanf(\"\
    %d\\n\", &T);\n    Binomial<mint> binom;\n    while(T--) {\n        char t;\n\
    \        int N, K;\n        scanf(\"%c(%d,%d)\\n\", &t, &N, &K);\n        if(t\
    \ == 'C') {\n            printf(\"%u\\n\", binom.binom(N, K).val());\n       \
    \ } else if(t == 'P') {\n            printf(\"%u\\n\", binom.perm(N, K).val());\n\
    \        } else if(t == 'H') {\n            printf(\"%u\\n\", binom.hom(N, K).val());\n\
    \        }\n    }\n}"
  dependsOn:
  - modint/modint.hpp
  - math/binom.hpp
  isVerificationFile: true
  path: test/yukicoder/yuki117.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/yuki117.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/yuki117.test.cpp
- /verify/test/yukicoder/yuki117.test.cpp.html
title: test/yukicoder/yuki117.test.cpp
---
