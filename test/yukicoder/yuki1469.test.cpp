#define PROBLEM "https://yukicoder.me/problems/no/1469"
#include "../../template/template.cpp"
#include "../../misc/rle.hpp"

int main() {
    string s;
    cin >> s;
    auto v = runlength_encoding(s);
    for(const auto& [c, _] : v) cout << c;
    cout << endl;
}