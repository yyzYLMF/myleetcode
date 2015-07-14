/*
 * @yang 2015/7/14
 * Note: This is an extension of House Robber.
 *
 * After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
    public:
    int myrob(vector<int>& nums, int m, int n) {
        int i,len=nums.size();
        memset(dp,0,(len+1)*sizeof(int));
        if(m > n)
            return 0;
        dp[n+1] = 0;
        dp[n] = nums[n];
        for(i=n-1; i>=m; --i) {
            dp[i] = max(nums[i]+dp[i+2],dp[i+1]);
        }
        return dp[m];
    }
    int rob(vector<int>& nums) {
        int i,len,temp1,temp2,ret;
        len = nums.size();
        if(len == 0)
            return 0;
        if(len == 1)
            return nums[0];
        dp = new int[len+1];
        temp1 = myrob(nums,2,len-2) + nums[0];
        temp2 = myrob(nums,1,len-1);
        ret = max(temp1,temp2);
        return ret;
    }
    private:
    int *dp;
};

int main() {
    Solution solu;
    return 0;
}
