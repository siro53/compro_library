#pragma once

#include <chrono>
#include <random>

class RNG32 {
  public:
    RNG32() : mt(std::chrono::steady_clock::now().time_since_epoch().count()) {}
    // [l, r)
    int randint(int l, int r) {
        std::uniform_int_distribution<int> dist(l, r - 1);
        return dist(mt);
    }
    int randint(int r) { return randint(0, r); }

  private:
    std::mt19937 mt;
};

class RNG64 {
  public:
    RNG64() : mt(std::chrono::steady_clock::now().time_since_epoch().count()) {}
    // [l, r)
    long long randint(long long l, long long r) {
        std::uniform_int_distribution<long long> dist(l, r - 1);
        return dist(mt);
    }
    long long randint(long long r) { return randint(0, r); }

  private:
    std::mt19937_64 mt;
};