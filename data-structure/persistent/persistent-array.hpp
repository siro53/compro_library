#pragma once

#include <string.h>
#include <utility>
#include <vector>

template <class T, int LOG = 4> struct PersistentArray {
    struct Node {
        T val;
        Node *childs[1 << LOG];

        Node() { memset(childs, 0, sizeof(childs)); }
        Node(const Node *node) { memcpy(childs, node->childs, sizeof(childs)); }
        Node(const Node &node) { memcpy(childs, node.childs, sizeof(childs)); }
    };

    Node *root;
    int depth;
    T identity;
    const int full_bit = (1 << LOG) - 1;

    PersistentArray() {}
    explicit PersistentArray(int N, const T &id = 0)
        : root(new Node()), depth(0), identity(id) {
        PersistentArray(std::vector<T>(N, id));
    }
    PersistentArray(const std::vector<T> &v) : root(new Node()), depth(0) {
        int N = (int)v.size();
        while(N > 0) {
            N >>= LOG;
            depth++;
        }
        N = (int)v.size();
        for(int i = 0; i < N; i++) {
            Node *now = root;
            for(int mask = i, d = depth; d > 0; d--) {
                if(!now->childs[mask & full_bit]) {
                    now->childs[mask & full_bit] = new Node();
                }
                now = now->childs[mask & full_bit];
                mask >>= LOG;
            }
            now->val = v[i];
        }
    }

    T get(int idx) { return get(root, idx); }

    Node *set(int idx, const T &new_value) { return set(root, idx, new_value); }

    T get(Node *node, int idx) {
        for(int i = 0; i < depth; i++) {
            node = node ? node->childs[idx & full_bit] : nullptr;
            idx >>= LOG;
        }
        return (node ? node->val : identity);
    }

    Node *set(Node *node, int idx, T new_value) {
        std::vector<std::pair<Node *, int>> st;
        for(int i = 0; i < depth; i++) {
            st.emplace_back(node, idx & full_bit);
            node = node ? node->childs[idx & full_bit] : nullptr;
            idx >>= LOG;
        }
        Node *new_child = new Node();
        new_child->val = new_value;
        while(!st.empty()) {
            auto [par, k] = st.back();
            st.pop_back();
            Node *new_par = par ? new Node(par) : new Node();
            new_par->childs[k] = new_child;
            new_child = new_par;
        }
        return (root = new_child);
    }
};