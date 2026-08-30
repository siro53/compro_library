#pragma once

#include <vector>

#include "cross.hpp"

namespace geometry {
    // 多角形の面積を求める
    inline D PolygonArea(const std::vector<Point> &p) {
        D res = 0;
        int n = p.size();
        for(int i = 0; i < n - 1; i++) res += cross(p[i], p[i + 1]);
        res += cross(p[n - 1], p[0]);
        return res * 0.5;
    }
} // namespace geometry
