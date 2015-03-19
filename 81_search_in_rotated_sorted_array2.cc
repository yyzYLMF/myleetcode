/*
 * @yang 2015/3/19
 *
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 *
 * Would this affect the run-time complexity? How and why?
 *
 * Write a function to determine if a given target is in the array.
 */
#include <iostream>
#include <cstdlib>
using namespace std;

//wrong answer, cant't deal with the duplicates num.
class Solution {
	public:
	bool search(int A[], int n, int target) {
		int low,high,mid;
		low=0;
		high=n-1;
		while(low<=high) {
			mid = (low+high)/2;
			if(A[mid]==target)
				return true;
			else if(A[mid] > target) {
				if(A[low] > target) {
					if(A[mid]>A[low])
						low=mid+1;
					else if(A[mid]<A[low])
						high=mid-1;
					else
						low++;
				}
				else
					high=mid-1;
			}
			else if(A[mid] < target) {
				if(A[high] < target) {
					if(A[high]>A[mid])
						high=mid-1;
					else if(A[high]<A[mid])
						low=mid+1;
					else
						high--;
				}
				else
					low=mid+1;
			}
		}
		return false;
	}
};

int main() {
	Solution solu;
	return 0;
}
