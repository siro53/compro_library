#pragma once

#include "dot.hpp"
#include "line.hpp"

namespace geometry {
    // 2直線の直交判定 : a⊥b <=> dot(a, b) = 0
    inline bool isOrthogonal(const Line &a, const Line &b) {
        return equal(dot(a.b - a.a, b.b - b.a), 0);
    }
} // namespace geometry
