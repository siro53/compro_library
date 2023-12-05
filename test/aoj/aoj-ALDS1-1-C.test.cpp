#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=jp"
#include "../../template/template.cpp"
#include "../../math/is-prime.hpp"

int main() {
    INT(n);
    int ans = 0;
    while(n--) {
        INT(p);
        ans += is_prime(p);
    }
    print(ans);
}