#pragma once

#include <algorithm>
#include <cassert>
#include <cmath>
#include <numeric>
#include <vector>

class SegmentFactorize {
public:
    explicit SegmentFactorize(long long L, long long R): L(L), R(R), sq(std::sqrt(R) + 1) {
        small.resize(sq);
        std::iota(small.begin(), small.end(), 0);
        large.resize(R - L);
        large_mul.assign(R - L, 1);
        for(long long i = 2; i * i < R; i++) {
            if(small[i] < i) continue;
            for(long long j = i * i; j < sq; j += i) {
                if(small[j] == j) small[j] = i;
            }
            for(long long j = (L + i - 1) / i * i; j < R; j += i) {
                long long now = j;
                do {
                    if(large_mul[j - L] * large_mul[j - L] > R) break;
                    large[j - L].push_back(i);
                    large_mul[j - L] *= i;
                    now /= i;
                } while(now % i == 0);
            }
        }
    } 
    std::vector<long long> factor(long long n) {
        assert(L <= n and n < R);
        std::vector<long long> ret = large[n - L];
        n /= large_mul[n - L];
        if(n >= sq) {
            ret.push_back(n);
            return ret;
        }
        while(n > 1) {
            ret.push_back(small[n]);
            n /= small[n];
        }
        return ret;
    }

private:
    long long L, R;
    int sq;
    std::vector<int> small;
    std::vector<std::vector<long long>> large;
    std::vector<long long> large_mul;
};