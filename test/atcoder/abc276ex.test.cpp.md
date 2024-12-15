---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/imos2D.hpp
    title: data-structure/imos2D.hpp
  - icon: ':question:'
    path: data-structure/sum2D.hpp
    title: data-structure/sum2D.hpp
  - icon: ':x:'
    path: math/F2.hpp
    title: math/F2.hpp
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc276/tasks/abc276_h
    links:
    - https://atcoder.jp/contests/abc276/tasks/abc276_h
  bundledCode: "#line 1 \"test/atcoder/abc276ex.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc276/tasks/abc276_h\"\
    \n#line 1 \"template/template.cpp\"\n#pragma region Macros\n#include <bits/stdc++.h>\n\
    using namespace std;\n// input output utils\nnamespace siro53_io {\n    // https://maspypy.github.io/library/other/io_old.hpp\n\
    \    struct has_val_impl {\n        template <class T>\n        static auto check(T\
    \ &&x) -> decltype(x.val(), std::true_type{});\n\n        template <class T> static\
    \ auto check(...) -> std::false_type;\n    };\n\n    template <class T>\n    class\
    \ has_val : public decltype(has_val_impl::check<T>(std::declval<T>())) {\n   \
    \ };\n\n    // debug\n    template <class T, enable_if_t<is_integral<T>::value,\
    \ int> = 0>\n    void dump(const T t) {\n        cerr << t;\n    }\n    template\
    \ <class T, enable_if_t<is_floating_point<T>::value, int> = 0>\n    void dump(const\
    \ T t) {\n        cerr << t;\n    }\n    template <class T, typename enable_if<has_val<T>::value>::type\
    \ * = nullptr>\n    void dump(const T &t) {\n        cerr << t.val();\n    }\n\
    \    void dump(__int128_t n) {\n        if(n == 0) {\n            cerr << '0';\n\
    \            return;\n        } else if(n < 0) {\n            cerr << '-';\n \
    \           n = -n;\n        }\n        string s;\n        while(n > 0) {\n  \
    \          s += (char)('0' + n % 10);\n            n /= 10;\n        }\n     \
    \   reverse(s.begin(), s.end());\n        cerr << s;\n    }\n    void dump(const\
    \ string &s) { cerr << s; }\n    void dump(const char *s) {\n        int n = (int)strlen(s);\n\
    \        for(int i = 0; i < n; i++) cerr << s[i];\n    }\n    template <class\
    \ T1, class T2> void dump(const pair<T1, T2> &p) {\n        cerr << '(';\n   \
    \     dump(p.first);\n        cerr << ',';\n        dump(p.second);\n        cerr\
    \ << ')';\n    }\n    template <class T> void dump(const vector<T> &v) {\n   \
    \     cerr << '{';\n        for(int i = 0; i < (int)v.size(); i++) {\n       \
    \     dump(v[i]);\n            if(i < (int)v.size() - 1) cerr << ',';\n      \
    \  }\n        cerr << '}';\n    }\n    template <class T> void dump(const set<T>\
    \ &s) {\n        cerr << '{';\n        for(auto it = s.begin(); it != s.end();\
    \ it++) {\n            dump(*it);\n            if(next(it) != s.end()) cerr <<\
    \ ',';\n        }\n        cerr << '}';\n    }\n    template <class Key, class\
    \ Value> void dump(const map<Key, Value> &mp) {\n        cerr << '{';\n      \
    \  for(auto it = mp.begin(); it != mp.end(); it++) {\n            dump(*it);\n\
    \            if(next(it) != mp.end()) cerr << ',';\n        }\n        cerr <<\
    \ '}';\n    }\n    template <class Key, class Value>\n    void dump(const unordered_map<Key,\
    \ Value> &mp) {\n        cerr << '{';\n        for(auto it = mp.begin(); it !=\
    \ mp.end(); it++) {\n            dump(*it);\n            if(next(it) != mp.end())\
    \ cerr << ',';\n        }\n        cerr << '}';\n    }\n    template <class T>\
    \ void dump(const deque<T> &v) {\n        cerr << '{';\n        for(int i = 0;\
    \ i < (int)v.size(); i++) {\n            dump(v[i]);\n            if(i < (int)v.size()\
    \ - 1) cerr << ',';\n        }\n        cerr << '}';\n    }\n    template <class\
    \ T> void dump(queue<T> q) {\n        cerr << '{';\n        while(!q.empty())\
    \ {\n            dump(q.front());\n            if((int)q.size() > 1) cerr << ',';\n\
    \            q.pop();\n        }\n        cerr << '}';\n    }\n\n    void debug_print()\
    \ { cerr << endl; }\n    template <class Head, class... Tail>\n    void debug_print(const\
    \ Head &h, const Tail &...t) {\n        dump(h);\n        if(sizeof...(Tail))\
    \ dump(' ');\n        debug_print(t...);\n    }\n    // print\n    template <class\
    \ T, enable_if_t<is_integral<T>::value, int> = 0>\n    void print_single(const\
    \ T t) {\n        cout << t;\n    }\n    template <class T, enable_if_t<is_floating_point<T>::value,\
    \ int> = 0>\n    void print_single(const T t) {\n        cout << t;\n    }\n \
    \   template <class T, typename enable_if<has_val<T>::value>::type * = nullptr>\n\
    \    void print_single(const T t) {\n        cout << t.val();\n    }\n    void\
    \ print_single(__int128_t n) {\n        if(n == 0) {\n            cout << '0';\n\
    \            return;\n        } else if(n < 0) {\n            cout << '-';\n \
    \           n = -n;\n        }\n        string s;\n        while(n > 0) {\n  \
    \          s += (char)('0' + n % 10);\n            n /= 10;\n        }\n     \
    \   reverse(s.begin(), s.end());\n        cout << s;\n    }\n    void print_single(const\
    \ string &s) { cout << s; }\n    void print_single(const char *s) {\n        int\
    \ n = (int)strlen(s);\n        for(int i = 0; i < n; i++) cout << s[i];\n    }\n\
    \    template <class T1, class T2> void print_single(const pair<T1, T2> &p) {\n\
    \        print_single(p.first);\n        cout << ' ';\n        print_single(p.second);\n\
    \    }\n    template <class T> void print_single(const vector<T> &v) {\n     \
    \   for(int i = 0; i < (int)v.size(); i++) {\n            print_single(v[i]);\n\
    \            if(i < (int)v.size() - 1) cout << ' ';\n        }\n    }\n    template\
    \ <class T> void print_single(const set<T> &s) {\n        for(auto it = s.begin();\
    \ it != s.end(); it++) {\n            print_single(*it);\n            if(next(it)\
    \ != s.end()) cout << ' ';\n        }\n    }\n    template <class T> void print_single(const\
    \ deque<T> &v) {\n        for(int i = 0; i < (int)v.size(); i++) {\n         \
    \   print_single(v[i]);\n            if(i < (int)v.size() - 1) cout << ' ';\n\
    \        }\n    }\n    template <class T> void print_single(queue<T> q) {\n  \
    \      while(!q.empty()) {\n            print_single(q.front());\n           \
    \ if((int)q.size() > 1) cout << ' ';\n            q.pop();\n        }\n    }\n\
    \n    void print() { cout << '\\n'; }\n    template <class Head, class... Tail>\n\
    \    void print(const Head &h, const Tail &...t) {\n        print_single(h);\n\
    \        if(sizeof...(Tail)) print_single(' ');\n        print(t...);\n    }\n\
    \n    // input\n    template <class T, enable_if_t<is_integral<T>::value, int>\
    \ = 0>\n    void input_single(T &t) {\n        cin >> t;\n    }\n    template\
    \ <class T, enable_if_t<is_floating_point<T>::value, int> = 0>\n    void input_single(T\
    \ &t) {\n        cin >> t;\n    }\n    template <class T, typename enable_if<has_val<T>::value>::type\
    \ * = nullptr>\n    void input_single(T &t) {\n        cin >> t;\n    }\n    void\
    \ input_single(__int128_t &n) {\n        string s;\n        cin >> s;\n      \
    \  if(s == \"0\") {\n            n = 0;\n            return;\n        }\n    \
    \    bool is_minus = false;\n        if(s[0] == '-') {\n            s = s.substr(1);\n\
    \            is_minus = true;\n        }\n        n = 0;\n        for(int i =\
    \ 0; i < (int)s.size(); i++) n = n * 10 + (int)(s[i] - '0');\n        if(is_minus)\
    \ n = -n;\n    }\n    void input_single(string &s) { cin >> s; }\n    template\
    \ <class T1, class T2> void input_single(pair<T1, T2> &p) {\n        input_single(p.first);\n\
    \        input_single(p.second);\n    }\n    template <class T> void input_single(vector<T>\
    \ &v) {\n        for(auto &e : v) input_single(e);\n    }\n    void input() {}\n\
    \    template <class Head, class... Tail> void input(Head &h, Tail &...t) {\n\
    \        input_single(h);\n        input(t...);\n    }\n}; // namespace siro53_io\n\
    #ifdef DEBUG\n#define debug(...)                                             \
    \                \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]: \"\
    , debug_print(__VA_ARGS__)\n#else\n#define debug(...) (void(0))\n#endif\n// io\
    \ setup\nstruct Setup {\n    Setup() {\n        cin.tie(0);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(15);\n    }\n} __Setup;\nusing namespace\
    \ siro53_io;\n// types\nusing ll = long long;\nusing i128 = __int128_t;\n// input\
    \ macros\n#define INT(...)                                                   \
    \            \\\n    int __VA_ARGS__;                                        \
    \                   \\\n    input(__VA_ARGS__)\n#define LL(...)              \
    \                                                  \\\n    ll __VA_ARGS__;   \
    \                                                         \\\n    input(__VA_ARGS__)\n\
    #define STRING(...)                                                          \
    \  \\\n    string __VA_ARGS__;                                               \
    \         \\\n    input(__VA_ARGS__)\n#define CHAR(...)                      \
    \                                        \\\n    char __VA_ARGS__;           \
    \                                               \\\n    input(__VA_ARGS__)\n#define\
    \ DBL(...)                                                               \\\n\
    \    double __VA_ARGS__;                                                     \
    \   \\\n    input(__VA_ARGS__)\n#define LD(...)                              \
    \                                  \\\n    long double __VA_ARGS__;          \
    \                                         \\\n    input(__VA_ARGS__)\n#define\
    \ UINT(...)                                                              \\\n\
    \    unsigned int __VA_ARGS__;                                               \
    \   \\\n    input(__VA_ARGS__)\n#define ULL(...)                             \
    \                                  \\\n    unsigned long long __VA_ARGS__;   \
    \                                         \\\n    input(__VA_ARGS__)\n#define\
    \ VEC(name, type, len)                                                   \\\n\
    \    vector<type> name(len);                                                 \
    \   \\\n    input(name);\n#define VEC2(name, type, len1, len2)               \
    \                            \\\n    vector name(len1, vector<type>(len2));  \
    \                                   \\\n    input(name);\n// other macros\n//\
    \ https://trap.jp/post/1224/\n#define OVERLOAD3(_1, _2, _3, name, ...) name\n\
    #define ALL(v) (v).begin(), (v).end()\n#define RALL(v) (v).rbegin(), (v).rend()\n\
    #define REP1(i, n) for(int i = 0; i < int(n); i++)\n#define REP2(i, a, b) for(int\
    \ i = (a); i < int(b); i++)\n#define REP(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)\n\
    #define SORT(v) sort(ALL(v))\n#define RSORT(v) sort(RALL(v))\n#define UNIQUE(v)\
    \                                                              \\\n    sort(ALL(v)),\
    \ (v).erase(unique(ALL(v)), (v).end()), v.shrink_to_fit()\n#define REV(v) reverse(ALL(v))\n\
    #define SZ(v) ((int)(v).size())\n#define MIN(v) (*min_element(ALL(v)))\n#define\
    \ MAX(v) (*max_element(ALL(v)))\n// util const\nconst int INF = 1 << 30;\nconst\
    \ ll LLINF = 1LL << 60;\nconstexpr int MOD = 1000000007;\nconstexpr int MOD2 =\
    \ 998244353;\nconst int dx[4] = {1, 0, -1, 0};\nconst int dy[4] = {0, 1, 0, -1};\n\
    // util functions\nvoid Case(int i) { cout << \"Case #\" << i << \": \"; }\nint\
    \ popcnt(int x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return __builtin_popcountll(x);\
    \ }\ntemplate <class T> inline bool chmax(T &a, T b) {\n    return (a < b ? a\
    \ = b, true : false);\n}\ntemplate <class T> inline bool chmin(T &a, T b) {\n\
    \    return (a > b ? a = b, true : false);\n}\ntemplate <class T, int dim>\nauto\
    \ make_vector_impl(vector<int>& sizes, const T &e) {\n    if constexpr(dim ==\
    \ 1) {\n        return vector(sizes[0], e);\n    } else {\n        int n = sizes[dim\
    \ - 1];\n        sizes.pop_back();\n        return vector(n, make_vector_impl<T,\
    \ dim - 1>(sizes, e));\n    }\n}\ntemplate <class T, int dim>\nauto make_vector(const\
    \ int (&sizes)[dim], const T &e = T()) {\n    vector<int> s(dim);\n    for(int\
    \ i = 0; i < dim; i++) s[i] = sizes[dim - i - 1];\n    return make_vector_impl<T,\
    \ dim>(s, e);\n}\nvector<int> iota_gen(int n, int start = 0) {\n    vector<int>\
    \ ord(n);\n    iota(ord.begin(), ord.end(), start);\n    return ord;\n}\ntemplate<typename\
    \ T>\nvector<int> ord_sort(const vector<T>& v, bool greater = false) {\n    auto\
    \ ord = iota_gen((int)v.size());\n    sort(ALL(ord), [&](int i, int j) {\n   \
    \     if(greater) return v[i] > v[j];\n        return v[i] < v[j];\n    });\n\
    \    return ord;\n}\n#pragma endregion Macros\n#line 2 \"data-structure/imos2D.hpp\"\
    \n\n#line 5 \"data-structure/imos2D.hpp\"\n\ntemplate <typename T> \nclass imos2D\
    \ {\npublic:\n    int H, W;\n\n    imos2D() = default;\n    explicit imos2D(int\
    \ H, int W): H(H), W(W), imos(H + 1, std::vector<T>(W + 1, 0)), isBuilt(false)\
    \ {}\n\n    void add(int li, int lj, int ri, int rj, T val) {\n        assert(0\
    \ <= li and li < H);\n        assert(li <= ri and ri <= H);\n        assert(0\
    \ <= lj and lj < W);\n        assert(lj <= rj and rj <= W);\n        imos[li][lj]\
    \ += val;\n        imos[li][rj] -= val;\n        imos[ri][lj] -= val;\n      \
    \  imos[ri][rj] += val;\n    } \n\n    void build() {\n        for(int i = 0;\
    \ i <= H; i++) {\n            for(int j = 1; j <= W; j++) {\n                imos[i][j]\
    \ += imos[i][j - 1];\n            }\n        }\n        for(int j = 0; j <= W;\
    \ j++) {\n            for(int i = 1; i <= H; i++) {\n                imos[i][j]\
    \ += imos[i - 1][j];\n            }\n        }\n        isBuilt = true;\n    }\n\
    \n    inline std::vector<T>& operator[](int i) {\n        assert(isBuilt);\n \
    \       return imos[i];\n    }\n\nprivate:\n    std::vector<std::vector<T>> imos;\n\
    \    bool isBuilt;\n};\n#line 2 \"data-structure/sum2D.hpp\"\n\n#line 5 \"data-structure/sum2D.hpp\"\
    \n\ntemplate <typename T> class sum2D {\n  public:\n    sum2D() = default;\n \
    \   explicit sum2D(int height, int width)\n        : sum(height + 1, std::vector<T>(width\
    \ + 1, 0)), isBuilt(false) {}\n    void add(int row, int column, T val) {\n  \
    \      assert(0 <= row + 1 && row + 1 < (int)sum.size());\n        assert(0 <=\
    \ column + 1 && column + 1 < (int)sum[0].size());\n        sum[row + 1][column\
    \ + 1] += val;\n    }\n    void build() {\n        for(int i = 1; i < (int)sum.size();\
    \ i++) {\n            for(int j = 1; j < (int)sum[0].size(); j++) {\n        \
    \        sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];\n   \
    \         }\n        }\n        isBuilt = true;\n    }\n    T get_sum(int row_l,\
    \ int row_r, int column_l, int column_r) const {\n        assert(row_l <= row_r);\n\
    \        assert(column_l <= column_r);\n        assert(isBuilt);\n        return\
    \ (sum[row_r][column_r] - sum[row_l][column_r] -\n                sum[row_r][column_l]\
    \ + sum[row_l][column_l]);\n    }\n\n  private:\n    std::vector<std::vector<T>>\
    \ sum;\n    bool isBuilt;\n};\n#line 2 \"math/F2.hpp\"\n\n#line 7 \"math/F2.hpp\"\
    \n\ntemplate<int MAX_WIDTH>\nclass BitMatrix {\npublic:\n    int H, W;\n\n   \
    \ BitMatrix(): H(1), W(1), mat(1) {\n        assert(W <= MAX_WIDTH);\n    }\n\n\
    \    BitMatrix(int H, int W): H(H), W(W), mat(H) {\n        assert(W <= MAX_WIDTH);\n\
    \    }\n\n    inline std::bitset<MAX_WIDTH>& operator[](int i) { return mat[i];\
    \ }\n\n    // \u6383\u304D\u51FA\u3057\u6CD5\n    // https://drken1215.hatenablog.com/entry/2019/03/20/202800\n\
    \    int row_reduction(vector<int>& b) {\n        assert((int)b.size() == H);\n\
    \        int rank = 0;\n        for(int j = 0; j < W; j++) {\n            int\
    \ pivot = -1;\n            for(int i = rank; i < H; i++) {\n                if(mat[i][j])\
    \ {\n                    pivot = i;\n                    break;\n            \
    \    }\n            }\n            if(pivot == -1) continue;\n            std::swap(mat[pivot],\
    \ mat[rank]);\n            std::swap(b[pivot], b[rank]);\n            for(int\
    \ i = 0; i < H; i++) {\n                if(i != rank and mat[i][j]) {\n      \
    \              mat[i] ^= mat[rank];\n                    b[i] ^= b[rank];\n  \
    \              }\n            }\n            rank++;\n        }\n        return\
    \ rank;\n    }\n\n    // \u6383\u304D\u51FA\u3057\u6CD5\n    // https://drken1215.hatenablog.com/entry/2019/03/20/202800\n\
    \    int row_reduction() {\n        std::vector<int> b(H, 0);\n        return\
    \ row_reduction(b);\n    }\n\nprivate:\n    std::vector<std::bitset<MAX_WIDTH>>\
    \ mat;\n};\n\n// {rank, Ax = b\u306E\u89E3\u306E\u3046\u30611\u3064} \u3092\u8FD4\
    \u3059\n// \u89E3\u306A\u3057\u306E\u5834\u5408\u306F {-1, {}} \u3092\u8FD4\u3059\
    \ntemplate<int MAX_WIDTH>\nstd::pair<int, std::vector<int>> linear_equation_F2(BitMatrix<MAX_WIDTH>\
    \ A, std::vector<int> b) {\n    int H = A.H, W = A.W;\n    int rank = A.row_reduction(b);\n\
    \    // \u89E3\u306E\u5B58\u5728\u30C1\u30A7\u30C3\u30AF\n    for(int i = rank;\
    \ i < H; i++) if(b[i]) {\n        return {-1, {}};\n    }\n    std::vector<int>\
    \ ret(W);\n    for(int i = 0; i < rank; i++) {\n        int p = -1;\n        for(int\
    \ j = 0; j < W; j++) {\n            if(A[i][j]) {\n                p = j;\n  \
    \              break;\n            }\n        }\n        if(p == -1) continue;\n\
    \        ret[p] = b[i];\n    }\n    return {rank, ret};\n}\n#line 6 \"test/atcoder/abc276ex.test.cpp\"\
    \n\nusing Query = tuple<int, int, int, int, int>;\nconst int MAX_H = 2048;\nconst\
    \ int MAX_W = MAX_H * 4;\n\nint main() {\n    map<pair<int, int>, int> ID;\n \
    \   vector<pair<int, int>> rev;\n    auto f = [&](int i, int j) -> int {\n   \
    \     if(ID.count({i, j})) return ID[{i, j}];\n        int ret = SZ(ID);\n   \
    \     ID[{i, j}] = ret;\n        rev.emplace_back(i, j);\n        return ret;\n\
    \    };\n\n    INT(N, Q);\n    vector<Query> qs(Q);\n    int eq_num = 0;\n   \
    \ for(auto& [a, b, c, d, e] : qs) {\n        cin >> a >> b >> c >> d >> e;\n \
    \       a--;\n        c--;\n        if(e == 0) continue;\n        f(a, c);\n \
    \       f(a, d);\n        f(b, c);\n        f(b, d);\n        eq_num++;\n    }\n\
    \n    int sz = SZ(ID);\n    BitMatrix<MAX_W> mat(eq_num, sz);\n    vector<int>\
    \ res(eq_num, 0);\n    {\n        int i = 0;\n        for(auto& [a, b, c, d, e]\
    \ : qs) {\n            if(e == 0) continue;\n            for(int ii : {a, b})\
    \ {\n                for(int jj : {c, d}) {\n                    mat[i][f(ii,\
    \ jj)] = 1;\n                }\n            }\n            res[i] = (e == 2 ?\
    \ 1 : 0);\n            i++;\n        }\n    }\n    auto [rank, answer] = linear_equation_F2<MAX_W>(mat,\
    \ res);\n    if(rank == -1) {\n        print(\"No\");\n        return 0;\n   \
    \ }\n\n    auto out = make_vector<int>({N, N}, 0);\n    {\n        auto tmp =\
    \ make_vector<int>({N + 1, N + 1}, 0);\n        REP(i, sz) {\n            auto\
    \ [ii, jj] = rev[i];\n            tmp[ii][jj] = answer[i];\n        }\n      \
    \  REP(i, N) REP(j, N) {\n            out[i][j] = (tmp[i + 1][j + 1] ^ tmp[i][j\
    \ + 1] ^ tmp[i + 1][j] ^ tmp[i][j]) + 1;\n        }\n    }\n    {\n        imos2D<int>\
    \ imos(N, N);\n        for(const auto& [a, b, c, d, e] : qs) {\n            if(e\
    \ == 0) continue;\n            imos.add(a, c, b, d, 1);\n        }\n        imos.build();\n\
    \        sum2D<int> sum(N, N);\n        REP(i, N) REP(j, N) {\n            if(imos[i][j]\
    \ == 0) {\n                out[i][j] = 0;\n                sum.add(i, j, 1);\n\
    \            }\n        }\n        sum.build();\n        for(auto& [a, b, c, d,\
    \ e] : qs) {\n            if(e == 0 and sum.get_sum(a, b, c, d) == 0) {\n    \
    \            print(\"No\");\n                return 0;\n            }\n      \
    \  }\n    }\n    print(\"Yes\");\n    REP(i, N) print(out[i]);\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc276/tasks/abc276_h\"\n#include\
    \ \"../../template/template.cpp\"\n#include \"../../data-structure/imos2D.hpp\"\
    \n#include \"../../data-structure/sum2D.hpp\"\n#include \"../../math/F2.hpp\"\n\
    \nusing Query = tuple<int, int, int, int, int>;\nconst int MAX_H = 2048;\nconst\
    \ int MAX_W = MAX_H * 4;\n\nint main() {\n    map<pair<int, int>, int> ID;\n \
    \   vector<pair<int, int>> rev;\n    auto f = [&](int i, int j) -> int {\n   \
    \     if(ID.count({i, j})) return ID[{i, j}];\n        int ret = SZ(ID);\n   \
    \     ID[{i, j}] = ret;\n        rev.emplace_back(i, j);\n        return ret;\n\
    \    };\n\n    INT(N, Q);\n    vector<Query> qs(Q);\n    int eq_num = 0;\n   \
    \ for(auto& [a, b, c, d, e] : qs) {\n        cin >> a >> b >> c >> d >> e;\n \
    \       a--;\n        c--;\n        if(e == 0) continue;\n        f(a, c);\n \
    \       f(a, d);\n        f(b, c);\n        f(b, d);\n        eq_num++;\n    }\n\
    \n    int sz = SZ(ID);\n    BitMatrix<MAX_W> mat(eq_num, sz);\n    vector<int>\
    \ res(eq_num, 0);\n    {\n        int i = 0;\n        for(auto& [a, b, c, d, e]\
    \ : qs) {\n            if(e == 0) continue;\n            for(int ii : {a, b})\
    \ {\n                for(int jj : {c, d}) {\n                    mat[i][f(ii,\
    \ jj)] = 1;\n                }\n            }\n            res[i] = (e == 2 ?\
    \ 1 : 0);\n            i++;\n        }\n    }\n    auto [rank, answer] = linear_equation_F2<MAX_W>(mat,\
    \ res);\n    if(rank == -1) {\n        print(\"No\");\n        return 0;\n   \
    \ }\n\n    auto out = make_vector<int>({N, N}, 0);\n    {\n        auto tmp =\
    \ make_vector<int>({N + 1, N + 1}, 0);\n        REP(i, sz) {\n            auto\
    \ [ii, jj] = rev[i];\n            tmp[ii][jj] = answer[i];\n        }\n      \
    \  REP(i, N) REP(j, N) {\n            out[i][j] = (tmp[i + 1][j + 1] ^ tmp[i][j\
    \ + 1] ^ tmp[i + 1][j] ^ tmp[i][j]) + 1;\n        }\n    }\n    {\n        imos2D<int>\
    \ imos(N, N);\n        for(const auto& [a, b, c, d, e] : qs) {\n            if(e\
    \ == 0) continue;\n            imos.add(a, c, b, d, 1);\n        }\n        imos.build();\n\
    \        sum2D<int> sum(N, N);\n        REP(i, N) REP(j, N) {\n            if(imos[i][j]\
    \ == 0) {\n                out[i][j] = 0;\n                sum.add(i, j, 1);\n\
    \            }\n        }\n        sum.build();\n        for(auto& [a, b, c, d,\
    \ e] : qs) {\n            if(e == 0 and sum.get_sum(a, b, c, d) == 0) {\n    \
    \            print(\"No\");\n                return 0;\n            }\n      \
    \  }\n    }\n    print(\"Yes\");\n    REP(i, N) print(out[i]);\n}"
  dependsOn:
  - template/template.cpp
  - data-structure/imos2D.hpp
  - data-structure/sum2D.hpp
  - math/F2.hpp
  isVerificationFile: true
  path: test/atcoder/abc276ex.test.cpp
  requiredBy: []
  timestamp: '2024-12-15 14:15:56+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc276ex.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc276ex.test.cpp
- /verify/test/atcoder/abc276ex.test.cpp.html
title: test/atcoder/abc276ex.test.cpp
---
