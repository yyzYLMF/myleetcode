/*
@yang 2015/3/3

There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
if the m+n is even, do this:
return (double) ( ( (double) result[(n/2)-1] +(double) result[n/2]) /2.00 );

*/
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

#define M 5
#define N 7

class Solution {
	public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		vector<int> ivec;
		int i=0,j=0;
		while(i<m && j<n) {
			if(A[i] <= B[j]) {
				ivec.push_back(A[i]);
				i++;
			}
			else if(A[i] > B[j]) {
				ivec.push_back(B[j]);
				j++;
			}
		}
		if(i == m) {
			while(j<n) {
				ivec.push_back(B[j]);
				j++;
			}
		}
		else if(j == n) {
			while(i<m) {
				ivec.push_back(A[i]);
				i++;
			}
		}
		if(ivec.size()%2 == 1) {
			return (double)(ivec[ivec.size()/2]);
		}
		else {
			return (double)(((double)(ivec[ivec.size()/2-1]+ivec[ivec.size()/2]))/2.0);
		}
	}
};

int main() {
	int *a, *b;
	Solution solu;
	double result;

	a = new int[M];
	b = new int[N];

	for(int i=0; i<M; ++i)
		a[i]=i;
	for(int i=0; i<N; ++i)
		b[i]=i;
	result = solu.findMedianSortedArrays(a,M,b,N);
	cout<<"result: "<<result<<endl;

	return 0;
}
