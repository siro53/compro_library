template<class S, S (*op)(S, S), S (*e)()> 
class DisjointSparseTable {
    vector<vector<S>> table;
    vector<int> lookup;

public:
    DisjointSparseTable() {}
    DisjointSparseTable(vector<S> v) {
        int b = 0;
        while((1 << b) <= (int)v.size()) b++;
        table.resize(b, vector<S>(v.size(), e()));

        for(int i = 0; i < (int)v.size(); i++) table[0][i] = v[i];
        for(int i = 1; i < b; i++) {
            int shift = (1 << i);
            for(int j = 0; j < (int)v.size(); j += (shift << 1)) {
                int t = min(j + shift, (int)v.size());
                table[i][t-1] = v[t-1];
                for(int k = t - 2; k >= j; k--) table[i][k] = op(v[k], table[i][k + 1]);
                if((int)v.size() <= t) break;
                table[i][t] = v[t];
                int r = min(t + shift, (int)v.size());
                for(int k = t + 1; k < r; k++) table[i][k] = op(table[i][k - 1], v[k]);
            }
        }
        lookup.resize(1 << b);
        for(int i = 2; i < (int)lookup.size(); i++) {
            lookup[i] = lookup[i >> 1] + 1;
        }
    }

    S prod(int l, int r) {
        if(l >= --r) return table[0][l];
        int p = lookup[l ^ r];
        return op(table[p][l], table[p][r]);
    }
};