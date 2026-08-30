#pragma once

#include <vector>

#include "cross.hpp"
#include "dot.hpp"

namespace geometry {
    // 多角形gに点pが含まれているか?
    // 含まれる:2, 辺上にある:1, 含まれない:0
    inline int isContained(const std::vector<Point> &g, const Point &p) {
        bool in = false;
        int n = (int)g.size();
        for(int i = 0; i < n; i++) {
            Point a = g[i] - p, b = g[(i + 1) % n] - p;
            if(imag(a) > imag(b)) swap(a, b);
            if(imag(a) <= EPS && EPS < imag(b) && cross(a, b) < -EPS) in = !in;
            if(cross(a, b) == 0 && dot(a, b) <= 0) return 1;
        }
        return (in ? 2 : 0);
    }
} // namespace geometry
