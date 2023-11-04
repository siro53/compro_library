#pragma once

#include <algorithm>
#include <cassert>
#include <functional>
#include <limits>
#include <queue>
#include <tuple>
#include <vector>
#include <utility>

// ref: https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8
template <typename T> struct SlopeTrick {
    const T inf = std::numeric_limits<T>::max() / 3;

    T min_f, add_L, add_R;
    std::priority_queue<T> L;
    std::priority_queue<T, std::vector<T>, std::greater<T>> R;

  private:
    void push_L(T a) { L.push(a - add_L); }
    T top_L() {
        if(L.empty()) return -inf;
        return L.top() + add_L;
    }
    T pop_L() {
        T ret = top_L();
        if(!L.empty()) L.pop();
        return ret;
    }
    void push_R(T a) { R.push(a - add_R); }
    T top_R() {
        if(R.empty()) return inf;
        return R.top() + add_R;
    }
    T pop_R() {
        T ret = top_R();
        if(!R.empty()) R.pop();
        return ret;
    }

  public:
    SlopeTrick() : min_f(0), add_L(0), add_R(0) {}
    T get_min() const { return min_f; }
    std::tuple<T, T, T> get_min_lr() const { return {min_f, top_L(), top_R()}; }
    // 定数関数 f(x) = a を追加
    void add_const(T a) { min_f += a; }
    // f(x) = (x - a)+ を追加
    void add_right(T a) {
        min_f += std::max(top_L() - a, T(0));
        push_L(a);
        T t = pop_L();
        push_R(t);
    }
    // f(x) = (a - x)+ を追加
    void add_left(T a) {
        min_f += std::max(a - top_R(), T(0));
        push_R(a);
        T t = pop_R();
        push_L(t);
    }
    // f(x) = |x - a| = (x - a)+ + (a - x)+ を追加
    void add_abs(T a) {
        add_left(a);
        add_right(a);
    }
    // (左側)累積min
    // g(x) := min_{y <= x} f(y) なる g に変更
    void clear_right() {
        while(!R.empty()) R.pop();
    }
    // (右側)累積min
    // g(x) := min_{y >= x} f(y) なる g に変更
    void clear_left() {
        while(!L.empty()) L.pop();
    }
    // スライド最小値関数
    // g(x) := min_{x - b <= y <= x - a} f(y) (a <= b) なる g に変更
    void shift(T a, T b) {
        assert(a <= b);
        add_L += a;
        add_R += b;
    }
    // 平行移動
    // g(x) := f(x - a) なる g に変更
    void shift(T a) { shift(a, a); }
    size_t size() const { return L.size() + R.size(); }
    void swap(SlopeTrick& rhs) {
        std::swap(min_f, rhs.min_f);
        std::swap(add_L, rhs.add_L);
        std::swap(add_R, rhs.add_R);
        std::swap(L, rhs.L);
        std::swap(R, rhs.R);
    }
    void merge(SlopeTrick& rhs) {
        if(size() < rhs.size()) swap(rhs);
        while(!rhs.L.empty()) add_left(rhs.pop_L());
        while(!rhs.R.empty()) add_right(rhs.pop_R());
        min_f += rhs.min_f;
    }
    // L, R は空になる
    T eval(T x) {
        T ret = min_f;
        while(!L.empty()) ret += max(T(0), pop_L() - x);
        while(!R.empty()) ret += max(T(0), x - pop_R());
        return ret;
    }
};