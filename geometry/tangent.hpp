#pragma once

#include <cmath>
#include <vector>

#include "circle.hpp"
#include "line.hpp"
#include "rotate.hpp"
#include "unit-vector.hpp"

namespace geometry {
    // 円の共通接線
    inline std::vector<Line> tangent(const Circle &a, const Circle &b) {
        std::vector<Line> ret;
        // 2円の中心間の距離
        D g = std::abs(a.p - b.p);
        // 円が内包されている場合
        if(equal(g, 0)) return ret;
        Point u = unitVector(b.p - a.p);
        Point v = rotate(u, PI / 2);
        for(int s : {-1, 1}) {
            D h = (a.r + b.r * s) / g;
            if(equal(h * h, 1)) {
                ret.emplace_back(a.p + (h > 0 ? u : -u) * a.r,
                                 a.p + (h > 0 ? u : -u) * a.r + v);

            } else if(1 - h * h > 0) {
                Point U = u * h, V = v * std::sqrt(1 - h * h);
                ret.emplace_back(a.p + (U + V) * a.r,
                                 b.p - (U + V) * (b.r * s));
                ret.emplace_back(a.p + (U - V) * a.r,
                                 b.p - (U - V) * (b.r * s));
            }
        }
        return ret;
    }
} // namespace geometry
