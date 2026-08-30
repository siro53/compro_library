#pragma once

#include "projection.hpp"

namespace geometry {
    // 反射(reflection)
    // 直線lを対称軸として点pと線対称の位置にある点を求める
    inline Point reflection(const Line &l, const Point &p) {
        return p + (projection(l, p) - p) * (D)2.0;
    }
} // namespace geometry
