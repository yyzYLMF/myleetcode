/*
 * @yang 2015/4/1
 *
 * Given an array of integers, every element appears three times except for one. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */
#include <iostream>
#include <cstdlib>
using namespace std;
 
class Solution {
    public:
    int singleNumber(int A[], int n) {
        int bitnum[32] = {0};
        int i,j,sum=0;
        for(i=0;i<32;++i) {
            for(j=0;j<n;++j) {
                bitnum[i] += (A[j]>>i)&1;
            }
        }
        for(i=0;i<32;++i) {
            sum |= (bitnum[i]%3)<<i;
        }
        return sum;
    }
};

int main() {
    Solution solu;
    return 0;
}
