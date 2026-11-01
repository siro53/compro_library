#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../misc/compress.hpp"
#include "../../../misc/floor-ceil-div.hpp"
#include "../../../misc/rle.hpp"
#include "../../../misc/inversion-number.hpp"
#include "../../../misc/mo.hpp"
#include "../../../misc/timer.hpp"
#include "../../../random/rng.hpp"


int main() {
    for(ll a = -100; a <= 100; ++a) for(ll b = -20; b <= 20; ++b) if(b) {
        assert(floor_div(a, b) == ll(floor((long double)a / b)));
        assert(ceil_div(a, b) == ll(ceil((long double)a / b)));
    }
    Compress<int> compression; assert(compression.size() == 0);
    for(int x : {7, -2, 7, 0}) compression.push_back(x);
    compression.build(); const auto& c = compression;
    assert(c.size() == 3 && c[0] == -2 && c[1] == 0 && c[2] == 7);
    for(int x = -5; x <= 10; ++x) {
        vector<int> ref{-2, 0, 7}; assert(c.get(x) == lower_bound(ref.begin(), ref.end(), x) - ref.begin());
    }
    Compress<int> constructed(vector<int>{7, -2, 7, 0}); assert(constructed.size() == c.size());
    assert(runlength_encoding(string()).empty() && runlength_encoding(vector<int>{}).empty());
    assert((runlength_encoding(string("aaabbcaa")) == vector<pair<char, int>>{ {'a', 3}, {'b', 2}, {'c', 1}, {'a', 2} }));
    assert((runlength_encoding(vector<int>{1, 1, -2, 3, 3}) == vector<pair<int, int>>{ {1, 2}, {-2, 1}, {3, 2} }));
    mt19937 rng(64);
    for(int n = 0; n <= 30; ++n) {
        vector<int> a(n); for(auto& x : a) x = rng() % n;
        ll expected = 0; for(int i = 0; i < n; ++i) for(int j = i + 1; j < n; ++j) expected += a[i] > a[j];
        assert(inversion_number<ll>(a) == expected);
        Mo mo(n); mo.set_bucketsize(0);
        vector<pair<int, int>> ranges;
        for(int l = 0; l < n; ++l) for(int r = l + 1; r <= n; ++r) { mo.insert(l, r); ranges.emplace_back(l, r); }
        mo.build(); deque<int> current; vector<bool> seen(ranges.size());
        auto al = [&](int i) { current.push_front(i); };
        auto ar = [&](int i) { current.push_back(i); };
        auto dl = [&](int i) { assert(!current.empty() && current.front() == i); current.pop_front(); };
        auto dr = [&](int i) { assert(!current.empty() && current.back() == i); current.pop_back(); };
        for(int t = 0; t < int(ranges.size()); ++t) {
            int q = mo.process(al, ar, dl, dr); assert(q >= 0 && q < int(ranges.size()) && !seen[q]); seen[q] = true;
            auto [l, r] = ranges[q]; vector<int> expected(r - l); iota(expected.begin(), expected.end(), l);
            assert(vector<int>(current.begin(), current.end()) == expected);
        }
        assert(mo.process(al, ar, dl, dr) == -1 && mo.process(al, ar, dl, dr) == -1);
    }
    Timer timer;
    auto lower = chrono::high_resolution_clock::now(); timer.reset(); auto upper = chrono::high_resolution_clock::now();
    assert(lower <= timer.start_time && timer.start_time <= upper);
    timer.start_time = chrono::high_resolution_clock::now() - chrono::milliseconds(100);
    assert(timer.elapsed() >= 100 && timer() >= 100);
    RNG32 r32; RNG64 r64; RNG_0_1 real;
    for(int i = 0; i < 1000; ++i) {
        int a = r32.randint(-5, 3), b = r32.randint(7);
        ll c = r64.randint(-1000000000000LL, 1000000000000LL), d = r64.randint(7);
        double x = real.rand(), y = real();
        assert(-5 <= a && a < 3 && 0 <= b && b < 7);
        assert(-1000000000000LL <= c && c < 1000000000000LL && 0 <= d && d < 7);
        assert(0 <= x && x < 1 && 0 <= y && y < 1);
    }
    assert(r32.randint(4, 5) == 4 && r64.randint(-9, -8) == -9);
    INT(a0, b0); print(a0 + b0);
}
