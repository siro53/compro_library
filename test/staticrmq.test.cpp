#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../template/template.cpp"
#include "../data_structure/disjoint_sparse_table.hpp"

int op(int a, int b) { return min(a, b); }
int e() { return INF; }

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    DisjointSparseTable<int, op, e> dst(a);
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << dst.prod(l, r) << '\n';
    }
}