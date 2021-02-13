#include "modint.hpp"

using mint = ModInt<MOD>;

struct Combination {
    int MAX;
    vector<mint> fac, finv;
    Combination(int _MAX) : fac(_MAX), finv(_MAX), MAX(_MAX) {
        fac[0] = fac[1] = 1;
        for(int i = 2; i < MAX; i++) { fac[i] = fac[i - 1] * i; }
        finv[MAX - 1] = fac[MAX - 1].inv();
        for(int i = MAX - 1; i >= 1; i--) { finv[i - 1] = finv[i] * i; }
    }
    mint COM(int n, int k) {
        if(n < k || n < 0 || k < 0) { return 0; }
        return fac[n] * finv[k] * finv[n - k];
    }
};