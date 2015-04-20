/*
 * @yang 2015/4/20
 *
 * Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int first,second,temp;
        vector<int> ret;
        first=0;
        second=numbers.size()-1;
        while(first<second) {
            temp = numbers[first]+numbers[second];
            if(temp==target) {
                ret.push_back(first+1);
                ret.push_back(second+1);
                return ret;
            }
            else if(temp > target)
                second--;
            else
                first++;
        }
        return ret;
    }
};

int main() {
    Solution solu;
    vector<int> input;
    input.push_back(2);
    input.push_back(7);
    input.push_back(11);
    input.push_back(15);
    vector<int> ret=solu.twoSum(input,9);
    cout<<ret[0]<<ret[1]<<endl;
    return 0;
}
