/*
@yang 2015/3/7

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/
#include <iostream>
#include <cstdlib>
#include <climits>
#include <unistd.h>
#include <cmath>
using namespace std;



class Solution {
	public:
	class Node {
		public:
		long value;
		long times;
	};
	
	int divide(int dividend, int divisor) {
		int i,size;
		Node temp[33];
		long temp_value, temp_times=1, result, copy;
		int neg=0;

		if(divisor == 0)
			return INT_MAX;
		if(dividend < 0) {
			copy = 0-(long)dividend;
			neg++;
		}
		else
			copy = dividend;

		if(divisor < 0) {
			temp_value = 0 -(long)divisor;
			neg++;
		}
		else
			temp_value = divisor;

		if(copy < temp_value)
			return 0;

		temp[0].value = temp_value;
		temp[0].times = temp_times;
		for(i=1;i<33;i++) {
			temp_value = temp_value + temp_value;
			temp_times = temp_times + temp_times;
			temp[i].value = temp_value;
			temp[i].times = temp_times;
			if(temp[i].value > INT_MAX)
				break;
		}
		size = i;
		result = 0;
		while(size >= 0 && copy>0) {
			if(copy >= temp[size].value){
				copy = copy - temp[size].value;
				result = result + temp[size].times;
			}
			else {
				size--;
			}
		}
		if(neg == 0 || neg == 2) {
			if(result > INT_MAX){
				return INT_MAX;
			}
			else
				return result;
		}
		else {
			if(result-1 > INT_MAX)
				return INT_MAX;
			else
				return (0-result);
		}
	}
};

int main() {
	int a,b;
	Solution solu;
	int result;

	while(cin>>a>>b) {
		result = solu.divide(a,b);
		cout<<result<<endl;
	}
	return 0;
}
