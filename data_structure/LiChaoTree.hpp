template <typename T> struct LiChaoTree {
    struct Line {
        T a, b;
        Line(T _a, T _b) : a(_a), b(_b) {}
        inline T f(T x) const { return (a * x + b); }
    };
    vector<T> X;
    vector<Line> lines;
    int n;
    LiChaoTree() {}
    LiChaoTree(const vector<T> &_X, T _INF) : X(_X) {
        n = 1;
        while(n < X.size()) {
            n <<= 1;
        }
        while(X.size() < n) {
            X.emplace_back(X.back() + 1);
        }
        lines.assign((n << 1) - 1, Line(0, _INF));
    }
    void update(Line &line, int k, int l, int r) {
        int mid = (l + r) >> 1;
        bool flg_l = (line.f(X[l]) < lines[k].f(X[l]));
        bool flg_r = (line.f(X[mid]) < lines[k].f(X[mid]));
        if(flg_r) {
            swap(lines[k], line);
        }
        if(l + 1 >= r) {
            return;
        }
        if(flg_l != flg_r) {
            update(line, 2 * k + 1, l, mid);
        } else {
            update(line, 2 * k + 2, mid, r);
        }
    }
    void add(T a, T b) {
        Line l(a, b);
        update(l, 0, 0, n);
    }
    T query(int k) {
        const T x = X[k];
        k += n - 1;
        T ans = lines[k].f(x);
        while(k > 0) {
            k = (k - 1) >> 1;
            chmin(ans, lines[k].f(x));
        }
        return ans;
    }
};
