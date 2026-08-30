#pragma once

#include <vector>

#include "ccw.hpp"
#include "cross-point.hpp"

namespace geometry {
    // 凸多角形pを直線lで切断し、その左側を返す
    inline std::vector<Point> ConvexCut(std::vector<Point> p, Line l) {
        std::vector<Point> ret;
        int sz = (int)p.size();
        for(int i = 0; i < sz; i++) {
            Point now = p[i];
            Point nxt = p[i == sz - 1 ? 0 : i + 1];
            if(ccw(l.a, l.b, now) != -1) ret.emplace_back(now);
            if(ccw(l.a, l.b, now) * ccw(l.a, l.b, nxt) < 0) {
                ret.emplace_back(crossPoint(Line(now, nxt), l));
            }
        }
        return ret;
    }
} // namespace geometry
