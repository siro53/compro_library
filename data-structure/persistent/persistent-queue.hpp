#pragma once

template <class T, int LOG = 20> struct PersistentQueue {
    struct Node {
        T val;
        int idx;
        Node *pre[LOG]; // node[k] := このノードの2^k個前のノード

        Node(T val, int idx) : val(val), idx(idx) {}
    };
    Node *front_node;
    Node *back_node;

    PersistentQueue() : front_node(nullptr), back_node(nullptr) {}
    explicit PersistentQueue(Node *front_node, Node *back_node)
        : front_node(front_node), back_node(back_node) {}
    PersistentQueue push(const T &x) {
        Node *new_node = new Node(x, back_node ? back_node->idx + 1 : 0);
        new_node->pre[0] = back_node;
        for(int i = 1; i < LOG; i++) {
            Node *tmp = new_node->pre[i - 1];
            if(!tmp) break;
            new_node->pre[i] = tmp->pre[i - 1];
        }
        return PersistentQueue(front_node ? front_node : new_node, new_node);
    }
    PersistentQueue pop() {
        if(!front_node or !back_node or front_node->idx == back_node->idx) {
            return PersistentQueue();
        }
        int sz = back_node->idx - front_node->idx - 1;
        Node *node = back_node;
        for(int i = 0; i < LOG; i++)
            if(sz >> i & 1) node = node->pre[i];
        return PersistentQueue(node, back_node);
    }
    bool empty() const { return (front_node == nullptr and back_node == nullptr); }
    T front() const { return front_node->val; }
    T back() const { return back_node->val; }
};