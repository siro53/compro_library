#pragma once

#include <cmath>
#include <vector>

#include "circle.hpp"
#include "cross.hpp"
#include "distance-between-line-and-point.hpp"
#include "is-intersect.hpp"
#include "projection.hpp"
#include "unit-vector.hpp"

namespace geometry {
    // 直線s, tの交点の計算
    inline Point crossPoint(const Line &s, const Line &t) {
        D d1 = cross(s.b - s.a, t.b - t.a);
        D d2 = cross(s.b - s.a, s.b - t.a);
        if(equal(std::abs(d1), 0) && equal(std::abs(d2), 0)) return t.a;
        return t.a + (t.b - t.a) * (d2 / d1);
    }

    // 線分s, tの交点の計算
    inline Point crossPoint(const Segment &s, const Segment &t) {
        return crossPoint(Line(s), Line(t));
    }

    // 2つの円の交点
    inline std::vector<Point> crossPoint(const Circle &c1, const Circle &c2) {
        std::vector<Point> res;
        int mode = isIntersect(c1, c2);
        // 2つの中心の距離
        D d = std::abs(c1.p - c2.p);
        // 2円が離れている場合
        if(mode == 4) return res;
        // 1つの円がもう1つの円に内包されている場合
        if(mode == 0) return res;
        // 2円が外接する場合
        if(mode == 3) {
            D t = c1.r / (c1.r + c2.r);
            res.emplace_back(c1.p + (c2.p - c1.p) * t);
            return res;
        }
        // 内接している場合
        if(mode == 1) {
            if(c2.r < c1.r - EPS) {
                res.emplace_back(c1.p + (c2.p - c1.p) * (c1.r / d));
            } else {
                res.emplace_back(c2.p + (c1.p - c2.p) * (c2.r / d));
            }
            return res;
        }
        // 2円が重なる場合
        D rc1 = (c1.r * c1.r + d * d - c2.r * c2.r) / (2 * d);
        D rs1 = std::sqrt(c1.r * c1.r - rc1 * rc1);
        if(c1.r - std::abs(rc1) < EPS) rs1 = 0;
        Point e12 = (c2.p - c1.p) / std::abs(c2.p - c1.p);
        res.emplace_back(c1.p + rc1 * e12 + rs1 * e12 * Point(0, 1));
        res.emplace_back(c1.p + rc1 * e12 + rs1 * e12 * Point(0, -1));
        return res;
    }

    // 円cと直線lの交点
    inline std::vector<Point> crossPoint(const Circle &c, const Line &l) {
        std::vector<Point> res;
        D d = distanceBetweenLineAndPoint(l, c.p);
        // 交点を持たない
        if(d > c.r + EPS) return res;
        // 接する
        Point h = projection(l, c.p);
        if(equal(d, c.r)) {
            res.emplace_back(h);
            return res;
        }
        Point e = unitVector(l.b - l.a);
        D ph = std::sqrt(c.r * c.r - d * d);
        res.emplace_back(h - e * ph);
        res.emplace_back(h + e * ph);
        return res;
    }
} // namespace geometry
