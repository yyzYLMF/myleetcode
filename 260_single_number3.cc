#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> singleNumber(vector<int>& nums) {
        int i,j,off,left,right,count;
        vector<int> ret;
        if(nums.size() <= 2) {
            return nums;
        }
        for(i=0;i<32;i++){
            off = 1<<i;
            left = 0;
            right = 0;
            count = 0;
            for(j=0;j<nums.size();++j) {
                if((nums[j]&off) == 0) {
                    count++;
                    left = left^nums[j];
                }
                else {
                    right = right^nums[j];
                }
            }
            if(count%2==1) {
                ret.push_back(left);
                ret.push_back(right);
                return ret;
            }
        }
        return ret;
    }
};

int main() {
    Solution solu;
    return 0;
}
