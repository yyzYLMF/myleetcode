/*
 * @yang 2015/3/16
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 */
#include <iostream>
#include <cstdlib>
using namespace std;

//Time Limit Exceeded
class Solution {
    public:
    void myfun(int &result, int m, int n) {
        if(m==0 || n==0) {
            result++;
            return;
        }
        myfun(result,m-1,n);
        myfun(result,m,n-1);
    }

    int uniquePaths(int m, int n) {
        int result=0;

        if(m<=1 || n<=1)
            return 1;
        myfun(result,m-2,n-1);
        myfun(result,m-1,n-2);
        return result;
    }
};

class Solution2 {
    public:
    int uniquePaths(int m, int n) {
        int **path;
        int i,j;
        
        if(m<=1 || n<=1)
            return 1;
        path = new int*[m];
        for(i=0;i<m;++i)
            path[i] = new int[n];
        for(i=0;i<m;++i)
            path[i][0]=1;
        for(j=0;j<n;++j)
            path[0][j]=1;
        for(i=1;i<m;++i) {
            for(j=1;j<n;++j) {
                path[i][j] = path[i-1][j]+path[i][j-1];
            }
        }
        return path[m-1][n-1];
    }
};

int main() {
    int m,n;
    Solution2 solu;

    while(cin>>m>>n) {
        cout<<solu.uniquePaths(m,n)<<endl;
    }
    return 0;
}
