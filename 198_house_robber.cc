/*
 * @yang 2015/4/7
 *
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    int rob(vector<int> &num) {
        int *dp,i,len,temp;
        if(num.empty())
            return 0;
        if(num.size()==1)
            return num[0];
        len=num.size();
        dp = new int[len];
        dp[len-1] = num[len-1];
        dp[len-2] = max(num[len-2],num[len-1]);
        for(i=len-3;i>=0;--i) {
            temp = num[i]+dp[i+2];
            dp[i] = max(dp[i+1],temp);
        }
        return dp[0];
    }
};

int main() {
    Solution solu;
    return 0;
}
