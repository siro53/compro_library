---
title: Heavy Light Decomposition (HL分解)
documentation_of: ../../graph/hld.hpp
---

## 内容
木をHL分解する。

HL分解とは、木を $O(\log{N})$ 本のパスに分解することである。

各頂点の**重み**を、その頂点を根とする部分木のsizeと定義する。

各頂点について根から再帰的に、**子の中で最も重みの大きい頂点**への辺(heavy edge)のみを残し、それ以外の子への辺(light edge)を切る。
これを再帰的に行う。

- [詳しい証明](https://math314.hateblo.jp/entry/2014/06/24/220107)
- [図があって分かりやすい](https://qiita.com/Pro_ktmr/items/4e1e051ea0561772afa3)

実装の際には、まず1回目のDFSで部分木のsizeを求めつつ、各頂点の隣接リストの先頭に、自分の子かつ最も重みの大きい子を持ってくる。

2回目のDFSでは、各頂点の番号をpre-order（いわゆるオイラーツアーをする）で訪れた順に振り直す。こうすることで、HL分解後の各パスについて頂点番号が連続するため、各パスを区間として扱える。また、オイラーツアーをして番号を振り直したことで部分木クエリにも対応出来る。

- [ferinさんのブログ](https://ferin-tech.hatenablog.com/entry/2019/11/21/HL%E5%88%86%E8%A7%A3%E3%81%AE%E5%AE%9F%E8%A3%85)
- [kazuma8128さんのブログ](https://kazuma8128.hatenablog.com/entry/2018/07/16/010500)

## 使い方
- `add_edge(u, v)`
    - 無向辺 $(u, v)$ を追加
- `build(root)`
    - 根を $root$ とした根付き木に対してHL分解する。これを呼び忘れると`assert()`に引っかかるようになっている。
- `operator[](u)`
    - オイラーツアーして頂点番号を振り直した後の頂点 $u$ の頂点番号を返す。
- `lca(u, v)`
    - 頂点 $u$ と頂点 $v$ のLCAを返す。
- `dist(u, v)`
    - 頂点 $u$ と頂点 $v$ の距離を返す。
- `la(u, k)`
    - 頂点 $u$ から親方向に距離 $k$ だけ遡った先の頂点を返す。$depth(u) < k$ の場合は`-1`を返す。
    - [Level Ancestor Problem](https://suisen-kyopro.hatenablog.com/entry/2022/04/04/043452)
- `path(u, v)`
    - 頂点 $u$ から頂点 $v$ へのパスを $O(\log{N})$ 本の区間として返す。帰ってくる区間は、オイラーツアーをして頂点番号を振り直した後のものが返る。
- `path_edge(u, v)`
    - `path(u, v)`の辺属性 ver.
    - $(u, v)$ という辺があったとしたら、子になる方の頂点が辺に対応した値を持つように実装すればOK（根に対応する値はないものとする。）
- `subtree(u)`
    - 頂点 $u$ を根とする部分木に対応する区間が返る。

## 注意点

[この問題](https://judge.yosupo.jp/problem/vertex_set_path_composite)のように非可換なクエリが飛んでくる時は注意が必要。

左右の累積を保持する必要があり、載せるデータ構造(セグ木、BITなど)も順方向と逆方向の 2 本必要になる。

```cpp
Monoid resL = e();
Monoid resR = e();
int lca = hld.lca(u, v);
for(const auto& [l, r] : hld.path(u, lca)) {
    resL = op(seg.prod(l, r), resL);
}
for(const auto& [l, r] : hld.path_edge(lca, v)) {
    resR = op(resR, seg_rev.prod(l, r));
}
Monoid res = op(resL, resR);
```
