#define PROBLEM "https://yukicoder.me/problems/no/430"
#include "../../string/rolling-hash.hpp"
#include "../../template/template.cpp"

int main() {
    INT(N);
    VEC(S, string, N);
    set<RollingHash::u64> se;
    auto base = RollingHash::gen_base();
    REP(i, N) {
        RollingHash rh(S[i], base);
        int M = SZ(S[i]);
        auto h = rh.get(0, M);
        bool ok = se.count(h.val());
        if(!ok) {
            REP(j, M - 1) {
                auto t = h - rh.power[M - 1 - j] * S[i][j] -
                         rh.power[M - 1 - (j + 1)] * S[i][j + 1];
                t += rh.power[M - 1 - j] * S[i][j + 1] +
                     rh.power[M - 1 - (j + 1)] * S[i][j];
                if(se.count(t.val())) {
                    ok = true;
                    break;
                }
            }
        }
        print(ok ? "Yes" : "No");
        se.emplace(h.val());
    }
}