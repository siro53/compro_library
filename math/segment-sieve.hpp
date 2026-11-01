#pragma once

#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>

class SegmentSieve {
  public:
    explicit SegmentSieve(long long L, long long R)
        : L(L), R(R), sq(std::sqrt((long double)R) + 1) {
        assert(0 <= L && L <= R);
        small.assign(sq, true);
        large.assign(R - L, true);
        for(long long n = L; n < R && n < 2; n++) large[n - L] = false;
        for(long long i = 2; i < sq && i <= (R - 1) / i; i++) {
            if(!small[i]) continue;
            for(long long j = i * i; j < sq; j += i) small[j] = false;
            long long first = L / i + (L % i != 0);
            if(first > (R - 1) / i) continue;
            long long start = std::max(first * i, i * i);
            for(long long j = start; j < R;) {
                large[j - L] = false;
                if(R - 1 - j < i) break;
                j += i;
            }
        }
    }
    bool operator[](long long k) const {
        assert(L <= k && k < R);
        return large[k - L];
    }

  private:
    long long L, R;
    long long sq;
    std::vector<bool> small, large;
};
