#pragma once

#include "circle.hpp"

namespace geometry {
    // 点pが円cの内部(円周上も含む)に入っているかどうか
    inline bool isInCircle(const Circle &c, const Point &p) {
        D d = std::abs(c.p - p);
        return (equal(d, c.r) || d < c.r - EPS);
    }
} // namespace geometry
