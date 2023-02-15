#pragma once

#include "../../random/rng.hpp"
#include "diameter.hpp"

template <class Cost> class TreeHash {
  public:
    explicit TreeHash(int n) : G(n) {
        RNG64 rng;
        for(int i = 0; i < n; i++) rnd.push_back(rng.randint(1, mod - 1));
    }
    explicit TreeHash(const Graph<Cost> &g) : G(g) {
        RNG64 rng;
        for(int i = 0; i < (int)G.size(); i++)
            rnd.push_back(rng.randint(1, mod - 1));
    }
    inline void add_edge(int from, int to, Cost cost = 1) {
        G.add_undirected_edge(from, to, cost);
    }
    unsigned long long get_hash() {
        auto [_, path] = get_diameter(G);
        int len = (int)path.size();
        std::vector<int> cent;
        if(len & 1) {
            cent = {path[len / 2]};
        } else {
            cent = {path[len / 2], path[len / 2 - 1]};
        }
        unsigned long long res = std::numeric_limits<unsigned long long>::max();
        for(const int &root : cent) {
            std::vector<unsigned long long> hashed(G.size(), 1);
            hash_dfs(root, -1, 0, hashed);
            res = std::min(res, hashed[root]);
        }
        return res;
    }

  private:
    Graph<Cost> G;
    static constexpr unsigned long long mod = (1ULL << 61) - 1;
    static inline std::vector<unsigned long long> rnd;

    inline unsigned long long add(unsigned long long a, unsigned long long b) {
        if((a += b) >= mod) a -= mod;
        return a;
    }
    inline unsigned long long mul(unsigned long long a, unsigned long long b) {
        __uint128_t t = a;
        t *= b;
        unsigned long long na = t >> 61;
        unsigned long long nb = t & mod;
        if((na += nb) >= mod) na -= mod;
        return na;
    }
    unsigned long long hash_dfs(int v, int p, int d,
                                std::vector<unsigned long long> &res) {
        for(const auto &e : G[v]) {
            if(e.to != p) {
                res[v] = mul(res[v], hash_dfs(e.to, v, d + 1, res));
            }
        }
        return res[v] = add(res[v], rnd[d]);
    }
};