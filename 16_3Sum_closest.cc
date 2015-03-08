/*
@yang 2015/3/5

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
	public:
	typedef vector<int>::iterator index;
	int twoSumDiff(index head, index tail, int target) {
		int diff;
		int value;

		diff = target - (*head+*tail);
		while(head < tail) {
			value = *head + *tail;
			if(value == target) {
				return 0;
			}
			else if(value > target) {
				if(abs(target-value) < abs(diff))
					diff = target-value;
				tail--;
			}
			else if(value < target) {
				if(abs(target-value) < abs(diff))
					diff = target -value;
				head++;
			}
		}
		return diff;
	}

	int threeSumClosest(vector<int> &num, int target) {
		vector<int> copy(num);
		int diff,temp;
		index p;

		if(num.size() < 3)
			return -1;

		sort(copy.begin(), copy.end());
		diff = target - (copy[0]+copy[1]+copy[2]);
		for(p=copy.begin(); p+3<=copy.end(); ++p) {
			if(p!=copy.begin() && *p==*(p-1))
				continue;
			temp = twoSumDiff(p+1, copy.end()-1, target-(*p));
			if(temp == 0)
				return target;
			if(abs(temp) < abs(diff))
				diff=temp;
		}
		return target-diff;
	}
};

int main() {
	Solution solu;
	vector<int> num;
	int result;

	num.push_back(-1);
	num.push_back(2);
	num.push_back(1);
	num.push_back(-4);

	result = solu.threeSumClosest(num, 1);
	cout<<result<<endl;
	return 0;
}
