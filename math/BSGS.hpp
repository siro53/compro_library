// 与えられたx, y, pに対して、x^i=y(mod p)を満たす最小の正の整数iを返す
// 存在しない場合は-1
// O(√p log(p))
ll modlog(ll x, ll y, ll p) {
    ll H = sqrt(p) + 1;
    pair<ll, ll> baby[H];
    for(ll b = 0, xby = y; b < H; b++, xby = (xby * x) % p) {
        baby[b] = make_pair(xby, b);
    }
    sort(baby, baby + H);
    ll xH = 1;
    for(int i = 0; i < H; ++i) {
        xH = (xH * x) % p;
    }
    for(ll a = 1, xaH = xH; a <= H; a++, xaH = (xaH * xH) % p) {
        auto it = lower_bound(baby, baby + H, make_pair(xaH + 1, 0LL));
        if(it == baby) {
            continue;
        }
        it--;
        if(it->first == xaH) {
            return a * H - it->second;
        }
    }
    return -1;
}