#pragma once

#include "graph_template.hpp"

template<typename Cost = int>
std::vector<int> topological_sort(const Graph<Cost>& G) {
    int N = (int)G.size();
    std::vector<int> indeg(N, 0);
    for(int i = 0; i < N; i++) {
        for(const auto& e : G[i]) {
            indeg[e.to]++;
        }
    }
    std::vector<int> st, ret;
    for(int i = 0; i < N; i++) {
        if(indeg[i] == 0) st.push_back(i);
    }
    while(!st.empty()) {
        int u = st.back();
        st.pop_back();
        ret.push_back(u);
        for(const auto& e : G[u]) {
            indeg[e.to]--;
            if(indeg[e.to] == 0) st.push_back(e.to);
        }
    }
    return ret;
}