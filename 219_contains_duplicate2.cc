/*
 * @yang
 *
 * Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
 *
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
    public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> store;
        int i,len;
        
        len = nums.size();
        if(len <= 1 || k<=0)
            return false;
        for(i=0; i<len; ++i) {
            if(store.find(nums[i]) != store.end()) {
                if(store[nums[i]]+k >= i)
                    return true;
                store[nums[i]] = i;
            }
            else
                store[nums[i]] = i;
        }
        return false;
    }
};

class Solution2 {
    public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       set<int> store;
       int i,start,end,len;

       len = nums.size();
       if(len <= 1 || k<=0)
           return false;
       start = 0;
       end = 0;
       for(i=0; i<len; ++i) {
           if(store.count(nums[i]) > 0)
               return true;
           else {
               store.insert(nums[i]);
               end++;
           }
           if(end-start > k) {
               store.erase(nums[start]);
               start++;
           }
       }
       return false;
    }
};

int main() {
    Solution solu;
    return 0;
}
