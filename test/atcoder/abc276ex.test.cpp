#define PROBLEM "https://atcoder.jp/contests/abc276/tasks/abc276_h"
#include "../../template/template.cpp"
#include "../../data-structure/imos2D.hpp"
#include "../../data-structure/sum2D.hpp"
#include "../../math/F2.hpp"

using Query = tuple<int, int, int, int, int>;
const int MAX_H = 2048;
const int MAX_W = MAX_H * 4;

int main() {
    map<pair<int, int>, int> ID;
    vector<pair<int, int>> rev;
    auto f = [&](int i, int j) -> int {
        if(ID.count({i, j})) return ID[{i, j}];
        int ret = SZ(ID);
        ID[{i, j}] = ret;
        rev.emplace_back(i, j);
        return ret;
    };

    INT(N, Q);
    vector<Query> qs(Q);
    int eq_num = 0;
    for(auto& [a, b, c, d, e] : qs) {
        cin >> a >> b >> c >> d >> e;
        a--;
        c--;
        if(e == 0) continue;
        f(a, c);
        f(a, d);
        f(b, c);
        f(b, d);
        eq_num++;
    }

    int sz = SZ(ID);
    BitMatrix<MAX_W> mat(eq_num, sz);
    vector<int> res(eq_num, 0);
    {
        int i = 0;
        for(auto& [a, b, c, d, e] : qs) {
            if(e == 0) continue;
            for(int ii : {a, b}) {
                for(int jj : {c, d}) {
                    mat[i][f(ii, jj)] = 1;
                }
            }
            res[i] = (e == 2 ? 1 : 0);
            i++;
        }
    }
    auto [rank, answer] = linear_equation_F2<MAX_W>(mat, res);
    if(rank == -1) {
        print("No");
        return 0;
    }

    auto out = make_vector<int>({N, N}, 0);
    {
        auto tmp = make_vector<int>({N + 1, N + 1}, 0);
        REP(i, sz) {
            auto [ii, jj] = rev[i];
            tmp[ii][jj] = answer[i];
        }
        REP(i, N) REP(j, N) {
            out[i][j] = (tmp[i + 1][j + 1] ^ tmp[i][j + 1] ^ tmp[i + 1][j] ^ tmp[i][j]) + 1;
        }
    }
    {
        imos2D<int> imos(N, N);
        for(const auto& [a, b, c, d, e] : qs) {
            if(e == 0) continue;
            imos.add(a, c, b, d, 1);
        }
        imos.build();
        sum2D<int> sum(N, N);
        REP(i, N) REP(j, N) {
            if(imos[i][j] == 0) {
                out[i][j] = 0;
                sum.add(i, j, 1);
            }
        }
        sum.build();
        for(auto& [a, b, c, d, e] : qs) {
            if(e == 0 and sum.get_sum(a, b, c, d) == 0) {
                print("No");
                return 0;
            }
        }
    }
    print("Yes");
    REP(i, N) print(out[i]);
}