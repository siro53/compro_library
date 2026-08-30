#pragma once

#include "base.hpp"

namespace geometry {
    // 内積(dot product) : a・b = |a||b|cosΘ
    inline D dot(const Point &a, const Point &b) {
        return (a.real() * b.real() + a.imag() * b.imag());
    }
} // namespace geometry
