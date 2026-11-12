#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../../template/template.cpp"
#include "../../../../random/gen/sequence.hpp"

int main() {
    Random rng(7);
    {
        auto v = random_vector(rng, 100, 1, 4);
        static_assert(is_same<decltype(v), vector<int>>::value);
        assert(v.size() == 100);
        for(int x : v) assert(1 <= x && x < 4);
        assert(set<int>(v.begin(), v.end()).size() == 3);
        auto w = random_vector(rng, 10, 0LL, 1000000000000000000LL);
        static_assert(is_same<decltype(w), vector<long long>>::value);
        assert(random_vector(rng, 0, 1, 2).empty());
    }
    {
        for(int iter = 0; iter < 200; iter++) {
            auto v = random_distinct_vector(rng, 5, -3, 7);
            assert(v.size() == 5 && set<int>(v.begin(), v.end()).size() == 5);
            for(int x : v) assert(-3 <= x && x < 7);
        }
        // 全体を取ると順列になり、すべての並びが現れる
        set<vector<int>> seen;
        for(int iter = 0; iter < 3000; iter++) {
            auto v = random_distinct_vector(rng, 4, 10, 14);
            vector<int> s = v;
            sort(s.begin(), s.end());
            assert((s == vector<int>{10, 11, 12, 13}));
            seen.insert(v);
        }
        assert(seen.size() == 24);
        // 2 個選ぶとき、10 通りの組合せがすべて現れる
        set<pair<int, int>> pairs;
        for(int iter = 0; iter < 2000; iter++) {
            auto v = random_distinct_vector(rng, 2, 0, 5);
            pairs.emplace(min(v[0], v[1]), max(v[0], v[1]));
        }
        assert(pairs.size() == 10);
        auto big = random_distinct_vector(rng, 3, 0LL, LLONG_MAX);
        assert(set<long long>(big.begin(), big.end()).size() == 3);
        assert(random_distinct_vector(rng, 0, 5, 5).empty());
    }
    {
        set<vector<int>> seen;
        for(int iter = 0; iter < 3000; iter++) {
            auto p = random_permutation(rng, 4);
            vector<int> s = p;
            sort(s.begin(), s.end());
            assert((s == vector<int>{0, 1, 2, 3}));
            seen.insert(p);
        }
        assert(seen.size() == 24);
        assert(random_permutation(rng, 0).empty());
    }
    {
        set<vector<int>> seen;
        for(int iter = 0; iter < 2000; iter++) {
            auto s = random_subset(rng, 5, 2);
            assert(s.size() == 2 && s[0] < s[1] && 0 <= s[0] && s[1] < 5);
            seen.insert(s);
        }
        assert(seen.size() == 10);
        assert(random_subset(rng, 3, 0).empty());
        assert((random_subset(rng, 3, 3) == vector<int>{0, 1, 2}));
    }
    {
        // [1, 4) 内の空でない半開区間は 6 通り
        set<pair<int, int>> seen;
        for(int iter = 0; iter < 2000; iter++) {
            auto [a, b] = random_interval(rng, 1, 4);
            assert(1 <= a && a < b && b <= 4);
            seen.emplace(a, b);
        }
        assert(seen.size() == 6);
        assert((random_interval(rng, 5, 6) == pair<int, int>{5, 6}));
    }
    INT(a, b);
    print(a + b);
}
