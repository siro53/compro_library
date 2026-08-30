#pragma once

#include <cmath>
#include <vector>

#include "cross-point.hpp"

namespace geometry {
    // 点pを通る円cの接線
    // 2本あるので、接点のみを返す
    inline std::vector<Point> tangentToCircle(const Point &p, const Circle &c) {
        return crossPoint(c,
                          Circle(p, std::sqrt(std::norm(c.p - p) - c.r * c.r)));
    }
} // namespace geometry
