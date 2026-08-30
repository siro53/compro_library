#pragma once

#include <algorithm>
#include <vector>

#include "cross.hpp"

namespace geometry {
    // 凸包 O(NlogN)
    inline std::vector<Point> ConvexHull(std::vector<Point> p) {
        int n = (int)p.size(), k = 0;
        std::sort(p.begin(), p.end(), [](const Point &a, const Point &b) {
            return (a.real() != b.real() ? a.real() < b.real()
                                         : a.imag() < b.imag());
        });
        std::vector<Point> ch(2 * n);
        // 一直線上の3点を含める -> (< -EPS)
        // 含め無い -> (< EPS)
        for(int i = 0; i < n; ch[k++] = p[i++]) { // lower
            while(k >= 2 &&
                  cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS)
                --k;
        }
        for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) { // upper
            while(k >= t &&
                  cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS)
                --k;
        }
        ch.resize(k - 1);
        return ch;
    }
} // namespace geometry
