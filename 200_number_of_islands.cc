/*
 * @yang 2015/4/8
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 *
 Example 1:
 11110
 11010
 11000
 00000
 Answer: 1

 Example 2:
 11000
 11000
 00100
 00011
 Answer: 3
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
    public:
    void myfunc(vector<vector<char>> &grid, int **sign, int x, int y) {
        int m,n;
        m = grid.size();
        n = grid[0].size();
        sign[x][y]=1;
        if(x+1<m && grid[x+1][y]=='1' && sign[x+1][y]==0)
            myfunc(grid,sign,x+1,y);
        if(x-1>=0 && grid[x-1][y]=='1' && sign[x-1][y]==0)
            myfunc(grid,sign,x-1,y);
        if(y+1<n && grid[x][y+1]=='1' && sign[x][y+1]==0)
            myfunc(grid,sign,x,y+1);
        if(y-1>=0 && grid[x][y-1]=='1' && sign[x][y-1]==0)
            myfunc(grid,sign,x,y-1);
        return;
    }

    int numIslands(vector<vector<char>> &grid) {
        int **sign;
        int m,n,i,j,count;
        m=grid.size();
        if(m == 0)
            return 0;
        n=grid[0].size();
        if(n == 0)
            return 0;
        sign = new int*[m];
        for(i=0;i<m;++i) {
            sign[i] = new int[n];
            memset(sign[i],0,n*sizeof(int));
        }
        count=0;
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(grid[i][j]=='1' && sign[i][j]==0) {
                    myfunc(grid,sign,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solu;
    vector<char> temp(1,'1');
    vector<vector<char>> input;
    input.push_back(temp);
    cout<<solu.numIslands(input)<<endl;
    return 0;
}
