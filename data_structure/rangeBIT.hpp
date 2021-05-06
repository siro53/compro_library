#include "./BIT.hpp"

template<class T>
struct rangeBIT {
    BIT<T> p, q;
    rangeBIT(){}
    rangeBIT(int n): p(n+1), q(n+1) {}
    void add(int l, int r, T val) { // [l, r)にvalを加算
        p.add(l, -val * l);
        p.add(r, val * r);
        q.add(l, val);
        q.add(r, -val);
    }
    void add(int i, T val) {
        add(i, i+1, val);
    }
    T sum(int r) { // [0, r)
        return p.sum(r) + q.sum(r) * r;
    }
    T sum(int l, int r) { // [l, r)
        assert(l <= r);
        return sum(r) - sum(l);
    }
};