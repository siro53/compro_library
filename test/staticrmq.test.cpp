#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../template/template.cpp"

#include "../data_structure/segtree/segtree.hpp"

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SegmentTree<int> seg(a, INF,
                         [](const int &p, const int &q) { return min(p, q); });
    int l, r;
    while(q--) {
        cin >> l >> r;
        cout << seg.query(l, r) << "\n";
    }
}