/*
 * @yang 2015/3/16
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    int minPathSum(vector<vector<int> > &grid) {
        int m,n,i,j;
        int **value;

        m = grid.size();
        n = grid[0].size();
        value = new int*[m];
        for(i=0; i<m; ++i)
            value[i] = new int[n];
        value[0][0] = grid[0][0];
        for(i=1;i<m;++i)
            value[i][0] = value[i-1][0] + grid[i][0];
        for(j=1;j<n;++j)
            value[0][j] = value[0][j-1] + grid[0][j];
        for(i=1; i<m; ++i) {
            for(j=1; j<n; ++j) {
                value[i][j] = min(value[i-1][j],value[i][j-1])+grid[i][j];
            }
        }
        return value[m-1][n-1];
    }
};

int main() {
    Solution solu;
    return 0;
}
