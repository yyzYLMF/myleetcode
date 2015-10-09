#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    void gameOfLife(vector<vector<int> >& board) {
        int i,j,k,count;
        m = board.size();
        if(m == 0)
            return;
        n = board[0].size();
        if(n == 0)
            return;
        for(i=0;i<m;++i) {
            for(j=0;j<n;++j) {
                count = 0;
                for(k=0;k<8;++k) {
                    int nx = i+xx[k];
                    int ny = j+yy[k];
                    if(!judge(nx,ny))
                        continue;
                    if(board[nx][ny]==1 || board[nx][ny]==2 || board[nx][ny]==3)
                        count++;
                }
                if(board[i][j] == 0) {
                    if(count == 3)
                        board[i][j] = 4;
                    else
                        board[i][j] = 5;
                }
                else {
                    if(count < 2 || count > 3)
                        board[i][j] = 3;
                    else
                        board[i][j] = 2;
                }
            }
        }
        for(i=0;i<m;++i) {
            for(j=0;j<n;++j) {
                if(board[i][j]==2 || board[i][j]==4)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
        return;
    }
    private:
    int xx[8] = {-1,-1,-1,0,0,1,1,1};
    int yy[8] = {-1,0,1,-1,1,-1,0,1};
    int m,n;
    bool judge(int a, int b) {
        if(a<0||a>=m||b<0||b>=n)
            return false;
        else
            return true;
    }
};

int main() {
    Solution solu;
    vector<int> input1(1,0);
    vector<vector<int> >  input2(1,input1);
    solu.gameOfLife(input2);
    return 0;
}
