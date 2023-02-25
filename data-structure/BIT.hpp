#pragma once

#include <cassert>
#include <vector>

template <typename T> class BIT {
  public:
    BIT() = default;
    explicit BIT(int N) : N(N), dat(N + 1, 0) {}
    T sum(int r) {
        T ret = 0;
        for(; r >= 1; r -= lsb(r)) ret += dat[r];
        return ret;
    }
    T sum(int l, int r) {
        assert(l <= r);
        if(l == r) return T(0);
        return (sum(r) - sum(l));
    }
    void add(int pos, T val) {
        for(int i = pos + 1; i <= N; i += lsb(i)) dat[i] += val;
    }
    int lower_bound(T val) {
        int pos = 0;
        int k = 1;
        while(2 * k <= N) k <<= 1;
        for(; k >= 1; k >>= 1) {
            if(pos + k <= N and dat[pos + k] < val) {
                pos += k;
                val -= dat[pos];
            }
        }
        return pos + 1;
    }

  private:
    int N;
    std::vector<T> dat;

    inline int lsb(int i) { return i & (-i); }
};