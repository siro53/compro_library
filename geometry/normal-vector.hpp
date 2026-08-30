#pragma once

#include "base.hpp"

namespace geometry {
    // 法線ベクトル(normal vector)を求める
    // 90度回転した単位ベクトルをかける
    // -90度がよければPoint(0, -1)をかける
    inline Point normalVector(const Point &a) { return a * Point(0, 1); }
} // namespace geometry
