---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/is-prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: math/pow_mod.hpp
    title: math/pow_mod.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/primality_test
    links:
    - https://judge.yosupo.jp/problem/primality_test
  bundledCode: "#line 1 \"test/library-checker/math/primality-test.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"math/is-prime.hpp\"\n\n#line 4 \"math/is-prime.hpp\"\
    \n\n#line 2 \"math/pow_mod.hpp\"\n\nconstexpr long long pow_mod(long long x, long\
    \ long k, long long m) {\n    long long res = 1;\n    long long mul = (x >= 0\
    \ ? x % m : x % m + m);\n    while(k) {\n        if(k & 1) res = (__int128_t)res\
    \ * mul % m;\n        mul = (__int128_t)mul * mul % m;\n        k >>= 1;\n   \
    \ }\n    return res;\n}\n#line 6 \"math/is-prime.hpp\"\n\n/*\nref: Fast Primality\
    \ Testing for Integers That Fit into a Machine Word\nMichal Fori\u02C7sek and\
    \ Jakub Jan\u02C7cina\n*/\n\nconstexpr bool is_prime(int n) {\n    if(n <= 1)\
    \ return false;\n    if(n == 2 or n == 7 or n == 61) return true;\n    if((n &\
    \ 1) == 0) return false;\n    long long d = n - 1;\n    while((d & 1) == 0) d\
    \ >>= 1;\n    constexpr std::array<int, 3> bases = {2, 7, 61};\n    for(int a\
    \ : bases) {\n        long long t = d;\n        long long y = pow_mod(a, t, n);\n\
    \        while(t != n - 1 && y != 1 && y != n - 1) {\n            (y *= y) %=\
    \ n;\n            t <<= 1;\n        }\n        if(y != n - 1 && (t & 1) == 0)\
    \ return false;\n    }\n    return true;\n}\n\nconstexpr bool is_prime(long long\
    \ n) {\n    if(n <= 1) return false;\n    if(n == 2) return true;\n    if((n &\
    \ 1) == 0) return false;\n    long long d = n - 1;\n    while((d & 1) == 0) d\
    \ >>= 1;\n    constexpr std::array<long long, 7> bases = {\n        2, 325, 9375,\
    \ 28178, 450775, 9780504, 1795265022\n    };\n    for(long long a : bases) {\n\
    \        a %= n;\n        if(a == 0) continue;\n        long long t = d;\n   \
    \     long long y = pow_mod(a, t, n);\n        while(t != n - 1 && y != 1 && y\
    \ != n - 1) {\n            y = (__int128_t)y * y % n;\n            t <<= 1;\n\
    \        }\n        if(y != n - 1 && (t & 1) == 0) return false;\n    }\n    return\
    \ true;\n}\n#line 6 \"test/library-checker/math/primality-test.test.cpp\"\n\n\
    int main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int Q;\n\
    \    cin >> Q;\n    while(Q--) {\n        long long n;\n        cin >> n;\n  \
    \      cout << (is_prime(n) ? \"Yes\" : \"No\") << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../math/is-prime.hpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int Q;\n\
    \    cin >> Q;\n    while(Q--) {\n        long long n;\n        cin >> n;\n  \
    \      cout << (is_prime(n) ? \"Yes\" : \"No\") << '\\n';\n    }\n}"
  dependsOn:
  - math/is-prime.hpp
  - math/pow_mod.hpp
  isVerificationFile: true
  path: test/library-checker/math/primality-test.test.cpp
  requiredBy: []
  timestamp: '2023-09-29 01:34:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/math/primality-test.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/math/primality-test.test.cpp
- /verify/test/library-checker/math/primality-test.test.cpp.html
title: test/library-checker/math/primality-test.test.cpp
---
