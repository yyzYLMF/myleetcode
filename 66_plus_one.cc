/*
 * @yang 2015/3/16
 *
 * Given a non-negative number represented as an array of digits, plus one to the number.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
	public:
	vector<int> plusOne(vector<int> &digits) {
		vector<int> result(digits);
		int c=1,temp,i;
		for(i=result.size()-1; i>=0; --i) {
			temp = result[i]+c;
			if(temp == 10) {
				result[i]=0;
				c=1;
			}
			else {
				result[i] = temp;
				break;
			}
		}
		if(i<0)
			result.insert(result.begin(),1);
		return result;
	}
};

int main() {
	Solution solu;
	vector<int> input;
	vector<int> result;

	input.push_back(9);
	input.push_back(9);
	input.push_back(9);
	input.push_back(9);
	input.push_back(9);
	input.push_back(9);

	result = solu.plusOne(input);
	for(int i=0; i<result.size(); ++i) {
		cout<<result[i]<<" ";
	}
	cout<<endl;
	return 0;
}
