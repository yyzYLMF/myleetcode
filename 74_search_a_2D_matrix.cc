/*
 * @yang 2015/3/18
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * For example,
 *
 * Consider the following matrix:
 [
 [1,   3,  5,  7],
 [10, 11, 16, 20],
 [23, 30, 34, 50]
 ]
 * Given target = 3, return true.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
	public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int low,mid,high;
		int m,n,row;

		m=matrix.size();
		n=matrix[0].size();
		if(m==0 || n==0)
			return false;
		if(target<matrix[0][0] || target>matrix[m-1][n-1])
			return false;
		low=0;
		high=m-1;
		while(low+1<high) {
			mid=(low+high)/2;
			if(matrix[mid][0] == target)
				return true;
			else if(matrix[mid][0] > target)
				high = mid-1;
			else
				low = mid+1;
		}
		for(row=low; row<=high; ++row) {
			if(matrix[row][0]==target)
				return true;
			else if(matrix[row][0] > target)
				break;
		}
		row--;
		low=0;
		high=n-1;
		while(low<=high) {
			mid=(low+high)/2;
			if(matrix[row][mid] == target)
				return true;
			else if(matrix[row][mid] > target)
				high = mid-1;
			else
				low = mid+1;
		}
		return false;
	}
};

int main() {
	Solution solu;
	return 0;
}
