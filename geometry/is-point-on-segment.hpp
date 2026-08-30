#pragma once

#include "base.hpp"

namespace geometry {
    // 点cが"線分"ab上にあるか
    inline bool isPointOnSegment(const Point &a, const Point &b, const Point &c) {
        // |a-c| + |c-b| <= |a-b| なら線分上
        return (std::abs(a - c) + std::abs(c - b) < std::abs(a - b) + EPS);
    }
} // namespace geometry
