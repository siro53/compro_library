vector<bool> eratosthenes(int n) {
    vector<bool> isp(n + 1, true);
    isp[0] = isp[1] = false;
    for(int i = 2; i * i <= n; i++) {
        if(!isp[i]) continue;
        for(int j = i+i; j <= n; j += i) isp[j] = false;
    }
    return isp;
}