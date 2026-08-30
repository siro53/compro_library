#pragma once

#include "base.hpp"

namespace geometry {
    // ラジアン->度
    inline D radianToDegree(const D &radian) { return radian * 180.0 / PI; }
} // namespace geometry
