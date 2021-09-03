class Mo {
  private:
    vector<int> L, R, ord;
    vector<bool> nowuse;
    int BUCKET_SIZE;// bucket size
    int nl, nr, ptr;

  public:
    Mo(int N) : BUCKET_SIZE(sqrt(N)), nl(0), nr(0), ptr(0), nowuse(N) {}

    // [l, r)
    void insert(int l, int r) {
        L.push_back(l);
        R.push_back(r);
    }
    // クエリをsortする
    void build() {
        ord.resize(L.size());
        iota(ALL(ord), 0);
        sort(ALL(ord), [&](int l, int r) {
            if(L[l] / BUCKET_SIZE != L[r] / BUCKET_SIZE)
                return (L[l] < L[r]);
            else
                return (R[l] < R[r]);
        });
    }
    // クエリを1つ進める, 返り値はクエリのid
    int process() {
        if(ptr == ord.size()) return -1;
        int qid = ord[ptr];
        while(nl > L[qid]) add_left(--nl);
        while(nr < R[qid]) add_right(nr++);
        while(nl < L[qid]) del_left(nl++);
        while(nr > R[qid]) del_right(--nr);
        return ord[ptr++];
    }

    void add_left(int id);
    void add_right(int id);
    void del_left(int id);
    void del_right(int id);
};