#pragma once

#include <algorithm>

#include "distance-between-segment-and-point.hpp"
#include "is-intersect.hpp"

namespace geometry {
    // 線分sとtの距離
    inline D distanceBetweenSegments(const Segment &s, const Segment &t) {
        if(isIntersect(s, t, 1)) return (D)(0);
        D ans = distanceBetweenSegmentAndPoint(s, t.a);
        ans = std::min(ans, distanceBetweenSegmentAndPoint(s, t.b));
        ans = std::min(ans, distanceBetweenSegmentAndPoint(t, s.a));
        ans = std::min(ans, distanceBetweenSegmentAndPoint(t, s.b));
        return ans;
    }
} // namespace geometry
