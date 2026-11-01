#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../misc/mo.hpp"
#include "../../../misc/fraction.hpp"

void regression_test() {
    for(int a = -5; a <= 5; a++) if(a) for(int b = 1; b <= 5; b++) {
        Fraction<> f(a, b); f /= f; assert(f == Fraction<>(1));
    }
    Mo mo(20);
    vector<pair<int, int>> queries{{4, 5}, {1, 3}, {15, 18}, {0, 20}, {7, 8}, {3, 16}};
    for(auto [l, r] : queries) mo.insert(l, r);
    mo.build();
    deque<int> active;
    auto al = [&](int i) { if(!active.empty()) assert(i + 1 == active.front()); active.push_front(i); };
    auto ar = [&](int i) { if(!active.empty()) assert(i == active.back() + 1); active.push_back(i); };
    auto dl = [&](int i) { assert(!active.empty() && active.front() == i); active.pop_front(); };
    auto dr = [&](int i) { assert(!active.empty() && active.back() == i); active.pop_back(); };
    for(int q; (q = mo.process(al, ar, dl, dr)) != -1;) {
        auto [l, r] = queries[q];
        assert((int)active.size() == r - l);
        for(int i = l; i < r; i++) assert(active[i - l] == i);
    }
}

int main() {
    regression_test();
    INT(a, b);
    print(a + b);
}
