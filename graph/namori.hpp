#pragma once

#include "graph_template.hpp"

template <typename Cost> class Namori : public Graph<Cost> {
  public:
    using Graph<Cost>::Graph;
    using Graph<Cost>::G;

    void build() {
        int N = (int)G.size();
        std::vector<int> deg(N), st;
        std::vector<bool> seen(N);
        for(int i = 0; i < N; i++) {
            deg[i] = (int)G[i].size();
            if(deg[i] == 1) {
                st.emplace_back(i);
                seen[i] = true;
            }
        }
        while(!st.empty()) {
            int u = st.back();
            st.pop_back();
            for(int v : G[u]) {
                if(seen[v]) continue;
                deg[v]--;
                if(deg[v] == 1) {
                    st.emplace_back(v);
                    seen[v] = true;
                }
            }
        }
        loop_id.resize(N, -1);
        std::vector<int> loop;
        for(int i = 0; i < N; i++) {
            if(seen[i]) continue;
            auto dfs = [&](auto &&self, int u) -> void {
                loop_id[u] = (int)loop.size();
                loop.push_back(u);
                seen[u] = true;
                for(int v : G[u]) {
                    if(seen[v]) continue;
                    self(self, v);
                }
            };
            dfs(dfs, i);
            break;
        }
        for(int i = 0; i < (int)loop.size(); i++) {
            auto dfs = [&](auto&& self, int u) -> void {
                for(int v : G[u]) {
                    if(loop_id[v] != -1) continue;
                    loop_id[v] = loop_id[u];
                    self(self, v);
                }
            };
            dfs(dfs, loop[i]);
        }
    }
    int operator[](int i) const { return loop_id[i]; }

  private:
    std::vector<int> loop_id;
};