#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

template <class mint> class Binomial {
  public:
    explicit Binomial(): Binomial(1) {}
    explicit Binomial(int MAX) : f(MAX, mint(1)), f_inv(MAX, mint(1)) {
        for(int i = 1; i < MAX; i++) f[i] = f[i-1] * mint(i);
        f_inv[MAX - 1] = f[MAX - 1].inv();
        for(int i = MAX - 2; i >= 1; i--) {
            f_inv[i] = f_inv[i + 1] * mint(i + 1);
        } 
    }
    void extend() {
        int n = (int)f.size();
        f.resize(n * 2);
        f_inv.resize(n * 2);
        for(int i = n; i < n * 2; i++) f[i] = f[i - 1] * mint(i);
        f_inv[n * 2 - 1] = f[n * 2 - 1].inv();
        for(int i = n * 2 - 2; i >= n; i--) {
            f_inv[i] = f_inv[i + 1] * mint(i + 1);
        }
    }
    mint fac(int n) {
        if(n < 0) return mint(0);
        while(n >= (int)f.size()) extend();
        return f[n];
    }
    mint fac_inv(int n) {
        if(n < 0) return mint(0);
        while(n >= (int)f_inv.size()) extend();
        return f_inv[n];
    }
    mint inv(int n) {
        if(n < 0) return -mint(-n);
        assert(n != 0);
        while(n >= (int)f_inv.size()) extend();
        return (f_inv[n] * f[n - 1]);
    }
    mint binom(int n, int k) {
        if(n < k || n < 0 || k < 0) return mint(0);
        return (fac(n) * fac_inv(k) * fac_inv(n - k));
    }
    mint binom_naive(long long n, long long k) {
        if(n < k || n < 0 || k < 0) return mint(0);
        mint res(1);
        k = std::min(k, n - k);
        for(int i = 0; i < k; i++) res *= inv(i + 1) * mint(n - i);
        return res;
    }
    mint perm(int n, int k) {
        if(n < k || n < 0 || k < 0) return mint(0);
        return (fac(n) * fac_inv(n - k));
    }
    mint hom(int n, int k) {
        if(n < 0 || k < 0) return mint(0);
        return (k == 0 ? mint(1) : binom(n + k - 1, k));
    }

  private:
    std::vector<mint> f, f_inv;
};