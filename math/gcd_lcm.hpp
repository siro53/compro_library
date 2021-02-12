ll GCD(ll a, ll b) {
    if(b == 0)
        return a;
    else
        return GCD(b, a % b);
}

ll LCM(ll a, ll b) { return a * b / GCD(a, b); }