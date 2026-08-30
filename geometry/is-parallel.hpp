#pragma once

#include "cross.hpp"
#include "line.hpp"

namespace geometry {
    // 2直線の平行判定 : a//b <=> cross(a, b) = 0
    inline bool isParallel(const Line &a, const Line &b) {
        return equal(cross(a.b - a.a, b.b - b.a), 0);
    }
} // namespace geometry
