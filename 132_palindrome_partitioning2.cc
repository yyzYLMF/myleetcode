/*
 * @yang 2015/3/31
 *
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return the minimum cuts needed for a palindrome partitioning of s.
 *
 * For example, given s = "aab",
 * Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <climits>
using namespace std;

//Time Limit Exceeded, the problem is that judge() is a bad implementation, is not the recursion
class Solution {
    public:
    bool judge(string s) {
        int i,j;
        i=0;
        j=s.size()-1;
        while(i<=j) {
            if(s[i]!=s[j])
                break;
            i++;
            j--;
        }
        if(i<=j)
            return false;
        else
            return true;
    }

    int calculate(string s, int *dp, int pos, int len) {
        int i,mincut=INT_MAX,temp;
        if(pos >= len)
            return 0;
        if(dp[pos] != -1) 
            return dp[pos];
        for(i=len-1;i>=pos;--i) {
            if(judge(s.substr(pos,i-pos+1))) {
                if(i!=len-1)
                    temp = 1+calculate(s,dp,i+1,len);
                else {
                    temp = 0;
                    mincut = temp;
                    break;
                }
                if(temp < mincut)
                    mincut=temp;
            }
        }
        dp[pos] = mincut;
        return dp[pos];
    }

    int minCut(string s) {
        int len,i;
        int *dp;
        if(s.size()<=1)
            return 0;
        len = s.size();
        dp = new int[len];
        for(i=0;i<len-1;++i)
            dp[i] = -1;
        dp[len-1]=0;
        return calculate(s,dp,0,len);
    }
};

//AC, the judge() is perfect
class Solution2 {
    public:
    vector<vector<int> > vt;
    vector<int> temp;
    bool judge(string &s, int i, int j) {
        if (i > j)
            return false;
        if (vt[i][j] != -1)
            return vt[i][j];
        if (i == j)
            return vt[i][j] = 1;
        if (s[i] != s[j])
            return vt[i][j] = 0;
        else {
            if (i + 1 == j)
                return vt[i][j] = 1;
            else
                return vt[i][j] = judge(s, i + 1, j - 1);
        }
    }

    int minCut(string s) {
        int *dp;
        int i,j,len,mintemp;
        
        
        len = s.size();
        if(len <= 1)
            return 0;
        for(i=0;i<len;++i)
            temp.push_back(-1);
        for(i=0;i<len;++i)
            vt.push_back(temp);
        dp = new int[len];
        dp[len-1]=0;
        for(i=len-2;i>=0;--i) {
            if(judge(s,i,len-1))
                dp[i]=0;
            else {
                mintemp=len-i;
                for(j=len-2;j>=i;--j) {
                    if(judge(s,i,j))
                        mintemp = min(mintemp,dp[j+1]+1);
                    else
                        mintemp = min(mintemp,dp[j+1]+1+j-i);
                }
                dp[i]=mintemp;
            }
        }
        return dp[0];
    }
};

int main() {
    Solution2 solu;
    string s;
    while(cin>>s)
        cout<<solu.minCut(s)<<endl;
    return 0;
}
