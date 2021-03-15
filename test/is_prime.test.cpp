#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=jp"
#include "../template/template.cpp"
#include "../math/is_prime.hpp"

int main() {
    int t; cin >> t;
    int ans = 0;
    while(t--) {
        int n; 
        cin >> n;
        ans += is_prime(n);
    }
    cout << ans << endl;
}