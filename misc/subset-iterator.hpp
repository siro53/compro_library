#pragma once

#include <cstdint>
#include <x86intrin.h>

// Subset(S) := Sの部分集合を走査する
struct Subset {
    struct SubsetIter {
        uint32_t S, T;
        bool is_end;

        SubsetIter(uint32_t s): S(s), T(s), is_end(false) {}

        auto operator*() const { return T; }
        auto operator++() { T = (T - 1) & S; }
        auto operator!=(std::nullptr_t) {
            if(is_end) return false;
            is_end = (T == 0);
            return true;
        }
    };

    uint32_t S;

    Subset(uint32_t s): S(s) {}
    auto begin() { return SubsetIter(S); }
    auto end() { return nullptr; }
};

// Subset_k(S, k) := Sの部分集合のうち、sizeがkの集合のみ走査する
// verify: https://atcoder.jp/contests/xmascon24/submissions/61272051
struct Subset_k {
    struct SubsetIter_k {
        const uint32_t n, k, S;
        uint32_t T;

        SubsetIter_k(uint32_t S, uint32_t k): n(uint32_t(1) << __builtin_popcount(S)), k(k), S(S), T((uint32_t(1) << k) - 1) {}

        __attribute__((target("bmi2")))
        auto operator*() const { return _pdep_u32(T, S); }

        __attribute__((target("bmi")))
        auto operator++() {
            uint32_t y = T + _blsi_u32(T);
            T = y | (__andn_u32(y, T) >> _tzcnt_u32(T << 1));
        }
        auto operator!=(std::nullptr_t) const { return T < n; }
    };

    uint32_t S, k;
    
    Subset_k(uint32_t S, uint32_t k): S(S), k(k) {
        assert(k != 0);
    }

    auto begin() { return SubsetIter_k(S, k); }
    auto end() { return nullptr; }
};

// SetBit(S) := Sのうち、bitが立っているindexを小さい順に返す
// verify: https://atcoder.jp/contests/xmascon24/submissions/61272051
struct SetBit {
    struct SetBitIter {
        uint32_t S;

        SetBitIter(uint32_t S): S(S) {}

        __attribute__((target("bmi")))
        auto operator*() { return _tzcnt_u32(S); }

        __attribute__((target("bmi")))
        auto operator++() { S = _blsr_u32(S); }

        auto operator!=(std::nullptr_t) { return S; }
    };

    uint32_t S;

    SetBit(uint32_t S): S(S) {}

    auto begin() { return SetBitIter(S); }
    auto end() { return nullptr; }
};