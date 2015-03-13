/*
@yang 2015/3/13

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/
#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

class Solution {
	public:
	int maxSubArray(int A[], int n) {
		int result = INT_MIN;
		int temp=0;
		int i=0;

		if(n==0)
			return 0;
		else if(n==1)
			return A[0];
		while(i<n) {
			temp += A[i];
			if(temp > result)
				result = temp;
			if(temp<0)
				temp=0;
			i++;
		}
		return result;
	}
};

//more practice, using divide and conquer.
class Solution2 {
	public:
	int maxSubArray(int A[], int n) {
		//Divide is ok, but conquer will need many steps. I dont't think this method(NlogN) is better.
	}
};

int main() {
	int a[]={-2,1,-3,4,-1,2,1,-5,4};
	int result;
	Solution solu;

	result = solu.maxSubArray(a,9);
	cout<<result<<endl;
	return 0;
}
