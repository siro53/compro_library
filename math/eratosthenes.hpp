#pragma once

#include <vector>

std::vector<bool> eratosthenes(int n) {
    std::vector<bool> res(n, true);
    res[0] = res[1] = false;
    for(int i = 2; i * i <= n; i++) {
        if(!res[i]) continue;
        for(int j = i + i; j <= n; j++) res[j] = false;
    }
    return res;
}