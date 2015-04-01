/*
 * @yang 2015/4/1
 *
 * Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 *
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 *
 * Return true because "leetcode" can be segmented as "leet code".
 */
#include <iostream>
#include <cstdlib>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
    public:
    int *dp;
    
    bool myfun(string s, int pos, unordered_set<string> &dict) {
        int i,len=s.size();
        if(pos>=len)
            return true;
        if(dp[pos] != -1)
            return dp[pos]==1? true:false;
        dp[pos] = 0;
        for(i=len-1;i>=pos;--i) {
            if(dict.count(s.substr(pos,i+1-pos))) {
                if(myfun(s,i+1,dict)) {
                    dp[pos] = 1;
                    break;
                }
            }
        }
        return dp[pos]==1? true:false;
    }

    bool wordBreak(string s, unordered_set<string> &dict) {
        int i,len;
        len = s.size();
        if(len == 0)
            return dict.count(string(""));
        dp = new int[len];
        for(i=0;i<len;++i)
            dp[i]=-1;
        for(i=len-1;i>=0;--i) {
            if(dict.count(s.substr(0,i+1))) {
                if(myfun(s,i+1,dict))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solu;
    return 0;
}
