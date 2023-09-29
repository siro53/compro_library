#pragma once

#include <algorithm>
#include <vector>

template <typename T> class Compress {
  public:
    Compress() = default;
    explicit Compress(const std::vector<T> &v) : dat(v) {
        build();
    }
    void push_back(T val) { dat.push_back(val); }
	void build() {
		std::sort(dat.begin(), dat.end());
        dat.erase(std::unique(dat.begin(), dat.end()), dat.end());
	}
    int get(T val) const {
        int pos = std::lower_bound(dat.begin(), dat.end(), val) - dat.begin();
        return pos;
    }
    T operator[](int i) const { return dat[i]; }
    size_t size() const { return dat.size(); }

  private:
    std::vector<T> dat;
};