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

//Although is AC, but this is not a right answer
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

//This is the right answer;
class Solution2 {
	public:
	double findKth(int a[], int m, int b[], int n, int k)
	{
		//always assume that m is equal or smaller than n
		if (m > n)
			return findKth(b, n, a, m, k);
		if (m == 0)
			return b[k - 1];
		if (k == 1)
			return min(a[0], b[0]);
		//divide k into two parts
		int pa = min(k / 2, m), pb = k - pa;
		if (a[pa - 1] < b[pb - 1])
			return findKth(a + pa, m - pa, b, n, k - pa);
		else if (a[pa - 1] > b[pb - 1])
			return findKth(a, m, b + pb, n - pb, k - pb);
		else
			return a[pa - 1];
	}

	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
		int total = m + n;
		if (total & 0x1)
			return findKth(A, m, B, n, total / 2 + 1);
		else
			return (findKth(A, m, B, n, total / 2)
					+ findKth(A, m, B, n, total / 2 + 1)) / 2;
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
