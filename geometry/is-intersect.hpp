#pragma once

#include "ccw.hpp"
#include "circle.hpp"
#include "segment.hpp"

namespace geometry {
    // 線分sと線分tが交差しているかどうか
    // bound:線分の端点を含むか
    inline bool isIntersect(const Segment &s, const Segment &t, bool bound) {
        return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) < bound &&
               ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) < bound;
    }

    // 2つの円の交差判定
    // 返り値は共通接線の数
    inline int isIntersect(const Circle &c1, const Circle &c2) {
        D d = std::abs(c1.p - c2.p);
        // 2つの円が離れている場合
        if(d > c1.r + c2.r + EPS) return 4;
        // 外接している場合
        if(equal(d, c1.r + c2.r)) return 3;
        // 内接している場合
        if(equal(d, std::abs(c1.r - c2.r))) return 1;
        // 内包している場合
        if(d < std::abs(c1.r - c2.r) - EPS) return 0;
        return 2;
    }
} // namespace geometry
