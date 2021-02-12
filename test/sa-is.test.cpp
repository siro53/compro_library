#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include "../template/template.cpp"
#include "../string/sa-is.hpp"

int main() {
    string s;
    cin >> s;
    SA_IS sa(s);
    int n = int(s.size());
    for(int i = 0; i < n; i++) cout << sa[i] << " \n"[i + 1 == n];
}