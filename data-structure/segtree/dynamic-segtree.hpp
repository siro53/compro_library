#pragma once

#include <array>
#include <cassert>
#include <vector>

template <class Monoid, long long id_min, long long id_max>
class DynamicSegtree {
  public:
    using T = typename Monoid::value_type;

    explicit DynamicSegtree() : root(nullptr) {}

    void set(long long p, T val) { set(root, id_min, id_max, p, val); }
    T get(long long p) { return get(root, id_min, id_max, p); }
    T prod(long long l, long long r) { return prod(root, id_min, id_max, l, r); }
 
  private:
    struct Node {
        T val;
        std::array<Node *, 2> ch;
        Node() : val(Monoid::e()), ch({nullptr, nullptr}) {}
        Node(T val) : val(val), ch({nullptr, nullptr}) {}
    };

    Node *root;

    void set(Node *&node, long long l, long long r, long long p, T val) {
        if(node == nullptr) node = new Node();
        if(r - l == 1) {
            node->val = val;
            return;
        }
        long long mid = (l + r) / 2;
        if(p < mid)
            set(node->ch[0], l, mid, p, val);
        else
            set(node->ch[1], mid, r, p, val);
        node->val =
            Monoid::op(node->ch[0] == nullptr ? Monoid::e() : node->ch[0]->val,
                       node->ch[1] == nullptr ? Monoid::e() : node->ch[1]->val);
    }

    T get(Node *&node, long long l, long long r, long long p) {
        if(node == nullptr) return Monoid::e();
        if(r - l == 1) return node->val;
        long long mid = (l + r) / 2;
        if(p < mid)
            return get(node->ch[0], l, mid, p);
        else
            return get(node->ch[1], mid, r, p);
    }

    T prod(Node *&node, long long l, long long r, long long ql, long long qr) {
        if(node == nullptr or (qr <= l or r <= ql)) return Monoid::e();
        if(ql <= l and r <= qr) return node->val;
        long long mid = (l + r) / 2;
        return Monoid::op(prod(node->ch[0], l, mid, ql, qr),
                          prod(node->ch[1], mid, r, ql, qr));
    }
};