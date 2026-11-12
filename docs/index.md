---
title: "\u30E9\u30A4\u30D6\u30E9\u30EA\u4E00\u89A7"
---

# ライブラリ一覧

各ページでは、最初に用途と考え方を説明し、使用例で具体的な操作を確認してから、APIと計算量を参照できるようにしています。初めて使う場合は「使い方」まで順に読み、関数の引数や返り値を確認したい場合はAPI表を参照してください。

## 目的から選ぶ

- 配列の値を更新しながら区間和を求めるなら **BIT**、区間全体へ加算するなら **Range BIT** を使います。和以外の集約には **Segment Tree**、一般の区間更新には **Lazy Segment Tree** が対応します。
- 更新しない盤面の長方形和には **二次元累積和**、長方形への加算をまとめて反映したい場合には **二次元いもす法** が適しています。
- 集合の併合には **Union Find**、過去の状態も残す場合には **永続 Union Find** を使います。
- 最短路は、辺数を数えるなら **BFS**、非負の重みを加算するなら **Dijkstra 法** を選びます。木のパス上の集約を配列の区間処理へ変換したい場合は **HL 分解** を使います。
- 小さい数をまとめて素数判定するなら **エラトステネスの篩**、大きい数を個別に調べるなら **素数判定** のページが入口になります。
- 提出する解を愚直解とランダムな入力で比べるなら、**生成器ライブラリ一式** で入力生成器を書き、README の「ランダムテスト」で紹介している `scripts/randtest.py` で実行します。

下の一覧には、小さな補助関数やモノイドも含め、各ファイルの説明をまとめています。実装に不備があるAPIは、そのページの「利用条件と実装上の注意」に明記しています。アルゴリズムの数学的な性質と、現在のコードが対応できる範囲を確認してから利用してください。

## 使用例のコンパイル

使用例はC++17を前提とします。リポジトリのルートをincludeパスに加えると、例中のパスをそのまま使えます。

```sh
g++ -std=c++17 -O2 -Wall -Wextra -I /path/to/compro_library example.cpp
```

例では `template/template.cpp` を先にincludeしています。一部のヘッダーは標準ヘッダーや `using namespace std` をこのテンプレートに依存するためです。assertは例の計算結果を示すために使っており、すべての入力に対する正しさを検証するものではありません。

## 区間・計算量の読み方

配列の添字は原則として0から始まります。半開区間 $[l,r)$ は、位置 $l,l+1,\ldots,r-1$ を含み、右端 $r$ は含みません。たとえば $[1,4)$ にある要素は3個で、$[l,l)$ は空区間です。関数ごとの例外や値域の境界は、それぞれのページで説明します。

時間計算量は、特記しない限り1回の呼び出しに対する最悪時の上界です。**償却計算量**は、複数の操作の合計コストを操作回数で割った上界であり、個々の操作が必ずその時間で終わるという意味ではありません。**期待計算量**は乱数についての期待値で、償却計算量とは異なります。

表では通常、固定長整数の演算・比較・コピーを定数時間としています。多倍長整数や長さによって計算時間が変わる型を使う場合は、その演算コストも掛けてください。セグメント木などの汎用データ構造についても、渡した演算の計算時間が別途影響します。$O(\log N)$ などの記載は、サイズ0・1の境界では少なくとも定数時間と読み替えます。

また、数学的に定義できる演算でも、固定長整数では中間計算がオーバーフローすることがあります。返り値だけでなく、積・和・符号反転なども型の範囲内に収まることが前提です。

## data-structure

- [Binary Indexed Tree](https://github.com/siro53/compro_library/blob/main/docs/data-structure/BIT.md)
- [Binary Trie](https://github.com/siro53/compro_library/blob/main/docs/data-structure/binary-trie.md)
- [Compact Bit Vector](https://github.com/siro53/compro_library/blob/main/docs/data-structure/compact-bitvector.md)
- [削除可能な優先度付きキュー](https://github.com/siro53/compro_library/blob/main/docs/data-structure/erasable-priority-queue.md)
- [二次元いもす法](https://github.com/siro53/compro_library/blob/main/docs/data-structure/imos2D.md)
- [加算モノイド](https://github.com/siro53/compro_library/blob/main/docs/data-structure/monoid/add.md)
- [アフィン変換モノイド](https://github.com/siro53/compro_library/blob/main/docs/data-structure/monoid/affine.md)
- [ビット ANDモノイド](https://github.com/siro53/compro_library/blob/main/docs/data-structure/monoid/and.md)
- [最大公約数モノイド](https://github.com/siro53/compro_library/blob/main/docs/data-structure/monoid/gcd.md)
- [最大部分配列和モノイド](https://github.com/siro53/compro_library/blob/main/docs/data-structure/monoid/kadane.md)
- [最小公倍数モノイド](https://github.com/siro53/compro_library/blob/main/docs/data-structure/monoid/lcm.md)
- [最大値モノイド](https://github.com/siro53/compro_library/blob/main/docs/data-structure/monoid/max.md)
- [添字付き最大値モノイド](https://github.com/siro53/compro_library/blob/main/docs/data-structure/monoid/max_index.md)
- [最小値モノイド](https://github.com/siro53/compro_library/blob/main/docs/data-structure/monoid/min.md)
- [添字付き最小値モノイド](https://github.com/siro53/compro_library/blob/main/docs/data-structure/monoid/min_index.md)
- [ビット ORモノイド](https://github.com/siro53/compro_library/blob/main/docs/data-structure/monoid/or.md)
- [ローリングハッシュモノイド](https://github.com/siro53/compro_library/blob/main/docs/data-structure/monoid/rolling_hash.md)
- [和・個数モノイド](https://github.com/siro53/compro_library/blob/main/docs/data-structure/monoid/sum_count.md)
- [永続配列](https://github.com/siro53/compro_library/blob/main/docs/data-structure/persistent/persistent-array.md)
- [永続キュー](https://github.com/siro53/compro_library/blob/main/docs/data-structure/persistent/persistent-queue.md)
- [永続 Union Find](https://github.com/siro53/compro_library/blob/main/docs/data-structure/persistent/persistent-unionfind.md)
- [Range BIT](https://github.com/siro53/compro_library/blob/main/docs/data-structure/range-BIT.md)
- [Dynamic Segment Tree](https://github.com/siro53/compro_library/blob/main/docs/data-structure/segtree/dynamic-segtree.md)
- [Lazy Segment Tree](https://github.com/siro53/compro_library/blob/main/docs/data-structure/segtree/lazy-segtree.md)
- [Li Chao Tree](https://github.com/siro53/compro_library/blob/main/docs/data-structure/segtree/li-chao-tree.md)
- [Segment Tree Beats](https://github.com/siro53/compro_library/blob/main/docs/data-structure/segtree/segtree-beats.md)
- [Segment Tree](https://github.com/siro53/compro_library/blob/main/docs/data-structure/segtree/segtree.md)
- [Slope Trick](https://github.com/siro53/compro_library/blob/main/docs/data-structure/slope-trick.md)
- [二次元累積和](https://github.com/siro53/compro_library/blob/main/docs/data-structure/sum2D.md)
- [Union Find](https://github.com/siro53/compro_library/blob/main/docs/data-structure/unionfind.md)
- [値ごとの和・個数管理](https://github.com/siro53/compro_library/blob/main/docs/data-structure/utils/sum_count_manager.md)
- [Wavelet Matrix](https://github.com/siro53/compro_library/blob/main/docs/data-structure/wavelet-matrix.md)

## graph

- [グラフ構造体](https://github.com/siro53/compro_library/blob/main/docs/graph/graph_template.md)
- [なもりグラフの分解](https://github.com/siro53/compro_library/blob/main/docs/graph/namori.md)
- [区間に辺を張るグラフ](https://github.com/siro53/compro_library/blob/main/docs/graph/range-edge-graph.md)
- [強連結成分分解](https://github.com/siro53/compro_library/blob/main/docs/graph/scc.md)
- [幅優先探索](https://github.com/siro53/compro_library/blob/main/docs/graph/shortest-path/bfs.md)
- [Dijkstra 法](https://github.com/siro53/compro_library/blob/main/docs/graph/shortest-path/dijkstra.md)
- [トポロジカルソート](https://github.com/siro53/compro_library/blob/main/docs/graph/topological-sort.md)
- [重心分解](https://github.com/siro53/compro_library/blob/main/docs/graph/tree/centroid-decomposition.md)
- [木の直径](https://github.com/siro53/compro_library/blob/main/docs/graph/tree/diameter.md)
- [Heavy Light Decomposition](https://github.com/siro53/compro_library/blob/main/docs/graph/tree/hld.md)
- [最小共通祖先（ダブリング）](https://github.com/siro53/compro_library/blob/main/docs/graph/tree/lca.md)
- [木ハッシュ](https://github.com/siro53/compro_library/blob/main/docs/graph/tree/tree-hash.md)

## math

- [F₂ 上の行列・連立方程式](https://github.com/siro53/compro_library/blob/main/docs/math/F2.md)
- [Barrett Reduction](https://github.com/siro53/compro_library/blob/main/docs/math/barrett-reduction.md)
- [二項係数](https://github.com/siro53/compro_library/blob/main/docs/math/binom.md)
- [FFT による畳み込み](https://github.com/siro53/compro_library/blob/main/docs/math/convolution/fft.md)
- [NTT による畳み込み](https://github.com/siro53/compro_library/blob/main/docs/math/convolution/ntt.md)
- [約数列挙](https://github.com/siro53/compro_library/blob/main/docs/math/divisor.md)
- [エラトステネスの篩](https://github.com/siro53/compro_library/blob/main/docs/math/eratosthenes.md)
- [素数判定](https://github.com/siro53/compro_library/blob/main/docs/math/is-prime.md)
- [線形篩](https://github.com/siro53/compro_library/blob/main/docs/math/linear-sieve.md)
- [行列](https://github.com/siro53/compro_library/blob/main/docs/math/matrix.md)
- [剰余付き累乗](https://github.com/siro53/compro_library/blob/main/docs/math/pow_mod.md)
- [試し割りによる素因数分解](https://github.com/siro53/compro_library/blob/main/docs/math/prime-factor.md)
- [原始根](https://github.com/siro53/compro_library/blob/main/docs/math/primitive-root.md)
- [区間素因数分解](https://github.com/siro53/compro_library/blob/main/docs/math/segment-factorize.md)
- [区間素数判定](https://github.com/siro53/compro_library/blob/main/docs/math/segment-sieve.md)
- [2-SAT](https://github.com/siro53/compro_library/blob/main/docs/math/two-sat.md)

## modint

- [動的法 modint](https://github.com/siro53/compro_library/blob/main/docs/modint/dynamic-modint.md)
- [固定法 modint](https://github.com/siro53/compro_library/blob/main/docs/modint/modint.md)
- [法 2^61-1 の modint](https://github.com/siro53/compro_library/blob/main/docs/modint/modint_2_61.md)

## string

- [Rolling Hash](https://github.com/siro53/compro_library/blob/main/docs/string/rolling-hash.md)
- [Z algorithm](https://github.com/siro53/compro_library/blob/main/docs/string/z-algo.md)

## geometry

- [幾何の基本型](https://github.com/siro53/compro_library/blob/main/docs/geometry/base.md)
- [3 点の位置関係](https://github.com/siro53/compro_library/blob/main/docs/geometry/ccw.md)
- [円](https://github.com/siro53/compro_library/blob/main/docs/geometry/circle.md)
- [凸多角形の切断](https://github.com/siro53/compro_library/blob/main/docs/geometry/convex-cut.md)
- [凸包](https://github.com/siro53/compro_library/blob/main/docs/geometry/convex-hull.md)
- [交点](https://github.com/siro53/compro_library/blob/main/docs/geometry/cross-point.md)
- [外積](https://github.com/siro53/compro_library/blob/main/docs/geometry/cross.md)
- [度からラジアン](https://github.com/siro53/compro_library/blob/main/docs/geometry/degree-to-radian.md)
- [直線と点の距離](https://github.com/siro53/compro_library/blob/main/docs/geometry/distance-between-line-and-point.md)
- [線分と点の距離](https://github.com/siro53/compro_library/blob/main/docs/geometry/distance-between-segment-and-point.md)
- [線分間の距離](https://github.com/siro53/compro_library/blob/main/docs/geometry/distance-between-segments.md)
- [内積](https://github.com/siro53/compro_library/blob/main/docs/geometry/dot.md)
- [幾何ライブラリ（まとめて include）](https://github.com/siro53/compro_library/blob/main/docs/geometry/geometry.md)
- [多角形への包含判定](https://github.com/siro53/compro_library/blob/main/docs/geometry/is-contained.md)
- [凸多角形判定](https://github.com/siro53/compro_library/blob/main/docs/geometry/is-convex.md)
- [円への包含判定](https://github.com/siro53/compro_library/blob/main/docs/geometry/is-in-circle.md)
- [交差判定](https://github.com/siro53/compro_library/blob/main/docs/geometry/is-intersect.md)
- [直線の直交判定](https://github.com/siro53/compro_library/blob/main/docs/geometry/is-orthogonal.md)
- [直線の平行判定](https://github.com/siro53/compro_library/blob/main/docs/geometry/is-parallel.md)
- [点が直線上にあるか](https://github.com/siro53/compro_library/blob/main/docs/geometry/is-point-on-line.md)
- [点が線分上にあるか](https://github.com/siro53/compro_library/blob/main/docs/geometry/is-point-on-segment.md)
- [直線](https://github.com/siro53/compro_library/blob/main/docs/geometry/line.md)
- [法線ベクトル](https://github.com/siro53/compro_library/blob/main/docs/geometry/normal-vector.md)
- [多角形の符号付き面積](https://github.com/siro53/compro_library/blob/main/docs/geometry/polygon-area.md)
- [射影](https://github.com/siro53/compro_library/blob/main/docs/geometry/projection.md)
- [ラジアンから度](https://github.com/siro53/compro_library/blob/main/docs/geometry/radian-to-degree.md)
- [直線に対する反射](https://github.com/siro53/compro_library/blob/main/docs/geometry/reflection.md)
- [点・ベクトルの回転](https://github.com/siro53/compro_library/blob/main/docs/geometry/rotate.md)
- [線分](https://github.com/siro53/compro_library/blob/main/docs/geometry/segment.md)
- [点から円への接線](https://github.com/siro53/compro_library/blob/main/docs/geometry/tangent-to-circle.md)
- [2 円の共通接線](https://github.com/siro53/compro_library/blob/main/docs/geometry/tangent.md)
- [単位ベクトル](https://github.com/siro53/compro_library/blob/main/docs/geometry/unit-vector.md)

## misc

- [座標圧縮](https://github.com/siro53/compro_library/blob/main/docs/misc/compress.md)
- [整数の切り上げ・切り捨て除算](https://github.com/siro53/compro_library/blob/main/docs/misc/floor-ceil-div.md)
- [有理数](https://github.com/siro53/compro_library/blob/main/docs/misc/fraction.md)
- [転倒数](https://github.com/siro53/compro_library/blob/main/docs/misc/inversion-number.md)
- [Mo のアルゴリズム](https://github.com/siro53/compro_library/blob/main/docs/misc/mo.md)
- [ランレングス圧縮](https://github.com/siro53/compro_library/blob/main/docs/misc/rle.md)
- [bit 集合の列挙](https://github.com/siro53/compro_library/blob/main/docs/misc/subset-iterator.md)
- [タイマー](https://github.com/siro53/compro_library/blob/main/docs/misc/timer.md)

## random

- [乱数生成](https://github.com/siro53/compro_library/blob/main/docs/random/rng.md)
- [生成器ライブラリ一式](https://github.com/siro53/compro_library/blob/main/docs/random/gen/all.md)
- [テスト生成用の乱数 (Random)](https://github.com/siro53/compro_library/blob/main/docs/random/gen/random.md)
- [ランダムな数列・順列・部分集合・区間](https://github.com/siro53/compro_library/blob/main/docs/random/gen/sequence.md)
- [ランダムな文字列](https://github.com/siro53/compro_library/blob/main/docs/random/gen/string.md)
- [ランダムな木](https://github.com/siro53/compro_library/blob/main/docs/random/gen/tree.md)
- [ランダムなグラフ](https://github.com/siro53/compro_library/blob/main/docs/random/gen/graph.md)

## template

- [競プロ用テンプレート](https://github.com/siro53/compro_library/blob/main/docs/template/template.md)
