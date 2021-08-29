// 区間篩
// [L, R)に含まれる整数の素因数分解
// R <= 10^12, R - L <= 10^6 として O(log(R-L))
class segment_sieve {
private:
    ll L, R, M; // M = sqrt(R)+1
    vector<int> small;
    vector<vector<ll>> large;
    vector<ll> aux;
public:
    segment_sieve(ll L, ll R): L(L), R(R), M(sqrt(R)+1) {
        small.resize(M);
        iota(small.begin(), small.end(), 0);
        large.resize(R - L);
        aux.resize(R - L, 1);

        for(ll i = 2; i*i < R; i++) {
            if(small[i] < i) continue;
            for(ll j = i*i; j < M; j += i) {
                if(small[j] == j) small[j] = i;
            }

            for(ll j = (L+i-1)/i*i; j < R; j += i) {
                ll k = j;
                do{
                    if(aux[j-L] * aux[j-L] > R) break;
                    large[j-L].push_back(i);
                    aux[j-L] *= i;
                    k /= i;
                }while(k % i == 0);
            }
        }
    }

    vector<ll> factor(ll n) {
        assert(L <= n and n < R);
        vector<ll> res = large[n-L];
        n /= aux[n-L];
        if(n >= M) {
            res.push_back(n);
            return res;
        }
        while(n > 1) {
            res.push_back(small[n]);
            n /= small[n];
        }
        return res;
    }
};
