template <typename T, typename E> struct LazySegmentTree {
    using F = function<T(T, T)>;
    using G = function<T(T, E)>;
    using H = function<E(E, E)>;
    using P = function<E(E, int)>;
    F f;
    G g;
    H h;
    P p;
    T d1;
    E d0;
    int n;
    vector<T> node;
    vector<E> lazy;

    LazySegmentTree(
        int sz, F f, G g, H h, T d1, E d0, vector<T> v = vector<T>(),
        P p = [](E a, int b) { return a; })
        : f(f), g(g), h(h), d1(d1), d0(d0), p(p) {
        init(sz);
        if(sz == (int)v.size()) {
            build(sz, v);
        }
    }

    void init(int sz) {
        n = 1;
        while(n < sz) {
            n *= 2;
        }
        node.clear();
        node.resize(2 * n - 1, d1);
        lazy.clear();
        lazy.resize(2 * n - 1, d0);
    }

    void build(int sz, vector<T> v) {
        for(int i = 0; i < sz; i++) {
            node[i + n - 1] = v[i];
        }
        for(int i = n - 2; i >= 0; i--) {
            node[i] = f(node[2 * i + 1], node[2 * i + 2]);
        }
    }

    inline void eval(int len, int now) {
        if(lazy[now] == d0) {
            return;
        }
        if(2 * now + 1 < 2 * n - 1) {
            lazy[2 * now + 1] = h(lazy[2 * now + 1], lazy[now]);
            lazy[2 * now + 2] = h(lazy[2 * now + 2], lazy[now]);
        }
        node[now] = g(node[now], p(lazy[now], len));
        lazy[now] = d0;
    }

    T update(int a, int b, E x, int now = 0, int l = 0, int r = -1) {
        if(r < 0) {
            r = n;
        }
        eval(r - l, now);
        if(r <= a || b <= l) {
            return node[now];
        }
        if(a <= l && r <= b) {
            lazy[now] = h(lazy[now], x);
            return g(node[now], p(lazy[now], r - l));
        }
        T vl = update(a, b, x, 2 * now + 1, l, (l + r) / 2);
        T vr = update(a, b, x, 2 * now + 2, (l + r) / 2, r);
        return node[now] = f(vl, vr);
    }

    T query(int a, int b, int now = 0, int l = 0, int r = -1) {
        if(r < 0) {
            r = n;
        }
        eval(r - l, now);
        if(r <= a || b <= l) {
            return d1;
        }
        if(a <= l && r <= b) {
            return node[now];
        }
        T vl = query(a, b, 2 * now + 1, l, (l + r) / 2);
        T vr = query(a, b, 2 * now + 2, (l + r) / 2, r);
        return f(vl, vr);
    }
};
