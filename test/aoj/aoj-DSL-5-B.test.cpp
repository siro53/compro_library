#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B"
#include "../../template/template.cpp"
#include "../../data-structure/imos2D.hpp"

int main() {
    INT(N);
    constexpr int width = 1000;
    imos2D<int> imos(width, width);
    REP(i, N) {
        INT(x1, y1, x2, y2);
        imos.add(x1, y1, x2, y2, 1);
    }
    imos.build();
    int answer = 0;
    REP(x, width) REP(y, width) chmax(answer, imos[x][y]);
    print(answer);
}
