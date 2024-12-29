#pragma once

#include <cstdint>

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