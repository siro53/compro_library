#pragma once

#include "../graph/scc.hpp"

template<class Cost = int>
class TwoSat {
public:
    TwoSat() = default;
    explicit TwoSat(int N): N(N), scc(N * 2), ans(N), called_satisfiable(false) {}

    void add_clause(int i, bool f_i, int j, bool f_j) {
        if(!f_i) i = NOT(i);
        if(!f_j) j = NOT(j);
        scc.add_directed_edge(i, NOT(j));
        scc.add_directed_edge(j, NOT(i));
    }
    bool satisfiable() {
        scc.build();
        for(int i = 0; i < N; i++) {
            if(scc[i] == scc[NOT(i)]) return false;
            ans[i] = (scc[i] < scc[NOT(i)]);
        }
        called_satisfiable = true;
        return true;
    }
    std::vector<bool> get_answer() const {
        assert(called_satisfiable);
        return ans;
    }

private:
    int N;
    SCC<Cost> scc;
    std::vector<bool> ans;
    bool called_satisfiable;

    inline int NOT(int i) { return i + (i < N ? N : -N); }
};