/*
 * @yang 2015/3/24
 *
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 *
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 */
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Solution {
    public:
    int myfun(int **dp, int p, int r) {
        int i,sum=0;       
        if(p>r)
           return 1;
        if(dp[p][r] != 0)
           return dp[p][r];
        for(i=p;i<=r;++i) {
            sum+=myfun(dp,p,i-1) * myfun(dp,i+1,r);
        }
        dp[p][r]=sum;
        return dp[p][r];
    }

    int numTrees(int n) {
        int **dp;
        int sum=0,i;

        if(n==1)
            return 1;
        dp=new int*[n];
        for(i=0;i<n;++i) {
            dp[i]=new int[n];
            memset(dp[i],0,n*sizeof(int));
        }
        for(i=0;i<n;++i)
            dp[i][i]=1;
        for(i=0;i<n-1;++i)
            dp[i][i+1]=2;
        for(i=0;i<n;++i) {
            sum+= myfun(dp,0,i-1)*myfun(dp,i+1,n-1);
        }
        return sum;
    }
};

//perfect method from github
class Solution2 {
    public:
    int numTrees(int n) {
        vector<int> dp;
        for (int i = 0; i <= n; i++) {
            dp.push_back(0);
        }
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += (dp[j - 1] * dp[i - j]);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solu;
    int n;
    while(cin>>n) {
        cout<<solu.numTrees(n)<<endl;
    }
    return 0;
}
