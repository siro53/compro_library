#pragma once

#include "dot.hpp"
#include "line.hpp"
#include "segment.hpp"

namespace geometry {
    // 射影(projection)
    // 直線(線分)lに点pから引いた垂線の足を求める
    inline Point projection(const Line &l, const Point &p) {
        D t = dot(p - l.a, l.a - l.b) / std::norm(l.a - l.b);
        return l.a + (l.a - l.b) * t;
    }

    inline Point projection(const Segment &l, const Point &p) {
        D t = dot(p - l.a, l.a - l.b) / std::norm(l.a - l.b);
        return l.a + (l.a - l.b) * t;
    }
} // namespace geometry
