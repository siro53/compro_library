---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: geometry/base.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/ccw.hpp
    title: geometry/ccw.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/convex-cut.hpp
    title: geometry/convex-cut.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/convex-hull.hpp
    title: geometry/convex-hull.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross-point.hpp
    title: geometry/cross-point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross.hpp
    title: geometry/cross.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/degree-to-radian.hpp
    title: geometry/degree-to-radian.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance-between-line-and-point.hpp
    title: geometry/distance-between-line-and-point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance-between-segment-and-point.hpp
    title: geometry/distance-between-segment-and-point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance-between-segments.hpp
    title: geometry/distance-between-segments.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/dot.hpp
    title: geometry/dot.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is-contained.hpp
    title: geometry/is-contained.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is-convex.hpp
    title: geometry/is-convex.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is-in-circle.hpp
    title: geometry/is-in-circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is-intersect.hpp
    title: geometry/is-intersect.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is-orthogonal.hpp
    title: geometry/is-orthogonal.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is-parallel.hpp
    title: geometry/is-parallel.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is-point-on-line.hpp
    title: geometry/is-point-on-line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is-point-on-segment.hpp
    title: geometry/is-point-on-segment.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/normal-vector.hpp
    title: geometry/normal-vector.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/polygon-area.hpp
    title: geometry/polygon-area.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/projection.hpp
    title: geometry/projection.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/radian-to-degree.hpp
    title: geometry/radian-to-degree.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/reflection.hpp
    title: geometry/reflection.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/rotate.hpp
    title: geometry/rotate.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: geometry/segment.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/tangent-to-circle.hpp
    title: geometry/tangent-to-circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/tangent.hpp
    title: geometry/tangent.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/unit-vector.hpp
    title: geometry/unit-vector.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest/geometry/geometry.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"template/template.cpp\"\
    \n#pragma region Macros\n#include <bits/stdc++.h>\nusing namespace std;\n// input\
    \ output utils\nnamespace siro53_io {\n    // https://maspypy.github.io/library/other/io_old.hpp\n\
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
    \    return ord;\n}\n#pragma endregion Macros\n#line 3 \"test/mytest/geometry/geometry.test.cpp\"\
    \n\n#line 2 \"geometry/ccw.hpp\"\n\n#line 2 \"geometry/cross.hpp\"\n\n#line 2\
    \ \"geometry/base.hpp\"\n\n#line 5 \"geometry/base.hpp\"\n\nnamespace geometry\
    \ {\n    // Point : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\
    \u30EB\u3068\u3057\u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\
    \u6319\u8EF8(imag)\u3092y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long\
    \ double;\n    using Point = std::complex<D>;\n    const D EPS = 1e-7;\n    const\
    \ D PI = std::acos(D(-1));\n\n    inline bool equal(const D &a, const D &b) {\
    \ return std::fabs(a - b) < EPS; }\n} // namespace geometry\n#line 4 \"geometry/cross.hpp\"\
    \n\nnamespace geometry {\n    // \u5916\u7A4D(cross product) : a\xD7b = |a||b|sin\u0398\
    \n    inline D cross(const Point &a, const Point &b) {\n        return (a.real()\
    \ * b.imag() - a.imag() * b.real());\n    }\n} // namespace geometry\n#line 2\
    \ \"geometry/dot.hpp\"\n\n#line 4 \"geometry/dot.hpp\"\n\nnamespace geometry {\n\
    \    // \u5185\u7A4D(dot product) : a\u30FBb = |a||b|cos\u0398\n    inline D dot(const\
    \ Point &a, const Point &b) {\n        return (a.real() * b.real() + a.imag()\
    \ * b.imag());\n    }\n} // namespace geometry\n#line 5 \"geometry/ccw.hpp\"\n\
    \nnamespace geometry {\n    // \u70B9\u306E\u56DE\u8EE2\u65B9\u5411\n    // \u70B9\
    a, b, c\u306E\u4F4D\u7F6E\u95A2\u4FC2\u306B\u3064\u3044\u3066(a\u304C\u57FA\u6E96\
    \u70B9)\n    inline int ccw(const Point &a, Point b, Point c) {\n        b -=\
    \ a, c -= a;\n        // \u70B9a, b, c \u304C\n        // \u53CD\u6642\u8A08\u56DE\
    \u308A\u306E\u6642\u3001\n        if(cross(b, c) > EPS) return 1;\n        //\
    \ \u6642\u8A08\u56DE\u308A\u306E\u6642\u3001\n        if(cross(b, c) < -EPS) return\
    \ -1;\n        // c, a, b\u304C\u3053\u306E\u9806\u756A\u3067\u540C\u4E00\u76F4\
    \u7DDA\u4E0A\u306B\u3042\u308B\u6642\u3001\n        if(dot(b, c) < 0) return 2;\n\
    \        // a, b, c\u304C\u3053\u306E\u9806\u756A\u3067\u540C\u4E00\u76F4\u7DDA\
    \u4E0A\u306B\u3042\u308B\u5834\u5408\u3001\n        if(std::norm(b) < std::norm(c))\
    \ return -2;\n        // c\u304C\u7DDA\u5206ab\u4E0A\u306B\u3042\u308B\u5834\u5408\
    \u3001\n        return 0;\n    }\n} // namespace geometry\n#line 2 \"geometry/convex-cut.hpp\"\
    \n\n#line 4 \"geometry/convex-cut.hpp\"\n\n#line 2 \"geometry/cross-point.hpp\"\
    \n\n#line 5 \"geometry/cross-point.hpp\"\n\n#line 2 \"geometry/circle.hpp\"\n\n\
    #line 4 \"geometry/circle.hpp\"\n\nnamespace geometry {\n    // Circle : \u5186\
    \u3092\u8868\u3059\u69CB\u9020\u4F53\n    // p\u304C\u4E2D\u5FC3\u306E\u4F4D\u7F6E\
    \u30D9\u30AF\u30C8\u30EB\u3001r\u306F\u534A\u5F84\n    struct Circle {\n     \
    \   Point p;\n        D r;\n\n        Circle() = default;\n\n        Circle(Point\
    \ p, D r) : p(p), r(r) {}\n    };\n} // namespace geometry\n#line 2 \"geometry/distance-between-line-and-point.hpp\"\
    \n\n#line 2 \"geometry/line.hpp\"\n\n#line 4 \"geometry/line.hpp\"\n\nnamespace\
    \ geometry {\n    // Line : \u76F4\u7DDA\u3092\u8868\u3059\u69CB\u9020\u4F53\n\
    \    // b - a \u3067\u76F4\u7DDA\u30FB\u7DDA\u5206\u3092\u8868\u305B\u308B\n \
    \   struct Line {\n        Point a, b;\n        Line() = default;\n        Line(Point\
    \ a, Point b) : a(a), b(b) {}\n        // Ax+By=C\n        Line(D A, D B, D C)\
    \ {\n            if(equal(A, 0)) {\n                a = Point(0, C / B), b = Point(1,\
    \ C / B);\n            } else if(equal(B, 0)) {\n                a = Point(C /\
    \ A, 0), b = Point(C / A, 1);\n            } else if(equal(C, 0)) {\n        \
    \        a = Point(0, C / B), b = Point(1, (C - A) / B);\n            } else {\n\
    \                a = Point(0, C / B), b = Point(C / A, 0);\n            }\n  \
    \      }\n    };\n} // namespace geometry\n#line 5 \"geometry/distance-between-line-and-point.hpp\"\
    \n\nnamespace geometry {\n    // \u76F4\u7DDAl\u3068\u70B9p\u306E\u8DDD\u96E2\u3092\
    \u6C42\u3081\u308B\n    inline D distanceBetweenLineAndPoint(const Line &l, const\
    \ Point &p) {\n        return std::abs(cross(l.b - l.a, p - l.a)) / std::abs(l.b\
    \ - l.a);\n    }\n} // namespace geometry\n#line 2 \"geometry/is-intersect.hpp\"\
    \n\n#line 2 \"geometry/segment.hpp\"\n\n#line 4 \"geometry/segment.hpp\"\n\nnamespace\
    \ geometry {\n    // Segment : \u7DDA\u5206\u3092\u8868\u3059\u69CB\u9020\u4F53\
    \n    // Line\u3068\u540C\u3058\n    struct Segment : Line {\n        Segment()\
    \ = default;\n\n        Segment(Point a, Point b) : Line(a, b) {}\n        D get_dist()\
    \ { return std::abs(a - b); }\n    };\n} // namespace geometry\n#line 6 \"geometry/is-intersect.hpp\"\
    \n\nnamespace geometry {\n    // \u7DDA\u5206s\u3068\u7DDA\u5206t\u304C\u4EA4\u5DEE\
    \u3057\u3066\u3044\u308B\u304B\u3069\u3046\u304B\n    // bound:\u7DDA\u5206\u306E\
    \u7AEF\u70B9\u3092\u542B\u3080\u304B\n    inline bool isIntersect(const Segment\
    \ &s, const Segment &t, bool bound) {\n        return ccw(s.a, s.b, t.a) * ccw(s.a,\
    \ s.b, t.b) < bound &&\n               ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b)\
    \ < bound;\n    }\n\n    // 2\u3064\u306E\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A\n\
    \    // \u8FD4\u308A\u5024\u306F\u5171\u901A\u63A5\u7DDA\u306E\u6570\n    inline\
    \ int isIntersect(const Circle &c1, const Circle &c2) {\n        D d = std::abs(c1.p\
    \ - c2.p);\n        // 2\u3064\u306E\u5186\u304C\u96E2\u308C\u3066\u3044\u308B\
    \u5834\u5408\n        if(d > c1.r + c2.r + EPS) return 4;\n        // \u5916\u63A5\
    \u3057\u3066\u3044\u308B\u5834\u5408\n        if(equal(d, c1.r + c2.r)) return\
    \ 3;\n        // \u5185\u63A5\u3057\u3066\u3044\u308B\u5834\u5408\n        if(equal(d,\
    \ std::abs(c1.r - c2.r))) return 1;\n        // \u5185\u5305\u3057\u3066\u3044\
    \u308B\u5834\u5408\n        if(d < std::abs(c1.r - c2.r) - EPS) return 0;\n  \
    \      return 2;\n    }\n} // namespace geometry\n#line 2 \"geometry/projection.hpp\"\
    \n\n#line 6 \"geometry/projection.hpp\"\n\nnamespace geometry {\n    // \u5C04\
    \u5F71(projection)\n    // \u76F4\u7DDA(\u7DDA\u5206)l\u306B\u70B9p\u304B\u3089\
    \u5F15\u3044\u305F\u5782\u7DDA\u306E\u8DB3\u3092\u6C42\u3081\u308B\n    inline\
    \ Point projection(const Line &l, const Point &p) {\n        D t = dot(p - l.a,\
    \ l.a - l.b) / std::norm(l.a - l.b);\n        return l.a + (l.a - l.b) * t;\n\
    \    }\n\n    inline Point projection(const Segment &l, const Point &p) {\n  \
    \      D t = dot(p - l.a, l.a - l.b) / std::norm(l.a - l.b);\n        return l.a\
    \ + (l.a - l.b) * t;\n    }\n} // namespace geometry\n#line 2 \"geometry/unit-vector.hpp\"\
    \n\n#line 4 \"geometry/unit-vector.hpp\"\n\nnamespace geometry {\n    // \u5358\
    \u4F4D\u30D9\u30AF\u30C8\u30EB(unit vector)\u3092\u6C42\u3081\u308B\n    inline\
    \ Point unitVector(const Point &a) { return a / std::abs(a); }\n} // namespace\
    \ geometry\n#line 12 \"geometry/cross-point.hpp\"\n\nnamespace geometry {\n  \
    \  // \u76F4\u7DDAs, t\u306E\u4EA4\u70B9\u306E\u8A08\u7B97\n    inline Point crossPoint(const\
    \ Line &s, const Line &t) {\n        D d1 = cross(s.b - s.a, t.b - t.a);\n   \
    \     D d2 = cross(s.b - s.a, s.b - t.a);\n        if(equal(std::abs(d1), 0) &&\
    \ equal(std::abs(d2), 0)) return t.a;\n        return t.a + (t.b - t.a) * (d2\
    \ / d1);\n    }\n\n    // \u7DDA\u5206s, t\u306E\u4EA4\u70B9\u306E\u8A08\u7B97\
    \n    inline Point crossPoint(const Segment &s, const Segment &t) {\n        return\
    \ crossPoint(Line(s), Line(t));\n    }\n\n    // 2\u3064\u306E\u5186\u306E\u4EA4\
    \u70B9\n    inline std::vector<Point> crossPoint(const Circle &c1, const Circle\
    \ &c2) {\n        std::vector<Point> res;\n        int mode = isIntersect(c1,\
    \ c2);\n        // 2\u3064\u306E\u4E2D\u5FC3\u306E\u8DDD\u96E2\n        D d =\
    \ std::abs(c1.p - c2.p);\n        // 2\u5186\u304C\u96E2\u308C\u3066\u3044\u308B\
    \u5834\u5408\n        if(mode == 4) return res;\n        // 1\u3064\u306E\u5186\
    \u304C\u3082\u30461\u3064\u306E\u5186\u306B\u5185\u5305\u3055\u308C\u3066\u3044\
    \u308B\u5834\u5408\n        if(mode == 0) return res;\n        // 2\u5186\u304C\
    \u5916\u63A5\u3059\u308B\u5834\u5408\n        if(mode == 3) {\n            D t\
    \ = c1.r / (c1.r + c2.r);\n            res.emplace_back(c1.p + (c2.p - c1.p) *\
    \ t);\n            return res;\n        }\n        // \u5185\u63A5\u3057\u3066\
    \u3044\u308B\u5834\u5408\n        if(mode == 1) {\n            if(c2.r < c1.r\
    \ - EPS) {\n                res.emplace_back(c1.p + (c2.p - c1.p) * (c1.r / d));\n\
    \            } else {\n                res.emplace_back(c2.p + (c1.p - c2.p) *\
    \ (c2.r / d));\n            }\n            return res;\n        }\n        //\
    \ 2\u5186\u304C\u91CD\u306A\u308B\u5834\u5408\n        D rc1 = (c1.r * c1.r +\
    \ d * d - c2.r * c2.r) / (2 * d);\n        D rs1 = std::sqrt(c1.r * c1.r - rc1\
    \ * rc1);\n        if(c1.r - std::abs(rc1) < EPS) rs1 = 0;\n        Point e12\
    \ = (c2.p - c1.p) / std::abs(c2.p - c1.p);\n        res.emplace_back(c1.p + rc1\
    \ * e12 + rs1 * e12 * Point(0, 1));\n        res.emplace_back(c1.p + rc1 * e12\
    \ + rs1 * e12 * Point(0, -1));\n        return res;\n    }\n\n    // \u5186c\u3068\
    \u76F4\u7DDAl\u306E\u4EA4\u70B9\n    inline std::vector<Point> crossPoint(const\
    \ Circle &c, const Line &l) {\n        std::vector<Point> res;\n        D d =\
    \ distanceBetweenLineAndPoint(l, c.p);\n        // \u4EA4\u70B9\u3092\u6301\u305F\
    \u306A\u3044\n        if(d > c.r + EPS) return res;\n        // \u63A5\u3059\u308B\
    \n        Point h = projection(l, c.p);\n        if(equal(d, c.r)) {\n       \
    \     res.emplace_back(h);\n            return res;\n        }\n        Point\
    \ e = unitVector(l.b - l.a);\n        D ph = std::sqrt(c.r * c.r - d * d);\n \
    \       res.emplace_back(h - e * ph);\n        res.emplace_back(h + e * ph);\n\
    \        return res;\n    }\n} // namespace geometry\n#line 7 \"geometry/convex-cut.hpp\"\
    \n\nnamespace geometry {\n    // \u51F8\u591A\u89D2\u5F62p\u3092\u76F4\u7DDAl\u3067\
    \u5207\u65AD\u3057\u3001\u305D\u306E\u5DE6\u5074\u3092\u8FD4\u3059\n    inline\
    \ std::vector<Point> ConvexCut(std::vector<Point> p, Line l) {\n        std::vector<Point>\
    \ ret;\n        int sz = (int)p.size();\n        for(int i = 0; i < sz; i++) {\n\
    \            Point now = p[i];\n            Point nxt = p[i == sz - 1 ? 0 : i\
    \ + 1];\n            if(ccw(l.a, l.b, now) != -1) ret.emplace_back(now);\n   \
    \         if(ccw(l.a, l.b, now) * ccw(l.a, l.b, nxt) < 0) {\n                ret.emplace_back(crossPoint(Line(now,\
    \ nxt), l));\n            }\n        }\n        return ret;\n    }\n} // namespace\
    \ geometry\n#line 2 \"geometry/convex-hull.hpp\"\n\n#line 5 \"geometry/convex-hull.hpp\"\
    \n\n#line 7 \"geometry/convex-hull.hpp\"\n\nnamespace geometry {\n    // \u51F8\
    \u5305 O(NlogN)\n    inline std::vector<Point> ConvexHull(std::vector<Point> p)\
    \ {\n        int n = (int)p.size(), k = 0;\n        std::sort(p.begin(), p.end(),\
    \ [](const Point &a, const Point &b) {\n            return (a.real() != b.real()\
    \ ? a.real() < b.real()\n                                         : a.imag() <\
    \ b.imag());\n        });\n        std::vector<Point> ch(2 * n);\n        // \u4E00\
    \u76F4\u7DDA\u4E0A\u306E3\u70B9\u3092\u542B\u3081\u308B -> (< -EPS)\n        //\
    \ \u542B\u3081\u7121\u3044 -> (< EPS)\n        for(int i = 0; i < n; ch[k++] =\
    \ p[i++]) { // lower\n            while(k >= 2 &&\n                  cross(ch[k\
    \ - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS)\n                --k;\n        }\n\
    \        for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) { // upper\n\
    \            while(k >= t &&\n                  cross(ch[k - 1] - ch[k - 2], p[i]\
    \ - ch[k - 1]) < EPS)\n                --k;\n        }\n        ch.resize(k -\
    \ 1);\n        return ch;\n    }\n} // namespace geometry\n#line 2 \"geometry/degree-to-radian.hpp\"\
    \n\n#line 4 \"geometry/degree-to-radian.hpp\"\n\nnamespace geometry {\n    //\
    \ \u5EA6->\u30E9\u30B8\u30A2\u30F3\n    inline D degreeToRadian(const D &degree)\
    \ { return degree * PI / 180.0; }\n} // namespace geometry\n#line 2 \"geometry/distance-between-segments.hpp\"\
    \n\n#line 4 \"geometry/distance-between-segments.hpp\"\n\n#line 2 \"geometry/distance-between-segment-and-point.hpp\"\
    \n\n#line 6 \"geometry/distance-between-segment-and-point.hpp\"\n\nnamespace geometry\
    \ {\n    // \u7DDA\u5206l\u3068\u70B9p\u306E\u8DDD\u96E2\u3092\u6C42\u3081\u308B\
    \n    // \u5B9A\u7FA9\uFF1A\u70B9p\u304B\u3089\u300C\u7DDA\u5206l\u306E\u3069\u3053\
    \u304B\u300D\u3078\u306E\u6700\u77ED\u8DDD\u96E2\n    inline D distanceBetweenSegmentAndPoint(const\
    \ Segment &l, const Point &p) {\n        if(dot(l.b - l.a, p - l.a) < EPS) return\
    \ std::abs(p - l.a);\n        if(dot(l.a - l.b, p - l.b) < EPS) return std::abs(p\
    \ - l.b);\n        return std::abs(cross(l.b - l.a, p - l.a)) / std::abs(l.b -\
    \ l.a);\n    }\n} // namespace geometry\n#line 7 \"geometry/distance-between-segments.hpp\"\
    \n\nnamespace geometry {\n    // \u7DDA\u5206s\u3068t\u306E\u8DDD\u96E2\n    inline\
    \ D distanceBetweenSegments(const Segment &s, const Segment &t) {\n        if(isIntersect(s,\
    \ t, 1)) return (D)(0);\n        D ans = distanceBetweenSegmentAndPoint(s, t.a);\n\
    \        ans = std::min(ans, distanceBetweenSegmentAndPoint(s, t.b));\n      \
    \  ans = std::min(ans, distanceBetweenSegmentAndPoint(t, s.a));\n        ans =\
    \ std::min(ans, distanceBetweenSegmentAndPoint(t, s.b));\n        return ans;\n\
    \    }\n} // namespace geometry\n#line 2 \"geometry/is-contained.hpp\"\n\n#line\
    \ 4 \"geometry/is-contained.hpp\"\n\n#line 7 \"geometry/is-contained.hpp\"\n\n\
    namespace geometry {\n    // \u591A\u89D2\u5F62g\u306B\u70B9p\u304C\u542B\u307E\
    \u308C\u3066\u3044\u308B\u304B?\n    // \u542B\u307E\u308C\u308B:2, \u8FBA\u4E0A\
    \u306B\u3042\u308B:1, \u542B\u307E\u308C\u306A\u3044:0\n    inline int isContained(const\
    \ std::vector<Point> &g, const Point &p) {\n        bool in = false;\n       \
    \ int n = (int)g.size();\n        for(int i = 0; i < n; i++) {\n            Point\
    \ a = g[i] - p, b = g[(i + 1) % n] - p;\n            if(imag(a) > imag(b)) swap(a,\
    \ b);\n            if(imag(a) <= EPS && EPS < imag(b) && cross(a, b) < -EPS) in\
    \ = !in;\n            if(cross(a, b) == 0 && dot(a, b) <= 0) return 1;\n     \
    \   }\n        return (in ? 2 : 0);\n    }\n} // namespace geometry\n#line 2 \"\
    geometry/is-convex.hpp\"\n\n#line 4 \"geometry/is-convex.hpp\"\n\n#line 6 \"geometry/is-convex.hpp\"\
    \n\nnamespace geometry {\n    // \u51F8\u591A\u89D2\u5F62\u304B\u3069\u3046\u304B\
    \n    inline bool isConvex(const std::vector<Point> &p) {\n        int n = p.size();\n\
    \        int now, pre, nxt;\n        for(int i = 0; i < n; i++) {\n          \
    \  pre = (i - 1 + n) % n;\n            nxt = (i + 1) % n;\n            now = i;\n\
    \            if(ccw(p[pre], p[now], p[nxt]) == -1) return false;\n        }\n\
    \        return true;\n    }\n} // namespace geometry\n#line 2 \"geometry/is-in-circle.hpp\"\
    \n\n#line 4 \"geometry/is-in-circle.hpp\"\n\nnamespace geometry {\n    // \u70B9\
    p\u304C\u5186c\u306E\u5185\u90E8(\u5186\u5468\u4E0A\u3082\u542B\u3080)\u306B\u5165\
    \u3063\u3066\u3044\u308B\u304B\u3069\u3046\u304B\n    inline bool isInCircle(const\
    \ Circle &c, const Point &p) {\n        D d = std::abs(c.p - p);\n        return\
    \ (equal(d, c.r) || d < c.r - EPS);\n    }\n} // namespace geometry\n#line 2 \"\
    geometry/is-orthogonal.hpp\"\n\n#line 5 \"geometry/is-orthogonal.hpp\"\n\nnamespace\
    \ geometry {\n    // 2\u76F4\u7DDA\u306E\u76F4\u4EA4\u5224\u5B9A : a\u22A5b <=>\
    \ dot(a, b) = 0\n    inline bool isOrthogonal(const Line &a, const Line &b) {\n\
    \        return equal(dot(a.b - a.a, b.b - b.a), 0);\n    }\n} // namespace geometry\n\
    #line 2 \"geometry/is-point-on-line.hpp\"\n\n#line 2 \"geometry/is-parallel.hpp\"\
    \n\n#line 5 \"geometry/is-parallel.hpp\"\n\nnamespace geometry {\n    // 2\u76F4\
    \u7DDA\u306E\u5E73\u884C\u5224\u5B9A : a//b <=> cross(a, b) = 0\n    inline bool\
    \ isParallel(const Line &a, const Line &b) {\n        return equal(cross(a.b -\
    \ a.a, b.b - b.a), 0);\n    }\n} // namespace geometry\n#line 4 \"geometry/is-point-on-line.hpp\"\
    \n\nnamespace geometry {\n    // \u70B9c\u304C\u76F4\u7DDAab\u4E0A\u306B\u3042\
    \u308B\u304B\n    inline bool isPointOnLine(const Point &a, const Point &b, const\
    \ Point &c) {\n        return isParallel(Line(a, b), Line(a, c));\n    }\n} //\
    \ namespace geometry\n#line 2 \"geometry/is-point-on-segment.hpp\"\n\n#line 4\
    \ \"geometry/is-point-on-segment.hpp\"\n\nnamespace geometry {\n    // \u70B9\
    c\u304C\"\u7DDA\u5206\"ab\u4E0A\u306B\u3042\u308B\u304B\n    inline bool isPointOnSegment(const\
    \ Point &a, const Point &b, const Point &c) {\n        // |a-c| + |c-b| <= |a-b|\
    \ \u306A\u3089\u7DDA\u5206\u4E0A\n        return (std::abs(a - c) + std::abs(c\
    \ - b) < std::abs(a - b) + EPS);\n    }\n} // namespace geometry\n#line 2 \"geometry/normal-vector.hpp\"\
    \n\n#line 4 \"geometry/normal-vector.hpp\"\n\nnamespace geometry {\n    // \u6CD5\
    \u7DDA\u30D9\u30AF\u30C8\u30EB(normal vector)\u3092\u6C42\u3081\u308B\n    //\
    \ 90\u5EA6\u56DE\u8EE2\u3057\u305F\u5358\u4F4D\u30D9\u30AF\u30C8\u30EB\u3092\u304B\
    \u3051\u308B\n    // -90\u5EA6\u304C\u3088\u3051\u308C\u3070Point(0, -1)\u3092\
    \u304B\u3051\u308B\n    inline Point normalVector(const Point &a) { return a *\
    \ Point(0, 1); }\n} // namespace geometry\n#line 2 \"geometry/polygon-area.hpp\"\
    \n\n#line 4 \"geometry/polygon-area.hpp\"\n\n#line 6 \"geometry/polygon-area.hpp\"\
    \n\nnamespace geometry {\n    // \u591A\u89D2\u5F62\u306E\u9762\u7A4D\u3092\u6C42\
    \u3081\u308B\n    inline D PolygonArea(const std::vector<Point> &p) {\n      \
    \  D res = 0;\n        int n = p.size();\n        for(int i = 0; i < n - 1; i++)\
    \ res += cross(p[i], p[i + 1]);\n        res += cross(p[n - 1], p[0]);\n     \
    \   return res * 0.5;\n    }\n} // namespace geometry\n#line 2 \"geometry/radian-to-degree.hpp\"\
    \n\n#line 4 \"geometry/radian-to-degree.hpp\"\n\nnamespace geometry {\n    //\
    \ \u30E9\u30B8\u30A2\u30F3->\u5EA6\n    inline D radianToDegree(const D &radian)\
    \ { return radian * 180.0 / PI; }\n} // namespace geometry\n#line 2 \"geometry/reflection.hpp\"\
    \n\n#line 4 \"geometry/reflection.hpp\"\n\nnamespace geometry {\n    // \u53CD\
    \u5C04(reflection)\n    // \u76F4\u7DDAl\u3092\u5BFE\u79F0\u8EF8\u3068\u3057\u3066\
    \u70B9p\u3068\u7DDA\u5BFE\u79F0\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u70B9\u3092\
    \u6C42\u3081\u308B\n    inline Point reflection(const Line &l, const Point &p)\
    \ {\n        return p + (projection(l, p) - p) * (D)2.0;\n    }\n} // namespace\
    \ geometry\n#line 2 \"geometry/tangent-to-circle.hpp\"\n\n#line 5 \"geometry/tangent-to-circle.hpp\"\
    \n\n#line 7 \"geometry/tangent-to-circle.hpp\"\n\nnamespace geometry {\n    //\
    \ \u70B9p\u3092\u901A\u308B\u5186c\u306E\u63A5\u7DDA\n    // 2\u672C\u3042\u308B\
    \u306E\u3067\u3001\u63A5\u70B9\u306E\u307F\u3092\u8FD4\u3059\n    inline std::vector<Point>\
    \ tangentToCircle(const Point &p, const Circle &c) {\n        return crossPoint(c,\n\
    \                          Circle(p, std::sqrt(std::norm(c.p - p) - c.r * c.r)));\n\
    \    }\n} // namespace geometry\n#line 2 \"geometry/tangent.hpp\"\n\n#line 5 \"\
    geometry/tangent.hpp\"\n\n#line 2 \"geometry/rotate.hpp\"\n\n#line 4 \"geometry/rotate.hpp\"\
    \n\nnamespace geometry {\n    // \u70B9p\u3092\u53CD\u6642\u8A08\u56DE\u308A\u306B\
    theta\u5EA6\u56DE\u8EE2\n    // theta\u306F\u30E9\u30B8\u30A2\u30F3\uFF01\uFF01\
    \uFF01\n    inline Point rotate(const Point &p, const D &theta) {\n        return\
    \ Point(std::cos(theta) * p.real() - std::sin(theta) * p.imag(),\n           \
    \          std::sin(theta) * p.real() + std::cos(theta) * p.imag());\n    }\n\
    } // namespace geometry\n#line 10 \"geometry/tangent.hpp\"\n\nnamespace geometry\
    \ {\n    // \u5186\u306E\u5171\u901A\u63A5\u7DDA\n    inline std::vector<Line>\
    \ tangent(const Circle &a, const Circle &b) {\n        std::vector<Line> ret;\n\
    \        // 2\u5186\u306E\u4E2D\u5FC3\u9593\u306E\u8DDD\u96E2\n        D g = std::abs(a.p\
    \ - b.p);\n        // \u5186\u304C\u5185\u5305\u3055\u308C\u3066\u3044\u308B\u5834\
    \u5408\n        if(equal(g, 0)) return ret;\n        Point u = unitVector(b.p\
    \ - a.p);\n        Point v = rotate(u, PI / 2);\n        for(int s : {-1, 1})\
    \ {\n            D h = (a.r + b.r * s) / g;\n            if(equal(h * h, 1)) {\n\
    \                ret.emplace_back(a.p + (h > 0 ? u : -u) * a.r,\n            \
    \                     a.p + (h > 0 ? u : -u) * a.r + v);\n\n            } else\
    \ if(1 - h * h > 0) {\n                Point U = u * h, V = v * std::sqrt(1 -\
    \ h * h);\n                ret.emplace_back(a.p + (U + V) * a.r,\n           \
    \                      b.p - (U + V) * (b.r * s));\n                ret.emplace_back(a.p\
    \ + (U - V) * a.r,\n                                 b.p - (U - V) * (b.r * s));\n\
    \            }\n        }\n        return ret;\n    }\n} // namespace geometry\n\
    #line 21 \"test/mytest/geometry/geometry.test.cpp\"\n\nusing namespace geometry;\n\
    \nvoid geometry_test() {\n    Point origin(0, 0), x(1, 0), y(0, 1);\n    assert(equal(dot(x,\
    \ y), 0));\n    assert(equal(cross(x, y), 1));\n    assert(equal(std::abs(unitVector(Point(3,\
    \ 4))), 1));\n    assert(normalVector(x) == y);\n    assert(std::abs(rotate(x,\
    \ PI / 2) - y) < EPS);\n    assert(equal(radianToDegree(degreeToRadian(90)), 90));\n\
    \    assert(ccw(origin, x, y) == 1);\n\n    Line horizontal(origin, x), vertical(origin,\
    \ y);\n    Segment horizontal_segment(origin, Point(2, 0));\n    Circle unit_circle(origin,\
    \ 1);\n    assert(isOrthogonal(horizontal, vertical));\n    assert(isParallel(horizontal,\
    \ Line(Point(0, 1), Point(1, 1))));\n    assert(isPointOnLine(origin, x, Point(2,\
    \ 0)));\n    assert(isPointOnSegment(origin, Point(2, 0), x));\n    assert(equal(distanceBetweenLineAndPoint(horizontal,\
    \ y), 1));\n    assert(equal(distanceBetweenSegmentAndPoint(horizontal_segment,\
    \ Point(3, 0)), 1));\n    assert(crossPoint(horizontal, vertical) == origin);\n\
    \    assert(isIntersect(horizontal_segment, Segment(Point(1, -1), Point(1, 1)),\
    \ true));\n    assert(equal(distanceBetweenSegments(horizontal_segment,\n    \
    \                                     Segment(Point(3, 0), Point(4, 0))),\n  \
    \               1));\n    assert(projection(horizontal, y) == origin);\n    assert(reflection(horizontal,\
    \ y) == Point(0, -1));\n\n    assert(isIntersect(unit_circle, Circle(Point(2,\
    \ 0), 1)) == 3);\n    assert(crossPoint(unit_circle, Circle(Point(2, 0), 1)).size()\
    \ == 1);\n    assert(crossPoint(unit_circle, horizontal).size() == 2);\n    assert(isInCircle(unit_circle,\
    \ origin));\n    assert(tangentToCircle(Point(2, 0), unit_circle).size() == 2);\n\
    \    assert(tangent(unit_circle, Circle(Point(4, 0), 1)).size() == 4);\n\n   \
    \ std::vector<Point> triangle = {origin, x, y};\n    assert(equal(PolygonArea(triangle),\
    \ 0.5));\n    assert(isConvex(triangle));\n    assert(ConvexHull(triangle).size()\
    \ == 3);\n    assert(isContained(triangle, Point(0.1, 0.1)) == 2);\n    assert(!ConvexCut(triangle,\
    \ Line(Point(0.5, -1), Point(0.5, 1))).empty());\n}\n\nint main() {\n    geometry_test();\n\
    \    INT(a, b);\n    print(a + b);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../template/template.cpp\"\
    \n\n#include \"../../../geometry/ccw.hpp\"\n#include \"../../../geometry/convex-cut.hpp\"\
    \n#include \"../../../geometry/convex-hull.hpp\"\n#include \"../../../geometry/degree-to-radian.hpp\"\
    \n#include \"../../../geometry/distance-between-segments.hpp\"\n#include \"../../../geometry/is-contained.hpp\"\
    \n#include \"../../../geometry/is-convex.hpp\"\n#include \"../../../geometry/is-in-circle.hpp\"\
    \n#include \"../../../geometry/is-orthogonal.hpp\"\n#include \"../../../geometry/is-point-on-line.hpp\"\
    \n#include \"../../../geometry/is-point-on-segment.hpp\"\n#include \"../../../geometry/normal-vector.hpp\"\
    \n#include \"../../../geometry/polygon-area.hpp\"\n#include \"../../../geometry/radian-to-degree.hpp\"\
    \n#include \"../../../geometry/reflection.hpp\"\n#include \"../../../geometry/tangent-to-circle.hpp\"\
    \n#include \"../../../geometry/tangent.hpp\"\n\nusing namespace geometry;\n\n\
    void geometry_test() {\n    Point origin(0, 0), x(1, 0), y(0, 1);\n    assert(equal(dot(x,\
    \ y), 0));\n    assert(equal(cross(x, y), 1));\n    assert(equal(std::abs(unitVector(Point(3,\
    \ 4))), 1));\n    assert(normalVector(x) == y);\n    assert(std::abs(rotate(x,\
    \ PI / 2) - y) < EPS);\n    assert(equal(radianToDegree(degreeToRadian(90)), 90));\n\
    \    assert(ccw(origin, x, y) == 1);\n\n    Line horizontal(origin, x), vertical(origin,\
    \ y);\n    Segment horizontal_segment(origin, Point(2, 0));\n    Circle unit_circle(origin,\
    \ 1);\n    assert(isOrthogonal(horizontal, vertical));\n    assert(isParallel(horizontal,\
    \ Line(Point(0, 1), Point(1, 1))));\n    assert(isPointOnLine(origin, x, Point(2,\
    \ 0)));\n    assert(isPointOnSegment(origin, Point(2, 0), x));\n    assert(equal(distanceBetweenLineAndPoint(horizontal,\
    \ y), 1));\n    assert(equal(distanceBetweenSegmentAndPoint(horizontal_segment,\
    \ Point(3, 0)), 1));\n    assert(crossPoint(horizontal, vertical) == origin);\n\
    \    assert(isIntersect(horizontal_segment, Segment(Point(1, -1), Point(1, 1)),\
    \ true));\n    assert(equal(distanceBetweenSegments(horizontal_segment,\n    \
    \                                     Segment(Point(3, 0), Point(4, 0))),\n  \
    \               1));\n    assert(projection(horizontal, y) == origin);\n    assert(reflection(horizontal,\
    \ y) == Point(0, -1));\n\n    assert(isIntersect(unit_circle, Circle(Point(2,\
    \ 0), 1)) == 3);\n    assert(crossPoint(unit_circle, Circle(Point(2, 0), 1)).size()\
    \ == 1);\n    assert(crossPoint(unit_circle, horizontal).size() == 2);\n    assert(isInCircle(unit_circle,\
    \ origin));\n    assert(tangentToCircle(Point(2, 0), unit_circle).size() == 2);\n\
    \    assert(tangent(unit_circle, Circle(Point(4, 0), 1)).size() == 4);\n\n   \
    \ std::vector<Point> triangle = {origin, x, y};\n    assert(equal(PolygonArea(triangle),\
    \ 0.5));\n    assert(isConvex(triangle));\n    assert(ConvexHull(triangle).size()\
    \ == 3);\n    assert(isContained(triangle, Point(0.1, 0.1)) == 2);\n    assert(!ConvexCut(triangle,\
    \ Line(Point(0.5, -1), Point(0.5, 1))).empty());\n}\n\nint main() {\n    geometry_test();\n\
    \    INT(a, b);\n    print(a + b);\n}\n"
  dependsOn:
  - template/template.cpp
  - geometry/ccw.hpp
  - geometry/cross.hpp
  - geometry/base.hpp
  - geometry/dot.hpp
  - geometry/convex-cut.hpp
  - geometry/cross-point.hpp
  - geometry/circle.hpp
  - geometry/distance-between-line-and-point.hpp
  - geometry/line.hpp
  - geometry/is-intersect.hpp
  - geometry/segment.hpp
  - geometry/projection.hpp
  - geometry/unit-vector.hpp
  - geometry/convex-hull.hpp
  - geometry/degree-to-radian.hpp
  - geometry/distance-between-segments.hpp
  - geometry/distance-between-segment-and-point.hpp
  - geometry/is-contained.hpp
  - geometry/is-convex.hpp
  - geometry/is-in-circle.hpp
  - geometry/is-orthogonal.hpp
  - geometry/is-point-on-line.hpp
  - geometry/is-parallel.hpp
  - geometry/is-point-on-segment.hpp
  - geometry/normal-vector.hpp
  - geometry/polygon-area.hpp
  - geometry/radian-to-degree.hpp
  - geometry/reflection.hpp
  - geometry/tangent-to-circle.hpp
  - geometry/tangent.hpp
  - geometry/rotate.hpp
  isVerificationFile: true
  path: test/mytest/geometry/geometry.test.cpp
  requiredBy: []
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/geometry/geometry.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/geometry/geometry.test.cpp
- /verify/test/mytest/geometry/geometry.test.cpp.html
title: test/mytest/geometry/geometry.test.cpp
---
