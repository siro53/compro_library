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
  bundledCode: "#line 1 \"string/rolling_hash.hpp\"\n// \u6700\u521D\u306Bbase\u3092\
    genBase()\u3067\u30E9\u30F3\u30C0\u30E0\u306B\u751F\u6210\u3059\u308B\u3053\u3068\
    \uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\n// RollingHash(s, base)\
    \ := \u6587\u5B57\u5217s\u306E\u30CF\u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EB\
    \u3092\u8A08\u7B97\u3059\u308B\n// get(l, r) := [l, r)\u306E\u30CF\u30C3\u30B7\
    \u30E5\u5024\u3092\u6C42\u3081\u308B\n// connect(h1, h2, h2len) := \u30CF\u30C3\
    \u30B7\u30E5\u5024h1\u3068, \u9577\u3055h2len\u306E\u30CF\u30C3\u30B7\u30E5\u5024\
    h2\u3092\u7D50\u5408\u3059\u308B\u3002\n// LCP(b, l1, r1, l2, r2) := \u533A\u9593\
    [l1, r1)\u3068\u3001\u30CF\u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EB\u304Cb\u3067\
    \u3042\u308B\u533A\u9593[l2,\n// r2)\u306E\u6587\u5B57\u5217\u306E \u6700\u9577\
    \u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055\u3092\u6C42\u3081\u308B\u3002\
    \nstruct RollingHash {\n    using ull = unsigned long long;\n    using ui128 =\
    \ __uint128_t;\n    static const ull mod = (1ULL << 61) - 1;\n    const ull base;\n\
    \    vector<ull> hashed, power;\n\n    inline ull add(ull a, ull b) {\n      \
    \  if((a += b) >= mod) {\n            a -= mod;\n        }\n        return a;\n\
    \    }\n    inline ull mul(ull a, ull b) {\n        ui128 t = (ui128)a * b;\n\
    \        ull na = t >> 61;\n        ull nb = t & mod;\n        if((na += nb) >=\
    \ mod) {\n            na -= mod;\n        }\n        return na;\n    }\n    static\
    \ inline ull genBase() {\n        random_device seed_gen;\n        mt19937_64\
    \ engine(seed_gen());\n        uniform_int_distribution<ull> rand(2, mod - 2);\n\
    \        return rand(engine);\n    }\n    RollingHash() = default;\n    RollingHash(const\
    \ string &s, ull base) : base(base) {\n        int n = (int)s.size();\n      \
    \  hashed.assign(n + 1, 0);\n        power.assign(n + 1, 0);\n        power[0]\
    \ = 1;\n        for(int i = 0; i < n; i++) {\n            power[i + 1] = mul(power[i],\
    \ base);\n            hashed[i + 1] = add(mul(hashed[i], base), s[i]);\n     \
    \   }\n    }\n    ull get(int l, int r) {\n        return add(hashed[r], mod -\
    \ mul(hashed[l], power[r - l]));\n    }\n    ull connect(ull h1, ull h2, int h2len)\
    \ {\n        return add(mul(h1, power[h2len]), h2);\n    }\n    int LCP(RollingHash\
    \ &b, int l1, int r1, int l2, int r2) {\n        assert(mod == b.mod);\n     \
    \   int len = min(r1 - l1, r2 - l2);\n        int low = -1, high = len + 1;\n\
    \        while(high - low > 1) {\n            int mid = (low + high) >> 1;\n \
    \           if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) {\n                low\
    \ = mid;\n            } else {\n                high = mid;\n            }\n \
    \       }\n        return low;\n    }\n};\n"
  code: "// \u6700\u521D\u306Bbase\u3092genBase()\u3067\u30E9\u30F3\u30C0\u30E0\u306B\
    \u751F\u6210\u3059\u308B\u3053\u3068\uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\uFF01\
    \uFF01\uFF01\n// RollingHash(s, base) := \u6587\u5B57\u5217s\u306E\u30CF\u30C3\
    \u30B7\u30E5\u30C6\u30FC\u30D6\u30EB\u3092\u8A08\u7B97\u3059\u308B\n// get(l,\
    \ r) := [l, r)\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u6C42\u3081\u308B\n//\
    \ connect(h1, h2, h2len) := \u30CF\u30C3\u30B7\u30E5\u5024h1\u3068, \u9577\u3055\
    h2len\u306E\u30CF\u30C3\u30B7\u30E5\u5024h2\u3092\u7D50\u5408\u3059\u308B\u3002\
    \n// LCP(b, l1, r1, l2, r2) := \u533A\u9593[l1, r1)\u3068\u3001\u30CF\u30C3\u30B7\
    \u30E5\u30C6\u30FC\u30D6\u30EB\u304Cb\u3067\u3042\u308B\u533A\u9593[l2,\n// r2)\u306E\
    \u6587\u5B57\u5217\u306E \u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\
    \u3055\u3092\u6C42\u3081\u308B\u3002\nstruct RollingHash {\n    using ull = unsigned\
    \ long long;\n    using ui128 = __uint128_t;\n    static const ull mod = (1ULL\
    \ << 61) - 1;\n    const ull base;\n    vector<ull> hashed, power;\n\n    inline\
    \ ull add(ull a, ull b) {\n        if((a += b) >= mod) {\n            a -= mod;\n\
    \        }\n        return a;\n    }\n    inline ull mul(ull a, ull b) {\n   \
    \     ui128 t = (ui128)a * b;\n        ull na = t >> 61;\n        ull nb = t &\
    \ mod;\n        if((na += nb) >= mod) {\n            na -= mod;\n        }\n \
    \       return na;\n    }\n    static inline ull genBase() {\n        random_device\
    \ seed_gen;\n        mt19937_64 engine(seed_gen());\n        uniform_int_distribution<ull>\
    \ rand(2, mod - 2);\n        return rand(engine);\n    }\n    RollingHash() =\
    \ default;\n    RollingHash(const string &s, ull base) : base(base) {\n      \
    \  int n = (int)s.size();\n        hashed.assign(n + 1, 0);\n        power.assign(n\
    \ + 1, 0);\n        power[0] = 1;\n        for(int i = 0; i < n; i++) {\n    \
    \        power[i + 1] = mul(power[i], base);\n            hashed[i + 1] = add(mul(hashed[i],\
    \ base), s[i]);\n        }\n    }\n    ull get(int l, int r) {\n        return\
    \ add(hashed[r], mod - mul(hashed[l], power[r - l]));\n    }\n    ull connect(ull\
    \ h1, ull h2, int h2len) {\n        return add(mul(h1, power[h2len]), h2);\n \
    \   }\n    int LCP(RollingHash &b, int l1, int r1, int l2, int r2) {\n       \
    \ assert(mod == b.mod);\n        int len = min(r1 - l1, r2 - l2);\n        int\
    \ low = -1, high = len + 1;\n        while(high - low > 1) {\n            int\
    \ mid = (low + high) >> 1;\n            if(get(l1, l1 + mid) == b.get(l2, l2 +\
    \ mid)) {\n                low = mid;\n            } else {\n                high\
    \ = mid;\n            }\n        }\n        return low;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling_hash.hpp
layout: document
title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
---
