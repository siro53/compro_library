#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../../template/template.cpp"
#include "../../../../random/gen/all.hpp"

// 生成器と同じ書き方で、各ヘッダの関数がまとめて使えることを確かめる
int main() {
    char prog[] = "gen", seed[] = "123";
    char *argv[] = {prog, seed, nullptr};
    Random rng(2, argv), again(123);
    int n = rng.size(2, 9);
    auto a = random_vector(rng, n, 1, 10);
    auto p = random_permutation(rng, n);
    string s = random_lowercase(rng, n, 3);
    auto t = random_tree(rng, n);
    auto g = random_connected_graph(rng, n, n - 1);
    // 同じ seed なら同じ順序で呼べば同じ結果になる
    assert(again.size(2, 9) == n);
    assert(random_vector(again, n, 1, 10) == a);
    assert(random_permutation(again, n) == p);
    assert(random_lowercase(again, n, 3) == s);
    assert(random_tree(again, n) == t);
    assert(random_connected_graph(again, n, n - 1) == g);
    INT(x, y);
    print(x + y);
}
