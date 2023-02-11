#pragma once

#include <array>
#include <cassert>
#include <utility>
#include <vector>

template <typename T = unsigned int, int LOG = 32> class BinaryTrie {
  public:
    explicit BinaryTrie() : root(nullptr), lazy_xor_value(0) {}
    int count(T val) {
        if(!root) return 0;
        Node *now = root;
        for(int i = LOG - 1; i >= 0; i--) {
            now = now->child[val >> i & 1];
            if(!now or now->count == 0) return 0;
        }
        return now->count;
    }
    void insert(T val) {
        if(!root) root = new Node();
        Node *now = root;
        now->count++;
        for(int i = LOG - 1; i >= 0; i--) {
            int dir = val >> i & 1;
            Node *nxt = now->child[dir];
            if(!nxt) {
                nxt = new Node();
                now->child[dir] = nxt;
            }
            now = nxt;
            now->count++;
        }
    }
    bool erase(T val) {
        if(count(val) == 0) return false;
        Node *now = root;
        for(int i = LOG - 1; i >= 0; i--) {
            now->count--;
            now = now->child[val >> i & 1];
            assert(now != nullptr);
            assert(now->count > 0);
        }
        now->count--;
        return true;
    }
    T min_element() {
        assert(root != nullptr);
        T ret = 0;
        Node *now = root;
        for(int i = LOG - 1; i >= 0; i--) {
            int dir = (lazy_xor_value >> i & 1);
            Node *nxt = now->child[dir];
            if(!nxt or nxt->count == 0) {
                ret += T(1) << i;
                nxt = now->child[dir ^ 1];
            }
            now = nxt;
            assert(now != nullptr and now->count > 0);
        }
        return ret;
    }
    T max_element() {
        assert(root != nullptr);
        T ret = 0;
        Node *now = root;
        for(int i = LOG - 1; i >= 0; i--) {
            int dir = (lazy_xor_value >> i & 1) ^ 1;
            Node *nxt = now->child[dir];
            if(!nxt or nxt->count == 0) {
                nxt = now->child[dir ^ 1];
            } else {
                ret += T(1) << i;
            }
            now = nxt;
            assert(now != nullptr and now->count > 0);
        }
        return ret;
    }
    T get_kth_element(int k) { // 小さい方からk番目の値(0-indexed)
        assert(0 <= k and k < size());
        Node *now = root;
        T ret = 0;
        for(int i = LOG - 1; i >= 0; i--) {
            int b = lazy_xor_value >> i & 1;
            int small_count = (now->child[b] ? now->child[b]->count : 0);
            int big_count = (now->child[b ^ 1] ? now->child[b ^ 1]->count : 0);
            assert(0 < small_count + big_count);
            assert(k < small_count + big_count);
            if(k >= small_count) {
                ret += T(1) << i;
                now = now->child[b ^ 1];
                k -= small_count;
            } else {
                now = now->child[b];
            }
        }
        return ret;
    }
    int lower_bound(T val) {
        int ret = 0;
        Node* now = root;
        for(int i = LOG - 1; i >= 0; i--) {
            int b = lazy_xor_value >> i & 1;
            int small_count = (now->child[b] ? now->child[b]->count : 0);
            int big_count = (now->child[b ^ 1] ? now->child[b ^ 1]->count : 0);
            if(small_count == 0) {
                assert(big_count);
                now = now->child[b ^ 1];
            } else if(big_count == 0) {
                assert(small_count);
                now = now->child[b];
            } else {
                if(b == (val >> i & 1)) { 
                    now = now->child[b];
                } else {
                    ret += small_count;
                    now = now->child[b ^ 1];
                }
            }
        }
        return ret;
    }
    int upper_bound(T val) {
        int id = lower_bound(val);
        T kth_element = get_kth_element(id);
        if(kth_element != val) return id;
        int cnt = count(kth_element);
        return id + cnt;
    }
    int size() {
        if(!root) return 0;
        return root->count;
    }
    inline bool empty() const { return (!root or root->count == 0); }
    void all_xor(T val) { lazy_xor_value ^= val; }

  private:
    struct Node {
        int count;
        std::array<Node *, 2> child;
        Node() : count(0), child({nullptr, nullptr}) {}
    };
    Node *root;
    T lazy_xor_value;
};