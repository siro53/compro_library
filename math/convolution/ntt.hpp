#pragma once

#include <array>
#include <utility>
#include <vector>

#include "../../modint/modint.hpp"
#include "../primitive-root.hpp"

namespace ntt {
    constexpr int exp_limit(int mod) { return __builtin_ctz(mod - 1); }

    template <class mint, int mod = mint::get_mod(),
              int g = primitive_root(mod)>
    struct ntt_info {
        static constexpr int limit = exp_limit(mod);
        std::array<mint, limit + 1> root;
        std::array<mint, limit + 1> iroot;

        ntt_info() {
            root[limit] = mint(g).pow((mod - 1) >> limit);
            iroot[limit] = root[limit].inv();
            for(int i = limit - 1; i >= 0; i--) {
                root[i] = root[i + 1] * root[i + 1];
                iroot[i] = iroot[i + 1] * iroot[i + 1];
            }
        }
    };

    inline uint64_t revbit(uint64_t mask) {
        int b = __builtin_clzll(mask);
        uint64_t x = mask;
        x = (x >> 32) | (x << 32);
        x = ((x >> 16) & 0x0000FFFF0000FFFF) | ((x << 16) & 0xFFFF0000FFFF0000);
        x = ((x >> 8) & 0x00FF00FF00FF00FF) | ((x << 8) & 0xFF00FF00FF00FF00);
        x = ((x >> 4) & 0x0F0F0F0F0F0F0F0F) | ((x << 4) & 0xF0F0F0F0F0F0F0F0);
        x = ((x >> 2) & 0x3333333333333333) | ((x << 2) & 0xCCCCCCCCCCCCCCCC);
        x = ((x >> 1) & 0x5555555555555555) | ((x << 1) & 0xAAAAAAAAAAAAAAAA);
        return (x >> b);
    }

    template<class mint>
    void ntt(std::vector<mint>& a) {
        int n = (int)a.size();
        int bitlen = __builtin_ctz(n);
        static const ntt_info<mint> info;
        for(int len = n, b = bitlen; len > 1; len >>= 1, b--) {
            for(int i = 0; i < n; i += len) {
                int t = len >> 1;
                mint wj = 1;
                for(int j = 0; j < t; j++) {
                    int p = i + j;
                    mint l = a[p] + a[p + t];
                    mint r = (a[p] - a[p + t]) * wj;
                    a[p] = l, a[p + t] = r;
                    wj *= info.root[b];
                }
            }
        }
        for(int i = 0; i < n; i++) {
            int j = revbit(i);
            if(i < j) std::swap(a[i], a[j]);
        }
    }

    template<class mint>
    void intt(std::vector<mint>& a) {
        int n = (int)a.size();
        static const ntt_info<mint> info;
        for(int i = 0; i < n; i++) {
            int j = revbit(i);
            if(i < j) std::swap(a[i], a[j]);
        }
        for(int len = 2, b = 1; len <= n; len <<= 1, b++) {
            for(int i = 0; i < n; i += len) {
                int t = len >> 1;
                mint wj = 1;
                for(int j = 0; j < t; j++) {
                    int p = i + j;
                    auto l = a[p] + a[p + t] * wj;
                    auto r = a[p] - a[p + t] * wj;
                    a[p] = l, a[p + t] = r;
                    wj *= info.iroot[b];
                }
            }
        }
        mint invn = mint(n).inv();
        for(int i = 0; i < n; i++) a[i] *= invn;
    }

    template<class mint>
    std::vector<mint> convolution(std::vector<mint> a, std::vector<mint> b) {
        int m = (int)a.size() + (int)b.size() - 1;
        int n = 1;
        while(n < m) n <<= 1;
        a.resize(n), b.resize(n);
        ntt<mint>(a);
        ntt<mint>(b);
        for(int i = 0; i < n; i++) a[i] *= b[i];
        intt<mint>(a);
        a.resize(m);
        return a;
    }
}; // namespace ntt