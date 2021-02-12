template <typename T> struct Compress {
    vector<T> v;
    Compress() {}
    Compress(vector<T> vv) : v(vv) {
        sort(ALL(v));
        v.erase(unique(ALL(v)), end(v));
    }
    void build(vector<T> vv) {
        v = vv;
        sort(ALL(v));
        v.erase(unique(ALL(v)), end(v));
    }
    int get(T x) { return (int)(lower_bound(ALL(v), x) - v.begin()); }
    T &operator[](int i) { return v[i]; }
    size_t size() { return v.size(); }
};