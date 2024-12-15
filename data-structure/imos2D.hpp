#pragma once

#include <cassert>
#include <vector>

// verify: https://atcoder.jp/contests/abc276/submissions/60797388

template <typename T> 
class imos2D {
public:
    int H, W;

    imos2D() = default;
    explicit imos2D(int H, int W): H(H), W(W), imos(H + 1, std::vector<T>(W + 1, 0)), isBuilt(false) {}

    void add(int li, int lj, int ri, int rj, T val) {
        assert(0 <= li and li < H);
        assert(li <= ri and ri <= H);
        assert(0 <= lj and lj < W);
        assert(lj <= rj and rj <= W);
        imos[li][lj] += val;
        imos[li][rj] -= val;
        imos[ri][lj] -= val;
        imos[ri][rj] += val;
    } 

    void build() {
        for(int i = 0; i <= H; i++) {
            for(int j = 1; j <= W; j++) {
                imos[i][j] += imos[i][j - 1];
            }
        }
        for(int j = 0; j <= W; j++) {
            for(int i = 1; i <= H; i++) {
                imos[i][j] += imos[i - 1][j];
            }
        }
        isBuilt = true;
    }

    inline std::vector<T>& operator[](int i) {
        assert(isBuilt);
        return imos[i];
    }

private:
    std::vector<std::vector<T>> imos;
    bool isBuilt;
};