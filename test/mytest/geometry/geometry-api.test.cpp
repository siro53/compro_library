#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../geometry/geometry.hpp"


using namespace geometry;
int main() {
    assert(equal(1, 1 + EPS / 2) && !equal(1, 1 + EPS * 2));
    for(auto coefficients : vector<array<D, 3>>{ {0, 2, 6}, {2, 0, 6}, {2, 3, 0}, {2, 3, 7} }) {
        auto [a, b, c] = coefficients; Line line; line = Line(a, b, c);
        assert(equal(a * line.a.real() + b * line.a.imag(), c));
        assert(equal(a * line.b.real() + b * line.b.imag(), c));
        assert(abs(line.a - line.b) > EPS);
    }
    Segment segment; segment = Segment(Point(0, 0), Point(3, 4)); assert(equal(segment.get_dist(), 5));
    Circle circle; circle = Circle(Point(0, 0), 2); assert(circle.p == Point(0, 0) && circle.r == 2);
    Point o(0, 0), e(2, 0);
    assert(ccw(o, e, Point(1, 1)) == 1 && ccw(o, e, Point(1, -1)) == -1);
    assert(ccw(o, e, Point(-1, 0)) == 2 && ccw(o, e, Point(3, 0)) == -2 && ccw(o, e, Point(1, 0)) == 0);
    Segment a(o, e), crossing(Point(1, -1), Point(1, 1)), touching(e, Point(3, 1));
    assert(isIntersect(a, crossing, false)); assert(isIntersect(a, touching, true)); assert(!isIntersect(a, touching, false));
    assert(abs(crossPoint(a, crossing) - Point(1, 0)) < EPS);
    assert(equal(distanceBetweenSegments(a, crossing), 0));
    assert(isPointOnLine(o, e, Point(3, 0)) && !isPointOnLine(o, e, Point(1, 1)));
    assert(!isPointOnSegment(o, e, Point(3, 0)) && isPointOnSegment(o, e, e));
    for(D distance : {0.5L, 1.0L, 2.0L, 3.0L, 4.0L}) {
        Circle other(Point(distance, 0), 1);
        int count = isIntersect(circle, other);
        int expected = distance < 1 ? 0 : distance == 1 ? 1 : distance < 3 ? 2 : distance == 3 ? 3 : 4;
        assert(count == expected && isIntersect(other, circle) == expected);
        auto points = crossPoint(circle, other);
        assert(points.size() == unsigned(expected == 0 || expected == 4 ? 0 : expected == 2 ? 2 : 1));
        for(auto p : points) assert(equal(abs(p - circle.p), circle.r) && equal(abs(p - other.p), other.r));
        auto lines = tangent(circle, other); assert(lines.size() == unsigned(expected));
        for(auto l : lines) assert(equal(distanceBetweenLineAndPoint(l, circle.p), circle.r) && equal(distanceBetweenLineAndPoint(l, other.p), other.r));
    }
    for(D height : {0.0L, 2.0L, 3.0L}) {
        Line l(Point(-5, height), Point(5, height)); auto points = crossPoint(circle, l);
        assert(points.size() == unsigned(height == 0 ? 2 : height == 2 ? 1 : 0));
        for(auto p : points) assert(equal(abs(p), 2) && equal(p.imag(), height));
    }
    Point outside(5, 0);
    for(auto p : tangentToCircle(outside, circle)) assert(equal(abs(p), 2) && equal(dot(p, outside - p), 0));
    vector<Point> square{Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2)};
    assert(isContained(square, Point(1, 1)) == 2 && isContained(square, Point(2, 1)) == 1 && isContained(square, Point(3, 1)) == 0);
    auto cut = ConvexCut(square, Line(Point(1, -1), Point(1, 3))); assert(equal(PolygonArea(cut), 2));
    assert(isConvex(square));
    vector<Point> concave{Point(0, 0), Point(2, 0), Point(1, 1), Point(2, 2), Point(0, 2)}; assert(!isConvex(concave));
    vector<Point> points = square; points.push_back(Point(1, 1)); points.push_back(square[0]);
    auto hull = ConvexHull(points); assert(hull.size() == 4 && equal(PolygonArea(hull), 4));
    INT(a0, b0); print(a0 + b0);
}
