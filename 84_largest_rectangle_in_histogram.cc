/*
 * @yang 2015/3/20
 *
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
 * For example,
 * Given height = [2,1,5,6,2,3],
 * return 10.
 */
#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
using namespace std;

class Solution {
	public:
	int largestRectangleArea(vector<int> &height) {
		int len,i,width,curHight,result;
		stack<int> sci;
		len = height.size();
		if(len==0)
			return 0;
		result=0;
		for(i=0;i<len;++i) {
			while(!sci.empty() && height[sci.top()] > height[i]) {
				curHight=height[sci.top()];
				sci.pop();
				if(sci.empty())
					width=i;
				else
					width=i-1-sci.top();
				result=max(result,curHight*width);
			}
			sci.push(i);
		}
		while(!sci.empty()) {
			curHight=height[sci.top()];
			sci.pop();
			if(sci.empty())
				width=i;
			else
				width=i-1-sci.top();
			result=max(result,curHight*width);
		}
		return result;
	}
};

int main() {
	Solution solu;
	vector<int> input;

	input.push_back(2);
	input.push_back(1);
	input.push_back(5);
	input.push_back(6);
	input.push_back(2);
	input.push_back(3);
	cout<<solu.largestRectangleArea(input)<<endl;
	return 0;
}
