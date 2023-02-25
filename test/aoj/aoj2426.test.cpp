#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2426"
#include "../../template/template.cpp"
#include "../../data-structure/sum2D.hpp"
#include "../../misc/compress.hpp"

using P = pair<int, int>;
int N, M;
P treasure[5001];
vector<int> xs, ys;

int main() {
    cin >> N >> M;

    REP(i, N) {
        int x, y;
        cin >> x >> y;
        xs.push_back(x);
        ys.push_back(y);
        treasure[i] = P(x, y);
    }

    // 宝の位置を座圧
    Compress<int> cx(xs), cy(ys);
    int xlen = cx.size();
    int ylen = cy.size();

    sum2D<int> sum2d(xlen + 1, ylen + 1);

    // 二次元累積和
    REP(i, N) {
        auto [x, y] = treasure[i];
        sum2d.add(cx.get(x), cy.get(y), 1);
    }

    sum2d.build();

    REP(_, M) {
        int x1, y1;
        int x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sx = cx.get(x1);
        int sy = cy.get(y1);
        int gx = cx.get(x2);
        if(gx < xlen && cx[gx] == x2) gx++;
        int gy = cy.get(y2);
        if(gy < ylen && cy[gy] == y2) gy++;

        cout << sum2d.get_sum(sx, gx, sy, gy) << '\n';
    }
}