#define PROBLEM "https://yukicoder.me/problems/no/1750"
#include "../../template/template.cpp"
#include "../../modint/modint.hpp"
#include "../../math/matrix.hpp"

using mint = ModInt<MOD2>;
using matrix = Matrix<mint>;

int main() {
    int N, M;
    ll T;
    cin >> N >> M >> T;
    matrix G(N);
    REP(_, M) {
        int a, b;
        cin >> a >> b;
        G[a][b] = G[b][a] = 1;
    }
    matrix init(N, 1);
    init[0][0] = mint(1);
    auto res = G.pow(T) * init;
    cout << res[0][0] << endl;
}