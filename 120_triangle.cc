/*
 * @yang 2015/3/27
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 [
 [2],
 [3,4],
 [6,5,7],
 [4,1,8,3]
 ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
    public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<vector<int> > dp(triangle);
        int i,j,height;
        height = triangle.size();
        int result=INT_MAX;

        for(i=2;i<=height;++i) {
            dp[i-1][0] = dp[i-2][0]+dp[i-1][0];
            dp[i-1][i-1] = dp[i-2][i-2] + dp[i-1][i-1];
        }
        for(i=3;i<=height;++i) {
            for(j=1;j<i-1;++j) {
                dp[i-1][j] = min(dp[i-2][j-1],dp[i-2][j]) + dp[i-1][j];
            }
        }
        for(i=0;i<height;++i) {
            if(dp[height-1][i] < result)
                result = dp[height-1][i];
        }
        return result;
    }
};

int main() {
    Solution solu;
    return 0;
}
