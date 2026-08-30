#pragma once

#include "base.hpp"

namespace geometry {
    // Circle : 円を表す構造体
    // pが中心の位置ベクトル、rは半径
    struct Circle {
        Point p;
        D r;

        Circle() = default;

        Circle(Point p, D r) : p(p), r(r) {}
    };
} // namespace geometry
