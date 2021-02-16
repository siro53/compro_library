struct FastFactorize {
    ll mul(ll a, ll b, ll c) { return (__int128)a * b % c; }
    ll power(ll a, ll b, ll mod) {
        ll res = 1;
        while(b) {
            if(b & 1) { res = mul(res, a, mod); }
            a = mul(a, a, mod);
            b >>= 1;
        }
        return res;
    }
    bool isPrime(ll n) {
        if(!(n & 1) && n != 2) { return false; }
        ll d = n - 1;
        int s = __builtin_ctzll(d);
        d >>= s;
        vector<int> A;
        if(n <= 1000000000) {
            A = {2, 3, 5, 7};
        } else {
            A = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        }
        for(int a : A) {
            ll p = power(a, d, n);
            int i = s;
            while(p != 1 && p != n - 1 && a % n && (--i)) { p = mul(p, p, n); }
            if(p != n - 1 && i != s) { return false; }
        }
        return true;
    }
    ll rho(ll n) {
        auto f = [&](ll a) { return mul(a, a, n) + 1; };
        ll x = 0, y = 0, p = 2, q;
        int i = 1, t = 0;
        while((t++) % 40 || gcd(p, n) == 1) {
            if(x == y) {
                x = ++i;
                y = f(x);
            }
            if(q = mul(p, abs(y - x), n)) { p = q; }
            x = f(x);
            y = f(f(y));
        }
        return gcd(p, n);
    }
    vector<ll> factor(ll n) {
        if(n == 1) { return {}; }
        if(isPrime(n)) { return {n}; }
        ll a = rho(n);
        assert(a != n && a != 1);
        auto l = factor(a), r = factor(n / a);
        l.insert(l.end(), r.begin(), r.end());
        return l;
    }
    // 未verify, バグってるかも
    vector<ll> divisor(ll n) {
        vector<ll> res;
        auto v = factor(n);
        map<ll, int> cnt;
        for(const ll &a : v) cnt[a]++;
        sort(ALL(v));
        v.erase(unique(ALL(v)), v.end());
        int sz = int(v.size());

        auto dfs = [&](auto &&dfs, int d, ll now) -> void {
            if(d == sz) {
                res.emplace_back(now);
                return;
            }
            ll nxt = now;
            dfs(dfs, d + 1, nxt);
            REP(i, cnt[v[d]]) {
                nxt *= v[d];
                dfs(dfs, d + 1, nxt);
            }
        };

        dfs(dfs, 0, 1);
        sort(ALL(res));
        return res;
    }
};