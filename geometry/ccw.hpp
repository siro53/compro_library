#pragma once

#include "cross.hpp"
#include "dot.hpp"

namespace geometry {
    // 点の回転方向
    // 点a, b, cの位置関係について(aが基準点)
    inline int ccw(const Point &a, Point b, Point c) {
        b -= a, c -= a;
        // 点a, b, c が
        // 反時計回りの時、
        if(cross(b, c) > EPS) return 1;
        // 時計回りの時、
        if(cross(b, c) < -EPS) return -1;
        // c, a, bがこの順番で同一直線上にある時、
        if(dot(b, c) < 0) return 2;
        // a, b, cがこの順番で同一直線上にある場合、
        if(std::norm(b) < std::norm(c)) return -2;
        // cが線分ab上にある場合、
        return 0;
    }
} // namespace geometry
