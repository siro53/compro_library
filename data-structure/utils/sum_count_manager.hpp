#pragma once

#include <cassert>
#include <vector>

#include "../../misc/compress.hpp"
#include "../segtree/segtree.hpp"
#include "../monoid/sum_count.hpp"

template<typename T>
struct SumCountManager {
    using S = typename MonoidSumCount<T, int>::S;
    Segtree<MonoidSumCount<T, int>> seg;
    Compress<T> comp;

    SumCountManager() = default;
    SumCountManager(std::vector<T> xs) {
        comp = Compress<T>(xs);
        seg = Segtree<MonoidSumCount<T, int>>((int)comp.size());
    }

    void add(T val) {
        int pos = comp.get(val);
        assert(pos < (int)comp.size() && comp[pos] == val);
        auto x = seg.get(pos);
        seg.set(pos, S(x.sum + val, x.cnt + 1));
    }

    int get(T val) const {
        return comp.get(val);
    }
};