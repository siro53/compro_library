#pragma once

#include <algorithm>
#include <cassert>
#include <cerrno>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <random>
#include <type_traits>
#include <utility>
#include <vector>

// seed を指定できる、ランダムテストの入力生成用の乱数
class Random {
  public:
    explicit Random(std::uint64_t seed = 0) : mt(seed) {}
    // argv[1] を seed として読む。引数がなければ seed = 0
    Random(int argc, char **argv) : mt(parse_seed(argc, argv)) {}

    // [0, n) の一様な整数 (n > 0)
    std::uint64_t uniform(std::uint64_t n) {
        assert(n > 0);
        // 2^64 mod n 個の値を棄却して剰余の偏りをなくす
        const std::uint64_t threshold = (0 - n) % n;
        std::uint64_t x = mt();
        while(x < threshold) x = mt();
        return x % n;
    }

    // [l, r) の一様な整数
    template <class T, class U>
    std::common_type_t<T, U, int> randint(T l, U r) {
        using C = std::common_type_t<T, U, int>;
        static_assert(std::is_integral<C>::value, "randint requires integers");
        const C lo = C(l), hi = C(r);
        assert(lo < hi);
        using UC = std::make_unsigned_t<C>;
        const std::uint64_t width = std::uint64_t(UC(hi) - UC(lo));
        return C(UC(lo) + UC(uniform(width)));
    }
    // [0, r) の一様な整数
    template <class T> std::common_type_t<T, int> randint(T r) {
        return randint(T(0), r);
    }

    // [l, r) に含まれる偶数から一様に選ぶ (偶数が 1 つ以上あること)
    template <class T, class U>
    std::common_type_t<T, U, int> even(T l, U r) {
        return with_parity(l, r, 0);
    }
    // [0, r) に含まれる偶数から一様に選ぶ
    template <class T> std::common_type_t<T, int> even(T r) {
        return even(T(0), r);
    }

    // [l, r) に含まれる奇数から一様に選ぶ (奇数が 1 つ以上あること)
    template <class T, class U>
    std::common_type_t<T, U, int> odd(T l, U r) {
        return with_parity(l, r, 1);
    }
    // [0, r) に含まれる奇数から一様に選ぶ
    template <class T> std::common_type_t<T, int> odd(T r) {
        return odd(T(0), r);
    }

    // [l, r) の実数 (53 bit の分解能)
    double real(double l, double r) {
        assert(l < r);
        const double u = double(mt() >> 11) / double(std::uint64_t(1) << 53);
        const double x = l + (r - l) * u;
        return x < r ? x : std::nextafter(r, l);
    }
    double real() { return real(0.0, 1.0); }

    // 確率 p で true
    bool coin(double p = 0.5) { return real() < p; }

    // 小さい値に偏らせた [l, r) の整数
    // 2 冪のスケール 1, 2, 4, ... を等確率で選び、その範囲で一様に選ぶ
    template <class T, class U>
    std::common_type_t<T, U, int> size(T l, U r) {
        using C = std::common_type_t<T, U, int>;
        const C lo = C(l), hi = C(r);
        assert(lo < hi);
        using UC = std::make_unsigned_t<C>;
        const std::uint64_t width = std::uint64_t(UC(hi) - UC(lo));
        int scales = 0;
        while(scales < 64 && (std::uint64_t(1) << scales) < width) scales++;
        const int k = int(uniform(std::uint64_t(scales + 1)));
        const std::uint64_t w = k >= 64 ? width : std::min(width, std::uint64_t(1) << k);
        return C(UC(lo) + UC(uniform(w)));
    }

    // v の要素を一様に 1 つ選ぶ (v は空でない)
    template <class T> const T &choice(const std::vector<T> &v) {
        assert(!v.empty());
        return v[uniform(v.size())];
    }

    // Fisher-Yates で v を一様にシャッフルする
    template <class T> void shuffle(std::vector<T> &v) {
        for(std::size_t i = v.size(); i > 1; i--) {
            std::swap(v[i - 1], v[uniform(i)]);
        }
    }

    // 標準の分布と組み合わせる場合のエンジン
    std::mt19937_64 &engine() { return mt; }

  private:
    std::mt19937_64 mt;

    // [l, r) のうち 2 で割った余りが parity (負の数も含めて数学的な偶奇) の値から一様に選ぶ
    template <class T, class U>
    std::common_type_t<T, U, int> with_parity(T l, U r, unsigned parity) {
        using C = std::common_type_t<T, U, int>;
        static_assert(std::is_integral<C>::value, "even/odd requires integers");
        using UC = std::make_unsigned_t<C>;
        const C lo = C(l), hi = C(r);
        assert(lo < hi);
        const std::uint64_t width = std::uint64_t(UC(hi) - UC(lo));
        // 2 の補数表現では UC への変換で偶奇が保たれる
        const std::uint64_t first = (std::uint64_t(UC(lo)) & 1) == parity ? 0 : 1;
        assert(first < width && "no integer of the requested parity in [l, r)");
        // first, first + 2, ... < width の個数 (width - first + 1 のあふれを避ける)
        const std::uint64_t count = (width - first - 1) / 2 + 1;
        return C(UC(lo) + UC(first + 2 * uniform(count)));
    }

    static std::uint64_t parse_seed(int argc, char **argv) {
        if(argc < 2) return 0;
        const char *s = argv[1];
        char *end = nullptr;
        errno = 0;
        const unsigned long long seed = std::strtoull(s, &end, 10);
        if(*s == '\0' || *s == '-' || *end != '\0' || errno == ERANGE) {
            std::cerr << "Random: invalid seed '" << s << "'\n";
            std::exit(2);
        }
        return seed;
    }
};
