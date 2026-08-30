#pragma once

#include "base.hpp"

namespace geometry {
    // Line : 直線を表す構造体
    // b - a で直線・線分を表せる
    struct Line {
        Point a, b;
        Line() = default;
        Line(Point a, Point b) : a(a), b(b) {}
        // Ax+By=C
        Line(D A, D B, D C) {
            if(equal(A, 0)) {
                a = Point(0, C / B), b = Point(1, C / B);
            } else if(equal(B, 0)) {
                a = Point(C / A, 0), b = Point(C / A, 1);
            } else if(equal(C, 0)) {
                a = Point(0, C / B), b = Point(1, (C - A) / B);
            } else {
                a = Point(0, C / B), b = Point(C / A, 0);
            }
        }
    };
} // namespace geometry
