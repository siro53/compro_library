#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_C"
#include "../../template/template.cpp"
#include "../../misc/subset-iterator.hpp"

int main() {
    INT(n, k);
    uint32_t mask = 0;
    REP(i, k) {
        INT(b);
        mask |= uint32_t(1) << b;
    }
    vector<uint32_t> subsets;
    for(auto s : Subset(mask)) subsets.push_back(s);
    // Subset enumerates in descending order; AOJ requires ascending order.
    reverse(subsets.begin(), subsets.end());
    for(auto s : subsets) {
        cout << s << ':';
        for(auto b : SetBit(s)) cout << ' ' << b;
        cout << '\n';
    }
}
