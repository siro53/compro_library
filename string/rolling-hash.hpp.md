---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/modint_2_61.hpp
    title: "\u6CD5 2^61-1 \u306E modint"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/monoid/rolling_hash.hpp
    title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u30E2\u30CE\u30A4\
      \u30C9"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki2102.test.cpp
    title: test/yukicoder/yuki2102.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki430.test.cpp
    title: test/yukicoder/yuki430.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/rolling-hash.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <random>\n#include <string>\n#include <vector>\n\n#line\
    \ 2 \"modint/modint_2_61.hpp\"\n\n#include <istream>\n#include <utility>\n\n//\
    \ \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u7528 modint\n// https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    class ModInt_2_61 {\n  public:\n    using M = ModInt_2_61;\n    ModInt_2_61()\
    \ : x(0) {}\n    ModInt_2_61(long long y) : x(y >= 0 ? y % mod : (mod - (-y) %\
    \ mod) % mod) {}\n    unsigned long long val() const { return x; }\n    M &operator+=(const\
    \ M &m) {\n        if((x += m.x) >= mod) x -= mod;\n        return *this;\n  \
    \  }\n    M &operator-=(const M &m) {\n        if((x += mod - m.x) >= mod) x -=\
    \ mod;\n        return *this;\n    }\n    M &operator*=(const M &m) {\n      \
    \  __uint128_t t = (__uint128_t)x * m.x;\n        unsigned long long na = t >>\
    \ 61;\n        unsigned long long nb = t & mod;\n        if((na += nb) >= mod)\
    \ na -= mod;\n        x = na;\n        return *this;\n    }\n    M &operator/=(const\
    \ M &m) {\n        *this *= m.inv();\n        return *this;\n    }\n    M operator-()\
    \ const { return M(-(long long)x); }\n    M operator+(const M &m) const { return\
    \ M(*this) += m; }\n    M operator-(const M &m) const { return M(*this) -= m;\
    \ }\n    M operator*(const M &m) const { return M(*this) *= m; }\n    M operator/(const\
    \ M &m) const { return M(*this) /= m; }\n    bool operator==(const M &m) const\
    \ { return (x == m.x); }\n    bool operator!=(const M &m) const { return (x !=\
    \ m.x); }\n    M inv() const {\n        long long a = x, b = mod, u = 1, v = 0,\
    \ t;\n        while(b > 0) {\n            t = a / b;\n            std::swap(a\
    \ -= t * b, b);\n            std::swap(u -= t * v, v);\n        }\n        return\
    \ M(u);\n    }\n    M pow(unsigned long long n) const {\n        M ret(1), mul(x);\n\
    \        while(n > 0) {\n            if(n & 1) ret *= mul;\n            mul *=\
    \ mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const M &p) {\n        return os\
    \ << p.x;\n    }\n    friend std::istream &operator>>(std::istream &is, M &a)\
    \ {\n        long long t;\n        is >> t;\n        a = M(t);\n        return\
    \ (is);\n    }\n    static constexpr unsigned long long get_mod() { return mod;\
    \ }\n\n  private:\n    unsigned long long x;\n    static constexpr unsigned long\
    \ long mod = (1LL << 61) - 1;\n};\n#line 10 \"string/rolling-hash.hpp\"\n\nstruct\
    \ RollingHash {\n    using u64 = unsigned long long;\n    using mint = ModInt_2_61;\n\
    \    static constexpr u64 mod = (1ULL << 61) - 1;\n    const u64 base;\n    std::vector<mint>\
    \ hashed, power;\n\n    explicit RollingHash(const std::vector<int> &v, u64 base)\
    \ : base(base) {\n        int n = (int)v.size();\n        hashed.assign(n + 1,\
    \ 0);\n        power.assign(n + 1, 0);\n        power[0] = 1;\n        for(int\
    \ i = 0; i < n; i++) {\n            power[i + 1] = power[i] * base;\n        \
    \    hashed[i + 1] = (hashed[i] * base) + v[i];\n        }\n    }\n    explicit\
    \ RollingHash(const std::string &s, u64 base) : base(base) {\n        int n =\
    \ (int)s.size();\n        hashed.assign(n + 1, 0);\n        power.assign(n + 1,\
    \ 0);\n        power[0] = 1;\n        for(int i = 0; i < n; i++) {\n         \
    \   power[i + 1] = power[i] * base;\n            hashed[i + 1] = (hashed[i] *\
    \ base) + s[i];\n        }\n    }\n    static inline u64 gen_base() {\n      \
    \  std::random_device seed_gen;\n        std::mt19937_64 engine(seed_gen());\n\
    \        std::uniform_int_distribution<u64> rand(2, mod - 2);\n        return\
    \ rand(engine);\n    }\n    mint get(int l, int r) {\n        assert(0 <= l);\n\
    \        assert(l <= r);\n        assert(r < (int)power.size());\n        return\
    \ (hashed[r] - (hashed[l] * power[r - l]));\n    }\n    mint connect(mint h1,\
    \ mint h2, int h2len) {\n        return (h1 * power[h2len] + h2);\n    }\n   \
    \ int get_lcp(RollingHash &b, int l1, int r1, int l2, int r2) {\n        assert(mod\
    \ == b.mod);\n        int len = std::min(r1 - l1, r2 - l2);\n        int low =\
    \ -1, high = len + 1;\n        while(high - low > 1) {\n            int mid =\
    \ (low + high) >> 1;\n            if(get(l1, l1 + mid) == b.get(l2, l2 + mid))\
    \ {\n                low = mid;\n            } else {\n                high =\
    \ mid;\n            }\n        }\n        return low;\n    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <random>\n\
    #include <string>\n#include <vector>\n\n#include \"../modint/modint_2_61.hpp\"\
    \n\nstruct RollingHash {\n    using u64 = unsigned long long;\n    using mint\
    \ = ModInt_2_61;\n    static constexpr u64 mod = (1ULL << 61) - 1;\n    const\
    \ u64 base;\n    std::vector<mint> hashed, power;\n\n    explicit RollingHash(const\
    \ std::vector<int> &v, u64 base) : base(base) {\n        int n = (int)v.size();\n\
    \        hashed.assign(n + 1, 0);\n        power.assign(n + 1, 0);\n        power[0]\
    \ = 1;\n        for(int i = 0; i < n; i++) {\n            power[i + 1] = power[i]\
    \ * base;\n            hashed[i + 1] = (hashed[i] * base) + v[i];\n        }\n\
    \    }\n    explicit RollingHash(const std::string &s, u64 base) : base(base)\
    \ {\n        int n = (int)s.size();\n        hashed.assign(n + 1, 0);\n      \
    \  power.assign(n + 1, 0);\n        power[0] = 1;\n        for(int i = 0; i <\
    \ n; i++) {\n            power[i + 1] = power[i] * base;\n            hashed[i\
    \ + 1] = (hashed[i] * base) + s[i];\n        }\n    }\n    static inline u64 gen_base()\
    \ {\n        std::random_device seed_gen;\n        std::mt19937_64 engine(seed_gen());\n\
    \        std::uniform_int_distribution<u64> rand(2, mod - 2);\n        return\
    \ rand(engine);\n    }\n    mint get(int l, int r) {\n        assert(0 <= l);\n\
    \        assert(l <= r);\n        assert(r < (int)power.size());\n        return\
    \ (hashed[r] - (hashed[l] * power[r - l]));\n    }\n    mint connect(mint h1,\
    \ mint h2, int h2len) {\n        return (h1 * power[h2len] + h2);\n    }\n   \
    \ int get_lcp(RollingHash &b, int l1, int r1, int l2, int r2) {\n        assert(mod\
    \ == b.mod);\n        int len = std::min(r1 - l1, r2 - l2);\n        int low =\
    \ -1, high = len + 1;\n        while(high - low > 1) {\n            int mid =\
    \ (low + high) >> 1;\n            if(get(l1, l1 + mid) == b.get(l2, l2 + mid))\
    \ {\n                low = mid;\n            } else {\n                high =\
    \ mid;\n            }\n        }\n        return low;\n    }\n};"
  dependsOn:
  - modint/modint_2_61.hpp
  isVerificationFile: false
  path: string/rolling-hash.hpp
  requiredBy:
  - data-structure/monoid/rolling_hash.hpp
  timestamp: '2023-12-05 19:29:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki2102.test.cpp
  - test/yukicoder/yuki430.test.cpp
documentation_of: string/rolling-hash.hpp
layout: document
link: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
title: Rolling Hash
---

## このライブラリでできること

`RollingHash` は、文字列や整数列の部分列を短いハッシュ値に変換します。長さ $N$ の列を $O(N)$ 時間で前処理すると、任意の連続部分列のハッシュを $O(1)$ 時間で取得できます。部分文字列の比較を何度も行う場合に使えます。

底を $b$、法を $m=2^{61}-1$ とし、$H(A)=\sum_{i=0}^{n-1}A_i b^{n-1-i}\pmod m$ として列を表します。先頭からのハッシュと底の累乗を持っておけば、不要な先頭部分を引くことで区間の値を取り出せます。

## 使い方

比較する列では、例のように同じ `base` を渡して構築してください。`get(l,r)` は半開区間 $[l,r)$ のハッシュです。`ababa` の区間 $[0,3)$ と $[2,5)$ はどちらも `aba` なので同じ値になります。

`get_lcp` はハッシュ比較を使った二分探索で最長共通接頭辞の長さを調べます。例の `ababa` と `ababx` は最初の4文字が同じなので、結果は $4$ です。`connect(h1,h2,len2)` は後ろに連結する列の長さを使い、$h_1b^{\mathrm{len2}}+h_2$ を計算します。

```cpp
#include "template/template.cpp"
#include "string/rolling-hash.hpp"

int main() {
    auto base = RollingHash::gen_base();
    RollingHash a(string("ababa"), base), b(string("ababx"), base);
    assert(a.get(0, 3) == a.get(2, 5));
    assert(a.get_lcp(b, 0, 5, 0, 5) == 4);
}
```

## API・計算量

必要な空間は $O(N)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `RollingHash(s,base), RollingHash(vector<int>,base)` | ハッシュ・累乗表を構築。 | O(N) |
| `gen_base()` | ランダムな底を返す static 関数。 | 固定長の乱数生成（期待 O(1)） |
| `get(l,r)` | [l,r) のハッシュ。空列は 0。 | O(1) |
| `connect(h1,h2,h2len)` | h1 の列の後ろに長さ h2len の h2 を連結。 | O(1) |
| `get_lcp(b,l1,r1,l2,r2)` | 自身の [l1,r1) と b の [l2,r2) の LCP 長。 | O(log(min(r1-l1,r2-l2)+1)) |

## 利用条件と実装上の注意

ハッシュが一致しても、元の列が等しいとは限りません。異なる長さの列を比較する場合は長さも確認してください。ハッシュ衝突の可能性を許容できない用途では、必要に応じて実際の列も比較します。

比較・連結する列は、底だけでなく文字や整数の符号化もそろえてください。`get_lcp` は底の一致を検査しません。`connect` に渡す長さは、そのオブジェクトの累乗表の範囲 $[0,N]$ に収めます。

公開メンバ `hashed,power` は前計算表、`base` は底、`mint` は剰余型です。これらの表を直接変更すると区間取得との整合性が失われます。
