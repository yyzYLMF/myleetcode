/*
 * @yang 2015/4/4
 *
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 *
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 */
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//Memory Limit Exceeded
class Solution {
    public:
    int maxProduct(int A[], int n) {
        int **dp;
        int i,j,max=0;
        if(n==1)
            return A[0];
        dp = new int*[n];
        for(i=0;i<n;++i) 
            dp[i] = new int[n];
        for(i=0;i<n;++i)
            dp[i][i] = A[i];
        for(i=n-1;i>=0;--i) {
            for(j=i+1;j<n;++j) {
                dp[i][j] = A[i]*dp[i+1][j];
                if(dp[i][j] > max)
                    max = dp[i][j];
            }
        }
        return max;
    }
};

//AC
class Solution2 {
    public:
    class Node {
        public:
        int temp_max;
        int temp_min;
    };

    int maxProduct(int A[], int n) {
        Node *dp;
        int i,j,fmax,tempmax,tempmin;
        if(n==1)
            return A[0];
        dp = new Node[n];
        dp[n-1].temp_max = A[n-1];
        dp[n-1].temp_min = A[n-1];
        fmax = A[n-1];
        for(i=n-2;i>=0;--i) {
            tempmax = A[i]*dp[i+1].temp_max;
            tempmin = A[i]*dp[i+1].temp_min;
            if(tempmax < tempmin)
                swap(tempmax,tempmin);
            dp[i].temp_max = max(tempmax,A[i]);
            dp[i].temp_min = min(tempmin,A[i]);
            if(dp[i].temp_max > fmax)
                fmax = dp[i].temp_max;
        }
        return fmax;
    }
};
            
int main() {
    Solution2 solu;
    int input[]={2,3,-2,4};
    cout<<solu.maxProduct(input,4)<<endl;
    return 0;
}
