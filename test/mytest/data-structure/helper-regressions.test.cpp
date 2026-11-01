#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../data-structure/unionfind.hpp"
#include "../../../data-structure/erasable-priority-queue.hpp"
#include "../../../data-structure/slope-trick.hpp"
#include "../../../data-structure/utils/sum_count_manager.hpp"

void regression_test() {
    UnionFind uf(5);
    uf.merge(0, 1); uf.merge(1, 3); uf.merge(2, 4);
    auto groups = uf.groups();
    vector<vector<int>> mapped;
    for(auto [_, group] : uf.groups_with_map()) mapped.push_back(group);
    assert(mapped == groups);
    ErasablePriorityQueue<int> q;
    q.push(1); q.push(1); q.erase(1);
    assert(!q.empty() && q.top() == 1);
    q.erase(1); assert(q.empty());
    q.push(2); assert(!q.empty()); q.pop(); assert(q.empty());
    SlopeTrick<long long> slope;
    slope.add_abs(3); slope.add_abs(5);
    const auto& cs = slope;
    assert(cs.get_min_lr() == make_tuple(2LL, 3LL, 5LL));
    assert(slope.eval(0) == 8);
    SumCountManager<int> manager(vector<int>{10, 20});
    manager.add(10); manager.add(10); manager.add(20);
    auto all = manager.seg.all_prod();
    assert(all.sum == 40 && all.cnt == 3);
}

int main() {
    regression_test();
    INT(a, b);
    print(a + b);
}
