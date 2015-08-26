#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    int missingNumber(vector<int>& nums) {
        int i,n;
        n = nums.size();
        if(n == 0)
            return 0;
        for(i=0;i<n;++i) {
            if(nums[i] >= n)
                continue;
            else {
                while(nums[i]<n && nums[nums[i]]!=nums[i]) {
                    swap(nums[i],nums[nums[i]]);
                }
            }
        }
        for(i=0;i<n;++i) {
            if(nums[i] != i)
                break;
        }
        return i;
    }
};

int main() {
    Solution solu;
    return 0;
}
