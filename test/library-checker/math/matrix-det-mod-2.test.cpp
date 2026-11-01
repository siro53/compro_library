#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det_mod_2"
#include "../../../template/template.cpp"
#include "../../../math/F2.hpp"

int main() {
    INT(N);
    BitMatrix<4096> a(N, N);
    REP(i, N) {
        STRING(row);
        REP(j, N) a[i][j] = row[j] == '1';
    }
    // Over F_2, the determinant is 1 exactly when the matrix has full rank.
    print(a.row_reduction() == N ? 1 : 0);
}
