#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"
#include "../../../data-structure/BIT.hpp"
#include "../../../misc/compress.hpp"
#include "../../../misc/mo.hpp"
#include "../../../template/template.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    REP(i, N) cin >> a[i];
    Compress<int> comp(a);
    REP(i, N) a[i] = comp.get(a[i]);
    int sz = SZ(comp);
    BIT<ll> bt(sz);
    vector<ll> ans(Q);
    Mo mo(N);
    REP(_, Q) {
        int l, r;
        cin >> l >> r;
        mo.insert(l, r);
    }
    mo.set_bucketsize(N / std::sqrt(Q));
    mo.build();
    ll now_ans = 0;
    const auto add_right = [&](int id) {
        now_ans += bt.sum(a[id] + 1, sz);
        bt.add(a[id], 1);
    };
    const auto add_left = [&](int id) {
        now_ans += bt.sum(a[id]);
        bt.add(a[id], 1);
    };
    const auto del_left = [&](int id) {
        now_ans -= bt.sum(a[id]);
        bt.add(a[id], -1);
    };
    const auto del_right = [&](int id) {
        now_ans -= bt.sum(a[id] + 1, sz);
        bt.add(a[id], -1);
    };
    REP(_, Q) {
        int qid = mo.process<decltype(add_left), decltype(add_right),
                             decltype(del_left), decltype(del_right)>(
            add_left, add_right, del_left, del_right);
        ans[qid] = now_ans;
    }
    REP(i, Q) cout << ans[i] << '\n';
}
