#pragma once

#include "is-parallel.hpp"

namespace geometry {
    // 点cが直線ab上にあるか
    inline bool isPointOnLine(const Point &a, const Point &b, const Point &c) {
        return isParallel(Line(a, b), Line(a, c));
    }
} // namespace geometry
