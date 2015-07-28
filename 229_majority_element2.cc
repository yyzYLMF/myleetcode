#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> majorityElement(vector<int>& nums) {
        int i,n1,n2,sum1,sum2;
        vector<int> ret;
        sum1 = 0;
        sum2 = 0;
        for(i=0;i<nums.size();++i) {
            if(sum1 != 0) {
                if(nums[i] == n1) {
                    sum1++;
                    continue;
                }
            }
            if(sum2 != 0) {
                if(nums[i] == n2) {
                    sum2++;
                    continue;
                }
            }
            if(sum1 == 0) {
                n1 = nums[i];
                sum1 = 1;
                continue;
            }
            if(sum2 == 0) {
                n2 = nums[i];
                sum2 = 1;
                continue;
            }
            sum1--;
            sum2--;
        }
        int number1=0,number2=0;
        for(i=0;i<nums.size();++i) {
            if(nums[i] == n1 && sum1!=0)
                number1++;
            else if(nums[i] == n2 && sum2!=0)
                number2++;
        }
        if(number1*3 > nums.size())
            ret.push_back(n1);
        if(number2*3 > nums.size())
            ret.push_back(n2);
        return ret;
    }
};

int main() {
    Solution solu;
    vector<int> input;
    input.push_back(1);
    input.push_back(1);
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    input.push_back(4);
    input.push_back(5);
    input.push_back(6);
    cout<<solu.majorityElement(input).size()<<endl;
    return 0;
}
