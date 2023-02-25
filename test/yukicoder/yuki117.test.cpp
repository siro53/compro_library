#define PROBLEM "https://yukicoder.me/problems/no/117"
#include <bits/stdc++.h>
using namespace std;
#include "../../modint/modint.hpp"
#include "../../math/binom.hpp"

using mint = ModInt<1000000007>;

int main() {
    int T;
    scanf("%d\n", &T);
    Binomial<mint> binom;
    while(T--) {
        char t;
        int N, K;
        scanf("%c(%d,%d)\n", &t, &N, &K);
        if(t == 'C') {
            printf("%u\n", binom.binom(N, K).val());
        } else if(t == 'P') {
            printf("%u\n", binom.perm(N, K).val());
        } else if(t == 'H') {
            printf("%u\n", binom.hom(N, K).val());
        }
    }
}