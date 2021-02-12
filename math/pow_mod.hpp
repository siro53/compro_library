ll pow_mod(ll n, ll k, ll mod) {
    if(k == 0) {
        return 1;
    } else if(k % 2 == 1) {
        return pow_mod(n, k - 1, mod) * n % mod;
    } else {
        ll t = pow_mod(n, k / 2, mod);
        return t * t % mod;
    }
}