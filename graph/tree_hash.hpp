class TreeHash {
  private:
    using ull = unsigned long long;
    using ui128 = __uint128_t;
    static const ull mod = (1ULL << 61) - 1;
    static vector<ull> rnd;
    int N;
    vector<vector<int>> G;
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
    ull hash_dfs(int v, int p, int d, vector<ull> &res) {
        for(const int &u : G[v]) {
            if(u != p) {
                res[v] = mul(res[v], hash_dfs(u, v, d + 1, res));
            }
        }
        return res[v] = add(res[v], rnd[d]);
    }
    vector<int> get_diameter_path() {
        vector<int> depth(N), par(N);

        auto dfs = [&](auto &&dfs, int v, int p, int d) -> void {
            depth[v] = d;
            par[v] = p;
            for(const int &u : G[v]) {
                if(u != p) {
                    dfs(dfs, u, v, d + 1);
                }
            }
        };

        dfs(dfs, 0, -1, 0);
        int from = max_element(ALL(depth)) - depth.begin();
        dfs(dfs, from, -1, 0);
        int to = max_element(ALL(depth)) - depth.begin();

        vector<int> res;
        int now = to;
        while(now != from) {
            res.emplace_back(now);
            now = par[now];
        }
        res.emplace_back(now);

        return res;
    }

  public:
    TreeHash(int n) : N(n), G(n) {
        random_device seed_gen;
        mt19937_64 engine(seed_gen());
        uniform_int_distribution<ull> rand(1, mod - 1);
        while((int)rnd.size() < N) {
            rnd.emplace_back(rand(engine));
        }
    }
    void add_edge(int u, int v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    ull get_hash() {
        auto dpath = get_diameter_path();
        int len = (int)dpath.size();
        vector<int> cent;
        if(len & 1) {
            cent = {dpath[len / 2]};
        } else {
            cent = {dpath[len / 2], dpath[len / 2 - 1]};
        }
        ull res = UINT64_MAX;
        for(const int &root : cent) {
            vector<ull> hashed(N, 1);
            hash_dfs(root, -1, 0, hashed);
            chmin(res, hashed[root]);
        }
        return res;
    }
};

vector<TreeHash::ull> TreeHash::rnd;