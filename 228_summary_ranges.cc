/*
 * @yang 2015/7/31
 *
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 *
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
    void myinsert(string &str, int num) {
        string temp="";
        long copy;
        bool neg = false;
        if(num == 0) {
            temp = temp+"0";
            str += temp;
            return;
        }
        if(num < 0 ) {
            neg = true;
            copy = 0 - (long)num;
        }
        else 
            copy = (long)num;
        while(copy != 0) {
            temp.insert(temp.begin(),copy%10+'0');
            copy = copy/10;
        }
        if(neg)
            temp.insert(temp.begin(),'-');
        str += temp;
        return;
    }

    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        string temp;
        int first,last,i;
        
        if(nums.size() == 0)
            return ret;
        first = nums[0];
        last = nums[0];
        for(i=1;i<nums.size();++i) {
            if(nums[i] == last+1) {
                last = nums[i];
            }
            else {
                if(first != last) {
                    temp = "";
                    myinsert(temp,first);
                    temp = temp+"->";
                    myinsert(temp,last);
                    ret.push_back(temp);
                    first = nums[i];
                    last = nums[i];
                }
                else {
                    temp = "";
                    myinsert(temp,first);
                    ret.push_back(temp);
                    first = nums[i];
                    last = nums[i];
                }
            }
        }
        if(first != last) {
            temp = "";
            myinsert(temp,first);
            temp = temp+"->";
            myinsert(temp,last);
            ret.push_back(temp);
        }
        else {
            temp = "";
            myinsert(temp,first);
            ret.push_back(temp);
        }
        return ret;
    }
};

int main() {
    Solution solu;
    vector<int> input(1,-1);
    cout<<solu.summaryRanges(input)[0]<<endl;
    return 0;
}
