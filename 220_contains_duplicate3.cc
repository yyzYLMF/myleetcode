#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>
#include <map>
using namespace std;

class Solution {
    public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long,long> sign;
        long i,start,key;
        if(nums.size() <= 1 || t<0)
            return false;
        start = 0;
        for(i=0;i<nums.size();++i) {
            key = nums[i]/((long)t+1);
            if(sign.find(key)!=sign.end() && abs((long)nums[i]-sign[key])<=t)
                return true;
            else if(sign.find(key-1)!=sign.end() && abs((long)nums[i]-sign[key-1])<=t)
                return true;
            else if(sign.find(key+1)!=sign.end() && abs((long)nums[i]-sign[key+1])<=t)
                return true;
            sign[key] = nums[i];
            if(i-start == k) {
                key = nums[start]/(t+1);
                sign.erase(key);
                start++;
            }
        }
        return false;
    }
};

//TLE
class Solution2 {
    public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int i;
        list<int> li;
        list<int>::iterator pos;
        if(nums.size() <= 1)
            return false;
        li.push_back(nums[0]);
        for(i=1;i<nums.size() && i<=k;++i) {
            pos = li.begin();
            while(pos != li.end()) {
                if(abs(nums[i]-*pos)<=t)
                    return true;
                pos++;
            }
            li.push_back(nums[i]);
        }
        if(i <= k)
            return false;
        for(;i<nums.size();++i) {
            li.pop_front();
            pos = li.begin();
            while(pos != li.end()) {
                if(nums[i]-*pos<=t || *pos-nums[i]<=t)
                    return true;
                pos++;
            }
            li.push_back(nums[i]);
        }
        return false;
    }
};

int main() {
    Solution solu;
    vector<int> input;
    input.push_back(-1);
    input.push_back(2147483647);
    cout<<solu.containsNearbyAlmostDuplicate(input,1, 2147483647)<<endl;
    return 0;
}
