#pragma once

#include "cross.hpp"
#include "dot.hpp"
#include "segment.hpp"

namespace geometry {
    // 線分lと点pの距離を求める
    // 定義：点pから「線分lのどこか」への最短距離
    inline D distanceBetweenSegmentAndPoint(const Segment &l, const Point &p) {
        if(dot(l.b - l.a, p - l.a) < EPS) return std::abs(p - l.a);
        if(dot(l.a - l.b, p - l.b) < EPS) return std::abs(p - l.b);
        return std::abs(cross(l.b - l.a, p - l.a)) / std::abs(l.b - l.a);
    }
} // namespace geometry
