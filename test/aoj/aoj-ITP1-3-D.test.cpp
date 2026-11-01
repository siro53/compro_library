#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D"
#include "../../template/template.cpp"
#include "../../math/divisor.hpp"

int main() {
    INT(a, b, c);
    auto divisors = divisor(c);
    print(int(upper_bound(divisors.begin(), divisors.end(), b)
              - lower_bound(divisors.begin(), divisors.end(), a)));
}
