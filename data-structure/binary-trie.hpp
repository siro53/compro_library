#pragma once

#include <array>
#include <cassert>
#include <vector>

template <class T = int, int LOG = 31> class BinaryTrie {
  public:
    explicit BinaryTrie(int pool_size = 1) {
        nodes.reserve(pool_size);
        nodes.emplace_back(0);
    }
    int count(T val) {
        int now_id = 0;
        for(int i = LOG - 1; i >= 0; i--) {
            now_id = nodes[now_id].ch[val >> i & 1];
            if(now_id == -1) return 0;
        }
        return nodes[now_id].cnt;
    }
    void insert(T val) {
        int now_id = 0;
        for(int i = LOG - 1; i >= 0; i--) {
            assert(0 <= now_id && now_id < (int)nodes.size());
            int nxt_id = nodes[now_id].ch[val >> i & 1];
            if(nxt_id == -1) {
                nxt_id = (int)nodes.size();
                nodes[now_id].ch[val >> i & 1] = nxt_id;
                nodes.emplace_back(nxt_id);
            }
            now_id = nxt_id;
            nodes[now_id].cnt++;
        }
    }
    void erase(T val) {
        if(count(val) == 0) return;
        int now_id = 0;
        for(int i = LOG - 1; i >= 0; i--) {
            now_id = nodes[now_id].ch[val >> i & 1];
            assert(0 <= now_id && now_id < (int)nodes.size());
            assert(nodes[now_id].cnt > 0);
            nodes[now_id].cnt--;
        }
    }
    T set_xor_min(T val) {
        int now_id = 0;
        T ans = 0;
        for(int i = LOG - 1; i >= 0; i--) {
            int dir = val >> i & 1;
            if(nodes[now_id].ch[dir] == -1 or nodes[nodes[now_id].ch[dir]].cnt == 0) {
                ans += (T(1) << i);
                dir ^= 1;
            }
            now_id = nodes[now_id].ch[dir];
            assert(0 <= now_id && now_id < (int)nodes.size());
        }
        return ans;
    }

  private:
    struct Node {
        int id, cnt;
        std::array<int, 2> ch;
        Node(int id) : id(id), cnt(0), ch({-1, -1}) {}
    };
    std::vector<Node> nodes;
};