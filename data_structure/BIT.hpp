template <typename T> struct BIT {
    int n;
    vector<T> bit;
    BIT(){}
    BIT(int _n) { init(_n); }
    void init(int _n) {
        n = _n + 1;
        bit.resize(n + 1, 0);
    }
    // [0, k)
    T sum(int k) {
        T res = 0;
        for(int i = k - 1; i >= 0; i = (i & (i + 1)) - 1) { res += bit[i]; }
        return res;
    }
    // [l, r)
    T sum(int l, int r) { return (l < r ? sum(r) - sum(l) : 0); }
    // bit[k] += x
    void add(int k, T x) {
        for(int i = k; i < n; i |= i + 1) { bit[i] += x; }
    }
    // v[0] + ... + v[res] >= x
    int lower_bound(T x) {
        int res = -1;
        int k = 1;
        while(2 * k <= n) { k <<= 1; }
        for(; k > 0; k >>= 1) {
            if(res + k < n && bit[res + k] < x) {
                x -= bit[res + k];
                res += k;
            }
        }
        return res + 1;
    }
};