template <class S, S (*op)(S, S), S (*e)()> class segtree {
    int N, sz;
    vector<S> node;

  public:
    segtree() {}
    segtree(vector<S> v) : N(int(v.size())) {
        sz = 1;
        while(sz < N) sz <<= 1;
        node.resize(2 * sz, e());
        for(int i = 0; i < N; i++) node[i + sz] = v[i];
        for(int i = sz - 1; i >= 1; i--)
            node[i] = op(node[2 * i], node[2 * i + 1]);
    }
    segtree(int n) : segtree(vector<S>(n, e())) {}
    void set(int p, S val) {
        p += sz;
        node[p] = val;
        while(p >>= 1) node[p] = op(node[2 * p], node[2 * p + 1]);
    }
    S get(int p) { return node[p + sz]; }
    S prod(int l, int r) {
        S vl = e(), vr = e();
        for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if(l & 1) vl = op(vl, node[l++]);
            if(r & 1) vr = op(vr, node[--r]);
        }
        return op(vl, vr);
    }
    S all_prod() { return node[1]; }
};