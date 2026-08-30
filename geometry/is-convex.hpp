#pragma once

#include <vector>

#include "ccw.hpp"

namespace geometry {
    // 凸多角形かどうか
    inline bool isConvex(const std::vector<Point> &p) {
        int n = p.size();
        int now, pre, nxt;
        for(int i = 0; i < n; i++) {
            pre = (i - 1 + n) % n;
            nxt = (i + 1) % n;
            now = i;
            if(ccw(p[pre], p[now], p[nxt]) == -1) return false;
        }
        return true;
    }
} // namespace geometry
