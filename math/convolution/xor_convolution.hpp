namespace xor_convolution {
    template<class T>
    void fwt(vector<T> &f, bool isInverse = false) {
        int n = (int)f.size(); // n は必ず 2 べき
        for(int i = 1; i < n; i <<= 1) {
            for(int j = 0; j < n; j++) {
                if(j & i) continue;
                T x = f[j], y = f[j | i];
                f[j] = x + y, f[j | i] = x - y;
                if(isInverse) {
                    f[j] /= 2, f[j | i] /= 2;
                }
            }
        }
    }

    template<class T>
    vector<T> convolution(vector<T> a, vector<T> b) {
        fwt<T>(a);
        fwt<T>(b);
        vector<T> c(a.size());
        for(int i = 0; i < (int)a.size(); i++) {
            c[i] = a[i] * b[i];
        }
        fwt<T>(c, true);
        return c;
    }
};