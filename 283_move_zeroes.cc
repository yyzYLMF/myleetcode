#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    void moveZeroes(vector<int>& nums) {
        int i,j,count=0;
        for(i=0,j=0;i<nums.size();++i) {
            if(nums[i] == 0) {
                count++;
            }
            else {
                nums[j++] = nums[i];
            }
        }
        int len = nums.size();
        for(i=0;i<count;++i)
            nums[len-1-i] = 0;
        return;
    }
};

int main() {
    Solution solu;
    return 0;
}
