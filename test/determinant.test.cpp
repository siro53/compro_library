#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"
#include "../template/template.cpp"
#include "../math/modint.hpp"
#include "../math/matrix.hpp"

using mint = ModInt<998244353>;

int main(){
    int n;
    cin >> n;
    Matrix<mint> mat(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    cout << mat.determinant() << endl;  
}