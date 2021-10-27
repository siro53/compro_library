template<class T, class F, class Compare = greater<T>>
vector<pair<int, T>> monotone_minima(int H, int W, const F& f, const Compare &compare = Compare()) {
    vector<pair<int, T>> res(H);
    auto solve = [&](auto&& self, int si, int gi, int sj, int gj) -> void {
        if(si >= gi) return;
        int mi = (si + gi) / 2;
        int id = -1;
        T val;
        for(int j = sj; j < gj; j++) {
            T now = f(mi, j);
            if(id == -1 or compare(val, now)) val = now, id = j;
        }
        res[mi] = {id, val};
        self(self, si, mi, sj, id+1);
        self(self, mi+1, gi, id, gj);
    };
    solve(solve, 0, H, 0, W);
    return res;
}