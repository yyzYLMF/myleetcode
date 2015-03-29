/*
 * @yang 2015/3/18
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 *
 * click to show follow up.
 *
 * Follow up:
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 */
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;

class Solution {
	public:
	void setZeroes(vector<vector<int> > &matrix) {
		map<int,int> row;
		map<int,int> column;
		int i,j,m,n;

		m=matrix.size();
		n=matrix[0].size();
		if(m==0 || n==0)
			return;
		for(i=0;i<m;++i) {
			for(j=0;j<n;++j) {
				if(matrix[i][j] == 0) {
					row[i]=1;
					column[j]=1;
				}
			}
		}

		for(i=0;i<m;++i) {
			if(row[i] > 0) {
				for(j=0;j<n;++j)
					matrix[i][j]=0;
			}
		}
		for(j=0;j<n;++j) {
			if(column[j] > 0) {
				for(i=0;i<m;++i)
					matrix[i][j]=0;
			}
		}
		return;
	}
};

//The best method, don't use extra space
class Solution2{
    public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        if (row == 0) {
            return;
        }
        int col = matrix[0].size();
        bool col_flag = false, row_flag = false;
        for (int i = 0; i < col; i++) {
            if (matrix[0][i] == 0) {
                col_flag = true;
                break;
            }
        }
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                row_flag = true;
                break;
            }
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < row; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < col; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < col; i++) {
            if (matrix[0][i] == 0) {
                for (int j = 1; j < row; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        if (col_flag) {
            for (int i = 0; i < col; i++) {
                matrix[0][i] = 0;
            }
        }
        if (row_flag) {
            for (int i = 0; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
        return;
    }
};

int main() {
    Solution solu;
    return 0;
}
