// https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409
class osa_k {
  private:
    int N;
    vector<int> min_factor;

  public:
    osa_k(int N) : N(N), min_factor(N) {
        iota(ALL(min_factor), 0);
        for(int i = 2; i * i < N; i++) {
            if(min_factor[i] < i) continue;
            for(int j = i * i; j < N; j += i) {
                if(min_factor[j] == j) min_factor[j] = i;
            }
        }
    }
    
    vector<int> factor(int n) {
        vector<int> res;
        while(n > 1) {
            res.push_back(min_factor[n]);
            n /= min_factor[n];
        }
        return res;
    }
};