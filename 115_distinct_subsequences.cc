/*
 * @yang 2015/3/27
 *
 * Given a string S and a string T, count the number of distinct subsequences of T in S.
 *
 * A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 *
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 *
 * Return 3.
 */
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
    public:
    int numDistinct(string S, string T) {
        int **dp;
        int i,j,m,n;
        
        m = S.size();
        n = T.size();
        if(n==0)
            return 1;
        else if(m < n)
            return 0;
        dp = new int*[m+1];
        for(i=0;i<=m;++i) 
            dp[i]=new int[n+1];
        for(j=1;j<=n;++j) 
            dp[0][j]=0;
        for(i=0;i<=m;++i)
            dp[i][0]=1;
        for(j=1;j<=n;++j) {
            for(i=1;i<=m;++i) {
                if(j>i)
                    dp[i][j]=0;
                else {
                    if(S[i-1] != T[j-1])
                        dp[i][j] = dp[i-1][j];
                    else {
                        if(i==j)
                            dp[i][j] = dp[i-1][j-1];
                        else if(i>j)
                            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                    }
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution solu;
    return 0;
}
