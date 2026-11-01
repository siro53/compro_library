# 公開 API と検証テストの対応

対象はリポジトリのライブラリヘッダー 106 ファイルです。既存の AOJ・Library Checker・yukicoder の verifier に加え、下表の自作テストで、公開操作・オーバーロード・有効な初期化手順・境界条件を検証します。`template/template.cpp` の競技用マクロ類はこの一覧の対象外です。

自作テストの `PROBLEM` は verifier に実行させるための A + B です。ライブラリの検証本体は入力を読む前の `assert` で、A + B を解いたことを検証の根拠にはしていません。`NDEBUG` を定義せず実行してください。

- 差分検証: 配列、全探索、Floyd–Warshall、直接 DFT、整数の `/`・`%` など、対象ライブラリから独立した期待値と比較します。
- GF(2) は行列サイズ 0〜3 のすべての行列と右辺を列挙し、解なし・不定・一意解、零行・零列を確認します。大きめの長方形行列も固定シードで追加します。
- 型の公開演算子は、複合代入の返却参照、入力の非破壊性、恒等元、非可換な合成順序も確認します。構造体の公開状態は、その API が初期化するフィールドを検査します。初期値が未定義と明記されたフィールドは代入後に利用します。
- 今回追加した差分テストの乱数は固定シードです。乱数生成器自体は値域と 1 要素区間、タイマーは開始時刻と単位を検査し、偶然の分布や短い待機時間に依存する判定はしません。
- 入力範囲・呼び出し順などは各 `docs/` の契約に従います。例えば空キューの `front()`、未構築の累積和、非可逆元での除算などは対象外です。有限個のテストによる検証であり、すべての入力についての数学的証明を意味しません。

## 実行

```sh
oj-verify run test/mytest
oj-verify all
python3 -m unittest discover -s test/mytest/headers -v
```

各ファイルは `g++ -std=c++17 -O2 -Wall -Wextra` でも直接コンパイルし、標準入力に `1 2` を渡して実行できます。追加テストは UndefinedBehaviorSanitizer でも実行します。BMI/BMI2 を使う既存の部分集合 API には対応 CPU が必要です。

## 対応表

API 欄はドキュメントの公開 API 表を基にしています。デフォルト構築・公開データ型・公開メンバの確認もテストに含めています。各型の前提条件を満たす利用を対象とし、すべてのテンプレート引数の組合せを網羅するものではありません。ジャッジ問題での大規模検証は引き続き `test/aoj/`・`test/library-checker/`・`test/yukicoder/` の既存 verifier を併用します。

| ヘッダー | API | 自作テスト（既存を含む） |
| --- | --- | --- |
| [data-structure/BIT.hpp](../../data-structure/BIT.hpp) | `BIT(N)`; `add(pos, val)`; `sum(r)`; `sum(l, r)`; `lower_bound(val)` | [basic-api.test.cpp](data-structure/basic-api.test.cpp) |
| [data-structure/binary-trie.hpp](../../data-structure/binary-trie.hpp) | `BinaryTrie()`; `insert(val)`; `erase(val)`; `count(val)`; `min_element(), max_element()`; `get_kth_element(k)`; `all_xor(val)`; `size(), empty()`; `lower_bound(val), upper_bound(val)` | [bit-queries.test.cpp](data-structure/bit-queries.test.cpp)、[binary-trie.test.cpp](data-structure/binary-trie.test.cpp) |
| [data-structure/compact-bitvector.hpp](../../data-structure/compact-bitvector.hpp) | `CompactBitVector(), CompactBitVector(N)`; `set(i, b)`; `access(i), operator[](i)`; `build()`; `rank(i, b)`; `select(i, b)` | [bit-queries.test.cpp](data-structure/bit-queries.test.cpp)、[wavelet-api.test.cpp](data-structure/wavelet-api.test.cpp) |
| [data-structure/erasable-priority-queue.hpp](../../data-structure/erasable-priority-queue.hpp) | `ErasablePriorityQueue()`; `push(val)`; `erase(val)`; `top()`; `pop()`; `empty()` | [basic-api.test.cpp](data-structure/basic-api.test.cpp) |
| [data-structure/imos2D.hpp](../../data-structure/imos2D.hpp) | `imos2D(H, W)`; `add(li, lj, ri, rj, val)`; `build()`; `operator[](i)` | [imos2D.test.cpp](data-structure/imos2D.test.cpp) |
| [data-structure/monoid/add.hpp](../../data-structure/monoid/add.hpp) | `op(l, r)`; `e()` | [monoids.test.cpp](data-structure/monoids.test.cpp)、[initialization-and-monoids.test.cpp](data-structure/initialization-and-monoids.test.cpp) |
| [data-structure/monoid/affine.hpp](../../data-structure/monoid/affine.hpp) | `op(l, r)`; `e()` | [monoids.test.cpp](data-structure/monoids.test.cpp)、[initialization-and-monoids.test.cpp](data-structure/initialization-and-monoids.test.cpp) |
| [data-structure/monoid/and.hpp](../../data-structure/monoid/and.hpp) | `op(l, r)`; `e()` | [monoids.test.cpp](data-structure/monoids.test.cpp)、[initialization-and-monoids.test.cpp](data-structure/initialization-and-monoids.test.cpp) |
| [data-structure/monoid/gcd.hpp](../../data-structure/monoid/gcd.hpp) | `op(l, r)`; `e()` | [monoids.test.cpp](data-structure/monoids.test.cpp)、[initialization-and-monoids.test.cpp](data-structure/initialization-and-monoids.test.cpp) |
| [data-structure/monoid/kadane.hpp](../../data-structure/monoid/kadane.hpp) | `S(lmax, rmax, allmax, sum)`; `op(l, r)`; `e()` | [monoids.test.cpp](data-structure/monoids.test.cpp)、[initialization-and-monoids.test.cpp](data-structure/initialization-and-monoids.test.cpp) |
| [data-structure/monoid/lcm.hpp](../../data-structure/monoid/lcm.hpp) | `op(l, r)`; `e()` | [monoids.test.cpp](data-structure/monoids.test.cpp)、[initialization-and-monoids.test.cpp](data-structure/initialization-and-monoids.test.cpp) |
| [data-structure/monoid/max.hpp](../../data-structure/monoid/max.hpp) | `op(l, r)`; `e()` | [monoids.test.cpp](data-structure/monoids.test.cpp)、[initialization-and-monoids.test.cpp](data-structure/initialization-and-monoids.test.cpp) |
| [data-structure/monoid/max_index.hpp](../../data-structure/monoid/max_index.hpp) | `op(l, r)`; `e()` | [monoids.test.cpp](data-structure/monoids.test.cpp)、[initialization-and-monoids.test.cpp](data-structure/initialization-and-monoids.test.cpp) |
| [data-structure/monoid/min.hpp](../../data-structure/monoid/min.hpp) | `op(l, r)`; `e()` | [monoids.test.cpp](data-structure/monoids.test.cpp)、[initialization-and-monoids.test.cpp](data-structure/initialization-and-monoids.test.cpp) |
| [data-structure/monoid/min_index.hpp](../../data-structure/monoid/min_index.hpp) | `op(l, r)`; `e()` | [monoids.test.cpp](data-structure/monoids.test.cpp)、[initialization-and-monoids.test.cpp](data-structure/initialization-and-monoids.test.cpp) |
| [data-structure/monoid/or.hpp](../../data-structure/monoid/or.hpp) | `op(l, r)`; `e()` | [monoids.test.cpp](data-structure/monoids.test.cpp)、[initialization-and-monoids.test.cpp](data-structure/initialization-and-monoids.test.cpp) |
| [data-structure/monoid/rolling_hash.hpp](../../data-structure/monoid/rolling_hash.hpp) | `S(h, len)`; `op(a, b)`; `e()` | [monoids.test.cpp](data-structure/monoids.test.cpp)、[initialization-and-monoids.test.cpp](data-structure/initialization-and-monoids.test.cpp) |
| [data-structure/monoid/sum_count.hpp](../../data-structure/monoid/sum_count.hpp) | `S(sum, cnt)`; `op(l, r)`; `e()` | [monoids.test.cpp](data-structure/monoids.test.cpp)、[initialization-and-monoids.test.cpp](data-structure/initialization-and-monoids.test.cpp) |
| [data-structure/persistent/persistent-array.hpp](../../data-structure/persistent/persistent-array.hpp) | `PersistentArray()`; `PersistentArray(v)`; `PersistentArray(N, id=0)`; `get(idx), get(node, idx)`; `set(idx, value), set(node, idx, value)`; `Node(), Node(pointer), Node(reference)` | [persistent-api.test.cpp](data-structure/persistent-api.test.cpp)、[initialization-and-monoids.test.cpp](data-structure/initialization-and-monoids.test.cpp) |
| [data-structure/persistent/persistent-queue.hpp](../../data-structure/persistent/persistent-queue.hpp) | `PersistentQueue()`; `PersistentQueue(front_node, back_node)`; `push(x)`; `pop()`; `front(), back()`; `empty()`; `Node(val, idx)` | [persistent-api.test.cpp](data-structure/persistent-api.test.cpp)、[initialization-and-monoids.test.cpp](data-structure/initialization-and-monoids.test.cpp) |
| [data-structure/persistent/persistent-unionfind.hpp](../../data-structure/persistent/persistent-unionfind.hpp) | `PersistentUnionFind(N)`; `leader_and_size(u[, r])`; `leader(u[, r]), size(u[, r])`; `same(u, v[, r])`; `merge(u, v[, r])`; `get_root()` | [persistent-api.test.cpp](data-structure/persistent-api.test.cpp)、[initialization-and-monoids.test.cpp](data-structure/initialization-and-monoids.test.cpp) |
| [data-structure/range-BIT.hpp](../../data-structure/range-BIT.hpp) | `RangeBIT(N)`; `add(l, r, val)`; `add(pos, val)`; `sum(r)`; `sum(l, r)` | [range-bit.test.cpp](data-structure/range-bit.test.cpp) |
| [data-structure/segtree/dynamic-segtree.hpp](../../data-structure/segtree/dynamic-segtree.hpp) | `DynamicSegtree()`; `set(p, val)`; `get(p)`; `prod(l, r)` | [segment-tree-api.test.cpp](data-structure/segment-tree-api.test.cpp)、[segtree-boundaries.test.cpp](data-structure/segtree-boundaries.test.cpp) |
| [data-structure/segtree/lazy-segtree.hpp](../../data-structure/segtree/lazy-segtree.hpp) | `LazySegtree(), LazySegtree(n), LazySegtree(v)`; `set(pos, val)`; `get(pos)`; `prod(l, r)`; `all_prod()`; `apply(pos, f)`; `apply(l, r, f)`; `max_right(l, g)`; `min_left(r, g)` | [segment-tree-api.test.cpp](data-structure/segment-tree-api.test.cpp)、[segtree-boundaries.test.cpp](data-structure/segtree-boundaries.test.cpp) |
| [data-structure/segtree/li-chao-tree.hpp](../../data-structure/segtree/li-chao-tree.hpp) | `LiChaoTree()`; `explicit LiChaoTree(const std::vector<T>& x)`; `void add_line(T a, T b)`; `void add_segment(T a, T b, T x_l, T x_r)`; `T get_min(T x)` | [li-chao-tree.test.cpp](data-structure/li-chao-tree.test.cpp) |
| [data-structure/segtree/segtree-beats.hpp](../../data-structure/segtree/segtree-beats.hpp) | `SegtreeBeats(), SegtreeBeats(n), SegtreeBeats(v)`; `set(pos, val)`; `get(pos)`; `prod(l, r)`; `all_prod()`; `apply(pos, f)`; `apply(l, r, f)`; `max_right(l, g)`; `min_left(r, g)` | [segment-tree-api.test.cpp](data-structure/segment-tree-api.test.cpp)、[segtree-boundaries.test.cpp](data-structure/segtree-boundaries.test.cpp) |
| [data-structure/segtree/segtree.hpp](../../data-structure/segtree/segtree.hpp) | `Segtree(), Segtree(n), Segtree(v)`; `set(pos, val)`; `get(pos)`; `apply(pos, val)`; `prod(l, r)`; `all_prod()`; `max_right(l, f)`; `min_left(r, f)` | [segment-tree-api.test.cpp](data-structure/segment-tree-api.test.cpp)、[segtree-boundaries.test.cpp](data-structure/segtree-boundaries.test.cpp) |
| [data-structure/slope-trick.hpp](../../data-structure/slope-trick.hpp) | `SlopeTrick()`; `get_min()`; `get_min_lr()`; `add_const(a)`; `add_right(a)`; `add_left(a)`; `add_abs(a)`; `clear_right()`; `clear_left()`; `shift(a, b)`; `shift(a)`; `size()`; `swap(rhs)`; `merge(rhs)`; `eval(x)` | [slope-trick.test.cpp](data-structure/slope-trick.test.cpp) |
| [data-structure/sum2D.hpp](../../data-structure/sum2D.hpp) | `sum2D(H, W)`; `add(row, column, val)`; `build()`; `get_sum(row_l, row_r, column_l, column_r)` | [basic-api.test.cpp](data-structure/basic-api.test.cpp) |
| [data-structure/unionfind.hpp](../../data-structure/unionfind.hpp) | `UnionFind(N)`; `leader(u)`; `same(u, v)`; `merge(u, v)`; `size(u)`; `groups()`; `groups_with_map()` | [basic-api.test.cpp](data-structure/basic-api.test.cpp) |
| [data-structure/utils/sum_count_manager.hpp](../../data-structure/utils/sum_count_manager.hpp) | `SumCountManager(xs)`; `add(val)`; `get(val)` | [basic-api.test.cpp](data-structure/basic-api.test.cpp) |
| [data-structure/wavelet-matrix.hpp](../../data-structure/wavelet-matrix.hpp) | `WaveletMatrix(vector<int> v)`; `access(pos), operator[](pos)`; `rank(i, x)`; `select(i, x)`; `quantile(l, r, i)`; `rangefreq(l, r, xr)`; `rangefreq(l, r, xl, xr)`; `prev_value(l, r, xr)`; `next_value(l, r, xl)` | [bit-queries.test.cpp](data-structure/bit-queries.test.cpp)、[wavelet-api.test.cpp](data-structure/wavelet-api.test.cpp) |
| [geometry/base.hpp](../../geometry/base.hpp) | `equal(a,b)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/ccw.hpp](../../geometry/ccw.hpp) | `ccw(a,b,c)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/circle.hpp](../../geometry/circle.hpp) | `Circle()`; `Circle(p,r)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/convex-cut.hpp](../../geometry/convex-cut.hpp) | `ConvexCut(p,l)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/convex-hull.hpp](../../geometry/convex-hull.hpp) | `ConvexHull(p)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/cross-point.hpp](../../geometry/cross-point.hpp) | `crossPoint(Line s,Line t)`; `crossPoint(Segment s,Segment t)`; `crossPoint(Circle c1,Circle c2)`; `crossPoint(Circle c,Line l)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/cross.hpp](../../geometry/cross.hpp) | `cross(a,b)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/degree-to-radian.hpp](../../geometry/degree-to-radian.hpp) | `degreeToRadian(degree)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/distance-between-line-and-point.hpp](../../geometry/distance-between-line-and-point.hpp) | `distanceBetweenLineAndPoint(l,p)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/distance-between-segment-and-point.hpp](../../geometry/distance-between-segment-and-point.hpp) | `distanceBetweenSegmentAndPoint(l,p)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/distance-between-segments.hpp](../../geometry/distance-between-segments.hpp) | `distanceBetweenSegments(s,t)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/dot.hpp](../../geometry/dot.hpp) | `dot(a,b)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/geometry.hpp](../../geometry/geometry.hpp) | `geometry.hpp の include` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/is-contained.hpp](../../geometry/is-contained.hpp) | `isContained(g,p)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/is-convex.hpp](../../geometry/is-convex.hpp) | `isConvex(p)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/is-in-circle.hpp](../../geometry/is-in-circle.hpp) | `isInCircle(c,p)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/is-intersect.hpp](../../geometry/is-intersect.hpp) | `isIntersect(s,t,bound)`; `isIntersect(c1,c2)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/is-orthogonal.hpp](../../geometry/is-orthogonal.hpp) | `isOrthogonal(a,b)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/is-parallel.hpp](../../geometry/is-parallel.hpp) | `isParallel(a,b)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/is-point-on-line.hpp](../../geometry/is-point-on-line.hpp) | `isPointOnLine(a,b,c)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/is-point-on-segment.hpp](../../geometry/is-point-on-segment.hpp) | `isPointOnSegment(a,b,c)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/line.hpp](../../geometry/line.hpp) | `Line()`; `Line(a,b)`; `Line(A,B,C)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/normal-vector.hpp](../../geometry/normal-vector.hpp) | `normalVector(a)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/polygon-area.hpp](../../geometry/polygon-area.hpp) | `PolygonArea(p)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/projection.hpp](../../geometry/projection.hpp) | `projection(Line l,p)`; `projection(Segment l,p)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/radian-to-degree.hpp](../../geometry/radian-to-degree.hpp) | `radianToDegree(radian)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/reflection.hpp](../../geometry/reflection.hpp) | `reflection(l,p)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/rotate.hpp](../../geometry/rotate.hpp) | `rotate(p,theta)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/segment.hpp](../../geometry/segment.hpp) | `Segment(), Segment(a,b)`; `get_dist()` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/tangent-to-circle.hpp](../../geometry/tangent-to-circle.hpp) | `tangentToCircle(p,c)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/tangent.hpp](../../geometry/tangent.hpp) | `tangent(a,b)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [geometry/unit-vector.hpp](../../geometry/unit-vector.hpp) | `unitVector(a)` | [geometry.test.cpp](geometry/geometry.test.cpp)、[geometry-api.test.cpp](geometry/geometry-api.test.cpp) |
| [graph/graph_template.hpp](../../graph/graph_template.hpp) | `Graph(N)`; `Edge(from, to, cost=1, id=-1)`; `Edge::operator int()`; `add_directed_edge(from, to, cost=1)`; `add_undirected_edge(from, to, cost=1)`; `size()`; `operator[](i)` | [graph-scc-two-sat.test.cpp](graph/graph-scc-two-sat.test.cpp) |
| [graph/namori.hpp](../../graph/namori.hpp) | `Namori(N)`; `add_undirected_edge(u, v, cost=1)`; `size()`; `build()`; `operator[](v)` | [tree-api.test.cpp](graph/tree-api.test.cpp) |
| [graph/range-edge-graph.hpp](../../graph/range-edge-graph.hpp) | `RangeEdgeGraph(int n, int m)`; `void add_edge(int from_l, int from_r, int to_l, int to_r, Cost cost)`; `operator Graph<Cost>() const` | [range-edge-graph.test.cpp](graph/range-edge-graph.test.cpp) |
| [graph/scc.hpp](../../graph/scc.hpp) | `SCC(N)`; `SCC(g)`; `add_directed_edge(from, to)`; `build()`; `operator[](v)`; `size()`; `get_contracted_graph()` | [graph-scc-two-sat.test.cpp](graph/graph-scc-two-sat.test.cpp) |
| [graph/shortest-path/bfs.hpp](../../graph/shortest-path/bfs.hpp) | `bfs(G, start, iv=0, inf=numeric_limits<Cost>::max())` | [bfs-topological-sort.test.cpp](graph/bfs-topological-sort.test.cpp) |
| [graph/shortest-path/dijkstra.hpp](../../graph/shortest-path/dijkstra.hpp) | `dijkstra(G, start, iv=0, inf=numeric_limits<Cost>::max())` | [graph-scc-two-sat.test.cpp](graph/graph-scc-two-sat.test.cpp) |
| [graph/topological-sort.hpp](../../graph/topological-sort.hpp) | `topological_sort(G)` | [bfs-topological-sort.test.cpp](graph/bfs-topological-sort.test.cpp) |
| [graph/tree/centroid-decomposition.hpp](../../graph/tree/centroid-decomposition.hpp) | `CentroidDecomposition(g)`; `get_subtree_size(u, p)`; `decomp(u, p)` | [tree-api.test.cpp](graph/tree-api.test.cpp) |
| [graph/tree/diameter.hpp](../../graph/tree/diameter.hpp) | `get_diameter(G)` | [tree-api.test.cpp](graph/tree-api.test.cpp) |
| [graph/tree/hld.hpp](../../graph/tree/hld.hpp) | `HeavyLightDecomposition(N)`; `HeavyLightDecomposition(G)`; `add_edge(u, v, cost=1)`; `build(root=0)`; `operator[](u)`; `lca(u, v)`; `dist(u, v)`; `la(u, k)`; `path_query(u, v, f, edge=false)`; `path_query(u, v, f, f_rev, edge=false)`; `subtree_query(u, f)` | [tree-api.test.cpp](graph/tree-api.test.cpp) |
| [graph/tree/lca.hpp](../../graph/tree/lca.hpp) | `LCA()`; `LCA(const Graph<Cost>& G, int root=0)`; `int get_lca(int u, int v)`; `int get_dist(int u, int v)` | [tree-api.test.cpp](graph/tree-api.test.cpp) |
| [graph/tree/tree-hash.hpp](../../graph/tree/tree-hash.hpp) | `TreeHash(N)`; `TreeHash(G)`; `add_edge(u, v, cost=1)`; `get_hash()` | [tree-api.test.cpp](graph/tree-api.test.cpp) |
| [math/F2.hpp](../../math/F2.hpp) | `BitMatrix(), BitMatrix(H,W)`; `operator[](i)`; `row_reduction(b)`; `row_reduction()`; `linear_equation_F2(A,b)` | [f2.test.cpp](math/f2.test.cpp) |
| [math/barrett-reduction.hpp](../../math/barrett-reduction.hpp) | `BarrettReduction(m=1)`; `mul(a, b)`; `rem(a)`; `quo(a)`; `quorem(a)` | [barrett-reduction.test.cpp](math/barrett-reduction.test.cpp) |
| [math/binom.hpp](../../math/binom.hpp) | `Binomial(MAX=1)`; `extend()`; `fac(n), fac_inv(n)`; `inv(n)`; `binom(n, k)`; `perm(n, k)`; `hom(n, k)`; `binom_naive(n, k)` | [matrix-binom.test.cpp](math/matrix-binom.test.cpp) |
| [math/convolution/fft.hpp](../../math/convolution/fft.hpp) | `Complex<D>(), Complex<D>(x,y)`; `Complex の単項 -, +, -, *, / と複合代入`; `omega<D>(k,n)`; `revbit(mask,bitlen)`; `fft(a,bitlen)`; `ifft(a,bitlen)`; `convolution(a,b)` | [transforms-api.test.cpp](math/transforms-api.test.cpp)、[convolution-regressions.test.cpp](math/convolution-regressions.test.cpp) |
| [math/convolution/ntt.hpp](../../math/convolution/ntt.hpp) | `exp_limit(int mod)`; `ntt_info<mint>()`; `revbit(uint64_t mask)`; `revbit(uint64_t mask, int bitlen)`; `ntt(std::vector<mint>& a)`; `intt(std::vector<mint>& a)`; `convolution(std::vector<mint> a, std::vector<mint> b)` | [transforms-api.test.cpp](math/transforms-api.test.cpp)、[convolution-regressions.test.cpp](math/convolution-regressions.test.cpp) |
| [math/divisor.hpp](../../math/divisor.hpp) | `divisor(n)` | [number-theory.test.cpp](math/number-theory.test.cpp)、[arithmetic-regressions.test.cpp](math/arithmetic-regressions.test.cpp) |
| [math/eratosthenes.hpp](../../math/eratosthenes.hpp) | `Eratosthenes(N)`; `operator[](k)` | [number-theory.test.cpp](math/number-theory.test.cpp)、[arithmetic-regressions.test.cpp](math/arithmetic-regressions.test.cpp) |
| [math/is-prime.hpp](../../math/is-prime.hpp) | `is_prime(int n)`; `is_prime(long long n)` | [number-theory.test.cpp](math/number-theory.test.cpp)、[arithmetic-regressions.test.cpp](math/arithmetic-regressions.test.cpp) |
| [math/linear-sieve.hpp](../../math/linear-sieve.hpp) | `LinearSieve(N)`; `operator[](k)`; `factor(num)` | [number-theory.test.cpp](math/number-theory.test.cpp)、[arithmetic-regressions.test.cpp](math/arithmetic-regressions.test.cpp) |
| [math/matrix.hpp](../../math/matrix.hpp) | `Matrix(n), Matrix(n,m)`; `height(), width()`; `operator[](i)`; `I(n)`; `operator+=, -=, +, -`; `operator*=, *`; `pow(k)` | [matrix-binom.test.cpp](math/matrix-binom.test.cpp) |
| [math/pow_mod.hpp](../../math/pow_mod.hpp) | `pow_mod(x, k, m)` | [number-theory.test.cpp](math/number-theory.test.cpp)、[arithmetic-regressions.test.cpp](math/arithmetic-regressions.test.cpp) |
| [math/prime-factor.hpp](../../math/prime-factor.hpp) | `prime_factor(n)` | [number-theory.test.cpp](math/number-theory.test.cpp)、[arithmetic-regressions.test.cpp](math/arithmetic-regressions.test.cpp) |
| [math/primitive-root.hpp](../../math/primitive-root.hpp) | `primitive_root(p)` | [number-theory.test.cpp](math/number-theory.test.cpp)、[arithmetic-regressions.test.cpp](math/arithmetic-regressions.test.cpp) |
| [math/segment-factorize.hpp](../../math/segment-factorize.hpp) | `SegmentFactorize(L, R)`; `factor(n)` | [number-theory.test.cpp](math/number-theory.test.cpp)、[arithmetic-regressions.test.cpp](math/arithmetic-regressions.test.cpp) |
| [math/segment-sieve.hpp](../../math/segment-sieve.hpp) | `SegmentSieve(long long L, long long R)`; `bool operator[](long long k) const` | [number-theory.test.cpp](math/number-theory.test.cpp)、[arithmetic-regressions.test.cpp](math/arithmetic-regressions.test.cpp) |
| [math/two_sat.hpp](../../math/two_sat.hpp) | `TwoSat(), TwoSat(N)`; `add_clause(i, fi, j, fj)`; `satisfiable()`; `get_answer()` | [graph-scc-two-sat.test.cpp](graph/graph-scc-two-sat.test.cpp) |
| [misc/compress.hpp](../../misc/compress.hpp) | `Compress(), Compress(v)`; `push_back(val)`; `build()`; `get(val)`; `operator[](i)`; `size()` | [utilities.test.cpp](misc/utilities.test.cpp) |
| [misc/floor-ceil-div.hpp](../../misc/floor-ceil-div.hpp) | `floor_div(a,b)`; `ceil_div(a,b)` | [utilities.test.cpp](misc/utilities.test.cpp) |
| [misc/fraction.hpp](../../misc/fraction.hpp) | `Fraction(), Fraction(a), Fraction(a,b)`; `normalize()`; `operator+, -, *, / と複合代入`; `単項 operator-`; `operator==, !=, <, <=, >, >=`; `gcd(a,b)` | [fraction-api.test.cpp](misc/fraction-api.test.cpp)、[fraction.test.cpp](misc/fraction.test.cpp)、[mo-and-fraction.test.cpp](misc/mo-and-fraction.test.cpp) |
| [misc/inversion-number.hpp](../../misc/inversion-number.hpp) | `inversion_number<T>(v)` | [utilities.test.cpp](misc/utilities.test.cpp) |
| [misc/mo.hpp](../../misc/mo.hpp) | `Mo(n)`; `insert(l,r)`; `set_bucketsize(bs)`; `build()`; `process(add_left,add_right,del_left,del_right)` | [utilities.test.cpp](misc/utilities.test.cpp) |
| [misc/rle.hpp](../../misc/rle.hpp) | `runlength_encoding(vector<T>)`; `runlength_encoding(string)` | [utilities.test.cpp](misc/utilities.test.cpp) |
| [misc/subset-iterator.hpp](../../misc/subset-iterator.hpp) | `Subset(S)`; `Subset_k(S,t)`; `SetBit(S)`; `begin(), end()`; `各 Iter の構築、operator*, operator++, operator!=` | [subset-iterator.test.cpp](misc/subset-iterator.test.cpp) |
| [misc/timer.hpp](../../misc/timer.hpp) | `Timer()`; `reset()`; `elapsed(), operator()()` | [utilities.test.cpp](misc/utilities.test.cpp) |
| [modint/dynamic-modint.hpp](../../modint/dynamic-modint.hpp) | `コンストラクタ(), コンストラクタ(long long y)`; `val(), get_mod()`; `operator+, -, *, +=, -=, *=`; `単項 operator-`; `operator/, /=, inv()`; `pow(n)`; `operator==, !=`; `operator<<, >>`; `set_mod(m)` | [dynamic-modint.test.cpp](modint/dynamic-modint.test.cpp) |
| [modint/modint.hpp](../../modint/modint.hpp) | `コンストラクタ(), コンストラクタ(long long y)`; `val(), get_mod()`; `operator+, -, *, +=, -=, *=`; `単項 operator-`; `operator/, /=, inv()`; `pow(n)`; `operator==, !=`; `operator<<, >>` | [dynamic-modint.test.cpp](modint/dynamic-modint.test.cpp) |
| [modint/modint_2_61.hpp](../../modint/modint_2_61.hpp) | `コンストラクタ(), コンストラクタ(long long y)`; `val(), get_mod()`; `operator+, -, *, +=, -=, *=`; `単項 operator-`; `operator/, /=, inv()`; `pow(n)`; `operator==, !=`; `operator<<, >>` | [dynamic-modint.test.cpp](modint/dynamic-modint.test.cpp) |
| [random/rng.hpp](../../random/rng.hpp) | `RNG32(), RNG64(), RNG_0_1()`; `RNG32::randint(l,r), RNG64::randint(l,r)`; `RNG32::randint(r), RNG64::randint(r)`; `RNG_0_1::rand(), operator()()` | [utilities.test.cpp](misc/utilities.test.cpp) |
| [string/rolling-hash.hpp](../../string/rolling-hash.hpp) | `RollingHash(s,base), RollingHash(vector<int>,base)`; `gen_base()`; `get(l,r)`; `connect(h1,h2,h2len)`; `get_lcp(b,l1,r1,l2,r2)` | [string-api.test.cpp](string/string-api.test.cpp)、[empty-inputs.test.cpp](string/empty-inputs.test.cpp) |
| [string/z-algo.hpp](../../string/z-algo.hpp) | `z_algo(s)` | [string-api.test.cpp](string/string-api.test.cpp)、[empty-inputs.test.cpp](string/empty-inputs.test.cpp) |
