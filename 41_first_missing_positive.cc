/*
@yang 2015/3/10

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/
#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
	public:
	int firstMissingPositive(int A[], int n) {
		int i=0,temp;

		while(i<n) {
			if(A[i] < 0 || A[i] >= n){
				i++;
				continue;
			}
			if(A[A[i]-1] == A[i]) {
				i++;
				continue;
			}
			else {
				temp = A[A[i]-1];
				A[A[i]-1] = A[i];
				A[i] = temp;
			}
		}
		for(i=0; i<n; ++i) {
			if(A[i] != i+1)
				break;
		}
		return i+1;
	}
};

int main() {
	int a[]={3,4,-1,1};
	Solution solu;
	int result;

	result = solu.firstMissingPositive(a,4);
	cout<<result<<endl;
	return 0;
}
