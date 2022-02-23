// [l, r]
// 詳細：https://twitter.com/noshi91/status/1316352023609004033
template<class F> ll golden_section_search(ll l, ll r, F f) {
    l--, r++;
    ll a = 1, b = 1;
    while(a + b < r - l) {
        a += b;
        swap(a, b);
    }
    auto fl = f(l+a), fr = f(l+b);
    while(a < b) {
        b -= a;
        swap(a, b);
        if(fl < fr) {
            fr = fl;
            fl = f(l + a);
        }
        else {
            l += b;
            if(l + b < r) {
                fl = fr;
                fr = f(l + b);
            }
            else {
                b -= a;
                swap(a, b);
                fl = f(l + a);
            }
        }
    }
    return l + 1;
}