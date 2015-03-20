/*
 * @yang 2015/3/20
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
 */
#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
	public:
	int maxarea(int *high, int n) {
		stack<int> sci;
		int i,curHigh,width,result=0;
		for(i=0;i<n;++i) {
			while(!sci.empty() && high[sci.top()] > high[i]) {
				curHigh = high[sci.top()];
				sci.pop();
				width = sci.empty() ? i:i-1-sci.top();
				result = max(result,width*curHigh);
			}
			sci.push(i);
		}
		return result;
	}
	int maximalRectangle(vector<vector<char> > &matrix) {
		int i,j,m,n;
		int result=0,temp;
		int **high;

		m=matrix.size();
		if(m==0)
			return 0;
		n=matrix[0].size();
		if(n==0)
			return 0;
		high = new int*[m];
		for(i=0;i<m;++i) {
			high[i]=new int[n+1];
			memset(high[i],0,sizeof(int)*(n+1));
		}
		for(j=0;j<n;++j)
			if(matrix[0][j]=='1')
				high[0][j]=1;
		for(j=0;j<n;++j) {
			for(i=1;i<m;++i) {
				if(matrix[i][j]=='1')
					high[i][j]=high[i-1][j]+1;
			}
		}
		for(i=0;i<m;++i) {
			temp=maxarea(high[i],n+1);
			if(temp>result)
				result=temp;
		}
		return result;
	}
};

int main() {
	Solution solu;
	return 0;
}
