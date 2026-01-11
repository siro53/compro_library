#pragma once

#include <cassert>
#include <functional>
#include <type_traits>
#include <queue>
#include <vector>

template<class T, bool isAscending = true>
struct ErasablePriorityQueue {
    using PQ = std::conditional_t<
        isAscending,
        std::priority_queue<T, std::vector<T>, std::greater<T>>,
        std::priority_queue<T>
    >;
    PQ que, rm_que;

    ErasablePriorityQueue() = default;

    void push(const T& val) {
        que.emplace(val);
    }

    T top() {
        normalize();
        assert(!que.empty());
        return que.top();
    }

    void pop() {
        normalize();
        assert(!que.empty());
        que.pop();
    }

    void erase(const T& val) {
        rm_que.emplace(val);
    }

    bool empty() {
        return que.empty();
    }
private:
    void normalize() {
        while(!que.empty() and !rm_que.empty() and que.top() == rm_que.top()) {
            que.pop();
            rm_que.pop();
        }
    }
};