/*
 * @yang
 *
 * Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 *
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;

class Solution {
    public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> store;
        int i,len;

        len = nums.size();
        if(len <= 1)
            return false;
        for(i=0; i<len; ++i) {
            if(store.count(nums[i]) > 0)
                return true;
            store.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    Solution solu;
    return 0;
}
