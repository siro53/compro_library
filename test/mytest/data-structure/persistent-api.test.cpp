#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../data-structure/persistent/persistent-array.hpp"
#include "../../../data-structure/persistent/persistent-unionfind.hpp"
#include "../../../data-structure/persistent/persistent-queue.hpp"


int main() {
    PersistentArray<int> empty;
    assert(empty.root && empty.depth == 0 && empty.identity == 0);
    PersistentArray<int> zeros(3); assert(zeros.get(1) == 0);
    using Array = PersistentArray<int, 2>;
    Array a(vector<int>{1, 2, 3, 4, 5});
    assert(a.full_bit == 3);
    vector<Array::Node*> roots{a.root};
    vector<vector<int>> values{ {1, 2, 3, 4, 5} };
    mt19937 rng(61);
    for(int t = 0; t < 100; ++t) {
        int version = rng() % roots.size(), p = rng() % 5, x = rng() % 100;
        auto next = values[version]; next[p] = x;
        auto root = a.set(roots[version], p, x);
        assert(a.root == root && a.get(p) == x);
        roots.push_back(root); values.push_back(next);
        for(int v = 0; v < int(roots.size()); ++v) for(int i = 0; i < 5; ++i) assert(a.get(roots[v], i) == values[v][i]);
    }
    a.set(0, 20); assert(a.get(0) == 20);
    Array::Node node; assert(node.val == 0);
    node.val = 7; node.childs[2] = &node;
    Array::Node by_pointer(&node), by_reference(node);
    assert(by_pointer.val == 7 && by_reference.val == 7);
    assert(by_pointer.childs[2] == &node && by_reference.childs[2] == &node);
    PersistentUnionFind uf(6);
    auto initial = uf.get_root();
    assert(uf.merge(0, 1)); auto first = uf.get_root();
    assert(uf.merge(2, 3, initial)); auto second = uf.get_root();
    for(auto root : {initial, first, second}) for(int i = 0; i < 6; ++i) {
        int size = (root == first && i < 2) || (root == second && 2 <= i && i < 4) ? 2 : 1;
        auto [leader, count] = uf.leader_and_size(i, root);
        assert(uf.leader(i, root) == leader && uf.size(i, root) == size && count == size);
        for(int j = 0; j < 6; ++j) {
            bool same = i == j || (root == first && i < 2 && j < 2) || (root == second && 2 <= i && i < 4 && 2 <= j && j < 4);
            assert(uf.same(i, j, root) == same);
        }
    }
    assert(!uf.merge(2, 3) && uf.get_root() == second);
    assert(!uf.merge(0, 1, first) && uf.get_root() == second);
    for(int i = 0; i < 6; ++i) {
        assert(uf.leader(i) == uf.leader(i, second));
        assert(uf.size(i) == uf.size(i, second));
        assert(uf.leader_and_size(i) == uf.leader_and_size(i, second));
        assert(uf.same(i, 2) == uf.same(i, 2, second));
    }
    using Queue = PersistentQueue<int, 10>;
    vector<Queue> queues(1); vector<deque<int>> expected(1);
    assert(queues[0].empty() && queues[0].pop().empty());
    Queue::Node qnode(7, 4); assert(qnode.val == 7 && qnode.idx == 4);
    for(int t = 0; t < 300; ++t) {
        int version = rng() % queues.size();
        auto q = queues[version]; auto ref = expected[version];
        if(ref.empty() || rng() % 2) { q = q.push(t); ref.push_back(t); }
        else { q = q.pop(); ref.pop_front(); }
        Queue rebuilt(q.front_node, q.back_node);
        assert(rebuilt.empty() == ref.empty());
        queues.push_back(q); expected.push_back(ref);
        for(int v = 0; v < int(queues.size()); ++v) {
            assert(queues[v].empty() == expected[v].empty());
            if(!expected[v].empty()) assert(queues[v].front() == expected[v].front() && queues[v].back() == expected[v].back());
        }
    }
    INT(a0, b0); print(a0 + b0);
}
