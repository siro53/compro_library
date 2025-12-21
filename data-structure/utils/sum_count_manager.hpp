#pragma once

#include "../../misc/compress.hpp"
#include "../segtree/segtree.hpp"
#include "../monoid/sum_count.hpp"

template<typename T>
struct SumCountManager {
    Segtree<MonoidSumCount<T, int>> seg;
    Compress<T> comp;

    SumCountManager() = default;
    SumCountManager(vector<T> xs) {
        comp = Compress<T>(xs);
        seg = Segtree<MonoidSumCount<T, int>>((int)comp.size());
    }

    void add(T val) {
        int pos = comp.get(val);
        assert(comp[pos] == val);
        auto x = seg.get(pos);
        seg.set(pos, S(x.sum + val, x.cnt + 1));
    }
};