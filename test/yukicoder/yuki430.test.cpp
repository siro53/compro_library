#define PROBLEM "https://yukicoder.me/problems/no/430"
#include "../../template/template.cpp"
#include "../../string/rolling-hash.hpp"

int main() {
    STRING(S);
    int N = SZ(S);
    debug(N);
    auto base = RollingHash::gen_base();
    RollingHash rh(S, base);
    map<RollingHash::u64, int> mp;
    REP(len, 1, 10 + 1) REP(i, N - len + 1) mp[rh.get(i, i + len).val()] += 1;
    INT(M);
    ll ans = 0;
    REP(_, M) {
        STRING(T);
        RollingHash r(T, base);
        ans += mp[r.get(0, SZ(T)).val()];
    }
    print(ans);
}