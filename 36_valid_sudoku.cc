/*
@yang 2015/3/9

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
	bool isValidSudoku(vector<vector<char> > &board) {
		int i,j,m,n;
		vector<char> rows[9], columns[9];
		vector<char> module;

		for(i=0; i<board.size(); ++i) {
			for(j=0; j<board.size(); ++j) {
				if(board[i][j] == '.')
					continue;
				if(count(rows[i].begin(), rows[i].end(), board[i][j]))
					break;
				else if(count(columns[j].begin(), columns[j].end(), board[i][j]))
					break;
				rows[i].push_back(board[i][j]);
				columns[j].push_back(board[i][j]);
			}
			if(j != board.size())
				break;
		}
		if(i != board.size())
			return false;

		for(i=0; i<9; i=i+3) {
			for(j=0; j<9; j=j+3) {
				module.clear();		
				for(m=0; m<3; ++m) {
					for(n=0; n<3; ++n) {
						if(board[i+m][j+n] == '.')
							continue;
						if(count(module.begin(), module.end(), board[i+m][j+n]))
							return false;
						module.push_back(board[i+m][j+n]);
					}
				}
			}
		}
		return true;
	}
};
