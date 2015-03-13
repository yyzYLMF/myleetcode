/*
@yang 2015/3/13

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
	public:
	int myfun(vector<int> temp, int* column, int n, int rows) {
		int i,j,k,result=0;

		if(rows == n+1)
			return 1;
		for(i=0; i<n; ++i) {
			if(column[i] == 1)
				continue;
			j=rows-1-1;
			k=i-1;
			while(j>=0 && k>=0) {
				if(temp[j] == k)
					break;
				j--;
				k--;
			}
			if(j>=0 && k>=0)
				continue;
			j=rows-1-1;
			k=i+1;
			while(j>=0 && k<n) {
				if(temp[j] == k)
					break;
				j--;
				k++;
			}
			if(j>=0 && k<n)
				continue;
			temp.push_back(i);
			column[i]=1;
			result += myfun(temp, column, n, rows+1);
			temp.pop_back();
			column[i]=0;
		}
		return result;
	}

	int totalNQueens(int n) {
		int result=0;
		vector<int> temp;
		int *column, *num;
		
		if(n==1)
			return 1;
		if(n==2)
			return 0;
		column=new int[n];
		num=new int[n];
		for(int i=0; i<n; ++i) {
			column[i] = 0;
		}
		for(int i=0; i<n; ++i) {
			if(i>n/2) {
				num[i] = num[n-1-i];
				result += num[i];
				continue;
			}
			temp.push_back(i);
			column[i]=1;
			num[i]=myfun(temp, column, n, 2);
			result += num[i];
			temp.pop_back();
			column[i]=0;
		}
		return result;
	}
};

int main() {
	Solution solu;
	int result,n;
	while(cin>>n) {
		result = solu.totalNQueens(n);
		cout<<result<<endl;
	}
	return 0;
}
