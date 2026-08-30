#pragma once

#include "base.hpp"

namespace geometry {
    // 外積(cross product) : a×b = |a||b|sinΘ
    inline D cross(const Point &a, const Point &b) {
        return (a.real() * b.imag() - a.imag() * b.real());
    }
} // namespace geometry
