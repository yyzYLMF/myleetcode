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

int main() {
	Solution solu;
	return 0;
}
