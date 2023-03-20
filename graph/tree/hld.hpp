#pragma once

#include <utility>

#include "../graph_template.hpp"

template <typename Cost = int> class HeavyLightDecomposition {
  public:
    explicit HeavyLightDecomposition(int N)
        : G(N), in(N), out(N), sz(N), head(N), par(N), dep(N), rev(N),
          isBuilt(false) {}
    explicit HeavyLightDecomposition(const Graph<Cost> &g)
        : G(g), in(g.size()), out(g.size()), sz(g.size()), head(g.size()),
          par(g.size()), dep(g.size()), rev(g.size()), isBuilt(false) {
        build();
    }
    void add_edge(int from, int to, Cost cost = 1) {
        G.add_undirected_edge(from, to, cost);
    }
    void build(int root = 0) {
        dfs1(root, -1, 0);
        head[root] = root;
        int idx = 0;
        dfs2(root, -1, idx);
        isBuilt = true;
    }
	int lca(int u, int v) const {
		assert(isBuilt);
		assert(0 <= u && u < (int)G.size());
		assert(0 <= v && v < (int)G.size());
		while(1) {
			if(in[u] > in[v]) std::swap(u, v);
			if(head[u] == head[v]) return u;
			v = par[head[v]];
		}
	}
	int dist(int u, int v) const {
		assert(isBuilt);
		assert(0 <= u && u < (int)G.size());
		assert(0 <= v && v < (int)G.size());
		return (dep[u] + dep[v] - 2 * dep[lca(u, v)]);
	}
	int la(int u, int k) const {
		assert(isBuilt);
		assert(0 <= u && u < (int)G.size());
		if(dep[u] < k) return -1;
		while(1) {
			if(in[u] - k >= in[head[u]]) {
				return rev[in[u] - k];
			}
			k -= (in[u] - in[head[u]] + 1);
			u = par[head[u]];
		}
	}
	template<class F>
	void path_query(int u, int v, const F& f, bool edge = false) const {
		assert(isBuilt);
		assert(0 <= u && u < (int)G.size());
		assert(0 <= v && v < (int)G.size());
		while(1) {
			if(in[u] > in[v]) std::swap(u, v);
			if(head[u] == head[v]) {
				f(in[u] + (int)(edge), in[v] + 1);
				break;
			} else {
				f(in[head[v]], in[v] + 1);
			}
			v = par[head[v]];
		}
	}
	template<class F, class F_rev>
	void path_query(int u, int v, const F& f, const F_rev& f_rev, bool edge = false) const {
		assert(isBuilt);
		assert(0 <= u && u < (int)G.size());
		assert(0 <= v && v < (int)G.size());
		int L = lca(u, v);
		path_query<F>(u, L, f, edge);
		path_query<F_rev>(L, v, f_rev, true);
	}
	template<class F>
	void subtree_query(int u, const F& f) const {
		assert(isBuilt);
		assert(0 <= u && u < (int)G.size());
		f(in[u], out[u]);
	}
	int operator[](int u) const {
		assert(isBuilt);
		assert(0 <= u && u < (int)G.size());
		return in[u];
	}

  private:
    Graph<Cost> G;
    std::vector<int> in, out, sz, head, par, dep, rev;
    bool isBuilt;

    void dfs1(int u, int p, int d) {
        dep[u] = d;
        sz[u] = 1;
        if(!G[u].empty() && G[u].front().to == p) {
            std::swap(G[u].front(), G[u].back());
        }
        for(auto &e : G[u]) {
            if(e.to == p) continue;
            dfs1(e.to, u, d + 1);
            sz[u] += sz[e.to];
            if(sz[e.to] > sz[G[u].front().to]) { std::swap(G[u].front(), e); }
        }
    }

    void dfs2(int u, int p, int &idx) {
        par[u] = p;
        in[u] = idx++;
        rev[in[u]] = u;
        for(const auto &e : G[u]) {
            if(e.to == p) continue;
            head[e.to] = (e.to == G[u].front().to ? head[u] : e.to);
            dfs2(e.to, u, idx);
        }
        out[u] = idx;
    }
};
