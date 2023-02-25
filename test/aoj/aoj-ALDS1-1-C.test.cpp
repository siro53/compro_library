#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=jp"
#include "../../template/template.cpp"
#include "../../math/is-prime.hpp"

int main() {
    int n;
    cin >> n;
    int ans = 0;
    while(n--) {
        int p;
        cin >> p;
        ans += is_prime(p);
    }
    cout << ans << endl;
}