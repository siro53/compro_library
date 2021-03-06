#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=jp"
#include "../compro_library/template/template.cpp"
#include "../compro_library/math/eratosthenes.hpp"

int main() {
    int t; cin >> t;

    auto isp = eratosthenes(100000000);
    int ans = 0;

    while(t--) {
        int n; cin >> n;
        ans += isp[n];
    }

    cout << ans << endl;
}