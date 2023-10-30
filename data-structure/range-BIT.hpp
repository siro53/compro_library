#pragma once

#include "BIT.hpp"

template <typename T> class RangeBIT {
  public:
    RangeBIT() = default;
    explicit RangeBIT(int N) : bt1(N + 1), bt2(N + 1){};
    void add(int l, int r, T val) {
        bt1.add(l, -val * l);
        bt1.add(r, val * r);
        bt2.add(l, val);
        bt2.add(r, -val);
    }
    void add(int pos, T val) { add(pos, pos + 1, val); }
    T sum(int r) { return bt1.sum(r) + bt2.sum(r) * r; }
    T sum(int l, int r) {
        assert(l <= r);
        if(l == r) return T(0);
        return (sum(r) - sum(l));
    }

  private:
    BIT<T> bt1, bt2;
};