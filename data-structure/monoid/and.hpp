#pragma once

template <typename T> struct MonoidAND {
    using value_type = T;
    inline static T op(const T &l, const T &r) { return (l & r); }
    inline static T e() { return T(1); }
};