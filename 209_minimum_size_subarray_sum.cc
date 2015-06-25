/*
 * @yang 2015/6/25
 *
 * Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 *
 * For example, given the array [2,3,1,2,4,3] and s = 7,
 * the subarray [4,3] has the minimal length under the problem constraint.
 */

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i,start,len,sum,ret,temp;

        len = nums.size();
        if(len <= 0)
            return 0;
        start = 0;
        i = 0;
        sum = 0;
        ret = 0;
        while(i < len && sum < s) {
            sum += nums[i];
            i++;
            ret++;
        }
        if(i >= len && sum < s)
            return 0;
        while(start<i && sum-nums[start] >= s) {
            sum -= nums[start];
            start++;
            ret--;
        }
        temp = ret;
        for(; i<len; ++i) {
            sum += nums[i];
            temp++;
            while(start<i &&sum-nums[start] >= s) {
                sum -= nums[start];
                start++;
                temp--;
            }
            if(temp < ret)
                ret = temp;
        }
        return ret;
    }
};

int main() {
    Solution solu;
    return 0;
}
