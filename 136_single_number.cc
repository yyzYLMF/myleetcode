/*
 * @yang 2015/4/1
 *
 * Given an array of integers, every element appears twice except for one. Find that single one.
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
        int result=0;
        for(int i=0;i<n;++i)
            result ^= A[i];
        return result;
    }
};

int main() {
    Solution solu;
    return 0;
}
