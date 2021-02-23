template <class T> class sum_2d {
    vector<vector<T>> imos;

  public:
    sum_2d(int H, int W) : imos(H + 1, vector<T>(W + 1, 0)) {}
    void add(int i, int j, T val) {
        if(i + 1 >= int(imos.size()) || j + 1 >= int(imos[0].size())) return;
        imos[i + 1][j + 1] += val;
    }
    void build() {
        for(int i = 1; i < int(imos.size()); i++) {
            for(int j = 1; j < int(imos[0].size()); j++) {
                imos[i][j] +=
                    imos[i - 1][j] + imos[i][j - 1] - imos[i - 1][j - 1];
            }
        }
    }
    T get_sum(int si, int sj, int gi, int gj) {
        return (imos[gi][gj] - imos[si][gj] - imos[gi][sj] + imos[si][sj]);
    }
};