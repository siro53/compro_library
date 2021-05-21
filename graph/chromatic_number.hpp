// 彩色数 O(n*2^n)
int chromatic_number(int N, const vector<vector<int>>& G) {
    // 本当はrandomに素数を取った方がいい
    constexpr int mod = int(1e9) + 9;
    // ind[S] = 頂点集合Sの部分集合であって、独立集合をなすものの個数
    vector<int> ind(1 << N, 0);
    // adj_bit[v] = vと隣接してる頂点の場所にbitを立てたもの
    vector<int> adj_bit(N, 0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) if(G[i][j]) adj_bit[i] |= (1 << j);
    }
    ind[0] = 1;
    for(int S = 1; S < (1 << N); S++) {
        int v = __builtin_ctz(S);
        ind[S] = ind[S ^ (1 << v)] + ind[(S ^ (1 << v)) & ~adj_bit[v]];
        if(ind[S] >= mod) ind[S] -= mod;
    }
    vector<ll> sum(1 << N);
    for(int S = 0; S < (1 << N); S++) sum[S] = ((N - (int)__builtin_popcount(S)) & 1 ? mod-1 : 1);
    for(int K = 1; K < N; K++) {
        ll res = 0;
        for(int S = 0; S < (1 << N); S++) {
            (sum[S] *= ind[S]) %= mod;
            res += sum[S];
        }
        if(res % mod > 0) return K;
    } 
    return N;
}