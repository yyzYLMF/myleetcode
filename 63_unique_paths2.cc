/*
 * @yang 2015/3/16
 *
 * Follow up for "Unique Paths":
 *
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 [
 [0,0,0],
 [0,1,0],
 [0,0,0]
 ]
 The total number of unique paths is 2.
 Note: m and n will be at most 100.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
	public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int m,n,i,j;
		int **path;
		m = obstacleGrid.size();
		n = obstacleGrid[0].size();
		path = new int*[m];
		for(i=0; i<m; ++i)
			path[i] = new int[n];
		path[0][0] = obstacleGrid[0][0] ? 0:1;
		for(i=1; i<m; ++i) {
			if(obstacleGrid[i][0]!=1 && path[i-1][0]==1)
				path[i][0]=1;
			else
				path[i][0]=0;
		}
		for(j=1; j<n; ++j) {
			if(obstacleGrid[0][j]!=1 && path[0][j-1]==1)
				path[0][j]=1;
			else
				path[0][j]=0;
		}
		for(i=1; i<m; ++i) {
			for(j=1; j<n; ++j) {
				if(obstacleGrid[i][j] == 1)
					path[i][j] = 0;
				else 
					path[i][j] = path[i-1][j] + path[i][j-1];
			}
		}
		return path[m-1][n-1];
	}
};
int main() {
	Solution solu;
	return 0;
}
