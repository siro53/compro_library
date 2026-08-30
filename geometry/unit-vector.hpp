#pragma once

#include "base.hpp"

namespace geometry {
    // 単位ベクトル(unit vector)を求める
    inline Point unitVector(const Point &a) { return a / std::abs(a); }
} // namespace geometry
