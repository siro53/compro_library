#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../misc/subset-iterator.hpp"

void check(uint32_t mask) {
    vector<uint32_t> bits;
    for(unsigned i = 0; i < 32; ++i) if(mask >> i & 1) bits.push_back(i);
    vector<uint32_t> actual_bits;
    SetBit bit_range(mask);
    assert(bit_range.S == mask);
    for(auto bit : bit_range) actual_bits.push_back(bit);
    assert(actual_bits == bits);
    vector<uint32_t> expected;
    for(unsigned choice = 0; choice < (1U << bits.size()); ++choice) {
        uint32_t value = 0;
        for(unsigned j = 0; j < bits.size(); ++j) if(choice >> j & 1) {
            value |= 1U << bits[j];
        }
        expected.push_back(value);
    }
    sort(expected.begin(), expected.end(), greater<uint32_t>());
    Subset subset_range(mask);
    assert(subset_range.S == mask);
    vector<uint32_t> actual;
    for(auto value : subset_range) actual.push_back(value);
    assert(actual == expected);
    // A new begin() must allow a second traversal, including the empty set.
    actual.clear();
    for(auto value : subset_range) actual.push_back(value);
    assert(actual == expected);
    for(unsigned k = 1; k <= bits.size(); ++k) {
        vector<uint32_t> fixed_expected, fixed_actual;
        for(auto value : expected) if(unsigned(__builtin_popcount(value)) == k) {
            fixed_expected.push_back(value);
        }
        reverse(fixed_expected.begin(), fixed_expected.end());
        Subset_k fixed_range(mask, k);
        assert(fixed_range.S == mask && fixed_range.k == k);
        for(auto value : fixed_range) fixed_actual.push_back(value);
        assert(fixed_actual == fixed_expected);
    }
}

int main() {
    for(uint32_t mask = 0; mask < 256; ++mask) check(mask);
    for(uint32_t mask : {0x80000000U, 0x80000005U, 0xf0000000U, 0x80808080U}) check(mask);
    SetBit::SetBitIter bit(1U << 31);
    assert(bit != nullptr && *bit == 31);
    ++bit;
    assert(!(bit != nullptr));
    Subset::SubsetIter subset(0);
    assert(subset != nullptr && *subset == 0);
    ++subset;
    assert(!(subset != nullptr));
    Subset_k::SubsetIter_k fixed(0x80000001U, 1);
    assert(fixed != nullptr && *fixed == 1);
    ++fixed;
    assert(fixed != nullptr && *fixed == 0x80000000U);
    ++fixed;
    assert(!(fixed != nullptr));
    INT(a, b);
    print(a + b);
}
