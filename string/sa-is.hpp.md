---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/sa-is.test.cpp
    title: test/sa-is.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/sa-is.hpp\"\nclass SA_IS {\n  private:\n    vector<int>\
    \ sa_is(const vector<int> &t, int alp_sz) {\n        const int n = int(t.size());\n\
    \        vector<bool> is_S(n, false), is_LMS(n, false);\n        vector<int> LMSs;\n\
    \n        // type-S\u306Asuffix\u3092\u8ABF\u3079\u308B\n        is_S[n - 1] =\
    \ true;\n        for(int i = n - 2; i >= 0; i--) {\n            if(t[i] < t[i\
    \ + 1] || ((t[i] == t[i + 1]) && is_S[i + 1])) {\n                is_S[i] = true;\n\
    \            }\n        }\n\n        // type-S*\u306Asuffix\u3092\u8ABF\u3079\u308B\
    \n        for(int i = 0; i < n; i++) {\n            if(is_S[i] && (i == 0 || !is_S[i\
    \ - 1])) {\n                is_LMS[i] = true;\n                LMSs.push_back(i);\n\
    \            }\n        }\n\n        // \u307E\u305Atype-S*\u304C\u30BD\u30FC\u30C8\
    \u3055\u308C\u3066\u3044\u308B\u3068\u4EEE\u5B9A\u3057\u3066\u3001induced_sort\u3092\
    \u884C\u3046\u3002\n        // induced_sort\u5F8C\u306FS*\u90E8\u5206\u5217\u306F\
    \u30BD\u30FC\u30C8\u3055\u308C\u3066\u3044\u308B\n        vector<int> pre_SA =\
    \ induced_sort(t, LMSs, is_S, alp_sz);\n        vector<int> sorted_LMSs(LMSs.size(),\
    \ 0);\n        {\n            int id = 0;\n            for(int i : pre_SA) {\n\
    \                if(is_LMS[i]) sorted_LMSs[id++] = i;\n            }\n       \
    \ }\n\n        // S*\u90E8\u5206\u6587\u5B57\u5217\u306E\u9806\u5E8F\u3092\u6C7A\
    \u5B9A\u3059\u308B\n        int rank = 0;\n        pre_SA[sorted_LMSs[0]] = 0;\n\
    \        if(int(sorted_LMSs.size()) > 1) pre_SA[sorted_LMSs[1]] = ++rank;\n  \
    \      for(int i = 1; i < int(LMSs.size()) - 1; i++) {\n            bool is_diff\
    \ = false;\n            for(int j = 0; j < n; j++) {\n                int now\
    \ = sorted_LMSs[i] + j;\n                int nxt = sorted_LMSs[i + 1] + j;\n \
    \               if(t[now] != t[nxt] || is_LMS[now] != is_LMS[nxt]) {\n       \
    \             is_diff = true;\n                    break;\n                }\n\
    \                if(j > 0 && is_LMS[now]) break;\n            }\n            if(is_diff)\
    \ {\n                pre_SA[sorted_LMSs[i + 1]] = ++rank;\n            } else\
    \ {\n                pre_SA[sorted_LMSs[i + 1]] = rank;\n            }\n     \
    \   }\n        // S*\u90E8\u5206\u6587\u5B57\u5217\u306E\u9806\u5E8F\u3092\u5143\
    \u306B\u65B0\u3057\u3044\u6587\u5B57\u5217\u3092\u4F5C\u308B\n        vector<int>\
    \ new_t(LMSs.size());\n        {\n            int id = 0;\n            for(int\
    \ i = 0; i < n; i++) {\n                if(is_LMS[i]) {\n                    new_t[id]\
    \ = pre_SA[i];\n                    id++;\n                }\n            }\n\
    \        }\n        // \u518D\u5E30\u7684\u306BS* suffix\u306E\u9806\u5E8F\u3092\
    \u6C42\u3081\u308B\n        vector<int> new_sa(LMSs.size(), 0);\n        if(rank\
    \ + 1 == int(LMSs.size())) {\n            new_sa = sorted_LMSs;\n        } else\
    \ {\n            new_sa = sa_is(new_t, rank + 1);\n            for(int i = 0;\
    \ i < int(new_sa.size()); i++) {\n                new_sa[i] = LMSs[new_sa[i]];\n\
    \            }\n        }\n        // S*\u306E\u30BD\u30FC\u30C8\u304C\u7D42\u308F\
    \u3063\u305F\u306E\u3067\u6700\u5F8C\u306Binduced_sort\n        auto res = induced_sort(t,\
    \ new_sa, is_S, alp_sz);\n        return res;\n    }\n\n    vector<int> induced_sort(const\
    \ vector<int> &t, const vector<int> &LMSs,\n                             const\
    \ vector<bool> &is_S, const int alp_sz) {\n        int n = int(t.size());\n  \
    \      vector<int> SA(n, 0);\n        vector<int> C(alp_sz + 1, 0);\n        for(int\
    \ i = 0; i < n; i++) C[t[i] + 1]++;\n        for(int i = 0; i < alp_sz; i++) C[i\
    \ + 1] += C[i];\n\n        // \u307E\u305Atype-S*\u304B\u3089\u30D0\u30B1\u30C3\
    \u30C8\u306B\u8A70\u3081\u308B\u3002\u5404bucket\u306BS*\u3092\u5F8C\u308D\u304B\
    \u3089\u633F\u5165\u3002\n        vector<int> cnt(alp_sz, 0);\n        for(int\
    \ i = int(LMSs.size()) - 1; i >= 0; i--) {\n            int c = t[LMSs[i]];\n\
    \            SA[C[c + 1] - 1 - cnt[c]] = LMSs[i];\n            cnt[c]++;\n   \
    \     }\n\n        // \u6B21\u306Btype-L\u3092\u8A70\u3081\u308B\u3002SA\u3092\
    \u524D\u304B\u3089\u8D70\u67FB\u3059\u308B\u3002\n        // type-S*\u3067\u3042\
    \u308Bsuffix\n        // S[i]\u306B\u3064\u3044\u3066\u3001S[i-1]\u304Ctype-L\u306A\
    \u3089\u30D0\u30B1\u30C3\u30C8\u306E\u5148\u982D\u306B\u5165\u308C\u308B\n   \
    \     cnt.assign(alp_sz, 0);\n        for(int i = 0; i < n; i++) {\n         \
    \   if(SA[i] == 0 || is_S[SA[i] - 1]) continue;\n            int c = t[SA[i] -\
    \ 1];\n            SA[C[c] + cnt[c]] = SA[i] - 1;\n            cnt[c]++;\n   \
    \     }\n\n        // \u6700\u5F8C\u306Btype-S\u3092\u8A70\u3081\u308B\u3002SA\u3092\
    \u5F8C\u308D\u304B\u3089\u8D70\u67FB\u3059\u308B\n        // type-L\u3067\u3042\
    \u308Bsuffix\n        // S[i]\u306B\u3064\u3044\u3066\u3001S[i-1]\u304Ctype-S\u306A\
    \u3089\u30D0\u30B1\u30C3\u30C8\u306E\u5F8C\u308D\u306B\u5165\u308C\u308B\n   \
    \     cnt.assign(alp_sz, 0);\n        for(int i = n - 1; i >= 0; i--) {\n    \
    \        if(SA[i] == 0 || !is_S[SA[i] - 1]) continue;\n            int c = t[SA[i]\
    \ - 1];\n            SA[C[c + 1] - 1 - cnt[c]] = SA[i] - 1;\n            cnt[c]++;\n\
    \        }\n\n        return SA;\n    }\n\n  public:\n    string S;\n    vector<int>\
    \ sa;\n    SA_IS(string s) : S(s), sa(S.size()) {\n        int n = int(s.size());\n\
    \        s += '$';\n        vector<int> t(n + 1);\n        for(int i = 0; i <\
    \ n; i++) t[i] = s[i] - '$';\n        sa = sa_is(t, 100);\n        sa.erase(sa.begin());\n\
    \    }\n    int operator[](const int i) const { return sa[i]; }\n};\n"
  code: "class SA_IS {\n  private:\n    vector<int> sa_is(const vector<int> &t, int\
    \ alp_sz) {\n        const int n = int(t.size());\n        vector<bool> is_S(n,\
    \ false), is_LMS(n, false);\n        vector<int> LMSs;\n\n        // type-S\u306A\
    suffix\u3092\u8ABF\u3079\u308B\n        is_S[n - 1] = true;\n        for(int i\
    \ = n - 2; i >= 0; i--) {\n            if(t[i] < t[i + 1] || ((t[i] == t[i + 1])\
    \ && is_S[i + 1])) {\n                is_S[i] = true;\n            }\n       \
    \ }\n\n        // type-S*\u306Asuffix\u3092\u8ABF\u3079\u308B\n        for(int\
    \ i = 0; i < n; i++) {\n            if(is_S[i] && (i == 0 || !is_S[i - 1])) {\n\
    \                is_LMS[i] = true;\n                LMSs.push_back(i);\n     \
    \       }\n        }\n\n        // \u307E\u305Atype-S*\u304C\u30BD\u30FC\u30C8\
    \u3055\u308C\u3066\u3044\u308B\u3068\u4EEE\u5B9A\u3057\u3066\u3001induced_sort\u3092\
    \u884C\u3046\u3002\n        // induced_sort\u5F8C\u306FS*\u90E8\u5206\u5217\u306F\
    \u30BD\u30FC\u30C8\u3055\u308C\u3066\u3044\u308B\n        vector<int> pre_SA =\
    \ induced_sort(t, LMSs, is_S, alp_sz);\n        vector<int> sorted_LMSs(LMSs.size(),\
    \ 0);\n        {\n            int id = 0;\n            for(int i : pre_SA) {\n\
    \                if(is_LMS[i]) sorted_LMSs[id++] = i;\n            }\n       \
    \ }\n\n        // S*\u90E8\u5206\u6587\u5B57\u5217\u306E\u9806\u5E8F\u3092\u6C7A\
    \u5B9A\u3059\u308B\n        int rank = 0;\n        pre_SA[sorted_LMSs[0]] = 0;\n\
    \        if(int(sorted_LMSs.size()) > 1) pre_SA[sorted_LMSs[1]] = ++rank;\n  \
    \      for(int i = 1; i < int(LMSs.size()) - 1; i++) {\n            bool is_diff\
    \ = false;\n            for(int j = 0; j < n; j++) {\n                int now\
    \ = sorted_LMSs[i] + j;\n                int nxt = sorted_LMSs[i + 1] + j;\n \
    \               if(t[now] != t[nxt] || is_LMS[now] != is_LMS[nxt]) {\n       \
    \             is_diff = true;\n                    break;\n                }\n\
    \                if(j > 0 && is_LMS[now]) break;\n            }\n            if(is_diff)\
    \ {\n                pre_SA[sorted_LMSs[i + 1]] = ++rank;\n            } else\
    \ {\n                pre_SA[sorted_LMSs[i + 1]] = rank;\n            }\n     \
    \   }\n        // S*\u90E8\u5206\u6587\u5B57\u5217\u306E\u9806\u5E8F\u3092\u5143\
    \u306B\u65B0\u3057\u3044\u6587\u5B57\u5217\u3092\u4F5C\u308B\n        vector<int>\
    \ new_t(LMSs.size());\n        {\n            int id = 0;\n            for(int\
    \ i = 0; i < n; i++) {\n                if(is_LMS[i]) {\n                    new_t[id]\
    \ = pre_SA[i];\n                    id++;\n                }\n            }\n\
    \        }\n        // \u518D\u5E30\u7684\u306BS* suffix\u306E\u9806\u5E8F\u3092\
    \u6C42\u3081\u308B\n        vector<int> new_sa(LMSs.size(), 0);\n        if(rank\
    \ + 1 == int(LMSs.size())) {\n            new_sa = sorted_LMSs;\n        } else\
    \ {\n            new_sa = sa_is(new_t, rank + 1);\n            for(int i = 0;\
    \ i < int(new_sa.size()); i++) {\n                new_sa[i] = LMSs[new_sa[i]];\n\
    \            }\n        }\n        // S*\u306E\u30BD\u30FC\u30C8\u304C\u7D42\u308F\
    \u3063\u305F\u306E\u3067\u6700\u5F8C\u306Binduced_sort\n        auto res = induced_sort(t,\
    \ new_sa, is_S, alp_sz);\n        return res;\n    }\n\n    vector<int> induced_sort(const\
    \ vector<int> &t, const vector<int> &LMSs,\n                             const\
    \ vector<bool> &is_S, const int alp_sz) {\n        int n = int(t.size());\n  \
    \      vector<int> SA(n, 0);\n        vector<int> C(alp_sz + 1, 0);\n        for(int\
    \ i = 0; i < n; i++) C[t[i] + 1]++;\n        for(int i = 0; i < alp_sz; i++) C[i\
    \ + 1] += C[i];\n\n        // \u307E\u305Atype-S*\u304B\u3089\u30D0\u30B1\u30C3\
    \u30C8\u306B\u8A70\u3081\u308B\u3002\u5404bucket\u306BS*\u3092\u5F8C\u308D\u304B\
    \u3089\u633F\u5165\u3002\n        vector<int> cnt(alp_sz, 0);\n        for(int\
    \ i = int(LMSs.size()) - 1; i >= 0; i--) {\n            int c = t[LMSs[i]];\n\
    \            SA[C[c + 1] - 1 - cnt[c]] = LMSs[i];\n            cnt[c]++;\n   \
    \     }\n\n        // \u6B21\u306Btype-L\u3092\u8A70\u3081\u308B\u3002SA\u3092\
    \u524D\u304B\u3089\u8D70\u67FB\u3059\u308B\u3002\n        // type-S*\u3067\u3042\
    \u308Bsuffix\n        // S[i]\u306B\u3064\u3044\u3066\u3001S[i-1]\u304Ctype-L\u306A\
    \u3089\u30D0\u30B1\u30C3\u30C8\u306E\u5148\u982D\u306B\u5165\u308C\u308B\n   \
    \     cnt.assign(alp_sz, 0);\n        for(int i = 0; i < n; i++) {\n         \
    \   if(SA[i] == 0 || is_S[SA[i] - 1]) continue;\n            int c = t[SA[i] -\
    \ 1];\n            SA[C[c] + cnt[c]] = SA[i] - 1;\n            cnt[c]++;\n   \
    \     }\n\n        // \u6700\u5F8C\u306Btype-S\u3092\u8A70\u3081\u308B\u3002SA\u3092\
    \u5F8C\u308D\u304B\u3089\u8D70\u67FB\u3059\u308B\n        // type-L\u3067\u3042\
    \u308Bsuffix\n        // S[i]\u306B\u3064\u3044\u3066\u3001S[i-1]\u304Ctype-S\u306A\
    \u3089\u30D0\u30B1\u30C3\u30C8\u306E\u5F8C\u308D\u306B\u5165\u308C\u308B\n   \
    \     cnt.assign(alp_sz, 0);\n        for(int i = n - 1; i >= 0; i--) {\n    \
    \        if(SA[i] == 0 || !is_S[SA[i] - 1]) continue;\n            int c = t[SA[i]\
    \ - 1];\n            SA[C[c + 1] - 1 - cnt[c]] = SA[i] - 1;\n            cnt[c]++;\n\
    \        }\n\n        return SA;\n    }\n\n  public:\n    string S;\n    vector<int>\
    \ sa;\n    SA_IS(string s) : S(s), sa(S.size()) {\n        int n = int(s.size());\n\
    \        s += '$';\n        vector<int> t(n + 1);\n        for(int i = 0; i <\
    \ n; i++) t[i] = s[i] - '$';\n        sa = sa_is(t, 100);\n        sa.erase(sa.begin());\n\
    \    }\n    int operator[](const int i) const { return sa[i]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/sa-is.hpp
  requiredBy: []
  timestamp: '2021-02-13 09:00:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/sa-is.test.cpp
documentation_of: string/sa-is.hpp
layout: document
title: SA-IS
---