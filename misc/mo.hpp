#pragma once

#include <algorithm>
#include <cassert>
#include <cmath>
#include <numeric>
#include <vector>

class Mo {
  public:
    explicit Mo(int n)
        : n(n), l(0), r(0), idx(0), BUCKET_SIZE(std::sqrt(n)), isBuilt(false) {}
    void insert(int l, int r) {
        assert(0 <= l and l < r and r <= n);
        L.push_back(l);
        R.push_back(r);
    }
    void set_bucketsize(int bs) {
        assert(!isBuilt);
        BUCKET_SIZE = std::max(1, bs);
    }
    void build() {
        ord.resize(L.size());
        std::iota(ord.begin(), ord.end(), 0);
        std::sort(ord.begin(), ord.end(), [&](int a, int b) {
            if(L[a] / BUCKET_SIZE != L[b] / BUCKET_SIZE) {
                return (L[a] < L[b]);
            }
            return (R[a] < R[b]);
        });
        isBuilt = true;
    }
    template <class AddLeft, class AddRight, class DelLeft, class DelRight>
    int process(const AddLeft &add_left, const AddRight &add_right,
                const DelLeft &del_left, const DelRight &del_right) {
        assert(isBuilt);
        if(idx == (int)ord.size()) return -1;
        int qid = ord[idx++];
        while(l > L[qid]) add_left(--l);
        while(l < L[qid]) del_left(l++);
        while(r < R[qid]) add_right(r++);
        while(r > R[qid]) del_right(--r);
        return qid;
    }

  private:
    std::vector<int> L, R, ord;
    int n, l, r, idx;
    int BUCKET_SIZE;
    bool isBuilt;
};