vector<int> maximum_independent_set(int N, vector<vector<int>> G) {
    int n1 = N / 2, n2 = N - n1;
 
    // ok1[S1] = S1が独立集合かどうか
    vector<bool> ok1(1 << n1, true);
    for(int u = 0; u < n1; u++) {
        for(int v = 0; v < u; v++) {
            if(G[u][v]) ok1[(1 << u) | (1 << v)] = false;
        }
    }
    for(int S = 0; S < (1 << n1); S++) {
        if(ok1[S]) continue;
        for(int v = 0; v < n1; v++) {
            if(S >> v & 1) continue;
            ok1[S | (1 << v)] = false;
        }
    }
    // Set[S1] = S1の頂点と辺で結ばれてないv2の頂点集合U
    vector<int> Set(1 << n1, 0);
    Set[0] = (1 << n2) - 1;
    for(int u = 0; u < n1; u++) {
        for(int v = 0; v < n2; v++) {
            if(G[u][v + n1] == 0) Set[1 << u] |= (1 << v);
        }
    }
    for(int S = 0; S < (1 << n1); S++) {
        for(int u = 0; u < n1; u++) {
            if(S >> u & 1) continue;
            Set[S | (1 << u)] = Set[S] & Set[1 << u];
        }
    }
    // dp[S2] = V2の部分集合S2の最大独立集合のサイズ
    vector<int> dp(1 << n2), pre(1 << n2, -1);
    for(int S = 0; S < (1 << n2); S++) dp[S] = __builtin_popcount(S);
    for(int u = 0; u < n2; u++) {
        for(int v = 0; v < u; v++) {
            if(G[u + n1][v + n1]) dp[(1 << u) | (1 << v)] = 0;
        }
    }
    for(int S = 1; S < (1 << n2); S++) {
        if(dp[S] > 0) continue;
        for(int v = 0; v < n2; v++) {
            if(S >> v & 1) continue;
            dp[S | (1 << v)] = 0;
        }
    }
    for(int S = 0; S < (1 << n2); S++) {
        for(int u = 0; u < n2; u++) {
            if(S >> u & 1) continue;
            if(dp[S | (1 << u)] < dp[S]) {
                dp[S | (1 << u)] = dp[S];
                pre[S | (1 << u)] = S;
            }
        }
    }
    // 復元
    int max_size = 0;
    int res_S1 = -1, res_S2 = -1;
    for(int S1 = 0; S1 < (1 << n1); S1++) {
        if(!ok1[S1]) continue;
        int sz1 = __builtin_popcount(S1);
        if(max_size < sz1 + dp[Set[S1]]) {
            max_size = sz1 + dp[Set[S1]];
            res_S1 = S1, res_S2 = Set[S1];
        }
    }
    vector<int> res;
    for(int i = 0; i < n1; i++) if(res_S1 >> i & 1) res.push_back(i);
    int now = res_S2;
    while(pre[now] != -1) {
        int T = now ^ pre[now];
        now = pre[now];
    }
    for(int i = 0; i < n2; i++) if(now >> i & 1) res.push_back(i+n1);
    return res;
}