---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/xmascon24/submissions/61272051
  bundledCode: "#line 2 \"misc/subset-iterator.hpp\"\n\n#include <cstdint>\n#include\
    \ <x86intrin.h>\n\n// Subset(S) := S\u306E\u90E8\u5206\u96C6\u5408\u3092\u8D70\
    \u67FB\u3059\u308B\nstruct Subset {\n    struct SubsetIter {\n        uint32_t\
    \ S, T;\n        bool is_end;\n\n        SubsetIter(uint32_t s): S(s), T(s), is_end(false)\
    \ {}\n\n        auto operator*() const { return T; }\n        auto operator++()\
    \ { T = (T - 1) & S; }\n        auto operator!=(std::nullptr_t) {\n          \
    \  if(is_end) return false;\n            is_end = (T == 0);\n            return\
    \ true;\n        }\n    };\n\n    uint32_t S;\n\n    Subset(uint32_t s): S(s)\
    \ {}\n    auto begin() { return SubsetIter(S); }\n    auto end() { return nullptr;\
    \ }\n};\n\n// Subset_k(S, k) := S\u306E\u90E8\u5206\u96C6\u5408\u306E\u3046\u3061\
    \u3001size\u304Ck\u306E\u96C6\u5408\u306E\u307F\u8D70\u67FB\u3059\u308B\n// verify:\
    \ https://atcoder.jp/contests/xmascon24/submissions/61272051\nstruct Subset_k\
    \ {\n    struct SubsetIter_k {\n        const uint32_t n, k, S;\n        uint32_t\
    \ T;\n\n        SubsetIter_k(uint32_t S, uint32_t k): n(uint32_t(1) << __builtin_popcount(S)),\
    \ k(k), S(S), T((uint32_t(1) << k) - 1) {}\n\n        __attribute__((target(\"\
    bmi2\")))\n        auto operator*() const { return _pdep_u32(T, S); }\n\n    \
    \    __attribute__((target(\"bmi\")))\n        auto operator++() {\n         \
    \   uint32_t y = T + _blsi_u32(T);\n            T = y | (__andn_u32(y, T) >> _tzcnt_u32(T\
    \ << 1));\n        }\n        auto operator!=(std::nullptr_t) const { return T\
    \ < n; }\n    };\n\n    uint32_t S, k;\n    \n    Subset_k(uint32_t S, uint32_t\
    \ k): S(S), k(k) {\n        assert(k != 0);\n    }\n\n    auto begin() { return\
    \ SubsetIter_k(S, k); }\n    auto end() { return nullptr; }\n};\n\n// SetBit(S)\
    \ := S\u306E\u3046\u3061\u3001bit\u304C\u7ACB\u3063\u3066\u3044\u308Bindex\u3092\
    \u5C0F\u3055\u3044\u9806\u306B\u8FD4\u3059\n// verify: https://atcoder.jp/contests/xmascon24/submissions/61272051\n\
    struct SetBit {\n    struct SetBitIter {\n        uint32_t S;\n\n        SetBitIter(uint32_t\
    \ S): S(S) {}\n\n        __attribute__((target(\"bmi\")))\n        auto operator*()\
    \ { return _tzcnt_u32(S); }\n\n        __attribute__((target(\"bmi\")))\n    \
    \    auto operator++() { S = _blsr_u32(S); }\n\n        auto operator!=(std::nullptr_t)\
    \ { return S; }\n    };\n\n    uint32_t S;\n\n    SetBit(uint32_t S): S(S) {}\n\
    \n    auto begin() { return SetBitIter(S); }\n    auto end() { return nullptr;\
    \ }\n};\n"
  code: "#pragma once\n\n#include <cstdint>\n#include <x86intrin.h>\n\n// Subset(S)\
    \ := S\u306E\u90E8\u5206\u96C6\u5408\u3092\u8D70\u67FB\u3059\u308B\nstruct Subset\
    \ {\n    struct SubsetIter {\n        uint32_t S, T;\n        bool is_end;\n\n\
    \        SubsetIter(uint32_t s): S(s), T(s), is_end(false) {}\n\n        auto\
    \ operator*() const { return T; }\n        auto operator++() { T = (T - 1) & S;\
    \ }\n        auto operator!=(std::nullptr_t) {\n            if(is_end) return\
    \ false;\n            is_end = (T == 0);\n            return true;\n        }\n\
    \    };\n\n    uint32_t S;\n\n    Subset(uint32_t s): S(s) {}\n    auto begin()\
    \ { return SubsetIter(S); }\n    auto end() { return nullptr; }\n};\n\n// Subset_k(S,\
    \ k) := S\u306E\u90E8\u5206\u96C6\u5408\u306E\u3046\u3061\u3001size\u304Ck\u306E\
    \u96C6\u5408\u306E\u307F\u8D70\u67FB\u3059\u308B\n// verify: https://atcoder.jp/contests/xmascon24/submissions/61272051\n\
    struct Subset_k {\n    struct SubsetIter_k {\n        const uint32_t n, k, S;\n\
    \        uint32_t T;\n\n        SubsetIter_k(uint32_t S, uint32_t k): n(uint32_t(1)\
    \ << __builtin_popcount(S)), k(k), S(S), T((uint32_t(1) << k) - 1) {}\n\n    \
    \    __attribute__((target(\"bmi2\")))\n        auto operator*() const { return\
    \ _pdep_u32(T, S); }\n\n        __attribute__((target(\"bmi\")))\n        auto\
    \ operator++() {\n            uint32_t y = T + _blsi_u32(T);\n            T =\
    \ y | (__andn_u32(y, T) >> _tzcnt_u32(T << 1));\n        }\n        auto operator!=(std::nullptr_t)\
    \ const { return T < n; }\n    };\n\n    uint32_t S, k;\n    \n    Subset_k(uint32_t\
    \ S, uint32_t k): S(S), k(k) {\n        assert(k != 0);\n    }\n\n    auto begin()\
    \ { return SubsetIter_k(S, k); }\n    auto end() { return nullptr; }\n};\n\n//\
    \ SetBit(S) := S\u306E\u3046\u3061\u3001bit\u304C\u7ACB\u3063\u3066\u3044\u308B\
    index\u3092\u5C0F\u3055\u3044\u9806\u306B\u8FD4\u3059\n// verify: https://atcoder.jp/contests/xmascon24/submissions/61272051\n\
    struct SetBit {\n    struct SetBitIter {\n        uint32_t S;\n\n        SetBitIter(uint32_t\
    \ S): S(S) {}\n\n        __attribute__((target(\"bmi\")))\n        auto operator*()\
    \ { return _tzcnt_u32(S); }\n\n        __attribute__((target(\"bmi\")))\n    \
    \    auto operator++() { S = _blsr_u32(S); }\n\n        auto operator!=(std::nullptr_t)\
    \ { return S; }\n    };\n\n    uint32_t S;\n\n    SetBit(uint32_t S): S(S) {}\n\
    \n    auto begin() { return SetBitIter(S); }\n    auto end() { return nullptr;\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/subset-iterator.hpp
  requiredBy: []
  timestamp: '2025-03-09 11:06:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/subset-iterator.hpp
layout: document
title: "bit \u96C6\u5408\u306E\u5217\u6319"
---

## このライブラリでできること

`Subset`、`Subset_k`、`SetBit` は、32 bit整数を集合とみなし、range-forで部分集合や要素を列挙するための型です。bit $i$ が立っていることを、要素 $i$ が集合に含まれることと対応させます。

$k=\operatorname{popcount}(S)$ とすると、`Subset(S)` は空集合を含む $2^k$ 個、`Subset_k(S,t)` は要素数が $t$ の $\binom kt$ 個、`SetBit(S)` は $k$ 個の要素の添字を列挙します。1回のイテレータ操作は定数時間です。

## 使い方

例の `Subset(5)` では $5=101_2$ なので、部分集合のマスクは $5,4,1,0$ の順に現れます。`Subset` は降順、`Subset_k` は固定個数の部分集合を昇順に列挙します。

`SetBit(10)` は $10=1010_2$ の立っている位置を返すので、返り値はマスクではなく添字 $1,3$ です。何を列挙しているかを区別して使ってください。

```cpp
#include "template/template.cpp"
#include "misc/subset-iterator.hpp"

int main() {
    vector<uint32_t> subsets;
    for (auto s : Subset(5)) subsets.push_back(s);
    assert((subsets == vector<uint32_t>{5, 4, 1, 0}));
    vector<unsigned> bits;
    for (auto i : SetBit(10)) bits.push_back(i);
    assert((bits == vector<unsigned>{1, 3}));
}
```

## API・計算量

列挙器自身が使う追加空間は $O(1)$ です。列挙結果を配列などに保存する場合、その分の領域は別途必要になります。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Subset(S)` | S の全ての部分集合を降順に列挙。0 も含む。 | 構築 O(1)、全体 O(2^k) |
| `Subset_k(S,t)` | 要素数 t の部分集合を昇順に列挙。 | 構築 O(1)、全体 O(C(k,t)) |
| `SetBit(S)` | 立っている bit の添字を昇順に列挙。 | 構築 O(1)、全体 O(k) |
| `begin(), end()` | イテレータと nullptr の番兵を返す。 | O(1) |
| `各 Iter の構築、operator*, operator++, operator!=` | 初期化、現在値取得、次へ移動、終端判定。 | O(1) |

## 利用条件と実装上の注意

`Subset_k(S,t)` は $1\le t\le k<32$ の範囲で使います。$k=32$ は32 bit幅を超えるシフトになるため使えません。`SetBit` はBMI、`Subset_k` はBMI/BMI2命令に対応したx86 CPUが必要で、実行時の対応判定はしません。

各内部イテレータは `operator*` で現在値、`operator++` で次の状態、`operator!=` で終了を扱います。特に `Subset` の終端比較には副作用があるため、汎用STLイテレータではなくrange-for用として使ってください。assertのため、共通テンプレートなどを先に include します。
