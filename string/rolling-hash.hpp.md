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
  bundledCode: "#line 2 \"string/rolling-hash.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <random>\n#include <string>\n#include <vector>\n\nclass\
    \ RollingHash {\npublic:\n    using u64 = unsigned long long;\n    using u128\
    \ = __uint128_t;\n\n    explicit RollingHash(const std::vector<int>& v, u64 base):\
    \ base(base) {\n        int n = (int)v.size();\n        hashed.assign(n + 1, 0);\n\
    \        power.assign(n + 1, 0);\n        power[0] = 1;\n        for(int i = 0;\
    \ i < n; i++) {\n            power[i + 1] = mul(power[i], base);\n           \
    \ hashed[i + 1] = add(mul(hashed[i], base), v[i]);\n        }\n    }\n    explicit\
    \ RollingHash(const std::string& s, u64 base): base(base) {\n        std::vector<int>\
    \ v(s.size());\n        for(int i = 0; i < (int)s.size(); i++) v[i] = s[i];\n\
    \        RollingHash(v, base);\n    }\n    static inline u64 genBase() {\n   \
    \     std::random_device seed_gen;\n        std::mt19937_64 engine(seed_gen());\n\
    \        std::uniform_int_distribution<u64> rand(2, mod - 2);\n        return\
    \ rand(engine);\n    }\n    u64 get(int l, int r) {\n        return add(hashed[r],\
    \ mod - mul(hashed[l], power[r - l]));\n    }\n    u64 connect(u64 h1, u64 h2,\
    \ int h2len) {\n        return add(mul(h1, power[h2len]), h2);\n    }\n    int\
    \ get_lcp(RollingHash &b, int l1, int r1, int l2, int r2) {\n        assert(mod\
    \ == b.mod);\n        int len = std::min(r1 - l1, r2 - l2);\n        int low =\
    \ -1, high = len + 1;\n        while(high - low > 1) {\n            int mid =\
    \ (low + high) >> 1;\n            if(get(l1, l1 + mid) == b.get(l2, l2 + mid))\
    \ {\n                low = mid;\n            } else {\n                high =\
    \ mid;\n            }\n        }\n        return low;\n    }\n\nprivate:\n   \
    \ static const u64 mod = (1ULL << 61) - 1;\n    const u64 base;\n    std::vector<u64>\
    \ hashed, power;\n\n    inline u64 add(u64 a, u64 b) const {\n        if((a +=\
    \ b) >= mod) a -= mod;\n        return a;\n    }\n    inline u64 mul(u64 a, u64\
    \ b) const {\n        u128 t = (u128)a * b;\n        u64 na = t >> 61;\n     \
    \   u64 nb = t & mod;\n        if((na += nb) >= mod) na -= mod;\n        return\
    \ na;\n    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <random>\n\
    #include <string>\n#include <vector>\n\nclass RollingHash {\npublic:\n    using\
    \ u64 = unsigned long long;\n    using u128 = __uint128_t;\n\n    explicit RollingHash(const\
    \ std::vector<int>& v, u64 base): base(base) {\n        int n = (int)v.size();\n\
    \        hashed.assign(n + 1, 0);\n        power.assign(n + 1, 0);\n        power[0]\
    \ = 1;\n        for(int i = 0; i < n; i++) {\n            power[i + 1] = mul(power[i],\
    \ base);\n            hashed[i + 1] = add(mul(hashed[i], base), v[i]);\n     \
    \   }\n    }\n    explicit RollingHash(const std::string& s, u64 base): base(base)\
    \ {\n        std::vector<int> v(s.size());\n        for(int i = 0; i < (int)s.size();\
    \ i++) v[i] = s[i];\n        RollingHash(v, base);\n    }\n    static inline u64\
    \ genBase() {\n        std::random_device seed_gen;\n        std::mt19937_64 engine(seed_gen());\n\
    \        std::uniform_int_distribution<u64> rand(2, mod - 2);\n        return\
    \ rand(engine);\n    }\n    u64 get(int l, int r) {\n        return add(hashed[r],\
    \ mod - mul(hashed[l], power[r - l]));\n    }\n    u64 connect(u64 h1, u64 h2,\
    \ int h2len) {\n        return add(mul(h1, power[h2len]), h2);\n    }\n    int\
    \ get_lcp(RollingHash &b, int l1, int r1, int l2, int r2) {\n        assert(mod\
    \ == b.mod);\n        int len = std::min(r1 - l1, r2 - l2);\n        int low =\
    \ -1, high = len + 1;\n        while(high - low > 1) {\n            int mid =\
    \ (low + high) >> 1;\n            if(get(l1, l1 + mid) == b.get(l2, l2 + mid))\
    \ {\n                low = mid;\n            } else {\n                high =\
    \ mid;\n            }\n        }\n        return low;\n    }\n\nprivate:\n   \
    \ static const u64 mod = (1ULL << 61) - 1;\n    const u64 base;\n    std::vector<u64>\
    \ hashed, power;\n\n    inline u64 add(u64 a, u64 b) const {\n        if((a +=\
    \ b) >= mod) a -= mod;\n        return a;\n    }\n    inline u64 mul(u64 a, u64\
    \ b) const {\n        u128 t = (u128)a * b;\n        u64 na = t >> 61;\n     \
    \   u64 nb = t & mod;\n        if((na += nb) >= mod) na -= mod;\n        return\
    \ na;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling-hash.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling-hash.hpp
layout: document
redirect_from:
- /library/string/rolling-hash.hpp
- /library/string/rolling-hash.hpp.html
title: string/rolling-hash.hpp
---
