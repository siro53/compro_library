#pragma once

#include "base.hpp"

namespace geometry {
    // 度->ラジアン
    inline D degreeToRadian(const D &degree) { return degree * PI / 180.0; }
} // namespace geometry
