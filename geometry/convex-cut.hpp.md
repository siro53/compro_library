---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geometry/base.hpp
    title: "\u5E7E\u4F55\u306E\u57FA\u672C\u578B"
  - icon: ':x:'
    path: geometry/ccw.hpp
    title: "3 \u70B9\u306E\u4F4D\u7F6E\u95A2\u4FC2"
  - icon: ':x:'
    path: geometry/circle.hpp
    title: "\u5186"
  - icon: ':x:'
    path: geometry/cross-point.hpp
    title: "\u4EA4\u70B9"
  - icon: ':x:'
    path: geometry/cross.hpp
    title: "\u5916\u7A4D"
  - icon: ':x:'
    path: geometry/distance-between-line-and-point.hpp
    title: "\u76F4\u7DDA\u3068\u70B9\u306E\u8DDD\u96E2"
  - icon: ':x:'
    path: geometry/dot.hpp
    title: "\u5185\u7A4D"
  - icon: ':x:'
    path: geometry/is-intersect.hpp
    title: "\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':x:'
    path: geometry/line.hpp
    title: "\u76F4\u7DDA"
  - icon: ':x:'
    path: geometry/projection.hpp
    title: "\u5C04\u5F71"
  - icon: ':x:'
    path: geometry/segment.hpp
    title: "\u7DDA\u5206"
  - icon: ':x:'
    path: geometry/unit-vector.hpp
    title: "\u5358\u4F4D\u30D9\u30AF\u30C8\u30EB"
  _extendedRequiredBy:
  - icon: ':x:'
    path: geometry/geometry.hpp
    title: "\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA\uFF08\u307E\u3068\u3081\u3066\
      \ include\uFF09"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/geometry/geometry-api.test.cpp
    title: test/mytest/geometry/geometry-api.test.cpp
  - icon: ':x:'
    path: test/mytest/geometry/geometry.test.cpp
    title: test/mytest/geometry/geometry.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/convex-cut.hpp\"\n\n#include <vector>\n\n#line\
    \ 2 \"geometry/ccw.hpp\"\n\n#line 2 \"geometry/cross.hpp\"\n\n#line 2 \"geometry/base.hpp\"\
    \n\n#include <cmath>\n#include <complex>\n\nnamespace geometry {\n    // Point\
    \ : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\
    \u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092\
    y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point\
    \ = std::complex<D>;\n    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\
    \n    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS;\
    \ }\n} // namespace geometry\n#line 4 \"geometry/cross.hpp\"\n\nnamespace geometry\
    \ {\n    // \u5916\u7A4D(cross product) : a\xD7b = |a||b|sin\u0398\n    inline\
    \ D cross(const Point &a, const Point &b) {\n        return (a.real() * b.imag()\
    \ - a.imag() * b.real());\n    }\n} // namespace geometry\n#line 2 \"geometry/dot.hpp\"\
    \n\n#line 4 \"geometry/dot.hpp\"\n\nnamespace geometry {\n    // \u5185\u7A4D\
    (dot product) : a\u30FBb = |a||b|cos\u0398\n    inline D dot(const Point &a, const\
    \ Point &b) {\n        return (a.real() * b.real() + a.imag() * b.imag());\n \
    \   }\n} // namespace geometry\n#line 5 \"geometry/ccw.hpp\"\n\nnamespace geometry\
    \ {\n    // \u70B9\u306E\u56DE\u8EE2\u65B9\u5411\n    // \u70B9a, b, c\u306E\u4F4D\
    \u7F6E\u95A2\u4FC2\u306B\u3064\u3044\u3066(a\u304C\u57FA\u6E96\u70B9)\n    inline\
    \ int ccw(const Point &a, Point b, Point c) {\n        b -= a, c -= a;\n     \
    \   // \u70B9a, b, c \u304C\n        // \u53CD\u6642\u8A08\u56DE\u308A\u306E\u6642\
    \u3001\n        if(cross(b, c) > EPS) return 1;\n        // \u6642\u8A08\u56DE\
    \u308A\u306E\u6642\u3001\n        if(cross(b, c) < -EPS) return -1;\n        //\
    \ c, a, b\u304C\u3053\u306E\u9806\u756A\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\
    \u3042\u308B\u6642\u3001\n        if(dot(b, c) < 0) return 2;\n        // a, b,\
    \ c\u304C\u3053\u306E\u9806\u756A\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\
    \u308B\u5834\u5408\u3001\n        if(std::norm(b) < std::norm(c)) return -2;\n\
    \        // c\u304C\u7DDA\u5206ab\u4E0A\u306B\u3042\u308B\u5834\u5408\u3001\n\
    \        return 0;\n    }\n} // namespace geometry\n#line 2 \"geometry/cross-point.hpp\"\
    \n\n#line 5 \"geometry/cross-point.hpp\"\n\n#line 2 \"geometry/circle.hpp\"\n\n\
    #line 4 \"geometry/circle.hpp\"\n\nnamespace geometry {\n    // Circle : \u5186\
    \u3092\u8868\u3059\u69CB\u9020\u4F53\n    // p\u304C\u4E2D\u5FC3\u306E\u4F4D\u7F6E\
    \u30D9\u30AF\u30C8\u30EB\u3001r\u306F\u534A\u5F84\n    struct Circle {\n     \
    \   Point p;\n        D r;\n\n        Circle() = default;\n\n        Circle(Point\
    \ p, D r) : p(p), r(r) {}\n    };\n} // namespace geometry\n#line 2 \"geometry/distance-between-line-and-point.hpp\"\
    \n\n#line 2 \"geometry/line.hpp\"\n\n#line 4 \"geometry/line.hpp\"\n\nnamespace\
    \ geometry {\n    // Line : \u76F4\u7DDA\u3092\u8868\u3059\u69CB\u9020\u4F53\n\
    \    // b - a \u3067\u76F4\u7DDA\u30FB\u7DDA\u5206\u3092\u8868\u305B\u308B\n \
    \   struct Line {\n        Point a, b;\n        Line() = default;\n        Line(Point\
    \ a, Point b) : a(a), b(b) {}\n        // Ax+By=C\n        Line(D A, D B, D C)\
    \ {\n            if(equal(A, 0)) {\n                a = Point(0, C / B), b = Point(1,\
    \ C / B);\n            } else if(equal(B, 0)) {\n                a = Point(C /\
    \ A, 0), b = Point(C / A, 1);\n            } else if(equal(C, 0)) {\n        \
    \        a = Point(0, C / B), b = Point(1, (C - A) / B);\n            } else {\n\
    \                a = Point(0, C / B), b = Point(C / A, 0);\n            }\n  \
    \      }\n    };\n} // namespace geometry\n#line 5 \"geometry/distance-between-line-and-point.hpp\"\
    \n\nnamespace geometry {\n    // \u76F4\u7DDAl\u3068\u70B9p\u306E\u8DDD\u96E2\u3092\
    \u6C42\u3081\u308B\n    inline D distanceBetweenLineAndPoint(const Line &l, const\
    \ Point &p) {\n        return std::abs(cross(l.b - l.a, p - l.a)) / std::abs(l.b\
    \ - l.a);\n    }\n} // namespace geometry\n#line 2 \"geometry/is-intersect.hpp\"\
    \n\n#line 2 \"geometry/segment.hpp\"\n\n#line 4 \"geometry/segment.hpp\"\n\nnamespace\
    \ geometry {\n    // Segment : \u7DDA\u5206\u3092\u8868\u3059\u69CB\u9020\u4F53\
    \n    // Line\u3068\u540C\u3058\n    struct Segment : Line {\n        Segment()\
    \ = default;\n\n        Segment(Point a, Point b) : Line(a, b) {}\n        D get_dist()\
    \ { return std::abs(a - b); }\n    };\n} // namespace geometry\n#line 6 \"geometry/is-intersect.hpp\"\
    \n\nnamespace geometry {\n    // \u7DDA\u5206s\u3068\u7DDA\u5206t\u304C\u4EA4\u5DEE\
    \u3057\u3066\u3044\u308B\u304B\u3069\u3046\u304B\n    // bound:\u7DDA\u5206\u306E\
    \u7AEF\u70B9\u3092\u542B\u3080\u304B\n    inline bool isIntersect(const Segment\
    \ &s, const Segment &t, bool bound) {\n        return ccw(s.a, s.b, t.a) * ccw(s.a,\
    \ s.b, t.b) < bound &&\n               ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b)\
    \ < bound;\n    }\n\n    // 2\u3064\u306E\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A\n\
    \    // \u8FD4\u308A\u5024\u306F\u5171\u901A\u63A5\u7DDA\u306E\u6570\n    inline\
    \ int isIntersect(const Circle &c1, const Circle &c2) {\n        D d = std::abs(c1.p\
    \ - c2.p);\n        // 2\u3064\u306E\u5186\u304C\u96E2\u308C\u3066\u3044\u308B\
    \u5834\u5408\n        if(d > c1.r + c2.r + EPS) return 4;\n        // \u5916\u63A5\
    \u3057\u3066\u3044\u308B\u5834\u5408\n        if(equal(d, c1.r + c2.r)) return\
    \ 3;\n        // \u5185\u63A5\u3057\u3066\u3044\u308B\u5834\u5408\n        if(equal(d,\
    \ std::abs(c1.r - c2.r))) return 1;\n        // \u5185\u5305\u3057\u3066\u3044\
    \u308B\u5834\u5408\n        if(d < std::abs(c1.r - c2.r) - EPS) return 0;\n  \
    \      return 2;\n    }\n} // namespace geometry\n#line 2 \"geometry/projection.hpp\"\
    \n\n#line 6 \"geometry/projection.hpp\"\n\nnamespace geometry {\n    // \u5C04\
    \u5F71(projection)\n    // \u76F4\u7DDA(\u7DDA\u5206)l\u306B\u70B9p\u304B\u3089\
    \u5F15\u3044\u305F\u5782\u7DDA\u306E\u8DB3\u3092\u6C42\u3081\u308B\n    inline\
    \ Point projection(const Line &l, const Point &p) {\n        D t = dot(p - l.a,\
    \ l.a - l.b) / std::norm(l.a - l.b);\n        return l.a + (l.a - l.b) * t;\n\
    \    }\n\n    inline Point projection(const Segment &l, const Point &p) {\n  \
    \      D t = dot(p - l.a, l.a - l.b) / std::norm(l.a - l.b);\n        return l.a\
    \ + (l.a - l.b) * t;\n    }\n} // namespace geometry\n#line 2 \"geometry/unit-vector.hpp\"\
    \n\n#line 4 \"geometry/unit-vector.hpp\"\n\nnamespace geometry {\n    // \u5358\
    \u4F4D\u30D9\u30AF\u30C8\u30EB(unit vector)\u3092\u6C42\u3081\u308B\n    inline\
    \ Point unitVector(const Point &a) { return a / std::abs(a); }\n} // namespace\
    \ geometry\n#line 12 \"geometry/cross-point.hpp\"\n\nnamespace geometry {\n  \
    \  // \u76F4\u7DDAs, t\u306E\u4EA4\u70B9\u306E\u8A08\u7B97\n    inline Point crossPoint(const\
    \ Line &s, const Line &t) {\n        D d1 = cross(s.b - s.a, t.b - t.a);\n   \
    \     D d2 = cross(s.b - s.a, s.b - t.a);\n        if(equal(std::abs(d1), 0) &&\
    \ equal(std::abs(d2), 0)) return t.a;\n        return t.a + (t.b - t.a) * (d2\
    \ / d1);\n    }\n\n    // \u7DDA\u5206s, t\u306E\u4EA4\u70B9\u306E\u8A08\u7B97\
    \n    inline Point crossPoint(const Segment &s, const Segment &t) {\n        return\
    \ crossPoint(Line(s), Line(t));\n    }\n\n    // 2\u3064\u306E\u5186\u306E\u4EA4\
    \u70B9\n    inline std::vector<Point> crossPoint(const Circle &c1, const Circle\
    \ &c2) {\n        std::vector<Point> res;\n        int mode = isIntersect(c1,\
    \ c2);\n        // 2\u3064\u306E\u4E2D\u5FC3\u306E\u8DDD\u96E2\n        D d =\
    \ std::abs(c1.p - c2.p);\n        // 2\u5186\u304C\u96E2\u308C\u3066\u3044\u308B\
    \u5834\u5408\n        if(mode == 4) return res;\n        // 1\u3064\u306E\u5186\
    \u304C\u3082\u30461\u3064\u306E\u5186\u306B\u5185\u5305\u3055\u308C\u3066\u3044\
    \u308B\u5834\u5408\n        if(mode == 0) return res;\n        // 2\u5186\u304C\
    \u5916\u63A5\u3059\u308B\u5834\u5408\n        if(mode == 3) {\n            D t\
    \ = c1.r / (c1.r + c2.r);\n            res.emplace_back(c1.p + (c2.p - c1.p) *\
    \ t);\n            return res;\n        }\n        // \u5185\u63A5\u3057\u3066\
    \u3044\u308B\u5834\u5408\n        if(mode == 1) {\n            if(c2.r < c1.r\
    \ - EPS) {\n                res.emplace_back(c1.p + (c2.p - c1.p) * (c1.r / d));\n\
    \            } else {\n                res.emplace_back(c2.p + (c1.p - c2.p) *\
    \ (c2.r / d));\n            }\n            return res;\n        }\n        //\
    \ 2\u5186\u304C\u91CD\u306A\u308B\u5834\u5408\n        D rc1 = (c1.r * c1.r +\
    \ d * d - c2.r * c2.r) / (2 * d);\n        D rs1 = std::sqrt(c1.r * c1.r - rc1\
    \ * rc1);\n        if(c1.r - std::abs(rc1) < EPS) rs1 = 0;\n        Point e12\
    \ = (c2.p - c1.p) / std::abs(c2.p - c1.p);\n        res.emplace_back(c1.p + rc1\
    \ * e12 + rs1 * e12 * Point(0, 1));\n        res.emplace_back(c1.p + rc1 * e12\
    \ + rs1 * e12 * Point(0, -1));\n        return res;\n    }\n\n    // \u5186c\u3068\
    \u76F4\u7DDAl\u306E\u4EA4\u70B9\n    inline std::vector<Point> crossPoint(const\
    \ Circle &c, const Line &l) {\n        std::vector<Point> res;\n        D d =\
    \ distanceBetweenLineAndPoint(l, c.p);\n        // \u4EA4\u70B9\u3092\u6301\u305F\
    \u306A\u3044\n        if(d > c.r + EPS) return res;\n        // \u63A5\u3059\u308B\
    \n        Point h = projection(l, c.p);\n        if(equal(d, c.r)) {\n       \
    \     res.emplace_back(h);\n            return res;\n        }\n        Point\
    \ e = unitVector(l.b - l.a);\n        D ph = std::sqrt(c.r * c.r - d * d);\n \
    \       res.emplace_back(h - e * ph);\n        res.emplace_back(h + e * ph);\n\
    \        return res;\n    }\n} // namespace geometry\n#line 7 \"geometry/convex-cut.hpp\"\
    \n\nnamespace geometry {\n    // \u51F8\u591A\u89D2\u5F62p\u3092\u76F4\u7DDAl\u3067\
    \u5207\u65AD\u3057\u3001\u305D\u306E\u5DE6\u5074\u3092\u8FD4\u3059\n    inline\
    \ std::vector<Point> ConvexCut(std::vector<Point> p, Line l) {\n        std::vector<Point>\
    \ ret;\n        int sz = (int)p.size();\n        for(int i = 0; i < sz; i++) {\n\
    \            Point now = p[i];\n            Point nxt = p[i == sz - 1 ? 0 : i\
    \ + 1];\n            if(ccw(l.a, l.b, now) != -1) ret.emplace_back(now);\n   \
    \         if(ccw(l.a, l.b, now) * ccw(l.a, l.b, nxt) == -1) {\n              \
    \  ret.emplace_back(crossPoint(Line(now, nxt), l));\n            }\n        }\n\
    \        return ret;\n    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include <vector>\n\n#include \"ccw.hpp\"\n#include \"cross-point.hpp\"\
    \n\nnamespace geometry {\n    // \u51F8\u591A\u89D2\u5F62p\u3092\u76F4\u7DDAl\u3067\
    \u5207\u65AD\u3057\u3001\u305D\u306E\u5DE6\u5074\u3092\u8FD4\u3059\n    inline\
    \ std::vector<Point> ConvexCut(std::vector<Point> p, Line l) {\n        std::vector<Point>\
    \ ret;\n        int sz = (int)p.size();\n        for(int i = 0; i < sz; i++) {\n\
    \            Point now = p[i];\n            Point nxt = p[i == sz - 1 ? 0 : i\
    \ + 1];\n            if(ccw(l.a, l.b, now) != -1) ret.emplace_back(now);\n   \
    \         if(ccw(l.a, l.b, now) * ccw(l.a, l.b, nxt) == -1) {\n              \
    \  ret.emplace_back(crossPoint(Line(now, nxt), l));\n            }\n        }\n\
    \        return ret;\n    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/ccw.hpp
  - geometry/cross.hpp
  - geometry/base.hpp
  - geometry/dot.hpp
  - geometry/cross-point.hpp
  - geometry/circle.hpp
  - geometry/distance-between-line-and-point.hpp
  - geometry/line.hpp
  - geometry/is-intersect.hpp
  - geometry/segment.hpp
  - geometry/projection.hpp
  - geometry/unit-vector.hpp
  isVerificationFile: false
  path: geometry/convex-cut.hpp
  requiredBy:
  - geometry/geometry.hpp
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
  - test/mytest/geometry/geometry-api.test.cpp
documentation_of: geometry/convex-cut.hpp
layout: document
title: "\u51F8\u591A\u89D2\u5F62\u306E\u5207\u65AD"
---

## このライブラリでできること

`ConvexCut(p,l)` は、凸多角形を有向直線で切り、直線の左側に残る部分を返します。直線を $a\to b$ とすると、数学的には半平面 $\{x\mid(b-a)\times(x-a)\ge0\}$ との共通部分です。

各辺を一度調べ、内側の頂点と境界を横切る交点を順に残すため、頂点数 $N$ に対して $O(N)$ 時間です。

## 使い方

例では正方形を下から上へ向く直線 $x=1$ で切っています。その左側は $x\le1$ なので、正方形の左半分が残ります。同じ直線でも2点の順序を逆にすると、残る側も逆になります。

```cpp
#include "template/template.cpp"
#include "geometry/convex-cut.hpp"

int main() {
    using namespace geometry;
    vector<Point> p{ {0, 0}, {2, 0}, {2, 2}, {0, 2}};
    auto cut = ConvexCut(p, Line(Point(1, -1), Point(1, 3)));
    assert(cut.size() == 4);
}
```

## API・計算量

入力のコピーと返り値を合わせて $O(N)$ の空間を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `ConvexCut(p,l)` | 左側（境界込み）の頂点列。全て外なら空。 | O(N) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

反時計回りの凸多角形と、異なる2点で表した直線を渡してください。全体が捨てる側にあれば空の配列になります。

交点を追加するのは、辺の両端が切断直線の左右に分かれる場合だけです。境界上の頂点はそのまま残し、共線な辺に不要な交点を追加しません。EPS による向きの判定のため、ほぼ共線な配置では誤差の影響を受けます。
