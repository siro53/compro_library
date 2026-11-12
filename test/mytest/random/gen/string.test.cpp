#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../../template/template.cpp"
#include "../../../../random/gen/string.hpp"

int main() {
    Random rng(3);
    string s = random_string(rng, 1000, "xyz");
    assert(s.size() == 1000);
    assert(s.find_first_not_of("xyz") == string::npos);
    assert(s.find('x') != string::npos && s.find('y') != string::npos && s.find('z') != string::npos);
    assert(random_string(rng, 0, "").empty());
    assert(random_string(rng, 5, "q") == "qqqqq");
    string t = random_lowercase(rng, 1000, 2);
    assert(t.find_first_not_of("ab") == string::npos && t.find('a') != string::npos && t.find('b') != string::npos);
    string u = random_lowercase(rng, 5000);
    assert(set<char>(u.begin(), u.end()).size() == 26);
    for(char c : u) assert('a' <= c && c <= 'z');
    INT(a, b);
    print(a + b);
}
