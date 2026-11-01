#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../misc/rle.hpp"
#include "../../../string/z-algo.hpp"

void regression_test() {
    assert(z_algo("").empty());
    assert(z_algo("aaaa") == vector<int>({4, 3, 2, 1}));
    assert(runlength_encoding(string()).empty());
    assert(runlength_encoding(vector<int>()).empty());
    auto rle = runlength_encoding(string("aab"));
    assert(rle == (vector<pair<char, int>>{{'a', 2}, {'b', 1}}));
}

int main() {
    regression_test();
    INT(a, b);
    print(a + b);
}
