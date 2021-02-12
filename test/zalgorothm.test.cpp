#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "../template/template.cpp"
#include "../string/z_algo.hpp"

int main(){
    string s;
    cin >> s;
    auto z = z_algo(s);
    for(int i = 0; i < z.size(); i++) {
        cout << z[i] << ' ';
    }
    cout << "\n";
}