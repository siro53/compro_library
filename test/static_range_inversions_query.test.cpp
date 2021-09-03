#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include "../template/template.cpp"
#include "../data_structure/mo.hpp"
#include "../data_structure/compress.hpp"
#include "../data_structure/BIT.hpp"

int N, Q;
vector<int> a;
vector<ll> ans;
Compress<int> comp;
BIT<int> bt(1);
ll now_ans;

void Mo::add_right(int id) {
    int p = a[id];
    now_ans += bt.sum(p+1, comp.size());
    bt.add(p, 1);
}

void Mo::add_left(int id) {
    int p = a[id];
    now_ans += bt.sum(0, p);
    bt.add(p, 1);
}

void Mo::del_left(int id) {
    int p = a[id];
    now_ans -= bt.sum(0, p);
    bt.add(p, -1);
}

void Mo::del_right(int id) {
    int p = a[id];
    now_ans -= bt.sum(p+1, comp.size());
    bt.add(p, -1);
}

int main() {
    cin >> N >> Q;
    a.resize(N);
    REP(i, N) cin >> a[i];
    comp = Compress<int>(a);
    REP(i, N) a[i] = comp.get(a[i]);
    bt.init(comp.size());

    ans.resize(Q);
    Mo mo(N);
    REP(_, Q) {
        int l, r;
        cin >> l >> r;
        mo.insert(l, r);
    }
    mo.build();
    now_ans = 0;
    REP(i, Q) {
        int qid = mo.process();
        ans[qid] = now_ans;
    }

    REP(i, Q) cout << ans[i] << "\n";
}