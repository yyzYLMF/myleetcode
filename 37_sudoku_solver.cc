/*
@yang 2015/3/10

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
	public:
	bool mysolve(vector<char> *rows, vector<char> *columns, vector<char> *modules, vector<vector<char> > &board){
		int i,j;
		char num;

		for(i=0; i<9; ++i) {
			for(j=0; j<9; ++j) {
				if(board[i][j]!='.')
					continue;
				for(num='1'; num<='9'; ++num) {
					if(count(rows[i].begin(),rows[i].end(),num))
						continue;
					if(count(columns[j].begin(),columns[j].end(),num))
						continue;
					if(count(modules[(i/3)*3+j/3].begin(), modules[(i/3)*3+j/3].end(),num))
						continue;
					board[i][j] = num;
					rows[i].push_back(num);
					columns[j].push_back(num);
					modules[(i/3)*3+j/3].push_back(num);
					if(i==8 && j==8)
						return true;
					if(mysolve(rows,columns,modules,board))
						return true;
					else {
						rows[i].pop_back();
						columns[j].pop_back();
						modules[(i/3)*3+j/3].pop_back();
						board[i][j] = '.';
					}	
				}
				return false;
			}
		}
		return true;
	}

	void solveSudoku(vector<vector<char> > &board) {
		int i,j;
		vector<char> rows[9], columns[9], modules[9];

		for(i=0; i<9; ++i) {
			for(j=0; j<9; ++j) {
				if(board[i][j] == '.')
					continue;
				rows[i].push_back(board[i][j]);
				columns[j].push_back(board[i][j]);
				modules[(i/3)*3+j/3].push_back(board[i][j]);
			}
		}
		mysolve(rows, columns, modules, board);
		return;
	}
};
