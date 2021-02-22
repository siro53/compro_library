#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include "../template/template.cpp"
#include "../graph/two_sat.hpp"

string tmp;

int main() {
    cin >> tmp; cin >> tmp;
    int N, M; cin >> N >> M;

    two_sat ts(N);

    REP(i, M) {
        int a, b, c; cin >> a >> b >> c;
        ts.add_clause(abs(a)-1, a>0, abs(b)-1, b>0);
    }

    if(!ts.satisfiable()) {
        cout << "s UNSATISFIABLE\n";
        return 0;
    }

    auto ans = ts.answer();

    cout << "s SATISFIABLE\n";
    cout << "v ";
    REP(i, N) cout << (ans[i] ? 1 : -1) * (i + 1) << " ";
    cout << 0 << "\n";
}