#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include "../../../math/two_sat.hpp"
#include "../../../template/template.cpp"


int main() {
    string tmp;
    cin >> tmp;
    cin >> tmp;
    int N, M;
    cin >> N >> M;

    TwoSat ts(N);

    REP(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        ts.add_clause(abs(a) - 1, a > 0, abs(b) - 1, b > 0);
    }

    if(!ts.satisfiable()) {
        cout << "s UNSATISFIABLE\n";
        return 0;
    }

    auto ans = ts.get_answer();

    cout << "s SATISFIABLE\n";
    cout << "v ";
    REP(i, N) cout << (ans[i] ? 1 : -1) * (i + 1) << ' ';
    cout << 0 << '\n';
}