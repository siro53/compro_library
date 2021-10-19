#define PROBLEM "https://yukicoder.me/problems/no/1333"
#include "../compro_library/template/template.cpp"

#include "../compro_library/math/modint.hpp"
using mint = ModInt<MOD>;
#include "../compro_library/graph/re_rooting.hpp"

using S = tuple<mint, mint, mint>;
using Cost = mint;

S op(S x, Edge<Cost> e) {
    auto [s2, d, sz] = x;
    return S(d*2*e.cost + s2 + e.cost*e.cost*(sz+1), d+e.cost*(sz+1), sz+1);
}
S merge(S x, S y) {
    auto [s2x, dx, szx] = x;
    auto [s2y, dy, szy] = y;
    return S(s2x + s2y, dx + dy, szx + szy);
}
S op2(S x, int id) {
    return x;
}
S e() { return {0, 0, 0}; }

int main() {
    int N;
    cin >> N;
    re_rooting_edge<S, Cost, op, merge, op2, e> re(N);
    REP(i, N-1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        re.add_edge(u, v, w);
    }
    auto dp = re.solve();
    mint ans = 0;
    REP(i, N) ans += get<0>(dp[i]);
    ans /= 2;
    cout << ans << endl;
}