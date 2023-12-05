#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"
#include "../../../template/template.cpp"

#include "../../../math/is-prime.hpp"

int main() {
    INT(Q);
    while(Q--) {
        LL(n);
        print(is_prime(n) ? "Yes" : "No");
    }
}