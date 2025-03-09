#pragma once

#include <chrono>

struct Timer {
    std::chrono::high_resolution_clock::time_point start_time;

    Timer() { reset(); }

    // タイマーをリセットする
    void reset() {
        start_time = std::chrono::high_resolution_clock::now();
    }

    // タイマーセットしてから何 milliseconds 経過したかを返す
    long long elapsed() {
        auto end_time = std::chrono::high_resolution_clock::now();
        auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        return elapsed_time.count();
    }

    // タイマーセットしてから何 milliseconds 経過したかを返す
    auto operator()() { return elapsed(); }
};
