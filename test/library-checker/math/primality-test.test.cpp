#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"
#include <bits/stdc++.h>
using namespace std;

#include "../../../math/is-prime.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while(Q--) {
        long long n;
        cin >> n;
        cout << (is_prime(n) ? "Yes" : "No") << '\n';
    }
}