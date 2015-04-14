/*
 * @yang 2015/4/14
 *
 * The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.
 *
 * The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
 *
 * Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).
 *
 * In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

//Wrong Answer
class Solution {
    public:
    struct Node {
        int need;
        int value;
    };
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        Node **dp;
        int i,j,m,n,temp1,temp11,temp2,temp22;
        m=dungeon.size();
        if(m==0)
            return 0;
        n=dungeon[0].size();
        if(n==0)
            return 0;
        dp = new Node*[m];
        for(i=0;i<m;++i)
            dp[i] = new Node[n];
        dp[0][0].value = dungeon[0][0];
        dp[0][0].need = dungeon[0][0];
        for(i=1;i<m;++i) {
            dp[i][0].value = dp[i-1][0].value + dungeon[i][0];
            if(dp[i][0].value < dp[i-1][0].need)
                dp[i][0].need = dp[i][0].value;
            else
                dp[i][0].need = dp[i-1][0].need;
        }
        for(i=1;i<n;++i) {
            dp[0][i].value = dp[0][i-1].value + dungeon[0][i];
            if(dp[0][i].value < dp[0][i-1].need)
                dp[0][i].need = dp[0][i].value;
            else
                dp[0][i].need = dp[0][i-1].need;
        }
        for(i=1;i<m;++i) {
            for(j=1;j<n;++j) {
                temp1 = dungeon[i][j] + dp[i-1][j].value;
                temp11 = min(temp1, dp[i-1][j].need);
                
                temp2 = dungeon[i][j] + dp[i][j-1].value;
                temp22 = min(temp2, dp[i][j-1].need);
                if(temp11 > temp22) {
                    dp[i][j].value = temp1;
                    dp[i][j].need = temp11;
                }
                else {
                    dp[i][j].value = temp2;
                    dp[i][j].need = temp22;
                }
            }
        }
        if(dp[m-1][n-1].need >= 0)
            return 1;
        else
            return -dp[m-1][n-1].need+1;
    }
};

//AC
class Solution2 {
    public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        if(dungeon.empty())
            return 0;
        vector<vector<int> > dp(dungeon.size());
        for(int i = 0; i < dp.size(); i++) {
            dp[i].reserve(dungeon[i].size());
        }
        int m = dungeon.size();
        int n = dungeon[0].size();
        if(dungeon[m - 1][n - 1] >= 0) {
            dp[m - 1][n - 1] = 1;
        } else {
            dp[m - 1][n - 1] = 1 - dungeon[m - 1][n - 1];
        }

        for(int i = m - 2; i >= 0; i--) {
            dp[i][n - 1] = max(dp[i + 1][n - 1] - dungeon[i][n - 1], 1);
        }
        for(int j = n - 2; j >= 0; j--) {
            dp[m - 1][j] = max(dp[m - 1][j + 1] - dungeon[m - 1][j], 1);
        }
        for(int i = m - 2; i >= 0; i--) {
            for(int j = n - 2; j >= 0; j--) {
                dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
            }
        }

        return dp[0][0];
    }

};

int main() {
    Solution2 solu;
    vector<vector<int> > input;
    vector<int> temp;
    temp.push_back(-5);
    temp.push_back(3);
    input.push_back(temp);
    temp.push_back(2);
    temp.push_back(1);
    return 0;
}
