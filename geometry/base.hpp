#pragma once

#include <cmath>
#include <complex>

namespace geometry {
    // Point : 複素数型を位置ベクトルとして扱う
    // 実軸(real)をx軸、挙軸(imag)をy軸として見る
    using D = long double;
    using Point = std::complex<D>;
    const D EPS = 1e-7;
    const D PI = std::acos(D(-1));

    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS; }
} // namespace geometry
