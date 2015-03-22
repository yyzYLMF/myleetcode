/*
 * @yang 2015/3/19
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 *
 * For example,
 * Given board =
 [
 ["ABCE"],
 ["SFCS"],
 ["ADEE"]
 ]
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
    bool myfind(vector<vector<char> > &board, string &word, int **sign, int i, int j, int remain) {
        int index=word.size()-remain;
        int m,n;
        m=board.size();
        n=board[0].size();
        if(remain == 0)
            return true;
        if(i-1>=0 && sign[i-1][j]==0 && board[i-1][j]==word[index]) {
            sign[i-1][j]=1;
            if(myfind(board,word,sign,i-1,j,remain-1))
                return true;
            sign[i-1][j]=0;
        }
        if(j+1<n && sign[i][j+1]==0 && board[i][j+1]==word[index]) {
            sign[i][j+1]=1;
            if(myfind(board,word,sign,i,j+1,remain-1))
                return true;
            sign[i][j+1]=0;
        }
        if(i+1<m && sign[i+1][j]==0 && board[i+1][j]==word[index]) {
            sign[i+1][j]=1;
            if(myfind(board,word,sign,i+1,j,remain-1))
                return true;
            sign[i+1][j]=0;
        }
        if(j-1>=0 && sign[i][j-1]==0 && board[i][j-1]==word[index]) {
            sign[i][j-1]=1;
            if(myfind(board,word,sign,i,j-1,remain-1))
                return true;
            sign[i][j-1]=0;
        }
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        int m,n,i,j,len;
        int **sign;
        m=board.size();
        n=board[0].size();
        len=word.size();
        if(m==0 || n==0 || len==0)
            return false;
        sign = new int*[m];
        for(i=0;i<m;++i)
            sign[i]=new int[n];
        for(i=0;i<m;++i)
            for(j=0;j<n;++j)
                sign[i][j]=0;
        for(i=0;i<m;++i) {
            for(j=0;j<n;++j) {
                if(board[i][j] == word[0]) {
                    sign[i][j]=1;
                    if(myfind(board,word,sign,i,j,len-1))
                        return true;
                    sign[i][j]=0;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solu;
    string s;
    vector<vector<char> > input;
    vector<char> vc;
    vc.push_back('a');
    vc.push_back('b');
    input.push_back(vc);
    input.push_back(vc);
    cin>>s;
    cout<<solu.exist(input,s)<<endl;
    return 0;
}
