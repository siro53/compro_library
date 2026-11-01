#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"
#include "../../template/template.cpp"
#include "../../math/pow_mod.hpp"

int main() {
    LL(m, n);
    print(pow_mod(m, n, 1000000007));
}
