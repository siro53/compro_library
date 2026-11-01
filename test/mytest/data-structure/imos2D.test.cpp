#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../data-structure/imos2D.hpp"

int main() {
    mt19937 rng(20261102);
    for(int h = 0; h <= 8; ++h) for(int w = 0; w <= 8; ++w) {
        imos2D<ll> imos;
        imos = imos2D<ll>(h, w);
        assert(imos.H == h && imos.W == w);
        vector<vector<ll>> expected(h, vector<ll>(w));
        if(h && w) for(int step = 0; step < 100; ++step) {
            int x1 = rng() % h, y1 = rng() % w;
            int x2 = x1 + rng() % (h - x1 + 1);
            int y2 = y1 + rng() % (w - y1 + 1);
            ll delta = ll(rng() % 2000001) - 1000000;
            imos.add(x1, y1, x2, y2, delta);
            for(int x = x1; x < x2; ++x) for(int y = y1; y < y2; ++y) {
                expected[x][y] += delta;
            }
        }
        imos.build();
        for(int x = 0; x < h; ++x) for(int y = 0; y < w; ++y) {
            assert(imos[x][y] == expected[x][y]);
        }
        if(h && w) {
            imos[0][0] = 42;
            assert(imos[0][0] == 42);
        }
    }
    INT(a, b);
    print(a + b);
}
