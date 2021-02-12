template<class T>
map<T, int> prime_factor(T n) {
    map<T, int> ret;
    for(T i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if(n != 1)
        ret[n] = 1;
    return ret;
}