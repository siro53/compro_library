#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../string/rolling-hash.hpp"
#include "../../../string/z-algo.hpp"


int main() {
    const uint64_t base = 911382323;
    auto random_base = RollingHash::gen_base(); assert(2 <= random_base && random_base <= RollingHash::mod - 2);
    for(string s : {string(), string("a"), string("aaaaa"), string("abacaba"), string("abcdef")}) {
        vector<int> values(s.begin(), s.end());
        RollingHash hash(s, base), vector_hash(values, base);
        assert(hash.base == base && hash.hashed.size() == s.size() + 1 && hash.power[0].val() == 1);
        auto z = z_algo(s); assert(z.size() == s.size());
        for(int i = 0; i < int(s.size()); ++i) {
            int expected = 0; while(i + expected < int(s.size()) && s[expected] == s[i + expected]) ++expected;
            assert(z[i] == expected);
        }
        for(int l = 0; l <= int(s.size()); ++l) for(int r = l; r <= int(s.size()); ++r) {
            __int128 expected = 0;
            for(int i = l; i < r; ++i) expected = (expected * base + s[i]) % RollingHash::mod;
            assert(hash.get(l, r).val() == expected && hash.get(l, r) == vector_hash.get(l, r));
            for(int mid = l; mid <= r; ++mid) assert(hash.connect(hash.get(l, mid), hash.get(mid, r), r - mid) == hash.get(l, r));
            for(int start = 0; start <= int(s.size()); ++start) {
                int common = 0;
                while(l + common < r && start + common < int(s.size()) && s[l + common] == s[start + common]) ++common;
                assert(hash.get_lcp(vector_hash, l, r, start, s.size()) == common);
            }
        }
    }
    INT(a, b); print(a + b);
}
