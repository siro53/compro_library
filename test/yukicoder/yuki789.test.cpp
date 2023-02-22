#define PROBLEM "https://yukicoder.me/problems/no/789"
#include "../../template/template.cpp"
#include "../../data-structure/segtree/dynamic-segtree.hpp"
#include "../../data-structure/monoid/add.hpp"

int main() {
    int Q;
    cin >> Q;
    DynamicSegtree<MonoidAdd<ll>, 0, 1000000002> seg;
    ll ans = 0;
    while(Q--) {
        int type;
        cin >> type;
        if(type == 0) {
            ll x, y;
            cin >> x >> y;
            seg.set(x, seg.get(x) + y);
        } else {
            ll l, r;
            cin >> l >> r;
            r++;
            ans += seg.prod(l, r);
        }
    }
    cout << ans << endl;
}