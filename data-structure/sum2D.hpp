#pragma once

#include <cassert>
#include <vector>

template <typename T> class sum2D {
  public:
    sum2D() = default;
    explicit sum2D(int height, int width)
        : sum(height + 1, std::vector<T>(width + 1, 0)), isBuilt(false) {}
    void add(int row, int column, T val) {
        assert(0 <= row + 1 && row + 1 < (int)sum.size());
        assert(0 <= column + 1 && column + 1 < (int)sum[0].size());
        sum[row + 1][column + 1] += val;
    }
    void build() {
        for(int i = 1; i < (int)sum.size(); i++) {
            for(int j = 1; j < (int)sum[0].size(); j++) {
                sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
        isBuilt = true;
    }
    T get_sum(int row_l, int row_r, int column_l, int column_r) const {
        assert(row_l <= row_r);
        assert(column_l <= column_r);
        assert(isBuilt);
        return (sum[row_r][column_r] - sum[row_l][column_r] -
                sum[row_r][column_l] + sum[row_l][column_l]);
    }

  private:
    std::vector<std::vector<T>> sum;
    bool isBuilt;
};