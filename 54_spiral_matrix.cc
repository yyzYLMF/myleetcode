/*
@yang 2015/3/13

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
	public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		int m,n,count,direct,i,j;
		vector<int> result;
		int **sign;
		
		if(matrix.size() == 0)
			return result;
		m = matrix.size();
		n = matrix[0].size();
		if(m*n == 0)
			return result;
		sign = new int*[m];
		for(i=0; i<m; ++i)
			sign[i] = new int[n];
		for(i=0; i<m; ++i) {
			for(j=0; j<n; ++j) {
				sign[i][j] = 0;
			}
		}
		i=0;
		j=0;
		direct=0;
		count=0;
		while(count != m*n) {
			result.push_back(matrix[i][j]);
			sign[i][j] = 1;
			count++;
			if(direct == 0) {
				j++;
				if(j>=n || sign[i][j] == 1) {
					direct=1;
					j--;
					i++;
				}
			}
			else if(direct == 1) {
				i++;
				if(i>=m || sign[i][j] == 1) {
					direct=2;
					i--;
					j--;
				}
			}
			else if(direct == 2) {
				j--;
				if(j<0 || sign[i][j] == 1) {
					direct=3;
					j++;
					i--;
				}
			}
			else {
				i--;
				if(i<0 || sign[i][j] == 1) {
					direct=0;
					i++;
					j++;
				}
			}
		}
		return result;				
	}
};

int main() {
	vector<int> input1(3,1);
	vector<int> input2(3,2);
	vector<vector<int> > input;
	vector<int> result;
	Solution solu;

	input.push_back(input1);
	input.push_back(input2);
	result = solu.spiralOrder(input);
	for(int i=0; i<result.size(); ++i) {
		cout<<result[i]<<" ";
	}
	cout<<endl;
	return 0;
}
