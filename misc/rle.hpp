#pragma once

#include <string>
#include <vector>
#include <utility>

template<class T>
std::vector<std::pair<T, int>> runlength_encoding(const std::vector<T>& v) {
    std::vector<std::pair<T, int>> ret = {{v[0], 1}};
    for(size_t i = 1; i < v.size(); i++) {
        if(ret.back().first == v[i]) ret.back().second++;
        else ret.emplace_back(v[i], 1);
    }
    return ret;
}

std::vector<std::pair<char, int>> runlength_encoding(const std::string& s) {
    std::vector<std::pair<char, int>> ret = {{s[0], 1}};
    for(size_t i = 1; i < s.size(); i++) {
        if(ret.back().first == s[i]) ret.back().second++;
        else ret.emplace_back(s[i], 1);
    }
    return ret;
}
