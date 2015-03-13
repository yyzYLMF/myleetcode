/*
@yang 2015/3/13

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/
#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
	public:
	bool canJump(int A[], int n) {
		int i=0,j,max,max_index;
		if(n<=1)
			return true;
		while(i<n) {
			if(i+A[i] >= n-1)
				return true;
			if(A[i] == 0)
				return false;
			max=0;
			for(j=1; j<=A[i]; ++j) {
				if(i+j+A[i+j] > max) {
					max = i+j+A[i+j];
					max_index = j;
				}
			}
			i=i+max_index;
		}
	}
};

int main() {
	int a[]={3,2,1,0,4};
	Solution solu;

	cout<<solu.canJump(a,5)<<endl;
	return 0;
}
