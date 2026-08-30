#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"

#include "../../../geometry/ccw.hpp"
#include "../../../geometry/convex-cut.hpp"
#include "../../../geometry/convex-hull.hpp"
#include "../../../geometry/degree-to-radian.hpp"
#include "../../../geometry/distance-between-segments.hpp"
#include "../../../geometry/is-contained.hpp"
#include "../../../geometry/is-convex.hpp"
#include "../../../geometry/is-in-circle.hpp"
#include "../../../geometry/is-orthogonal.hpp"
#include "../../../geometry/is-point-on-line.hpp"
#include "../../../geometry/is-point-on-segment.hpp"
#include "../../../geometry/normal-vector.hpp"
#include "../../../geometry/polygon-area.hpp"
#include "../../../geometry/radian-to-degree.hpp"
#include "../../../geometry/reflection.hpp"
#include "../../../geometry/tangent-to-circle.hpp"
#include "../../../geometry/tangent.hpp"

using namespace geometry;

void geometry_test() {
    Point origin(0, 0), x(1, 0), y(0, 1);
    assert(equal(dot(x, y), 0));
    assert(equal(cross(x, y), 1));
    assert(equal(std::abs(unitVector(Point(3, 4))), 1));
    assert(normalVector(x) == y);
    assert(std::abs(rotate(x, PI / 2) - y) < EPS);
    assert(equal(radianToDegree(degreeToRadian(90)), 90));
    assert(ccw(origin, x, y) == 1);

    Line horizontal(origin, x), vertical(origin, y);
    Segment horizontal_segment(origin, Point(2, 0));
    Circle unit_circle(origin, 1);
    assert(isOrthogonal(horizontal, vertical));
    assert(isParallel(horizontal, Line(Point(0, 1), Point(1, 1))));
    assert(isPointOnLine(origin, x, Point(2, 0)));
    assert(isPointOnSegment(origin, Point(2, 0), x));
    assert(equal(distanceBetweenLineAndPoint(horizontal, y), 1));
    assert(equal(distanceBetweenSegmentAndPoint(horizontal_segment, Point(3, 0)), 1));
    assert(crossPoint(horizontal, vertical) == origin);
    assert(isIntersect(horizontal_segment, Segment(Point(1, -1), Point(1, 1)), true));
    assert(equal(distanceBetweenSegments(horizontal_segment,
                                         Segment(Point(3, 0), Point(4, 0))),
                 1));
    assert(projection(horizontal, y) == origin);
    assert(reflection(horizontal, y) == Point(0, -1));

    assert(isIntersect(unit_circle, Circle(Point(2, 0), 1)) == 3);
    assert(crossPoint(unit_circle, Circle(Point(2, 0), 1)).size() == 1);
    assert(crossPoint(unit_circle, horizontal).size() == 2);
    assert(isInCircle(unit_circle, origin));
    assert(tangentToCircle(Point(2, 0), unit_circle).size() == 2);
    assert(tangent(unit_circle, Circle(Point(4, 0), 1)).size() == 4);

    std::vector<Point> triangle = {origin, x, y};
    assert(equal(PolygonArea(triangle), 0.5));
    assert(isConvex(triangle));
    assert(ConvexHull(triangle).size() == 3);
    assert(isContained(triangle, Point(0.1, 0.1)) == 2);
    assert(!ConvexCut(triangle, Line(Point(0.5, -1), Point(0.5, 1))).empty());
}

int main() {
    geometry_test();
    INT(a, b);
    print(a + b);
}
