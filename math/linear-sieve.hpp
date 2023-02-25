#pragma once

#include <cassert>
#include <vector>

class LinearSieve {
  public:
    LinearSieve() {}
    explicit LinearSieve(int n) : n(n), min_factor(n + 1, -1) {
        std::vector<int> prime_list;
        for(int d = 2; d <= n; d++) {
            if(min_factor[d] == -1) {
                min_factor[d] = d;
                prime_list.push_back(d);
            }
            for(int p : prime_list) {
                if(p * d > n or min_factor[d] < p) break;
                min_factor[p * d] = p;
            }
        }
    }
    std::vector<int> factor(int num) {
        assert(0 <= num and num <= n);
        std::vector<int> ret;
        while(num > 1) {
            ret.push_back(min_factor[num]);
            num /= min_factor[num];
        }
        return ret;
    }
    const int &operator[](int k) const { return min_factor[k]; }

  private:
    int n;
    std::vector<int> min_factor;
};