#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../../template/template.cpp"
#include "../../../../random/gen/random.hpp"

int main() {
    // 同じ seed なら同じ列、異なる seed なら (ほぼ確実に) 異なる列
    {
        Random a(42), b(42), c(43);
        bool differ = false;
        for(int i = 0; i < 100; i++) {
            long long x = a.randint(0LL, 1000000000000LL);
            assert(x == b.randint(0LL, 1000000000000LL));
            differ |= x != c.randint(0LL, 1000000000000LL);
        }
        assert(differ);
    }
    // argv[1] からの seed、引数なしは seed 0
    {
        char prog[] = "gen", seed[] = "42";
        char *argv1[] = {prog, seed, nullptr};
        char *argv0[] = {prog, nullptr};
        Random a(2, argv1), b(42), c(1, argv0), d(0);
        for(int i = 0; i < 10; i++) {
            assert(a.randint(1000) == b.randint(1000));
            assert(c.randint(1000) == d.randint(1000));
        }
    }
    // 返り値の型は引数の共通型 (int 未満は int に昇格)
    {
        Random rng;
        static_assert(is_same<decltype(rng.randint(1, 2)), int>::value);
        static_assert(is_same<decltype(rng.randint(1, 2LL)), long long>::value);
        static_assert(is_same<decltype(rng.randint(char(1))), int>::value);
        static_assert(is_same<decltype(rng.size(1, 2)), int>::value);
    }
    Random rng(1);
    // randint: [l, r) の値をすべて取り、範囲外は出ない
    {
        vector<int> cnt(7);
        for(int i = 0; i < 7000; i++) {
            int x = rng.randint(-3, 4);
            assert(-3 <= x && x < 4);
            cnt[x + 3]++;
        }
        for(int c : cnt) assert(700 < c && c < 1300);
        for(int i = 0; i < 100; i++) assert(rng.randint(5) < 5 && rng.randint(5) >= 0);
        assert(rng.randint(-9, -8) == -9);
        const long long lo = LLONG_MIN, hi = LLONG_MAX;
        for(int i = 0; i < 100; i++) {
            long long x = rng.randint(lo, hi);
            assert(lo <= x && x < hi);
        }
        unsigned long long u = rng.randint(0ULL, ~0ULL);
        assert(u < ~0ULL);
        assert(rng.uniform(1) == 0);
    }
    // even, odd: 負の数も含めた数学的な偶奇で、該当する値をすべて取る
    {
        static_assert(is_same<decltype(rng.even(1, 2LL)), long long>::value);
        static_assert(is_same<decltype(rng.odd(5)), int>::value);
        for(int l = -7; l <= 7; l++) {
            for(int r = l + 1; r <= l + 8; r++) {
                for(int parity = 0; parity < 2; parity++) {
                    set<int> expected, seen;
                    for(int x = l; x < r; x++) if(((x % 2) + 2) % 2 == parity) expected.insert(x);
                    if(expected.empty()) continue;
                    for(int i = 0; i < 200; i++) seen.insert(parity ? rng.odd(l, r) : rng.even(l, r));
                    assert(seen == expected);
                }
            }
        }
        vector<int> cnt(5);
        for(int i = 0; i < 5000; i++) {
            int x = rng.even(-4, 5);  // -4, -2, 0, 2, 4
            cnt[(x + 4) / 2]++;
        }
        for(int c : cnt) assert(800 < c && c < 1200);
        for(int i = 0; i < 100; i++) {
            int e = rng.even(10), o = rng.odd(10);
            assert(0 <= e && e < 10 && e % 2 == 0);
            assert(0 <= o && o < 10 && o % 2 == 1);
            long long be = rng.even(LLONG_MIN, LLONG_MAX), bo = rng.odd(LLONG_MIN, LLONG_MAX);
            assert(be % 2 == 0 && bo % 2 != 0 && bo < LLONG_MAX);
            unsigned long long ue = rng.even(0ULL, ~0ULL), uo = rng.odd(0ULL, ~0ULL);
            assert(ue % 2 == 0 && uo % 2 == 1 && uo < ~0ULL);
        }
        assert(rng.even(3, 5) == 4 && rng.odd(4, 6) == 5);
        assert(rng.odd(-1, 0) == -1 && rng.even(-1, 1) == 0);
        assert(rng.even(LLONG_MAX - 1, LLONG_MAX) == LLONG_MAX - 1);
        assert(rng.odd(LLONG_MIN + 1, LLONG_MIN + 2) == LLONG_MIN + 1);
    }
    // real, coin
    {
        for(int i = 0; i < 1000; i++) {
            double x = rng.real(-1.5, 2.5);
            assert(-1.5 <= x && x < 2.5);
            double y = rng.real();
            assert(0 <= y && y < 1);
        }
        int heads = 0;
        for(int i = 0; i < 10000; i++) heads += rng.coin(0.3);
        assert(2700 < heads && heads < 3300);
        for(int i = 0; i < 100; i++) assert(!rng.coin(0.0) && rng.coin(1.0));
    }
    // size: 範囲内で、小さい値ほど出やすい
    {
        int small = 0;
        set<int> seen;
        for(int i = 0; i < 10000; i++) {
            int x = rng.size(1, 1001);
            assert(1 <= x && x < 1001);
            small += x < 10;
            seen.insert(x);
        }
        assert(small > 2000 && seen.count(1) && *seen.rbegin() > 900);
        for(int i = 0; i < 100; i++) assert(rng.size(5, 6) == 5);
        long long big = rng.size(0LL, LLONG_MAX);
        assert(big >= 0);
    }
    // choice, shuffle
    {
        vector<int> v{3, 1, 4, 1, 5};
        set<int> chosen;
        for(int i = 0; i < 1000; i++) chosen.insert(rng.choice(v));
        assert((chosen == set<int>{1, 3, 4, 5}));
        set<vector<int>> perms;
        for(int i = 0; i < 2000; i++) {
            vector<int> w{0, 1, 2, 3};
            rng.shuffle(w);
            vector<int> s = w;
            sort(s.begin(), s.end());
            assert((s == vector<int>{0, 1, 2, 3}));
            perms.insert(w);
        }
        assert(perms.size() == 24);
        vector<int> empty;
        rng.shuffle(empty);
        assert(empty.empty());
        assert(rng.engine()() != rng.engine()());
    }
    INT(a, b);
    print(a + b);
}
