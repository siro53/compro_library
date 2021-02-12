// 最初にbaseをgenBase()でランダムに生成すること！！！！！！！！！
// RollingHash(s, base) := 文字列sのハッシュテーブルを計算する
// get(l, r) := [l, r)のハッシュ値を求める
// connect(h1, h2, h2len) := ハッシュ値h1と, 長さh2lenのハッシュ値h2を結合する。
// LCP(b, l1, r1, l2, r2) := 区間[l1, r1)と、ハッシュテーブルがbである区間[l2,
// r2)の文字列の 最長共通接頭辞の長さを求める。
struct RollingHash {
    using ull = unsigned long long;
    using ui128 = __uint128_t;
    static const ull mod = (1ULL << 61) - 1;
    const ull base;
    vector<ull> hashed, power;

    inline ull add(ull a, ull b) {
        if((a += b) >= mod) {
            a -= mod;
        }
        return a;
    }
    inline ull mul(ull a, ull b) {
        ui128 t = (ui128)a * b;
        ull na = t >> 61;
        ull nb = t & mod;
        if((na += nb) >= mod) {
            na -= mod;
        }
        return na;
    }
    static inline ull genBase() {
        random_device seed_gen;
        mt19937_64 engine(seed_gen());
        uniform_int_distribution<ull> rand(2, mod - 2);
        return rand(engine);
    }
    RollingHash() = default;
    RollingHash(const string &s, ull base) : base(base) {
        int n = (int)s.size();
        hashed.assign(n + 1, 0);
        power.assign(n + 1, 0);
        power[0] = 1;
        for(int i = 0; i < n; i++) {
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = add(mul(hashed[i], base), s[i]);
        }
    }
    ull get(int l, int r) {
        return add(hashed[r], mod - mul(hashed[l], power[r - l]));
    }
    ull connect(ull h1, ull h2, int h2len) {
        return add(mul(h1, power[h2len]), h2);
    }
    int LCP(RollingHash &b, int l1, int r1, int l2, int r2) {
        assert(mod == b.mod);
        int len = min(r1 - l1, r2 - l2);
        int low = -1, high = len + 1;
        while(high - low > 1) {
            int mid = (low + high) >> 1;
            if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low;
    }
};