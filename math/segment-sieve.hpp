#pragma once

#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>

class SegmentSieve {
  public:
    explicit SegmentSieve(long long L, long long R)
        : L(L), R(R), sq(std::sqrt(R) + 1) {
        small.assign(sq, true);
        large.assign(R - L, true);
        for(long long i = 2; i * i < R; i++) {
            if(!small[i]) continue;
            for(long long j = i * i; j < R; j += i) small[j] = false;
            long long start = std::max((L + i - 1) / i, i * 2);
            for(long long j = start; j < R; j += i) large[j - L] = false;
        }
    }
    bool operator[](long long k) const { return large[k - L]; }

  private:
    long long L, R;
    int sq;
    std::vector<bool> small, large;
};