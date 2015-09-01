/*
 * @yang 2015/4/7
 *
 * Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
 *
 * For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 */
#include <iostream>
#include <cstdlib>
#include <cstdint>
using namespace std;

//BEST
class Solution {
    public:
    int hammingWeight(uint32_t n) {
        int ret=0;
        while(n != 0) {
            ret++;
            n = n&(n-1);
        }
        return ret;
    }
};

class Solution2 {
    public:
    int hammingWeight(uint32_t n) {
        int i,temp,count=0;
        for(i=0;i<32;++i) {
            temp=1<<i;
            if(n & temp)
                count++;
        }
        return count;
    }
};

int main() {
    Solution solu;
    int i;
    while(cin>>i)
        cout<<solu.hammingWeight(i)<<endl;
    return 0;
}
