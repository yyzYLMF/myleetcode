#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

//best method
class Solution2 {
    public:
    int findDuplicate(vector<int>& nums) {
        int slow,fast;
        slow = nums[0];
        fast = nums[nums[0]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int clc_num = 1;
        fast = nums[fast];
        while(fast != slow) {
            clc_num++;
            fast = nums[fast];
        }
        fast = nums[0];
        for(int i=0;i<clc_num;++i) {
            fast = nums[fast];
        }
        slow = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

class Solution {
    public:
    int findDuplicate(vector<int>& nums) {
        int i,n,low,high,mid,count;
        n = nums.size();
        if(n<=2)
            return nums[0];
        n = n-1;
        low = 1;
        high = n;
        while(low < high) {
            mid = (low + high) / 2;
            count = 0;
            for(i=0;i<=n;++i) {
                if(nums[i] <= mid) 
                    count++;
            }
            if(count <= mid)
                low = mid+1;
            else
                high = mid;
        }
        return low;
    }
};

int main() {
    Solution2 solu;
    vector<int> input;
    input.push_back(1);
    input.push_back(3);
    input.push_back(4);
    input.push_back(2);
    input.push_back(1);
    cout<<solu.findDuplicate(input)<<endl;
    return 0;
}
