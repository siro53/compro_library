#include "modint.hpp"

using mint = ModInt<MOD>;

// - 多項式補間：n次以下の多項式fを具体的に求めるのが難しいときに用いるテク

// N次以下の多項式fについて、
// 相異なるn+1個の点(x_i, y_i)がfを通る(f(x_i)=y_iを満たす)とき、
// f(T)の値を返す
// O(N^2)
mint LagrangeInterPolation(vector<mint> x, vector<mint> y, mint T) {
    int N = x.size();
    N--;
    mint res = 0;
    for(int i = 0; i <= N; i++) {
        mint t = 1;
        for(int j = 0; j <= N; j++) {
            if(i == j) {
                continue;
            }
            t *= T - x[j];
            t /= (x[i] - x[j]);
        }
        res += t * y[i];
    }
    return res;
}

// N次以下の多項式fについて、
// 相異なるn+1個の点(x_i, y_i)がfを通る(f(x_i)=y_iを満たす)とき、
// f(x)を返す(f(x)の係数を返す)
// O(N^2)
vector<mint> LagrangeInterPolationCoef(vector<mint> x, vector<mint> y) {
    int N = x.size();
    N--;
    for(int i = 0; i <= N; i++) {
        mint t = 1;
        for(int j = 0; j <= N; j++) {
            if(i == j) {
                continue;
            }
            t *= (x[i] - x[j]);
        }
        y[i] /= t;
    }
    int now = 0;
    int next = 1;
    vector<vector<mint>> dp(2, vector<mint>(N + 2));
    dp[0][0] = -x[0];
    dp[0][1] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= N + 1; j++) {
            dp[next][j] = dp[now][j] * (-x[i]);
            if(j >= 1) {
                dp[next][j] += dp[now][j - 1];
            }
        }
        swap(next, now);
    }
    vector<mint> xinv(N + 1);
    for(int i = 0; i <= N; i++) {
        xinv[i] = x[i].inverse();
    }
    vector<mint> res(N + 1); // f(x)
    for(int i = 0; i <= N; i++) {
        if(y[i] == 0) {
            continue;
        }
        // 0で割らないように場合分け
        if(x[i] == 0) {
            for(int j = 0; j <= N; j++) {
                res[j] += dp[now][j + 1] * y[i];
            }
        } else {
            res[0] -= dp[now][0] * xinv[i] * y[i];
            mint prev = -dp[now][0] * xinv[i];
            for(int j = 1; j <= N; j++) {
                res[j] -= (dp[now][j] - prev) * xinv[i] * y[i];
                prev = (-dp[now][j] + prev) * xinv[i];
            }
        }
    }
    return res;
}

// N次以下の多項式fについて、
// 相異なるn+1個の点(x_i, y_i)がfを通る(f(x_i)=y_iを満たす)とき、
// f(T)の値を返す
// ただし、x_i = a + i * d (0<=i<=N)のようにx_iが等差数列になっているとき、
// O(Nlog(mod)) で求められる

mint LagrangeInterPolationArithmetic(mint a, mint d, vector<mint> y, mint T) {
    int N = y.size();
    N--;
    mint res = 0, ft = 1;
    for(int i = 0; i <= N; i++) {
        ft *= (T - (a + mint(i) * d));
    }
    mint f = 1;
    for(int i = 1; i <= N; i++) {
        f *= -d * mint(i);
    }
    res += y[0] * ft / (T - a);
    for(int i = 0; i < N; i++) {
        f *= d * mint(i + 1) / (d * mint(i - N));
        res += y[i + 1] / f * ft / (T - a - d * mint(i + 1));
    }
    return res;
}