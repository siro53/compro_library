#pragma once

#include <cassert>
#include <string>

#include "random.hpp"

// 各文字を alphabet から一様に選んだ長さ n の文字列
inline std::string random_string(Random &rng, int n,
                                 const std::string &alphabet) {
    assert(n >= 0);
    assert(n == 0 || !alphabet.empty());
    std::string s(n, '\0');
    for(auto &c : s) c = alphabet[rng.uniform(alphabet.size())];
    return s;
}

// 英小文字の先頭 k 種類 ('a' から k 文字) からなる長さ n の文字列
inline std::string random_lowercase(Random &rng, int n, int k = 26) {
    assert(1 <= k && k <= 26);
    std::string alphabet(k, 'a');
    for(int i = 0; i < k; i++) alphabet[i] = char('a' + i);
    return random_string(rng, n, alphabet);
}
