#pragma once

#include "line.hpp"

namespace geometry {
    // Segment : 線分を表す構造体
    // Lineと同じ
    struct Segment : Line {
        Segment() = default;

        Segment(Point a, Point b) : Line(a, b) {}
        D get_dist() { return std::abs(a - b); }
    };
} // namespace geometry
