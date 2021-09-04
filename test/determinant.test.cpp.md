---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: "\u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: ModInt
  - icon: ':question:'
    path: template/template.cpp
    title: "\u7AF6\u30D7\u30ED\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/determinant.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\
    \n#line 1 \"template/template.cpp\"\n#pragma region Macros\n#include <bits/stdc++.h>\n\
    using namespace std;\ntemplate <class T> inline bool chmax(T &a, T b) {\n    if(a\
    \ < b) {\n        a = b;\n        return 1;\n    }\n    return 0;\n}\ntemplate\
    \ <class T> inline bool chmin(T &a, T b) {\n    if(a > b) {\n        a = b;\n\
    \        return 1;\n    }\n    return 0;\n}\n#ifdef DEBUG\ntemplate <class T,\
    \ class U>\nostream &operator<<(ostream &os, const pair<T, U> &p) {\n    os <<\
    \ '(' << p.first << ',' << p.second << ')';\n    return os;\n}\ntemplate <class\
    \ T> ostream &operator<<(ostream &os, const vector<T> &v) {\n    os << '{';\n\
    \    for(int i = 0; i < (int)v.size(); i++) {\n        if(i) { os << ','; }\n\
    \        os << v[i];\n    }\n    os << '}';\n    return os;\n}\nvoid debugg()\
    \ { cerr << endl; }\ntemplate <class T, class... Args>\nvoid debugg(const T &x,\
    \ const Args &... args) {\n    cerr << \" \" << x;\n    debugg(args...);\n}\n\
    #define debug(...)                                                           \
    \  \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]: \", debugg(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\nstruct Setup\
    \ {\n    Setup() {\n        cin.tie(0);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(15);\n    }\n} __Setup;\n\nusing ll = long\
    \ long;\n#define ALL(v) (v).begin(), (v).end()\n#define RALL(v) (v).rbegin(),\
    \ (v).rend()\n#define FOR(i, a, b) for(int i = (a); i < int(b); i++)\n#define\
    \ REP(i, n) FOR(i, 0, n)\nconst int INF = 1 << 30;\nconst ll LLINF = 1LL << 60;\n\
    constexpr int MOD = 1000000007;\nconst int dx[4] = {1, 0, -1, 0};\nconst int dy[4]\
    \ = {0, 1, 0, -1};\n\nvoid Case(int i) { cout << \"Case #\" << i << \": \"; }\n\
    int popcount(int x) { return __builtin_popcount(x); }\nll popcount(ll x) { return\
    \ __builtin_popcountll(x); }\n#pragma endregion Macros\n#line 1 \"math/modint.hpp\"\
    \ntemplate <int mod> struct ModInt {\n    int x;\n    ModInt() : x(0) {}\n   \
    \ ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n    ModInt\
    \ &operator+=(const ModInt &p) {\n        if((x += p.x) >= mod)\n            x\
    \ -= mod;\n        return *this;\n    }\n    ModInt &operator-=(const ModInt &p)\
    \ {\n        if((x += mod - p.x) >= mod)\n            x -= mod;\n        return\
    \ *this;\n    }\n    ModInt &operator*=(const ModInt &p) {\n        x = (int)(1LL\
    \ * x * p.x % mod);\n        return *this;\n    }\n    ModInt &operator/=(const\
    \ ModInt &p) {\n        *this *= p.inv();\n        return *this;\n    }\n    ModInt\
    \ operator-() const { return ModInt(-x); }\n    ModInt operator+(const ModInt\
    \ &p) const { return ModInt(*this) += p; }\n    ModInt operator-(const ModInt\
    \ &p) const { return ModInt(*this) -= p; }\n    ModInt operator*(const ModInt\
    \ &p) const { return ModInt(*this) *= p; }\n    ModInt operator/(const ModInt\
    \ &p) const { return ModInt(*this) /= p; }\n    bool operator==(const ModInt &p)\
    \ const { return x == p.x; }\n    bool operator!=(const ModInt &p) const { return\
    \ x != p.x; }\n    ModInt inv() const {\n        int a = x, b = mod, u = 1, v\
    \ = 0, t;\n        while(b > 0) {\n            t = a / b;\n            swap(a\
    \ -= t * b, b);\n            swap(u -= t * v, v);\n        }\n        return ModInt(u);\n\
    \    }\n    ModInt pow(int64_t n) const {\n        ModInt ret(1), mul(x);\n  \
    \      while(n > 0) {\n            if(n & 1)\n                ret *= mul;\n  \
    \          mul *= mul;\n            n >>= 1;\n        }\n        return ret;\n\
    \    }\n    friend ostream &operator<<(ostream &os, const ModInt &p) {\n     \
    \   return os << p.x;\n    }\n    friend istream &operator>>(istream &is, ModInt\
    \ &a) {\n        int64_t t;\n        is >> t;\n        a = ModInt<mod>(t);\n \
    \       return (is);\n    }\n    static int get_mod() { return mod; }\n};\n#line\
    \ 1 \"math/matrix.hpp\"\n// \u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA\ntemplate\
    \ <class T> struct Matrix {\n    vector<vector<T>> A;\n\n    Matrix() {}\n\n \
    \   Matrix(size_t n, size_t m) : A(n, vector<T>(m, 0)) {}\n\n    Matrix(size_t\
    \ n) : A(n, vector<T>(n, 0)){};\n\n    size_t height() const { return (A.size());\
    \ }\n\n    size_t width() const { return (A[0].size()); }\n\n    inline const\
    \ vector<T> &operator[](int k) const { return (A.at(k)); }\n\n    inline vector<T>\
    \ &operator[](int k) { return (A.at(k)); }\n\n    // \u5358\u4F4D\u884C\u5217\n\
    \    static Matrix I(size_t n) {\n        Matrix mat(n);\n        for(int i =\
    \ 0; i < n; i++)\n            mat[i][i] = 1;\n        return (mat);\n    }\n\n\
    \    Matrix &operator+=(const Matrix &B) {\n        size_t n = height(), m = width();\n\
    \        assert(n == B.height() && m == B.width());\n        for(int i = 0; i\
    \ < n; i++)\n            for(int j = 0; j < m; j++)\n                (*this)[i][j]\
    \ += B[i][j];\n        return (*this);\n    }\n\n    Matrix &operator-=(const\
    \ Matrix &B) {\n        size_t n = height(), m = width();\n        assert(n ==\
    \ B.height() && m == B.width());\n        for(int i = 0; i < n; i++)\n       \
    \     for(int j = 0; j < m; j++)\n                (*this)[i][j] -= B[i][j];\n\
    \        return (*this);\n    }\n\n    Matrix &operator*=(const Matrix &B) {\n\
    \        size_t n = height(), m = B.width(), p = width();\n        assert(p ==\
    \ B.height());\n        vector<vector<T>> C(n, vector<T>(m, 0));\n\t\tT sum;\n\
    \        for(int i = 0; i < n; i++){\n            for(int j = 0; j < m; j++){\n\
    \t\t\t\tsum = 0;\n                for(int k = 0; k < p; k++){\n              \
    \      sum += (*this)[i][k] * B[k][j];\n\t\t\t\t}\n\t\t\t\tC[i][j] = sum;\n\t\t\
    \t}\n\t\t}\n        A.swap(C);\n        return (*this);\n    }\n\n    // \u7D2F\
    \u4E57\n    Matrix &operator^=(long long k) {\n        Matrix B = Matrix::I(height());\n\
    \        while(k > 0) {\n            if(k & 1)\n                B *= *this;\n\
    \            *this *= *this;\n            k >>= 1LL;\n        }\n        A.swap(B.A);\n\
    \        return (*this);\n    }\n\n    Matrix operator+(const Matrix &B) const\
    \ { return (Matrix(*this) += B); }\n\n    Matrix operator-(const Matrix &B) const\
    \ { return (Matrix(*this) -= B); }\n\n    Matrix operator*(const Matrix &B) const\
    \ { return (Matrix(*this) *= B); }\n\n    Matrix operator^(const long long k)\
    \ const { return (Matrix(*this) ^= k); }\n\n    friend ostream &operator<<(ostream\
    \ &os, Matrix &p) {\n        size_t n = p.height(), m = p.width();\n        for(int\
    \ i = 0; i < n; i++) {\n            os << \"[\";\n            for(int j = 0; j\
    \ < m; j++) {\n                os << p[i][j] << (j + 1 == m ? \"]\\n\" : \",\"\
    );\n            }\n        }\n        return (os);\n    }\n\n    // \u884C\u5217\
    \u5F0F\n    T determinant() {\n        Matrix B(*this);\n        assert(width()\
    \ == height());\n        T ret = 1;\n        for(int i = 0; i < width(); i++)\
    \ {\n            int idx = -1;\n            for(int j = i; j < width(); j++) {\n\
    \                if(B[j][i] != 0)\n                    idx = j;\n            }\n\
    \            if(idx == -1)\n                return (0);\n            if(i != idx)\
    \ {\n                ret *= -1;\n                swap(B[i], B[idx]);\n       \
    \     }\n            ret *= B[i][i];\n            T vv = B[i][i];\n          \
    \  for(int j = 0; j < width(); j++) {\n                B[i][j] /= vv;\n      \
    \      }\n            for(int j = i + 1; j < width(); j++) {\n               \
    \ T a = B[j][i];\n                for(int k = 0; k < width(); k++) {\n       \
    \             B[j][k] -= B[i][k] * a;\n                }\n            }\n    \
    \    }\n        return (ret);\n    }\n};\n#line 5 \"test/determinant.test.cpp\"\
    \n\nusing mint = ModInt<998244353>;\n\nint main(){\n    int n;\n    cin >> n;\n\
    \    Matrix<mint> mat(n);\n    for(int i = 0; i < n; i++) {\n        for(int j\
    \ = 0; j < n; j++) {\n            cin >> mat[i][j];\n        }\n    }\n    cout\
    \ << mat.determinant() << endl;  \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n#include\
    \ \"../template/template.cpp\"\n#include \"../math/modint.hpp\"\n#include \"../math/matrix.hpp\"\
    \n\nusing mint = ModInt<998244353>;\n\nint main(){\n    int n;\n    cin >> n;\n\
    \    Matrix<mint> mat(n);\n    for(int i = 0; i < n; i++) {\n        for(int j\
    \ = 0; j < n; j++) {\n            cin >> mat[i][j];\n        }\n    }\n    cout\
    \ << mat.determinant() << endl;  \n}"
  dependsOn:
  - template/template.cpp
  - math/modint.hpp
  - math/matrix.hpp
  isVerificationFile: true
  path: test/determinant.test.cpp
  requiredBy: []
  timestamp: '2021-07-01 11:58:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/determinant.test.cpp
layout: document
redirect_from:
- /verify/test/determinant.test.cpp
- /verify/test/determinant.test.cpp.html
title: test/determinant.test.cpp
---
