#pragma once

#include <vector>

class Eratosthenes {
  public:
    Eratosthenes() {}
    explicit Eratosthenes(int n) : n(n), isp(n + 1, true) {
        isp[0] = isp[1] = false;
        for(int i = 2; i * i <= n; i++) {
            if(!isp[i]) continue;
            for(int j = i * i; j <= n; j += i) isp[j] = false;
        }
    }
    bool operator[](int k) const { return isp[k]; }

  private:
    int n;
    std::vector<bool> isp;
};