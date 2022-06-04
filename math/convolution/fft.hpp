namespace FFT {
    using D = double;
    struct C {
        D x, y;
        C() : x(0), y(0) {}
        C(D x, D y) : x(x), y(y) {}
        C(complex<D> c) : x(c.real()), y(c.imag()) {}
        inline C operator+(const C &c) const { return C(x + c.x, y + c.y); }
        inline C operator-(const C &c) const { return C(x - c.x, y - c.y); }
        inline C operator*(const C &c) const {
            return C(x * c.x - y * c.y, x * c.y + y * c.x);
        }
    };
    const D PI = acosl(-1);

    vector<C> fft(vector<C> a, bool inv = false) {
        int n = int(a.size());
        int h = 0;
        for(int i = 0; 1 << i < n; i++) h++;
        for(int i = 0; i < n; i++) {
            int j = 0;
            for(int k = 0; k < h; k++) j |= (i >> k & 1) << (h - 1 - k);
            if(i < j) swap(a[i], a[j]);
        }
        for(int b = 1; b < n; b *= 2) {
            for(int j = 0; j < b; j++) {
                C w = C(polar<D>(1, (2 * PI) / (2 * b) * j * (inv ? 1 : -1)));
                for(int k = 0; k < n; k += 2 * b) {
                    C s = a[j + k], t = a[j + k + b] * w;
                    a[j + k] = s + t, a[j + k + b] = s - t;
                }
            }
        }
        if(inv) {
            for(int i = 0; i < n; i++) a[i] = C(a[i].x / n, a[i].y / n);
        }
        return a;
    }
    vector<C> fft(vector<D> a, bool inv = false) {
        vector<C> A(a.size());
        for(int i = 0; i < int(a.size()); i++) A[i] = C(a[i], 0);
        return fft(A, inv);
    }
    vector<D> conv(vector<D> a, vector<D> b) {
        int s = int(a.size() + b.size()) - 1;
        int t = 1;
        while(t < s) t *= 2;
        a.resize(t), b.resize(t);
        vector<C> A = fft(a), B = fft(b);
        for(int i = 0; i < t; i++) A[i] = A[i] * B[i];
        A = fft(A, true);
        a.resize(s);
        for(int i = 0; i < s; i++) a[i] = A[i].x;
        return a;
    }
} // namespace FFT