#pragma once

#include <vector>
#include <string>

std::vector<int> z_algo(const std::string& s) {
    int n = (int)s.size();
    std::vector<int> z(n);
    z[0] = n;
    for(int i = 1, j = 0; i < n;) {
        while(i + j < n and s[j] == s[i + j]) j++;
        z[i] = j;
        if(j == 0) {
            i++;
            continue;
        }
        int k = 1;
        while(k < j and k + z[k] < j) {
            z[i + k] = z[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return z;
}