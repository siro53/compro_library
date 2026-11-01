#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../math/F2.hpp"

bool satisfies(BitMatrix<8> a, const vector<int>& b, int mask) {
    for(int i = 0; i < a.H; ++i) {
        int parity = 0;
        for(int j = 0; j < a.W; ++j) parity ^= int(a[i][j]) & (mask >> j & 1);
        if(parity != b[i]) return false;
    }
    return true;
}

void check(BitMatrix<8> a, vector<int> b) {
    auto reduced = a;
    auto rhs = b;
    int rank = reduced.row_reduction(rhs);
    auto homogeneous = a;
    assert(homogeneous.row_reduction() == rank);
    int solutions = 0, nullity_count = 0;
    vector<int> zero(a.H);
    for(int mask = 0; mask < (1 << a.W); ++mask) {
        bool valid = satisfies(a, b, mask);
        assert(satisfies(reduced, rhs, mask) == valid);
        solutions += valid;
        nullity_count += satisfies(a, zero, mask);
    }
    assert(nullity_count == (1 << (a.W - rank)));
    auto saved = a;
    auto saved_b = b;
    auto [solution_rank, x] = linear_equation_F2(a, b);
    if(solutions == 0) {
        assert(solution_rank == -1 && x.empty());
    } else {
        assert(solution_rank == rank && int(x.size()) == a.W);
        assert(solutions == nullity_count);
        int mask = 0;
        for(int j = 0; j < a.W; ++j) {
            assert(x[j] == 0 || x[j] == 1);
            mask |= x[j] << j;
        }
        assert(satisfies(a, b, mask));
    }
    // linear_equation_F2 takes its inputs by value.
    assert(b == saved_b && a.H == saved.H && a.W == saved.W);
    for(int i = 0; i < a.H; ++i) assert(a[i] == saved[i]);
}

int main() {
    BitMatrix<8> initial;
    assert(initial.H == 1 && initial.W == 1 && initial[0].none());
    check(initial, {0});
    check(initial, {1});
    // Exhaust all small rectangular systems, including zero rows/columns.
    for(int h = 0; h <= 3; ++h) for(int w = 0; w <= 3; ++w) {
        for(int bits = 0; bits < (1 << (h * w)); ++bits) {
            BitMatrix<8> a(h, w);
            for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j) {
                a[i][j] = bits >> (i * w + j) & 1;
            }
            for(int rhs = 0; rhs < (1 << h); ++rhs) {
                vector<int> b(h);
                for(int i = 0; i < h; ++i) b[i] = rhs >> i & 1;
                check(a, b);
            }
        }
    }
    mt19937 rng(20261103);
    for(int t = 0; t < 300; ++t) {
        int h = rng() % 9, w = rng() % 9;
        BitMatrix<8> a(h, w);
        vector<int> b(h);
        for(int i = 0; i < h; ++i) {
            b[i] = rng() & 1;
            for(int j = 0; j < w; ++j) a[i][j] = rng() & 1;
        }
        check(a, b);
    }
    INT(a, b);
    print(a + b);
}
