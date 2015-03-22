/*
 * @yang 2015/3/21
 *
 * Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
 * Below is one possible representation of s1 = "great":
 * To scramble the string, we may choose any non-leaf node and swap its two children.
 * For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
 * We say that "rgeat" is a scrambled string of "great".
 * Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
 * We say that "rgtae" is a scrambled string of "great".
 * Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//Memory Limit Exceeded
class Solution {
    public:
    vector<string> mybranch(string &s1, vector<string> **dp, int m, int n) {
        int i,j,k;
        vector<string> left;
        vector<string> right;
        if(!dp[m][n].empty())
            return dp[m][n];
        for(i=m;i<n;++i) {
            left = mybranch(s1,dp,m,i);
            right = mybranch(s1,dp,i+1,n);
            for(j=0;j<left.size();++j) {
                for(k=0;k<right.size();++k) {
                    dp[m][n].push_back(left[j]+right[k]);
                    dp[m][n].push_back(right[k]+left[j]);
                }
            }
        }
        return dp[m][n];
    }

    bool isScramble(string s1, string s2) {
        vector<string> **dp;
        vector<string> left;
        vector<string> right;
        vector<string> store;
        int len,i,j,k;
        string s1copy(s1),s2copy(s2);

        if(s1.empty())
            return true;
        sort(s1copy.begin(),s1copy.end());
        sort(s2copy.begin(),s2copy.end());
        if(s1copy != s2copy)
            return false;
        len = s1.size();
        dp = new vector<string>* [len];
        for(i=0;i<len;++i)
            dp[i]=new vector<string>[len];
        for(i=0;i<len;++i)
            dp[i][i].push_back(string(1,s1[i]));
        for(i=0;i<len-1;++i) {
            left=mybranch(s1,dp,0,i);
            right=mybranch(s1,dp,i+1,len-1);
            for(j=0;j<left.size();++j) {
                for(k=0;k<right.size();++k) {
                    store.push_back(left[j] + right[k]);
                    store.push_back(right[k] + left[j]);
                }
            }
        }
        if(count(store.begin(), store.end(), s2))
            return true;
        else
            return false;
    }
};

//AC, if the pos1+len is the same as pos2+len, dp[pos1][pos2][len] is true(1) else is false(0)
class Solution2 {
    public:
    int judge(string &s1, string &s2, vector<vector<vector<int> > > &dp, int pos1, int pos2, int len) {
        if (dp[pos1][pos2][len] != -1) {
            return dp[pos1][pos2][len];
        }
        if (len == 0 || (len == 1 && s1[pos1] == s2[pos2])) {
            return dp[pos1][pos2][len] = 1;
        }
        for (int i = 1; i < len; i++) {
            if (judge(s1, s2, dp, pos1 + i, pos2 + i, len - i) && judge(s1, s2, dp, pos1, pos2, i)) {
                return dp[pos1][pos2][len] = 1;
            }
            if (judge(s1, s2, dp, pos1, pos2 + len - i, i) && judge(s1, s2, dp, pos1 + i, pos2, len - i)) {
                return dp[pos1][pos2][len] = 1;
            }
        }
        return dp[pos1][pos2][len] = 0;
    }
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        if (s1.length() == 0) {
            return true;
        }
        vector<vector<vector<int> > > dp;
        vector<vector<int> > tmp1;
        vector<int> tmp2;
        for (int i = 0; i <= s1.length(); i++) {
            tmp2.push_back(-1);
        }
        for (int i = 0; i <= s1.length(); i++) {
            tmp1.push_back(tmp2);
        }
        for (int i = 0; i <= s1.length(); i++) {
            dp.push_back(tmp1);
        }
        return judge(s1, s2, dp, 0, 0, s1.length());
    }
};

int main() {
    Solution solu;
    string s1,s2;
    while(cin>>s1>>s2) {
        cout<<solu.isScramble(s1,s2)<<endl;
    }
    return 0;
}
