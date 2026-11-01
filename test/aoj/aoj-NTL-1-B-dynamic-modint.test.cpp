#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"
#include "../../template/template.cpp"
#include "../../modint/dynamic-modint.hpp"

int main() {
    LL(m, n);
    DynamicModInt::set_mod(1000000007);
    print(DynamicModInt(m).pow(n));
}
