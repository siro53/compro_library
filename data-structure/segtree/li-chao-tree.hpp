#pragma once

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

template <typename T, T inf>
class LiChaoTree {
public:
    LiChaoTree() = default;
    explicit LiChaoTree(const std::vector<T>& x): xs(x) {
        std::sort(xs.begin(), xs.end());
        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
        n = (int)xs.size();
        sz = 1;
        while(sz < n) sz <<= 1;
        while((int)xs.size() < sz) xs.emplace_back(xs.back() + 1);
        node.resize(sz * 2, Line(T(0), inf));
    }
    // 直線 ax + b を追加
    void add_line(T a, T b) {
        update(a, b, 0, sz, 1);
    }
    // 線分 ax + b (x_l <= x < x_r) を追加
    void add_segment(T a, T b, T x_l, T x_r) {
        int l = std::lower_bound(xs.begin(), xs.end(), x_l) - xs.begin();
        int r = std::lower_bound(xs.begin(), xs.end(), x_r) - xs.begin();
        l += sz;
        r += sz;
        int width = 1, seg_idx_left = sz;
        while(l < r) {
            if(l & 1) {
                int L = (l - seg_idx_left) * width;
                int R = L + width;
                update(a, b, L, R, l);
                l++;
            }
            if(r & 1) {
                r--;
                int L = (r - seg_idx_left) * width;
                int R = L + width;
                update(a, b, L, R, r);
            }
            l >>= 1;
            r >>= 1;
            width <<= 1;
            seg_idx_left >>= 1;
        }
    }
    // min_{i} (a_i * x + b) を求める
    T get_min(T x) {
        int pos = std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        assert(0 <= pos and pos < sz);
        pos += sz;
        T ret = node[pos].eval(x);
        while(pos > 1) {
            pos >>= 1;
            ret = std::min(ret, node[pos].eval(x));
        }
        return ret;
    }
private:
    struct Line {
        T a, b;
        Line(T a, T b): a(a), b(b) {}
        inline T eval(T x) const { return (a * x + b); }
    };
    std::vector<T> xs;
    std::vector<Line> node;
    int n, sz;

    void update(T a, T b, int l, int r, int pos) {
        Line new_line(a, b);
        while(1) {
            bool is_over_l = (new_line.eval(xs[l]) >= node[pos].eval(xs[l]));
            bool is_over_r = (new_line.eval(xs[r-1]) >= node[pos].eval(xs[r-1]));
            if(is_over_l == is_over_r) {
                if(!is_over_l) node[pos] = new_line;
                break;
            }
            int mid = (l + r) >> 1;
            bool is_over_mid = (new_line.eval(xs[mid]) >= node[pos].eval(xs[mid]));
            if(!is_over_l and is_over_r) {
                if(is_over_mid) {
                    r = mid;
                    pos = (pos << 1);
                } else {
                    std::swap(new_line, node[pos]);
                    l = mid;
                    pos = (pos << 1) | 1;
                }
            } else {
                if(is_over_mid) {
                    l = mid;
                    pos = (pos << 1) | 1;
                } else {
                    std::swap(new_line, node[pos]);
                    r = mid;
                    pos = (pos << 1);
                }
            }
        }
    }
};