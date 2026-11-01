---
title: ライブラリ一覧
---

# ライブラリ一覧

各ページに役割、API の動作・返り値、計算量、利用条件、使用例を記載しています。API は現在の実装に対応し、実装上の不備がある場合は「前提・注意点」に明記しています。

使用例はリポジトリルートを include パスに加え、C++17 でコンパイルします。`template/template.cpp` を先に include する形に統一しています。一部のライブラリは標準ヘッダーや `using namespace std` をこのテンプレートに依存します。

```sh
g++ -std=c++17 -O2 -Wall -Wextra -I /path/to/compro_library example.cpp
```

計算量は、特記しない限り固定長整数の演算・比較・コピーを O(1) とします。多倍長整数や可変長の値を使う場合はその演算コストを掛けてください。対数計算量はサイズ 0・1 の場合 O(1) と読み替えます。「償却」は操作列全体に対する平均の上界、「期待」は乱数に関する期待値です。使用例は基本的な動作の例であり、全入力での正しさを証明するものではありません。

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

## template

- [競プロ用テンプレート](https://github.com/siro53/compro_library/blob/main/docs/template/template.md)
