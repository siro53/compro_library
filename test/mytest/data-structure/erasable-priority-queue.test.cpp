#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../random/rng.hpp"
#include "../../../data-structure/erasable-priority-queue.hpp"

void erasable_priority_queue_test() {
    RNG32 rnd;
    ErasablePriorityQueue<int> que;
    REP(i, 100000) {
        que.push(i);
    }
    for(int i = 100000 - 1; i >= 50000; i--) {
        que.erase(i);
    }
    for(int i = 50000; i < 100000; i++) {
        que.push(i);
    }
    REP(i, 100000) {
        int x = que.top();
        que.pop();
        assert(x == i);
    }
}

int main() {
    erasable_priority_queue_test();
    INT(a, b);
    print(a + b);
}