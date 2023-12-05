#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
// input output utils
namespace siro53_io {
    // https://maspypy.github.io/library/other/io_old.hpp
    struct has_val_impl {
        template <class T>
        static auto check(T &&x) -> decltype(x.val(), std::true_type{});

        template <class T> static auto check(...) -> std::false_type;
    };

    template <class T>
    class has_val : public decltype(has_val_impl::check<T>(std::declval<T>())) {
    };

    // debug
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    void dump(const T t) {
        cerr << t;
    }
    template <class T, enable_if_t<is_floating_point<T>::value, int> = 0>
    void dump(const T t) {
        cerr << t;
    }
    template <class T, typename enable_if<has_val<T>::value>::type * = nullptr>
    void dump(const T &t) {
        cerr << t.val();
    }
    void dump(__int128_t n) {
        if(n == 0) {
            cerr << '0';
            return;
        } else if(n < 0) {
            cerr << '-';
            n = -n;
        }
        string s;
        while (n > 0) {
            s += (char)('0' + n % 10);
            n /= 10;
        }
        reverse(s.begin(), s.end());
        cerr << s;
    }
    void dump(const string &s) { cerr << s; }
    void dump(const char *s) {
        int n = (int)strlen(s);
        for(int i = 0; i < n; i++) cerr << s[i];
    }
    template <class T1, class T2> void dump(const pair<T1, T2> &p) {
        cerr << '(' << p.first << ',' << p.second << ')';
    }
    template <class T> void dump(const vector<T> &v) {
        cerr << '{';
        for(int i = 0; i < (int)v.size(); i++) {
            cerr << v[i];
            if(i < (int)v.size() - 1) cerr << ',';
        }
        cerr << '}';
    }
    template <class T> void dump(const set<T> &s) {
        cerr << '{';
        for(auto it = s.begin(); it != s.end(); it++) {
            cerr << *it;
            if(next(it) != s.end()) cerr << ',';
        }
        cerr << '}';
    }
    template <class Key, class Value> void dump(const map<Key, Value> &mp) {
        cerr << '{';
        for(auto it = mp.begin(); it != mp.end(); it++) {
            cerr << '(' << it->first << ',' << it->second << ')';
            if(next(it) != mp.end()) cerr << ',';
        }
        cerr << '}';
    }
    template <class Key, class Value>
    void dump(const unordered_map<Key, Value> &mp) {
        cerr << '{';
        for(auto it = mp.begin(); it != mp.end(); it++) {
            cerr << '(' << it->first << ',' << it->second << ')';
            if(next(it) != mp.end()) cerr << ',';
        }
        cerr << '}';
    }
    template <class T> void dump(const deque<T> &v) {
        cerr << '{';
        for(int i = 0; i < (int)v.size(); i++) {
            cerr << v[i];
            if(i < (int)v.size() - 1) cerr << ',';
        }
        cerr << '}';
    }
    template <class T> void dump(queue<T> q) {
        cerr << '{';
        while(!q.empty()) {
            cerr << q.front();
            if((int)q.size() > 1) cerr << ',';
            q.pop();
        }
        cerr << '}';
    }

    void debug_print() { cerr << endl; }
    template <class Head, class... Tail>
    void debug_print(const Head &h, const Tail &...t) {
        dump(h);
        if(sizeof...(Tail)) dump(' ');
        debug_print(t...);
    }
    // print
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    void print_single(const T t) {
        cout << t;
    }
    template <class T, enable_if_t<is_floating_point<T>::value, int> = 0>
    void print_single(const T t) {
        cout << t;
    }
    template <class T, typename enable_if<has_val<T>::value>::type * = nullptr>
    void print_single(const T t) {
        cout << t.val();
    }
    void print_single(__int128_t n) {
        if(n == 0) {
            cout << '0';
            return;
        } else if(n < 0) {
            cout << '-';
            n = -n;
        }
        string s;
        while (n > 0) {
            s += (char)('0' + n % 10);
            n /= 10;
        }
        reverse(s.begin(), s.end());
        cout << s;
    }
    void print_single(const string &s) { cout << s; }
    void print_single(const char *s) {
        int n = (int)strlen(s);
        for(int i = 0; i < n; i++) cout << s[i];
    }
    template <class T1, class T2> void print_single(const pair<T1, T2> &p) {
        cout << p.first << ' ' << p.second;
    }
    template <class T> void print_single(const vector<T> &v) {
        for(int i = 0; i < (int)v.size(); i++) {
            cout << v[i];
            if(i < (int)v.size() - 1) cout << ' ';
        }
    }
    template <class T> void print_single(const set<T> &s) {
        for(auto it = s.begin(); it != s.end(); it++) {
            cout << *it;
            if(next(it) != s.end()) cout << ' ';
        }
    }
    template <class T> void print_single(const deque<T> &v) {
        for(int i = 0; i < (int)v.size(); i++) {
            cout << v[i];
            if(i < (int)v.size() - 1) cout << ' ';
        }
    }
    template <class T> void print_single(queue<T> q) {
        while(!q.empty()) {
            cout << q.front();
            if((int)q.size() > 1) cout << ' ';
            q.pop();
        }
    }

    void print() { cout << '\n'; }
    template <class Head, class... Tail>
    void print(const Head &h, const Tail &...t) {
        print_single(h);
        if(sizeof...(Tail)) print_single(' ');
        print(t...);
    }

    // input
    template <class... T> void input(T &...t) { (cin >> ... >> t); }
}; // namespace siro53_io
#ifdef DEBUG
#define debug(...)                                                             \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]: ", debug_print(__VA_ARGS__)
#else
#define debug(...) (void(0))
#endif
// io setup
struct Setup {
    Setup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(15);
    }
} __Setup;
using namespace siro53_io;
// types
using ll = long long;
using i128 = __int128_t;
// input macros
#define INT(...)                                                               \
    int __VA_ARGS__;                                                           \
    input(__VA_ARGS__)
#define LL(...)                                                                \
    ll __VA_ARGS__;                                                            \
    input(__VA_ARGS__)
#define STRING(...)                                                            \
    string __VA_ARGS__;                                                        \
    input(__VA_ARGS__)
#define CHAR(...)                                                              \
    char __VA_ARGS__;                                                          \
    input(__VA_ARGS__)
#define DBL(...)                                                               \
    double __VA_ARGS__;                                                        \
    input(__VA_ARGS__)
#define LD(...)                                                                \
    long double __VA_ARGS__;                                                   \
    input(__VA_ARGS__)
#define UINT(...)                                                              \
    unsigned int __VA_ARGS__;                                                  \
    input(__VA_ARGS__)
#define ULL(...)                                                               \
    unsigned long long __VA_ARGS__;                                            \
    input(__VA_ARGS__)
// other macros
// https://trap.jp/post/1224/
#define OVERLOAD3(_1, _2, _3, name, ...) name
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define REP1(i, n) for(int i = 0; i < int(n); i++)
#define REP2(i, a, b) for(int i = (a); i < int(b); i++)
#define REP(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(RALL(v))
#define UNIQUE(v)                                                              \
    sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end()), v.shrink_to_fit()
#define REV(v) reverse(ALL(v))
#define SZ(v) ((int)(v).size())
#define MIN(v) (*min_element(ALL(v)))
#define MAX(v) (*max_element(ALL(v)))
// util const
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
constexpr int MOD = 1000000007;
constexpr int MOD2 = 998244353;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
// util functions
void Case(int i) { cout << "Case #" << i << ": "; }
int popcount(int x) { return __builtin_popcount(x); }
int popcount(ll x) { return __builtin_popcountll(x); }
template <class T> inline bool chmax(T &a, T b) {
    return (a < b ? a = b, true : false);
}
template <class T> inline bool chmin(T &a, T b) {
    return (a > b ? a = b, true : false);
}
#pragma endregion Macros
