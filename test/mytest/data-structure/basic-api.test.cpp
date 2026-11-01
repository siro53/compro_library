#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../data-structure/BIT.hpp"
#include "../../../data-structure/sum2D.hpp"
#include "../../../data-structure/unionfind.hpp"
#include "../../../data-structure/erasable-priority-queue.hpp"
#include "../../../data-structure/utils/sum_count_manager.hpp"


int main() {
    BIT<ll> bit; bit = BIT<ll>(8);
    vector<ll> a{0, 2, 0, 5, 1, 0, 3, 0};
    for(int i = 0; i < 8; ++i) bit.add(i, a[i]);
    for(int l = 0; l <= 8; ++l) for(int r = l; r <= 8; ++r) assert(bit.sum(l, r) == accumulate(a.begin() + l, a.begin() + r, 0LL));
    for(int r = 0; r <= 8; ++r) assert(bit.sum(r) == accumulate(a.begin(), a.begin() + r, 0LL));
    for(ll x = 1; x <= 12; ++x) {
        int r = 1; while(r <= 8 && accumulate(a.begin(), a.begin() + r, 0LL) < x) ++r;
        assert(bit.lower_bound(x) == r);
    }
    BIT<ll> empty(0); assert(empty.sum(0) == 0 && empty.sum(0, 0) == 0 && empty.lower_bound(1) == 1);
    sum2D<ll> grid; grid = sum2D<ll>(4, 5);
    for(int i = 0; i < 4; ++i) for(int j = 0; j < 5; ++j) { grid.add(i, j, i - j); grid.add(i, j, 1); }
    grid.build(); const auto& cg = grid;
    for(int l = 0; l <= 4; ++l) for(int r = l; r <= 4; ++r) for(int b = 0; b <= 5; ++b) for(int e = b; e <= 5; ++e) {
        ll expected = 0;
        for(int i = l; i < r; ++i) for(int j = b; j < e; ++j) expected += i - j + 1;
        assert(cg.get_sum(l, r, b, e) == expected);
    }
    sum2D<ll> zero(0, 0); zero.build(); assert(zero.get_sum(0, 0, 0, 0) == 0);
    UnionFind uf; uf = UnionFind(8); vector<int> label(8); iota(label.begin(), label.end(), 0);
    mt19937 rng(63);
    for(int t = 0; t < 30; ++t) {
        int u = rng() % 8, v = rng() % 8, before = label[u], after = label[v];
        assert(uf.merge(u, v) == (before != after));
        for(int& x : label) if(x == before) x = after;
        vector<vector<int>> expected;
        for(int id = 0; id < 8; ++id) {
            vector<int> group; for(int i = 0; i < 8; ++i) if(label[i] == id) group.push_back(i);
            if(!group.empty()) expected.push_back(group);
        }
        auto groups = uf.groups(); sort(groups.begin(), groups.end()); sort(expected.begin(), expected.end());
        assert(groups == expected);
        vector<vector<int>> mapped;
        for(auto [leader, group] : uf.groups_with_map()) {
            for(int x : group) assert(uf.leader(x) == leader);
            mapped.push_back(group);
        }
        sort(mapped.begin(), mapped.end()); assert(mapped == expected);
        for(int i = 0; i < 8; ++i) {
            assert(uf.size(i) == count(label.begin(), label.end(), label[i]));
            for(int j = 0; j < 8; ++j) assert(uf.same(i, j) == (label[i] == label[j]));
        }
    }
    UnionFind none(0); assert(none.groups().empty() && none.groups_with_map().empty());
    ErasablePriorityQueue<int> queue; multiset<int> reference;
    for(int t = 0; t < 500; ++t) {
        if(reference.empty() || rng() % 3 == 0) { int x = rng() % 20; queue.push(x); reference.insert(x); }
        else if(rng() % 2) { auto it = next(reference.begin(), rng() % reference.size()); queue.erase(*it); reference.erase(it); }
        else { assert(queue.top() == *reference.begin()); queue.pop(); reference.erase(reference.begin()); }
        assert(queue.empty() == reference.empty());
        if(!reference.empty()) assert(queue.top() == *reference.begin());
    }
    SumCountManager<ll> manager; manager = SumCountManager<ll>({5, -2, 5, 9});
    const auto& cm = manager;
    assert(cm.get(-3) == 0 && cm.get(0) == 1 && cm.get(10) == 3 && manager.comp.size() == 3);
    manager.add(-2); manager.add(-2); manager.add(9);
    assert(manager.seg.get(0).sum == -4 && manager.seg.get(0).cnt == 2);
    assert(manager.seg.all_prod().sum == 5 && manager.seg.all_prod().cnt == 3);
    INT(a0, b0); print(a0 + b0);
}
