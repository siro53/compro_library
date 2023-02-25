#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "../../../template/template.cpp"
#include "../../../graph/shortest-path/dijkstra.hpp"

int main() {
    int N, M, s, t;
    cin >> N >> M >> s >> t;
    Graph<ll> G(N);
    REP(_, M) {
        int from, to;
        ll cost;
        cin >> from >> to >> cost;
        G.add_directed_edge(from, to, cost);
    }
    auto [dist, prev] = dijkstra<ll>(G, s, 0, LLINF);
    if(dist[t] == LLINF) {
        cout << "-1\n";
    } else {
        vector<int> path;
        path.push_back(t);
        while(1) {
            int p = prev[path.back()];
            if(p == -1) break;
            path.push_back(p);
        }
        reverse(ALL(path));
        cout << dist[t] << ' ' << SZ(path) - 1 << '\n';
        REP(i, SZ(path) - 1) {
            cout << path[i] << ' ' << path[i+1] << '\n';
        }
    }
}