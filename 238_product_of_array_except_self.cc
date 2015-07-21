/*
 * @yang 2015/7/21
 *
 * Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 *
 * Solve it without division and in O(n).
 *
 * For example, given [1,2,3,4], return [24,12,8,6].
 *
 * Follow up:
 * Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
 */

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i,temp,len=nums.size();
        vector<int> ret(len,1);
        temp = 1;
        for(i=1;i<=len-1;++i) {
            temp = temp*nums[i-1];
            ret[i] = temp;
        }
        temp = 1; 
        for(i=len-2;i>=0;--i) {
            temp = temp*nums[i+1];
            ret[i] = ret[i]*temp;
        }
        return ret;
    }
};

int main() {
    Solution solu;
    return 0;
}
