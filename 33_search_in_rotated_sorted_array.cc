/*
@yang 2015/3/9

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
	public:
	int search(int A[], int n, int target) {
		int low,high,mid;

		low = 0;
		high = n-1;
		while(low <= high) {
			mid = (low+high)/2;
			if(A[mid] == target)
				return mid;
			else if(A[mid] > target) {
				if(A[low] > target) {
					if(A[low] > A[mid])
						high = mid-1;
					else
						low = mid+1;
				}
				else
					high = mid-1;
			}
			else if(A[mid] < target) {
				if(A[high] < target) {
					if(A[high] < A[mid])
						low = mid+1;
					else
						high = mid-1;
				}
				else
					low = mid+1;
			}
		}
		if(low > high)
			return -1;
	}
};

int main() {
	int A[]={4,5,6,7,0,1,2};
	Solution solu;
	int result;

	result = solu.search(A, 8, 0);
	if(result != -1)
		cout<<result<<" "<<A[result]<<endl;
	else
		cout<<"-1"<<endl;
	return 0;
}
