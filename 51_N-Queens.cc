/*
@yang 2015/3/12

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
[".Q..",  // Solution 1
"...Q",
"Q...",
"..Q."],

["..Q.",  // Solution 2
"Q...",
"...Q",
".Q.."]
]
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
class Solution {
	public:
	void myfun(vector<vector<string> > &result, vector<string> temp, int *columns, int n, int rows) {
		int i,j,k;
		if(rows == 0) {
			result.push_back(temp);
			return;
		}
		for(i=0; i<n; ++i) {
			if(columns[i] == 1)
				continue;
			j=i+1;
			k=rows-1+1;
			while(j<n && k<n) {
				if(temp[k][j] == 'Q')
					break;
				k++;
				j++;
			}
			if(j<n && k<n)
				continue;
			k=rows-1+1;
			j=i-1;
			while(j>=0 && k<n) {
				if(temp[k][j] == 'Q')
					break;
				k++;
				j--;
			}
			if(j>=0 && k<n)
				continue;
			temp[rows-1][i] = 'Q';
			columns[i] = 1;
			myfun(result, temp, columns, n, rows-1);
			temp[rows-1][i] = '.';
			columns[i] = 0;
		}
		return;
	}

	vector<vector<string> > solveNQueens(int n) {
		vector<vector<string> > result;
		vector<string> temp;
		int columns[n];
		int i,j;
		string s="";

		for(i=0; i<n; ++i) {
			columns[i] = 0;
		}

		for(j=0; j<n; ++j)
			s.insert(s.end(), '.');
		for(i=0; i<n; ++i)
			temp.push_back(s);
		
		for(i=0; i<n; ++i) {
			temp[n-1][i] = 'Q';
			columns[i]=1;
			myfun(result, temp, columns, n, n-1);
			temp[n-1][i] = '.';
			columns[i]=0;
		}
		return result;
	}
};

int main() {
	Solution solu;
	int n;
	int i,j;
	vector<vector<string> > result;

	while(cin>>n) {
		result = solu.solveNQueens(n);
		for(i=0; i<result.size(); ++i) {
			for(j=0; j<result[i].size(); ++j)
				cout<<result[i][j]<<endl;
			cout<<endl;
		}
	}
	return 0;
}
