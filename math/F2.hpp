#pragma once

#include <bitset>
#include <cassert>
#include <utility>
#include <vector>

template<int MAX_WIDTH>
class BitMatrix {
public:
    int H, W;

    BitMatrix(): H(1), W(1), mat(1) {
        assert(W <= MAX_WIDTH);
    }

    BitMatrix(int H, int W): H(H), W(W), mat(H) {
        assert(W <= MAX_WIDTH);
    }

    inline std::bitset<MAX_WIDTH>& operator[](int i) { return mat[i]; }

    // 掃き出し法
    // https://drken1215.hatenablog.com/entry/2019/03/20/202800
    int row_reduction(vector<int>& b) {
        assert((int)b.size() == H);
        int rank = 0;
        for(int j = 0; j < W; j++) {
            int pivot = -1;
            for(int i = rank; i < H; i++) {
                if(mat[i][j]) {
                    pivot = i;
                    break;
                }
            }
            if(pivot == -1) continue;
            std::swap(mat[pivot], mat[rank]);
            std::swap(b[pivot], b[rank]);
            for(int i = 0; i < H; i++) {
                if(i != rank and mat[i][j]) {
                    mat[i] ^= mat[rank];
                    b[i] ^= b[rank];
                }
            }
            rank++;
        }
        return rank;
    }

    // 掃き出し法
    // https://drken1215.hatenablog.com/entry/2019/03/20/202800
    int row_reduction() {
        std::vector<int> b(H, 0);
        return row_reduction(b);
    }

private:
    std::vector<std::bitset<MAX_WIDTH>> mat;
};

// {rank, Ax = bの解のうち1つ} を返す
// 解なしの場合は {-1, {}} を返す
template<int MAX_WIDTH>
std::pair<int, std::vector<int>> linear_equation_F2(BitMatrix<MAX_WIDTH> A, std::vector<int> b) {
    int H = A.H, W = A.W;
    int rank = A.row_reduction(b);
    // 解の存在チェック
    for(int i = rank; i < H; i++) if(b[i]) {
        return {-1, {}};
    }
    std::vector<int> ret(W);
    for(int i = 0; i < rank; i++) {
        int p = -1;
        for(int j = 0; j < W; j++) {
            if(A[i][j]) {
                p = j;
                break;
            }
        }
        if(p == -1) continue;
        ret[p] = b[i];
    }
    return {rank, ret};
}