#pragma once

#include <cassert>
#include <vector>

#include "compact-bitvector.hpp"

template <typename T, int BITLEN = 31> 
class WaveletMatrix {
public:
    explicit WaveletMatrix() = default;
    explicit WaveletMatrix(vector<int> v): N((int)v.size()), B(BITLEN, CompactBitVector(N)), zero_num(BITLEN, 0) {
        for(int k = BITLEN - 1; k >= 0; k--) {
            std::vector<T> zeros, ones;
            for(int i = 0; i < N; i++) {
                if(v[i] >> k & 1) {
                    ones.emplace_back(v[i]);
                    B[k].set(i, 1);
                } else {
                    zeros.emplace_back(v[i]);
                }
            }
            B[k].build();
            zero_num[k] = (int)zeros.size();
            for(int i = 0; i < N; i++) {
                if(i < (int)zeros.size()) v[i] = zeros[i];
                else v[i] = ones[i - (int)zeros.size()];
            }
        }
    }
    T access(int pos) const {
        T res = 0; 
        for(int k = BITLEN - 1; k >= 0; k--) {
            int b = B[k][pos];
            res |= (T(b) << k);
            pos = B[k].rank(pos, b) + zero_num[k] * b;
        }
        return res;
    }
    // [0, i) の範囲内に値 x が何個出現したか. O(log(σ))
    int rank(int i, T x) {
        int l = 0, r = i;
        for(int k = BITLEN - 1; k >= 0; k--) {
            int b = (x >> k & 1);
            l = B[k].rank(l, b) + zero_num[k] * b;
            r = B[k].rank(r, b) + zero_num[k] * b;
        }
        return (r - l);
    };
    // 左から i 個目の値 x の index. O(log(N)log(σ))
    int select(int i, T x) {
        int pos = 0;
        for(int k = BITLEN - 1; k >= 0; k--) {
            int b = (x >> k) & 1;
            pos = B[k].rank(pos, b) + zero_num[k] * b;
        }
        pos += i;
        for(int k = 0; k < BITLEN; k++) {
            if(x >> k & 1) {
                pos = B[k].select(pos - zero_num[k], 1);
            } else {
                pos = B[k].select(pos, 0);
            }
        }
        return pos;
    }
    // [l, r) の中で i 番目に小さい値を返す (i は 0-indexed)
    T quantile(int l, int r, int i) {
        assert(0 <= i and i < r - l);
        T res = 0;
        for(int k = BITLEN - 1; k >= 0; k--) {
            int zero_cnt = B[k].rank(r, 0) - B[k].rank(l, 0);
            int b = (zero_cnt <= i);
            if(b) {
                res |= (T(1) << k);
                i -= zero_cnt;
            }
            l = B[k].rank(l, b) + zero_num[k] * b;
            r = B[k].rank(r, b) + zero_num[k] * b;
        }
        return res;
    }
    // [l, r) の中で x < xr を満たす x の個数の総和を返す
    int rangefreq(int l, int r, T xr) {
        int res = 0;
        for(int k = BITLEN - 1; k >= 0; k--) {
            int b = (xr >> k & 1);
            if(b) res += B[k].rank(r, 0) - B[k].rank(l, 0);
            l = B[k].rank(l, b) + zero_num[k] * b;
            r = B[k].rank(r, b) + zero_num[k] * b;
        }
        return res;
    }
    // [l, r) の中で xl <= x < xr を満たす x の個数の総和を返す
    int rangefreq(int l, int r, T xl, T xr) {
        return (rangefreq(l, r, xr) - rangefreq(l, r, xl));
    }
    // [l, r) の中で x < xr を満たす x のうち最大値を返す
    // そのような x が存在しないならば -1 を返す
    T prev_value(int l, int r, T xr) {
        int num = rangefreq(l, r, xr);
        return (num == 0 ? -1 : quantile(l, r, num - 1));
    }
    // [l, r) の中で xl <= x を満たす x のうち最小値を返す
    // そのような x が存在しないならば -1 を返す
    T next_value(int l, int r, T xl) {
        int num = rangefreq(l, r, xl);
        return (num == r - l ? -1 : quantile(l, r, num));
    }
    T operator[](const int i) const { return access(i); }
private:
    int N;
    std::vector<CompactBitVector> B;
    std::vector<int> zero_num;
};