#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=jp"
#include "../../template/template.cpp"
#include "../../math/eratosthenes.hpp"

int main() {
    INT(t);
    Eratosthenes isp(100000000);
    int ans = 0;
    while(t--) {
        INT(n);
        ans += isp[n];
    }
    print(ans);
}