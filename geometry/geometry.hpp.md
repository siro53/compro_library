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
  bundledCode: "#line 1 \"geometry/geometry.hpp\"\nnamespace geometry {\n    // Point\
    \ : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\
    \u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092\
    y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = double;\n    using Point\
    \ = complex<D>;\n    const D EPS = 1e-7;\n    const D PI = acosl(-1);\n\n    inline\
    \ bool equal(const D &a, const D &b) { return fabs(a - b) < EPS; }\n\n    // \u5358\
    \u4F4D\u30D9\u30AF\u30C8\u30EB(unit vector)\u3092\u6C42\u3081\u308B\n    Point\
    \ unitVector(const Point &a) { return a / abs(a); }\n\n    // \u6CD5\u7DDA\u30D9\
    \u30AF\u30C8\u30EB(normal vector)\u3092\u6C42\u3081\u308B\n    // 90\u5EA6\u56DE\
    \u8EE2\u3057\u305F\u5358\u4F4D\u30D9\u30AF\u30C8\u30EB\u3092\u304B\u3051\u308B\
    \n    // -90\u5EA6\u304C\u3088\u3051\u308C\u3070Point(0, -1)\u3092\u304B\u3051\
    \u308B\n    Point normalVector(const Point &a) { return a * Point(0, 1); }\n\n\
    \    // \u5185\u7A4D(dot product) : a\u30FBb = |a||b|cos\u0398\n    D dot(const\
    \ Point &a, const Point &b) {\n        return (a.real() * b.real() + a.imag()\
    \ * b.imag());\n    }\n\n    // \u5916\u7A4D(cross product) : a\xD7b = |a||b|sin\u0398\
    \n    D cross(const Point &a, const Point &b) {\n        return (a.real() * b.imag()\
    \ - a.imag() * b.real());\n    }\n\n    // \u70B9p\u3092\u53CD\u6642\u8A08\u56DE\
    \u308A\u306Btheta\u5EA6\u56DE\u8EE2\n    // theta\u306F\u30E9\u30B8\u30A2\u30F3\
    \uFF01\uFF01\uFF01\n    Point rotate(const Point &p, const D &theta) {\n     \
    \   return Point(cos(theta) * p.real() - sin(theta) * p.imag(),\n            \
    \         sin(theta) * p.real() + cos(theta) * p.imag());\n    }\n\n    // \u30E9\
    \u30B8\u30A2\u30F3->\u5EA6\n    D radianToDegree(const D &radian) { return radian\
    \ * 180.0 / PI; }\n\n    // \u5EA6->\u30E9\u30B8\u30A2\u30F3\n    D degreeToRadian(const\
    \ D &degree) { return degree * PI / 180.0; }\n\n    // \u70B9\u306E\u56DE\u8EE2\
    \u65B9\u5411\n    // \u70B9a, b, c\u306E\u4F4D\u7F6E\u95A2\u4FC2\u306B\u3064\u3044\
    \u3066(a\u304C\u57FA\u6E96\u70B9)\n    int ccw(const Point &a, Point b, Point\
    \ c) {\n        b -= a, c -= a;\n        // \u70B9a, b, c \u304C\n        // \u53CD\
    \u6642\u8A08\u56DE\u308A\u306E\u6642\u3001\n        if(cross(b, c) > EPS) return\
    \ 1;\n        // \u6642\u8A08\u56DE\u308A\u306E\u6642\u3001\n        if(cross(b,\
    \ c) < -EPS) return -1;\n        // c, a, b\u304C\u3053\u306E\u9806\u756A\u3067\
    \u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u6642\u3001\n        if(dot(b,\
    \ c) < 0) return 2;\n        // a, b, c\u304C\u3053\u306E\u9806\u756A\u3067\u540C\
    \u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u5834\u5408\u3001\n        if(norm(b)\
    \ < norm(c)) return -2;\n        // c\u304C\u7DDA\u5206ab\u4E0A\u306B\u3042\u308B\
    \u5834\u5408\u3001\n        return 0;\n    }\n\n    // Line : \u76F4\u7DDA\u3092\
    \u8868\u3059\u69CB\u9020\u4F53\n    // b - a \u3067\u76F4\u7DDA\u30FB\u7DDA\u5206\
    \u3092\u8868\u305B\u308B\n    struct Line {\n        Point a, b;\n        Line()\
    \ = default;\n        Line(Point a, Point b) : a(a), b(b) {}\n        // Ax+By=C\n\
    \        Line(D A, D B, D C) {\n            if(equal(A, 0)) {\n              \
    \  a = Point(0, C / B), b = Point(1, C / B);\n            } else if(equal(B, 0))\
    \ {\n                b = Point(C / A, 0), b = Point(C / A, 1);\n            }\
    \ else {\n                a = Point(0, C / B), b = Point(C / A, 0);\n        \
    \    }\n        }\n    };\n\n    // Segment : \u7DDA\u5206\u3092\u8868\u3059\u69CB\
    \u9020\u4F53\n    // Line\u3068\u540C\u3058\n    struct Segment : Line {\n   \
    \     Segment() = default;\n\n        Segment(Point a, Point b) : Line(a, b) {}\n\
    \    };\n\n    // Circle : \u5186\u3092\u8868\u3059\u69CB\u9020\u4F53\n    //\
    \ p\u304C\u4E2D\u5FC3\u306E\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3001r\u306F\u534A\
    \u5F84\n    struct Circle {\n        Point p;\n        D r;\n\n        Circle()\
    \ = default;\n\n        Circle(Point p, D r) : p(p), r(r) {}\n    };\n\n    //\
    \ 2\u76F4\u7DDA\u306E\u76F4\u4EA4\u5224\u5B9A : a\u22A5b <=> dot(a, b) = 0\n \
    \   bool isOrthogonal(const Line &a, const Line &b) {\n        return equal(dot(a.b\
    \ - a.a, b.b - b.a), 0);\n    }\n    // 2\u76F4\u7DDA\u306E\u5E73\u884C\u5224\u5B9A\
    \ : a//b <=> cross(a, b) = 0\n    bool isParallel(const Line &a, const Line &b)\
    \ {\n        return equal(cross(a.b - a.a, b.b - b.a), 0);\n    }\n\n    // \u70B9\
    c\u304C\u76F4\u7DDAab\u4E0A\u306B\u3042\u308B\u304B\n    bool isPointOnLine(const\
    \ Point &a, const Point &b, const Point &c) {\n        return isParallel(Line(a,\
    \ b), Line(a, c));\n    }\n\n    // \u70B9c\u304C\"\u7DDA\u5206\"ab\u4E0A\u306B\
    \u3042\u308B\u304B\n    bool isPointOnSegment(const Point &a, const Point &b,\
    \ const Point &c) {\n        // |a-c| + |c-b| <= |a-b| \u306A\u3089\u7DDA\u5206\
    \u4E0A\n        return (abs(a - c) + abs(c - b) < abs(a - b) + EPS);\n    }\n\n\
    \    // \u76F4\u7DDAl\u3068\u70B9p\u306E\u8DDD\u96E2\u3092\u6C42\u3081\u308B\n\
    \    D distanceBetweenLineAndPoint(const Line &l, const Point &p) {\n        return\
    \ abs(cross(l.b - l.a, p - l.a)) / abs(l.b - l.a);\n    }\n\n    // \u7DDA\u5206\
    l\u3068\u70B9p\u306E\u8DDD\u96E2\u3092\u6C42\u3081\u308B\n    // \u5B9A\u7FA9\uFF1A\
    \u70B9p\u304B\u3089\u300C\u7DDA\u5206l\u306E\u3069\u3053\u304B\u300D\u3078\u306E\
    \u6700\u77ED\u8DDD\u96E2\n    D distanceBetweenSegmentAndPoint(const Segment &l,\
    \ const Point &p) {\n        if(dot(l.b - l.a, p - l.a) < EPS) return abs(p -\
    \ l.a);\n        if(dot(l.a - l.b, p - l.b) < EPS) return abs(p - l.b);\n    \
    \    return abs(cross(l.b - l.a, p - l.a)) / abs(l.b - l.a);\n    }\n\n    //\
    \ \u76F4\u7DDAs, t\u306E\u4EA4\u70B9\u306E\u8A08\u7B97\n    Point crossPoint(const\
    \ Line &s, const Line &t) {\n        D d1 = cross(s.b - s.a, t.b - t.a);\n   \
    \     D d2 = cross(s.b - s.a, s.b - t.a);\n        if(equal(abs(d1), 0) && equal(abs(d2),\
    \ 0)) return t.a;\n        return t.a + (t.b - t.a) * (d2 / d1);\n    }\n\n  \
    \  // \u7DDA\u5206s, t\u306E\u4EA4\u70B9\u306E\u8A08\u7B97\n    Point crossPoint(const\
    \ Segment &s, const Segment &t) {\n        return crossPoint(Line(s), Line(t));\n\
    \    }\n\n    // \u7DDA\u5206s\u3068\u7DDA\u5206t\u304C\u4EA4\u5DEE\u3057\u3066\
    \u3044\u308B\u304B\u3069\u3046\u304B\n    // bound:\u7DDA\u5206\u306E\u7AEF\u70B9\
    \u3092\u542B\u3080\u304B\n    bool isIntersect(const Segment &s, const Segment\
    \ &t, bool bound) {\n        return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <\
    \ bound &&\n               ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) < bound;\n\
    \    }\n\n    // \u7DDA\u5206s\u3068t\u306E\u8DDD\u96E2\n    D distanceBetweenSegments(const\
    \ Segment &s, const Segment &t) {\n        if(isIntersect(s, t, 1)) return (D)(0);\n\
    \        D ans = distanceBetweenSegmentAndPoint(s, t.a);\n        chmin(ans, distanceBetweenSegmentAndPoint(s,\
    \ t.b));\n        chmin(ans, distanceBetweenSegmentAndPoint(t, s.a));\n      \
    \  chmin(ans, distanceBetweenSegmentAndPoint(t, s.b));\n        return ans;\n\
    \    }\n\n    // \u5C04\u5F71(projection)\n    // \u76F4\u7DDA(\u7DDA\u5206)l\u306B\
    \u70B9p\u304B\u3089\u5F15\u3044\u305F\u5782\u7DDA\u306E\u8DB3\u3092\u6C42\u3081\
    \u308B\n    Point projection(const Line &l, const Point &p) {\n        D t = dot(p\
    \ - l.a, l.a - l.b) / norm(l.a - l.b);\n        return l.a + (l.a - l.b) * t;\n\
    \    }\n\n    Point projection(const Segment &l, const Point &p) {\n        D\
    \ t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);\n        return l.a + (l.a -\
    \ l.b) * t;\n    }\n\n    // \u53CD\u5C04(reflection)\n    // \u76F4\u7DDAl\u3092\
    \u5BFE\u79F0\u8EF8\u3068\u3057\u3066\u70B9p\u3068\u7DDA\u5BFE\u79F0\u306E\u4F4D\
    \u7F6E\u306B\u3042\u308B\u70B9\u3092\u6C42\u3081\u308B\n    Point reflection(const\
    \ Line &l, const Point &p) {\n        return p + (projection(l, p) - p) * (D)2.0;\n\
    \    }\n\n    // 2\u3064\u306E\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A\n    // \u8FD4\
    \u308A\u5024\u306F\u5171\u901A\u63A5\u7DDA\u306E\u6570\n    int isIntersect(const\
    \ Circle &c1, const Circle &c2) {\n        D d = abs(c1.p - c2.p);\n        //\
    \ 2\u3064\u306E\u5186\u304C\u96E2\u308C\u3066\u3044\u308B\u5834\u5408\n      \
    \  if(d > c1.r + c2.r + EPS) return 4;\n        // \u5916\u63A5\u3057\u3066\u3044\
    \u308B\u5834\u5408\n        if(equal(d, c1.r + c2.r)) return 3;\n        // \u5185\
    \u63A5\u3057\u3066\u3044\u308B\u5834\u5408\n        if(equal(d, abs(c1.r - c2.r)))\
    \ return 1;\n        // \u5185\u5305\u3057\u3066\u3044\u308B\u5834\u5408\n   \
    \     if(d < abs(c1.r - c2.r) - EPS) return 0;\n        return 2;\n    }\n\n \
    \   // 2\u3064\u306E\u5186\u306E\u4EA4\u70B9\n    vector<Point> crossPoint(const\
    \ Circle &c1, const Circle &c2) {\n        vector<Point> res;\n        int mode\
    \ = isIntersect(c1, c2);\n        // 2\u3064\u306E\u4E2D\u5FC3\u306E\u8DDD\u96E2\
    \n        D d = abs(c1.p - c2.p);\n        // 2\u5186\u304C\u96E2\u308C\u3066\u3044\
    \u308B\u5834\u5408\n        if(mode == 4) return res;\n        // 1\u3064\u306E\
    \u5186\u304C\u3082\u30461\u3064\u306E\u5186\u306B\u5185\u5305\u3055\u308C\u3066\
    \u3044\u308B\u5834\u5408\n        if(mode == 0) return res;\n        // 2\u5186\
    \u304C\u5916\u63A5\u3059\u308B\u5834\u5408\n        if(mode == 3) {\n        \
    \    D t = c1.r / (c1.r + c2.r);\n            res.emplace_back(c1.p + (c2.p -\
    \ c1.p) * t);\n            return res;\n        }\n        // \u5185\u63A5\u3057\
    \u3066\u3044\u308B\u5834\u5408\n        if(mode == 1) {\n            if(c2.r <\
    \ c1.r - EPS) {\n                res.emplace_back(c1.p + (c2.p - c1.p) * (c1.r\
    \ / d));\n            } else {\n                res.emplace_back(c2.p + (c1.p\
    \ - c2.p) * (c2.r / d));\n            }\n            return res;\n        }\n\
    \        // 2\u5186\u304C\u91CD\u306A\u308B\u5834\u5408\n        D rc1 = (c1.r\
    \ * c1.r + d * d - c2.r * c2.r) / (2 * d);\n        D rs1 = sqrt(c1.r * c1.r -\
    \ rc1 * rc1);\n        if(c1.r - abs(rc1) < EPS) rs1 = 0;\n        Point e12 =\
    \ (c2.p - c1.p) / abs(c2.p - c1.p);\n        res.emplace_back(c1.p + rc1 * e12\
    \ + rs1 * e12 * Point(0, 1));\n        res.emplace_back(c1.p + rc1 * e12 + rs1\
    \ * e12 * Point(0, -1));\n        return res;\n    }\n\n    // \u70B9p\u304C\u5186\
    c\u306E\u5185\u90E8(\u5186\u5468\u4E0A\u3082\u542B\u3080)\u306B\u5165\u3063\u3066\
    \u3044\u308B\u304B\u3069\u3046\u304B\n    bool isInCircle(const Circle &c, const\
    \ Point &p) {\n        D d = abs(c.p - p);\n        return (equal(d, c.r) || d\
    \ < c.r - EPS);\n    }\n\n    // \u5186c\u3068\u76F4\u7DDAl\u306E\u4EA4\u70B9\n\
    \    vector<Point> crossPoint(const Circle &c, const Line &l) {\n        vector<Point>\
    \ res;\n        D d = distanceBetweenLineAndPoint(l, c.p);\n        // \u4EA4\u70B9\
    \u3092\u6301\u305F\u306A\u3044\n        if(d > c.r + EPS) return res;\n      \
    \  // \u63A5\u3059\u308B\n        Point h = projection(l, c.p);\n        if(equal(d,\
    \ c.r)) {\n            res.emplace_back(h);\n            return res;\n       \
    \ }\n        Point e = unitVector(l.b - l.a);\n        D ph = sqrt(c.r * c.r -\
    \ d * d);\n        res.emplace_back(h - e * ph);\n        res.emplace_back(h +\
    \ e * ph);\n        return res;\n    }\n\n    // \u70B9p\u3092\u901A\u308B\u5186\
    c\u306E\u63A5\u7DDA\n    // 2\u672C\u3042\u308B\u306E\u3067\u3001\u63A5\u70B9\u306E\
    \u307F\u3092\u8FD4\u3059\n    vector<Point> tangentToCircle(const Point &p, const\
    \ Circle &c) {\n        return crossPoint(c, Circle(p, sqrt(norm(c.p - p) - c.r\
    \ * c.r)));\n    }\n\n    // \u5186\u306E\u5171\u901A\u63A5\u7DDA\n    vector<Line>\
    \ tangent(const Circle &a, const Circle &b) {\n        vector<Line> ret;\n   \
    \     // 2\u5186\u306E\u4E2D\u5FC3\u9593\u306E\u8DDD\u96E2\n        D g = abs(a.p\
    \ - b.p);\n        // \u5186\u304C\u5185\u5305\u3055\u308C\u3066\u3044\u308B\u5834\
    \u5408\n        if(equal(g, 0)) return ret;\n        Point u = unitVector(b.p\
    \ - a.p);\n        Point v = rotate(u, PI / 2);\n        for(int s : {-1, 1})\
    \ {\n            D h = (a.r + b.r * s) / g;\n            if(equal(h * h, 1)) {\n\
    \                ret.emplace_back(a.p + (h > 0 ? u : -u) * a.r,\n            \
    \                     a.p + (h > 0 ? u : -u) * a.r + v);\n\n            } else\
    \ if(1 - h * h > 0) {\n                Point U = u * h, V = v * sqrt(1 - h * h);\n\
    \                ret.emplace_back(a.p + (U + V) * a.r,\n                     \
    \            b.p - (U + V) * (b.r * s));\n                ret.emplace_back(a.p\
    \ + (U - V) * a.r,\n                                 b.p - (U - V) * (b.r * s));\n\
    \            }\n        }\n        return ret;\n    }\n\n    // \u591A\u89D2\u5F62\
    \u306E\u9762\u7A4D\u3092\u6C42\u3081\u308B\n    D PolygonArea(const vector<Point>\
    \ &p) {\n        D res = 0;\n        int n = p.size();\n        for(int i = 0;\
    \ i < n - 1; i++) res += cross(p[i], p[i + 1]);\n        res += cross(p[n - 1],\
    \ p[0]);\n        return res * 0.5;\n    }\n\n    // \u51F8\u591A\u89D2\u5F62\u304B\
    \u3069\u3046\u304B\n    bool isConvex(const vector<Point> &p) {\n        int n\
    \ = p.size();\n        int now, pre, nxt;\n        for(int i = 0; i < n; i++)\
    \ {\n            pre = (i - 1 + n) % n;\n            nxt = (i + 1) % n;\n    \
    \        now = i;\n            if(ccw(p[pre], p[now], p[nxt]) == -1) return false;\n\
    \        }\n        return true;\n    }\n\n    // \u51F8\u5305 O(NlogN)\n    vector<Point>\
    \ ConvexHull(vector<Point> &p) {\n        int n = (int)p.size(), k = 0;\n    \
    \    sort(ALL(p), [](const Point &a, const Point &b) {\n            return (real(a)\
    \ != real(b) ? real(a) < real(b) : imag(a) < imag(b));\n        });\n        vector<Point>\
    \ ch(2 * n);\n        // \u4E00\u76F4\u7DDA\u4E0A\u306E3\u70B9\u3092\u542B\u3081\
    \u308B -> (< -EPS)\n        // \u542B\u3081\u7121\u3044 -> (< EPS)\n        for(int\
    \ i = 0; i < n; ch[k++] = p[i++]) { // lower\n            while(k >= 2 &&\n  \
    \                cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS)\n     \
    \           --k;\n        }\n        for(int i = n - 2, t = k + 1; i >= 0; ch[k++]\
    \ = p[i--]) { // upper\n            while(k >= t &&\n                  cross(ch[k\
    \ - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS)\n                --k;\n        }\n\
    \        ch.resize(k - 1);\n        return ch;\n    }\n\n    // \u591A\u89D2\u5F62\
    g\u306B\u70B9p\u304C\u542B\u307E\u308C\u3066\u3044\u308B\u304B?\n    // \u542B\
    \u307E\u308C\u308B:2, \u8FBA\u4E0A\u306B\u3042\u308B:1, \u542B\u307E\u308C\u306A\
    \u3044:0\n    int isContained(const vector<Point> &g, const Point &p) {\n    \
    \    bool in = false;\n        int n = (int)g.size();\n        for(int i = 0;\
    \ i < n; i++) {\n            Point a = g[i] - p, b = g[(i + 1) % n] - p;\n   \
    \         if(imag(a) > imag(b)) swap(a, b);\n            if(imag(a) <= EPS &&\
    \ EPS < imag(b) && cross(a, b) < -EPS) in = !in;\n            if(cross(a, b) ==\
    \ 0 && dot(a, b) <= 0) return 1;\n        }\n        return (in ? 2 : 0);\n  \
    \  }\n\n} // namespace geometry\n"
  code: "namespace geometry {\n    // Point : \u8907\u7D20\u6570\u578B\u3092\u4F4D\
    \u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\u3066\u6271\u3046\n    // \u5B9F\u8EF8\
    (real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092y\u8EF8\u3068\u3057\u3066\u898B\
    \u308B\n    using D = double;\n    using Point = complex<D>;\n    const D EPS\
    \ = 1e-7;\n    const D PI = acosl(-1);\n\n    inline bool equal(const D &a, const\
    \ D &b) { return fabs(a - b) < EPS; }\n\n    // \u5358\u4F4D\u30D9\u30AF\u30C8\
    \u30EB(unit vector)\u3092\u6C42\u3081\u308B\n    Point unitVector(const Point\
    \ &a) { return a / abs(a); }\n\n    // \u6CD5\u7DDA\u30D9\u30AF\u30C8\u30EB(normal\
    \ vector)\u3092\u6C42\u3081\u308B\n    // 90\u5EA6\u56DE\u8EE2\u3057\u305F\u5358\
    \u4F4D\u30D9\u30AF\u30C8\u30EB\u3092\u304B\u3051\u308B\n    // -90\u5EA6\u304C\
    \u3088\u3051\u308C\u3070Point(0, -1)\u3092\u304B\u3051\u308B\n    Point normalVector(const\
    \ Point &a) { return a * Point(0, 1); }\n\n    // \u5185\u7A4D(dot product) :\
    \ a\u30FBb = |a||b|cos\u0398\n    D dot(const Point &a, const Point &b) {\n  \
    \      return (a.real() * b.real() + a.imag() * b.imag());\n    }\n\n    // \u5916\
    \u7A4D(cross product) : a\xD7b = |a||b|sin\u0398\n    D cross(const Point &a,\
    \ const Point &b) {\n        return (a.real() * b.imag() - a.imag() * b.real());\n\
    \    }\n\n    // \u70B9p\u3092\u53CD\u6642\u8A08\u56DE\u308A\u306Btheta\u5EA6\u56DE\
    \u8EE2\n    // theta\u306F\u30E9\u30B8\u30A2\u30F3\uFF01\uFF01\uFF01\n    Point\
    \ rotate(const Point &p, const D &theta) {\n        return Point(cos(theta) *\
    \ p.real() - sin(theta) * p.imag(),\n                     sin(theta) * p.real()\
    \ + cos(theta) * p.imag());\n    }\n\n    // \u30E9\u30B8\u30A2\u30F3->\u5EA6\n\
    \    D radianToDegree(const D &radian) { return radian * 180.0 / PI; }\n\n   \
    \ // \u5EA6->\u30E9\u30B8\u30A2\u30F3\n    D degreeToRadian(const D &degree) {\
    \ return degree * PI / 180.0; }\n\n    // \u70B9\u306E\u56DE\u8EE2\u65B9\u5411\
    \n    // \u70B9a, b, c\u306E\u4F4D\u7F6E\u95A2\u4FC2\u306B\u3064\u3044\u3066(a\u304C\
    \u57FA\u6E96\u70B9)\n    int ccw(const Point &a, Point b, Point c) {\n       \
    \ b -= a, c -= a;\n        // \u70B9a, b, c \u304C\n        // \u53CD\u6642\u8A08\
    \u56DE\u308A\u306E\u6642\u3001\n        if(cross(b, c) > EPS) return 1;\n    \
    \    // \u6642\u8A08\u56DE\u308A\u306E\u6642\u3001\n        if(cross(b, c) < -EPS)\
    \ return -1;\n        // c, a, b\u304C\u3053\u306E\u9806\u756A\u3067\u540C\u4E00\
    \u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u6642\u3001\n        if(dot(b, c) < 0) return\
    \ 2;\n        // a, b, c\u304C\u3053\u306E\u9806\u756A\u3067\u540C\u4E00\u76F4\
    \u7DDA\u4E0A\u306B\u3042\u308B\u5834\u5408\u3001\n        if(norm(b) < norm(c))\
    \ return -2;\n        // c\u304C\u7DDA\u5206ab\u4E0A\u306B\u3042\u308B\u5834\u5408\
    \u3001\n        return 0;\n    }\n\n    // Line : \u76F4\u7DDA\u3092\u8868\u3059\
    \u69CB\u9020\u4F53\n    // b - a \u3067\u76F4\u7DDA\u30FB\u7DDA\u5206\u3092\u8868\
    \u305B\u308B\n    struct Line {\n        Point a, b;\n        Line() = default;\n\
    \        Line(Point a, Point b) : a(a), b(b) {}\n        // Ax+By=C\n        Line(D\
    \ A, D B, D C) {\n            if(equal(A, 0)) {\n                a = Point(0,\
    \ C / B), b = Point(1, C / B);\n            } else if(equal(B, 0)) {\n       \
    \         b = Point(C / A, 0), b = Point(C / A, 1);\n            } else {\n  \
    \              a = Point(0, C / B), b = Point(C / A, 0);\n            }\n    \
    \    }\n    };\n\n    // Segment : \u7DDA\u5206\u3092\u8868\u3059\u69CB\u9020\u4F53\
    \n    // Line\u3068\u540C\u3058\n    struct Segment : Line {\n        Segment()\
    \ = default;\n\n        Segment(Point a, Point b) : Line(a, b) {}\n    };\n\n\
    \    // Circle : \u5186\u3092\u8868\u3059\u69CB\u9020\u4F53\n    // p\u304C\u4E2D\
    \u5FC3\u306E\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3001r\u306F\u534A\u5F84\n  \
    \  struct Circle {\n        Point p;\n        D r;\n\n        Circle() = default;\n\
    \n        Circle(Point p, D r) : p(p), r(r) {}\n    };\n\n    // 2\u76F4\u7DDA\
    \u306E\u76F4\u4EA4\u5224\u5B9A : a\u22A5b <=> dot(a, b) = 0\n    bool isOrthogonal(const\
    \ Line &a, const Line &b) {\n        return equal(dot(a.b - a.a, b.b - b.a), 0);\n\
    \    }\n    // 2\u76F4\u7DDA\u306E\u5E73\u884C\u5224\u5B9A : a//b <=> cross(a,\
    \ b) = 0\n    bool isParallel(const Line &a, const Line &b) {\n        return\
    \ equal(cross(a.b - a.a, b.b - b.a), 0);\n    }\n\n    // \u70B9c\u304C\u76F4\u7DDA\
    ab\u4E0A\u306B\u3042\u308B\u304B\n    bool isPointOnLine(const Point &a, const\
    \ Point &b, const Point &c) {\n        return isParallel(Line(a, b), Line(a, c));\n\
    \    }\n\n    // \u70B9c\u304C\"\u7DDA\u5206\"ab\u4E0A\u306B\u3042\u308B\u304B\
    \n    bool isPointOnSegment(const Point &a, const Point &b, const Point &c) {\n\
    \        // |a-c| + |c-b| <= |a-b| \u306A\u3089\u7DDA\u5206\u4E0A\n        return\
    \ (abs(a - c) + abs(c - b) < abs(a - b) + EPS);\n    }\n\n    // \u76F4\u7DDA\
    l\u3068\u70B9p\u306E\u8DDD\u96E2\u3092\u6C42\u3081\u308B\n    D distanceBetweenLineAndPoint(const\
    \ Line &l, const Point &p) {\n        return abs(cross(l.b - l.a, p - l.a)) /\
    \ abs(l.b - l.a);\n    }\n\n    // \u7DDA\u5206l\u3068\u70B9p\u306E\u8DDD\u96E2\
    \u3092\u6C42\u3081\u308B\n    // \u5B9A\u7FA9\uFF1A\u70B9p\u304B\u3089\u300C\u7DDA\
    \u5206l\u306E\u3069\u3053\u304B\u300D\u3078\u306E\u6700\u77ED\u8DDD\u96E2\n  \
    \  D distanceBetweenSegmentAndPoint(const Segment &l, const Point &p) {\n    \
    \    if(dot(l.b - l.a, p - l.a) < EPS) return abs(p - l.a);\n        if(dot(l.a\
    \ - l.b, p - l.b) < EPS) return abs(p - l.b);\n        return abs(cross(l.b -\
    \ l.a, p - l.a)) / abs(l.b - l.a);\n    }\n\n    // \u76F4\u7DDAs, t\u306E\u4EA4\
    \u70B9\u306E\u8A08\u7B97\n    Point crossPoint(const Line &s, const Line &t) {\n\
    \        D d1 = cross(s.b - s.a, t.b - t.a);\n        D d2 = cross(s.b - s.a,\
    \ s.b - t.a);\n        if(equal(abs(d1), 0) && equal(abs(d2), 0)) return t.a;\n\
    \        return t.a + (t.b - t.a) * (d2 / d1);\n    }\n\n    // \u7DDA\u5206s,\
    \ t\u306E\u4EA4\u70B9\u306E\u8A08\u7B97\n    Point crossPoint(const Segment &s,\
    \ const Segment &t) {\n        return crossPoint(Line(s), Line(t));\n    }\n\n\
    \    // \u7DDA\u5206s\u3068\u7DDA\u5206t\u304C\u4EA4\u5DEE\u3057\u3066\u3044\u308B\
    \u304B\u3069\u3046\u304B\n    // bound:\u7DDA\u5206\u306E\u7AEF\u70B9\u3092\u542B\
    \u3080\u304B\n    bool isIntersect(const Segment &s, const Segment &t, bool bound)\
    \ {\n        return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) < bound &&\n     \
    \          ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) < bound;\n    }\n\n    // \u7DDA\
    \u5206s\u3068t\u306E\u8DDD\u96E2\n    D distanceBetweenSegments(const Segment\
    \ &s, const Segment &t) {\n        if(isIntersect(s, t, 1)) return (D)(0);\n \
    \       D ans = distanceBetweenSegmentAndPoint(s, t.a);\n        chmin(ans, distanceBetweenSegmentAndPoint(s,\
    \ t.b));\n        chmin(ans, distanceBetweenSegmentAndPoint(t, s.a));\n      \
    \  chmin(ans, distanceBetweenSegmentAndPoint(t, s.b));\n        return ans;\n\
    \    }\n\n    // \u5C04\u5F71(projection)\n    // \u76F4\u7DDA(\u7DDA\u5206)l\u306B\
    \u70B9p\u304B\u3089\u5F15\u3044\u305F\u5782\u7DDA\u306E\u8DB3\u3092\u6C42\u3081\
    \u308B\n    Point projection(const Line &l, const Point &p) {\n        D t = dot(p\
    \ - l.a, l.a - l.b) / norm(l.a - l.b);\n        return l.a + (l.a - l.b) * t;\n\
    \    }\n\n    Point projection(const Segment &l, const Point &p) {\n        D\
    \ t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);\n        return l.a + (l.a -\
    \ l.b) * t;\n    }\n\n    // \u53CD\u5C04(reflection)\n    // \u76F4\u7DDAl\u3092\
    \u5BFE\u79F0\u8EF8\u3068\u3057\u3066\u70B9p\u3068\u7DDA\u5BFE\u79F0\u306E\u4F4D\
    \u7F6E\u306B\u3042\u308B\u70B9\u3092\u6C42\u3081\u308B\n    Point reflection(const\
    \ Line &l, const Point &p) {\n        return p + (projection(l, p) - p) * (D)2.0;\n\
    \    }\n\n    // 2\u3064\u306E\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A\n    // \u8FD4\
    \u308A\u5024\u306F\u5171\u901A\u63A5\u7DDA\u306E\u6570\n    int isIntersect(const\
    \ Circle &c1, const Circle &c2) {\n        D d = abs(c1.p - c2.p);\n        //\
    \ 2\u3064\u306E\u5186\u304C\u96E2\u308C\u3066\u3044\u308B\u5834\u5408\n      \
    \  if(d > c1.r + c2.r + EPS) return 4;\n        // \u5916\u63A5\u3057\u3066\u3044\
    \u308B\u5834\u5408\n        if(equal(d, c1.r + c2.r)) return 3;\n        // \u5185\
    \u63A5\u3057\u3066\u3044\u308B\u5834\u5408\n        if(equal(d, abs(c1.r - c2.r)))\
    \ return 1;\n        // \u5185\u5305\u3057\u3066\u3044\u308B\u5834\u5408\n   \
    \     if(d < abs(c1.r - c2.r) - EPS) return 0;\n        return 2;\n    }\n\n \
    \   // 2\u3064\u306E\u5186\u306E\u4EA4\u70B9\n    vector<Point> crossPoint(const\
    \ Circle &c1, const Circle &c2) {\n        vector<Point> res;\n        int mode\
    \ = isIntersect(c1, c2);\n        // 2\u3064\u306E\u4E2D\u5FC3\u306E\u8DDD\u96E2\
    \n        D d = abs(c1.p - c2.p);\n        // 2\u5186\u304C\u96E2\u308C\u3066\u3044\
    \u308B\u5834\u5408\n        if(mode == 4) return res;\n        // 1\u3064\u306E\
    \u5186\u304C\u3082\u30461\u3064\u306E\u5186\u306B\u5185\u5305\u3055\u308C\u3066\
    \u3044\u308B\u5834\u5408\n        if(mode == 0) return res;\n        // 2\u5186\
    \u304C\u5916\u63A5\u3059\u308B\u5834\u5408\n        if(mode == 3) {\n        \
    \    D t = c1.r / (c1.r + c2.r);\n            res.emplace_back(c1.p + (c2.p -\
    \ c1.p) * t);\n            return res;\n        }\n        // \u5185\u63A5\u3057\
    \u3066\u3044\u308B\u5834\u5408\n        if(mode == 1) {\n            if(c2.r <\
    \ c1.r - EPS) {\n                res.emplace_back(c1.p + (c2.p - c1.p) * (c1.r\
    \ / d));\n            } else {\n                res.emplace_back(c2.p + (c1.p\
    \ - c2.p) * (c2.r / d));\n            }\n            return res;\n        }\n\
    \        // 2\u5186\u304C\u91CD\u306A\u308B\u5834\u5408\n        D rc1 = (c1.r\
    \ * c1.r + d * d - c2.r * c2.r) / (2 * d);\n        D rs1 = sqrt(c1.r * c1.r -\
    \ rc1 * rc1);\n        if(c1.r - abs(rc1) < EPS) rs1 = 0;\n        Point e12 =\
    \ (c2.p - c1.p) / abs(c2.p - c1.p);\n        res.emplace_back(c1.p + rc1 * e12\
    \ + rs1 * e12 * Point(0, 1));\n        res.emplace_back(c1.p + rc1 * e12 + rs1\
    \ * e12 * Point(0, -1));\n        return res;\n    }\n\n    // \u70B9p\u304C\u5186\
    c\u306E\u5185\u90E8(\u5186\u5468\u4E0A\u3082\u542B\u3080)\u306B\u5165\u3063\u3066\
    \u3044\u308B\u304B\u3069\u3046\u304B\n    bool isInCircle(const Circle &c, const\
    \ Point &p) {\n        D d = abs(c.p - p);\n        return (equal(d, c.r) || d\
    \ < c.r - EPS);\n    }\n\n    // \u5186c\u3068\u76F4\u7DDAl\u306E\u4EA4\u70B9\n\
    \    vector<Point> crossPoint(const Circle &c, const Line &l) {\n        vector<Point>\
    \ res;\n        D d = distanceBetweenLineAndPoint(l, c.p);\n        // \u4EA4\u70B9\
    \u3092\u6301\u305F\u306A\u3044\n        if(d > c.r + EPS) return res;\n      \
    \  // \u63A5\u3059\u308B\n        Point h = projection(l, c.p);\n        if(equal(d,\
    \ c.r)) {\n            res.emplace_back(h);\n            return res;\n       \
    \ }\n        Point e = unitVector(l.b - l.a);\n        D ph = sqrt(c.r * c.r -\
    \ d * d);\n        res.emplace_back(h - e * ph);\n        res.emplace_back(h +\
    \ e * ph);\n        return res;\n    }\n\n    // \u70B9p\u3092\u901A\u308B\u5186\
    c\u306E\u63A5\u7DDA\n    // 2\u672C\u3042\u308B\u306E\u3067\u3001\u63A5\u70B9\u306E\
    \u307F\u3092\u8FD4\u3059\n    vector<Point> tangentToCircle(const Point &p, const\
    \ Circle &c) {\n        return crossPoint(c, Circle(p, sqrt(norm(c.p - p) - c.r\
    \ * c.r)));\n    }\n\n    // \u5186\u306E\u5171\u901A\u63A5\u7DDA\n    vector<Line>\
    \ tangent(const Circle &a, const Circle &b) {\n        vector<Line> ret;\n   \
    \     // 2\u5186\u306E\u4E2D\u5FC3\u9593\u306E\u8DDD\u96E2\n        D g = abs(a.p\
    \ - b.p);\n        // \u5186\u304C\u5185\u5305\u3055\u308C\u3066\u3044\u308B\u5834\
    \u5408\n        if(equal(g, 0)) return ret;\n        Point u = unitVector(b.p\
    \ - a.p);\n        Point v = rotate(u, PI / 2);\n        for(int s : {-1, 1})\
    \ {\n            D h = (a.r + b.r * s) / g;\n            if(equal(h * h, 1)) {\n\
    \                ret.emplace_back(a.p + (h > 0 ? u : -u) * a.r,\n            \
    \                     a.p + (h > 0 ? u : -u) * a.r + v);\n\n            } else\
    \ if(1 - h * h > 0) {\n                Point U = u * h, V = v * sqrt(1 - h * h);\n\
    \                ret.emplace_back(a.p + (U + V) * a.r,\n                     \
    \            b.p - (U + V) * (b.r * s));\n                ret.emplace_back(a.p\
    \ + (U - V) * a.r,\n                                 b.p - (U - V) * (b.r * s));\n\
    \            }\n        }\n        return ret;\n    }\n\n    // \u591A\u89D2\u5F62\
    \u306E\u9762\u7A4D\u3092\u6C42\u3081\u308B\n    D PolygonArea(const vector<Point>\
    \ &p) {\n        D res = 0;\n        int n = p.size();\n        for(int i = 0;\
    \ i < n - 1; i++) res += cross(p[i], p[i + 1]);\n        res += cross(p[n - 1],\
    \ p[0]);\n        return res * 0.5;\n    }\n\n    // \u51F8\u591A\u89D2\u5F62\u304B\
    \u3069\u3046\u304B\n    bool isConvex(const vector<Point> &p) {\n        int n\
    \ = p.size();\n        int now, pre, nxt;\n        for(int i = 0; i < n; i++)\
    \ {\n            pre = (i - 1 + n) % n;\n            nxt = (i + 1) % n;\n    \
    \        now = i;\n            if(ccw(p[pre], p[now], p[nxt]) == -1) return false;\n\
    \        }\n        return true;\n    }\n\n    // \u51F8\u5305 O(NlogN)\n    vector<Point>\
    \ ConvexHull(vector<Point> &p) {\n        int n = (int)p.size(), k = 0;\n    \
    \    sort(ALL(p), [](const Point &a, const Point &b) {\n            return (real(a)\
    \ != real(b) ? real(a) < real(b) : imag(a) < imag(b));\n        });\n        vector<Point>\
    \ ch(2 * n);\n        // \u4E00\u76F4\u7DDA\u4E0A\u306E3\u70B9\u3092\u542B\u3081\
    \u308B -> (< -EPS)\n        // \u542B\u3081\u7121\u3044 -> (< EPS)\n        for(int\
    \ i = 0; i < n; ch[k++] = p[i++]) { // lower\n            while(k >= 2 &&\n  \
    \                cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS)\n     \
    \           --k;\n        }\n        for(int i = n - 2, t = k + 1; i >= 0; ch[k++]\
    \ = p[i--]) { // upper\n            while(k >= t &&\n                  cross(ch[k\
    \ - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS)\n                --k;\n        }\n\
    \        ch.resize(k - 1);\n        return ch;\n    }\n\n    // \u591A\u89D2\u5F62\
    g\u306B\u70B9p\u304C\u542B\u307E\u308C\u3066\u3044\u308B\u304B?\n    // \u542B\
    \u307E\u308C\u308B:2, \u8FBA\u4E0A\u306B\u3042\u308B:1, \u542B\u307E\u308C\u306A\
    \u3044:0\n    int isContained(const vector<Point> &g, const Point &p) {\n    \
    \    bool in = false;\n        int n = (int)g.size();\n        for(int i = 0;\
    \ i < n; i++) {\n            Point a = g[i] - p, b = g[(i + 1) % n] - p;\n   \
    \         if(imag(a) > imag(b)) swap(a, b);\n            if(imag(a) <= EPS &&\
    \ EPS < imag(b) && cross(a, b) < -EPS) in = !in;\n            if(cross(a, b) ==\
    \ 0 && dot(a, b) <= 0) return 1;\n        }\n        return (in ? 2 : 0);\n  \
    \  }\n\n} // namespace geometry"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometry.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/geometry.hpp
layout: document
redirect_from:
- /library/geometry/geometry.hpp
- /library/geometry/geometry.hpp.html
title: geometry/geometry.hpp
---
