/*
 * @yang 2015/3/24
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 *
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 */
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
    public:
    bool isInterleave(string s1, string s2, string s3) {
        bool **dp;
        int m,n,len,i,j;
        m=s1.size();
        n=s2.size();
        len=s3.size();
        if(m+n != len)
            return false;
        dp=new bool*[m+1];
        for(i=0;i<m+1;++i)
            dp[i]=new bool[n+1];
        dp[0][0]=true;
        for(i=1;i<=len;++i) {
            for(j=0;j<=i;++j) {
                if(j>m || i-j>n )
                    continue;
                if(j-1>=0) {
                    if(s1[j-1]==s3[i-1] && dp[j-1][i-j]) {
                        dp[j][i-j]=true;
                        continue;
                    }
                }
                if(i-j-1>=0) { 
                    if(s2[i-j-1]==s3[i-1] && dp[j][i-j-1]) {
                        dp[j][i-j]=true;
                        continue;
                    }
                }
                dp[j][i-j]=false;
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution solu;
    string s1,s2,s3;
    while(cin>>s1>>s2>>s3) {
        cout<<solu.isInterleave(s1,s2,s3)<<endl;
    }
    return 0;
}
