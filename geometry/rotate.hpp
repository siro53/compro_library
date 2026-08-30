#pragma once

#include "base.hpp"

namespace geometry {
    // 点pを反時計回りにtheta度回転
    // thetaはラジアン！！！
    inline Point rotate(const Point &p, const D &theta) {
        return Point(std::cos(theta) * p.real() - std::sin(theta) * p.imag(),
                     std::sin(theta) * p.real() + std::cos(theta) * p.imag());
    }
} // namespace geometry
