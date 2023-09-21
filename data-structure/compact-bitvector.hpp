#pragma once

#include <cassert>
#include <vector>

class CompactBitVector {
  private:
    using u32 = unsigned int;
    using u64 = unsigned long long;

  public:
    explicit CompactBitVector() = default;
    explicit CompactBitVector(int n) : N(n), sz((N + 63) >> 6) {
        bv.assign(sz, 0);
        sum.assign(sz + 1, 0);
    }
    inline void set(int i, int b) {
        if(b) bv[i >> 6] |= (1ULL << (i & 63));
        else bv[i >> 6] &= ~(1ULL << (i & 63));
    }
    inline int access(int i) const { return (bv[i >> 6] >> (i & 63) & 1); }
    void build() {
        sum[0] = 0U;
        for(int i = 0; i < sz; i++) sum[i + 1] = sum[i] + (u32)__builtin_popcountll(bv[i]);
    }
    // [0, i)
    u32 rank(int i, int b) const {
        assert(i >= 0);
        u32 res = sum[i >> 6] + __builtin_popcountll(bv[i >> 6] & ((1ULL << (i & 63)) - 1));
        if(b == 0) res = i - res;
        return res;
    }
    int select(int i, int b) const {
        if(b and sum.back() > i) return -1;
        if(!b and N - sum.back() > i) return -1;
        int ok = N, ng = -1;
        while(ok - ng > 1) {
            int mid = (ok + ng) / 2;
            (rank(i, b) >= mid ? ok : ng) = mid;
        }
        return ok;
    }
    inline int operator[](const int i) const { return access(i); }

  private:
    int N, sz;
    std::vector<u64> bv;
    std::vector<u32> sum;
};