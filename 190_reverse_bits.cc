/*
 * @yang 2015/4/8
 *
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000)
 */
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <bitset>
using namespace std;

class Solution {
    public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> copy(n);
        uint32_t temp=1;
        for(int i=0;i<32;++i) {
            temp=1<<i;
            if(n&temp) 
                copy.set(31-i);
            else
                copy.reset(31-i);
        }
        return (uint32_t)copy.to_ulong();
    }
};

class Solution2 {
    public:
    uint32_t reverseBits(uint32_t n) {
        static uint32_t key = 0;
        static uint32_t val = 0;
        if (n == key) return val;
        if (n == val) return key;
        uint32_t ret = 0;
        int index = 31;
        key = n;
        while (n > 0) {
            ret |= (n & 0x1) << index;
            n >>= 1;
            index--;
        }
        val = ret;
        return val;
    }
};

int main() {
    Solution solu;
    uint32_t n;
    while(cin>>n)
        cout<<solu.reverseBits(n)<<endl;
    return 0;
}
