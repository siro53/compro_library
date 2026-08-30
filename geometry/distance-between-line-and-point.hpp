#pragma once

#include "cross.hpp"
#include "line.hpp"

namespace geometry {
    // 直線lと点pの距離を求める
    inline D distanceBetweenLineAndPoint(const Line &l, const Point &p) {
        return std::abs(cross(l.b - l.a, p - l.a)) / std::abs(l.b - l.a);
    }
} // namespace geometry
