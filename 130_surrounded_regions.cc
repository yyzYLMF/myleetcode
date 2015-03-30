/*
 * @yang 2015/3/30
 *
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 *
 * For example,
 X X X X
 X O O X
 X X O X
 X O X X
 * After running your function, the board should be:
 X X X X
 X X X X
 X X X X
 X O X X
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

//Time limit Exceeded
class Solution {
    public:
    bool traverse(vector<vector<char> > &board, int **sign, int i, int j, int direct) {
        int m,n;
        m=board.size();
        n=board[0].size();
        if(i==0 || i==m-1 || j==0 || j==n-1) {
            sign[i][j]=1;
            return true;
        }
        sign[i][j]=2;
        if(sign[i][j+1]==1 || sign[i][j+1]==-1) {
            sign[i][j] = sign[i][j+1];
            return sign[i][j]==1?true:false;
        }
        if(board[i][j+1]=='O' && sign[i][j+1]==0 && traverse(board,sign,i,j+1,2)) {
            sign[i][j] = 1;
            return true;
        }

        if(sign[i+1][j]==1 || sign[i+1][j]==-1) {
            sign[i][j] = sign[i+1][j];
            return sign[i][j]==1? true:false;
        }
        if(board[i+1][j]=='O' && sign[i+1][j]==0 && traverse(board,sign,i+1,j,3)) {
            sign[i][j] = 1;
            return true;
        }

        if(sign[i][j-1]==1 || sign[i][j-1]==-1) {
            sign[i][j] = sign[i][j-1];
            return sign[i][j]==1?true:false;
        }
        if(board[i][j-1]=='O' && sign[i][j-1]==0 && traverse(board,sign,i,j-1,4)) {
            sign[i][j] = 1;
            return true;
        }

        if(sign[i-1][j]==1 || sign[i-1][j]==-1) {
            sign[i][j] =  sign[i-1][j];
            return sign[i][j]==1?true:false;
        }
        if(board[i-1][j]=='O' && sign[i-1][j]==0 && traverse(board,sign,i-1,j,1)) {
            sign[i][j] = 1;
            return true;
        }
        sign[i][j]=0;
        return false;
    }
    void solve(vector<vector<char> > &board) {
        int i,j,m,n;
        int **sign;
        m=board.size();
        if(m <= 2)
            return;
        n=board[0].size();
        if(n <= 2)
            return;
        sign = new int*[m];
        cout<<m<<" "<<n<<endl;
        for(i=0;i<m;++i) {
            sign[i] = new int[n];
            memset(sign[i], 0, n*sizeof(int));
        }
        for(i=0;i<m;++i) {
            if(board[i][0]=='O')
                sign[i][0]=1;
            if(board[i][n-1]=='O')
                sign[i][n-1]=1;
        }
        for(j=0;j<n;++j) {
            if(board[0][j]=='O')
                sign[0][j]=1;
            if(board[m-1][j]=='O')
                sign[m-1][j]=1;
        }

        for(i=0;i<m;++i) {
            for(j=0;j<n;++j) {
                if(board[i][j]=='O' && sign[i][j]==0)
                    if(!traverse(board,sign,i,j,-1))
                        sign[i][j]=-1;
            }
        }
        for(i=0;i<m;++i) {
            for(j=0;j<n;++j) {
                if(board[i][j]=='O' && sign[i][j]==-1)
                    board[i][j]='X';
            }
        }
        return;
    }
};

class Solution2 {
    public:
    int row, col;
    vector<vector<int> > vis;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    bool judge(int x, int y) {
        return (x >= 0 && x < row && y >= 0 && y < col);
    }
    struct Node {
        int x, y;
        Node(){}
        Node(int a, int b) {
            x = a, y = b;
        }
    };

    bool bfs(vector<vector<char> > &g, vector<Node> &ans, int x, int y) {
        bool flag = true;
        queue<Node> q;
        vis[x][y] = 1;
        ans.push_back(Node(x, y));
        q.push(Node(x, y));
        Node t;
        int tx, ty;
        while (!q.empty()) {
            t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                tx = t.x + dx[i];
                ty = t.y + dy[i];
                if (judge(tx, ty) == false) {
                    flag =false;
                    continue;
                }
                if (vis[tx][ty] == 0 && g[tx][ty] == 'O') {
                    vis[tx][ty] = 1;
                    ans.push_back(Node(tx, ty));
                    q.push(Node(tx, ty));
                }
            }
        }
        return flag;
    }
    void solve(vector<vector<char> > &board) {
        row = board.size();
        if (row == 0)
            return;
        col = board[0].size();
        if (col == 0)
            return;
        vector<int> tmp;
        tmp.clear(), vis.clear();
        for (int i = 0; i < col; i++)
            tmp.push_back(0);
        for (int i = 0; i < row; i++)
            vis.push_back(tmp);
        vector<Node> ans;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                ans.clear();
                if (vis[i][j] == 0 && board[i][j] == 'O' && bfs(board, ans, i, j)) {
                    for (int k = 0; k < ans.size(); k++)
                        board[ ans[k].x ][ ans[k].y ] = 'X';
                }
            }
        return;
    }
};

int main() {
    Solution2 solu;
    vector<vector<char> > board;
    vector<char> tempo(200,'O');
    vector<char> tempx(200,'X');
    board.push_back(tempo);
    tempx[0]='O';
    tempx[199]='O';
    board.push_back(tempx);
    tempo[1]='X';
    tempo[198]='X';
    for(int i=0;i<196;++i)
        board.push_back(tempo);
    board.push_back(tempx);
    tempo[1]='O';
    tempo[198]='O';
    board.push_back(tempo);
    solu.solve(board);
    /*
    for(int i=0;i<board.size();++i) {
        for(int j=0;j<board[i].size();++j) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    return 0;
}
