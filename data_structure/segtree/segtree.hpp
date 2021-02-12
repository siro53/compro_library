template <typename Monoid> struct SegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;

  private:
    int n;
    vector<Monoid> node;
    Monoid E;
    F f;

  public:
    SegmentTree(vector<Monoid> &v, Monoid e, const F func) : f(func), E(e) {
        int sz = v.size();
        n = 1;
        while(n < sz) {
            n *= 2;
        }
        node.resize(2 * n - 1, E);
        for(int i = 0; i < sz; i++) {
            node[i + n - 1] = v[i];
        }
        for(int i = n - 2; i >= 0; i--) {
            node[i] = f(node[2 * i + 1], node[2 * i + 2]);
        }
    }

    void update(int i, Monoid val) {
        i += (n - 1);
        node[i] = val;
        while(i > 0) {
            i = (i - 1) / 2;
            node[i] = f(node[2 * i + 1], node[2 * i + 2]);
        }
    }

    Monoid query(int a, int b, int i = 0, int l = 0, int r = -1) {
        if(r < 0) {
            r = n;
        }
        if(r <= a || b <= l) {
            return E;
        }
        if(a <= l && r <= b) {
            return node[i];
        }
        Monoid vl = query(a, b, 2 * i + 1, l, (l + r) / 2);
        Monoid vr = query(a, b, 2 * i + 2, (l + r) / 2, r);
        return f(vl, vr);
    }

    Monoid operator[](const int &i) const { return node[i + n - 1]; }
};