/*
 * @yang 2015/4/6
 *
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always exist in the array.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

class Solution {
    public:
    int majorityElement(vector<int> &num) {
        map<int,int> mymap;
        int i,max_num=0,max_val;
        map<int,int>::iterator pos;
        if(num.size()==1)
            return num[0];
        for(i=0;i<num.size();++i)
            mymap[num[i]]++;
        pos = mymap.begin();
        while(pos != mymap.end()) {
            if(pos->second > max_num) {
                max_num = pos->second;
                max_val = pos->first;
            }
            pos++;
        }
        return max_val;
    }
};

int main() {
    Solution solu;
    vector<int> input(1,1);
    solu.majorityElement(input);
    return 0;
}
