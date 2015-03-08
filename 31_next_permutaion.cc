/*
@yang 2015/3/8

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
	void nextPermutation(vector<int> &num) {
		vector<int>::size_type i,pos;
		int small_value;
		int temp_value;
	
		if(num.size() <= 1)
			return;

		for(i=num.size()-1; i>0; --i) {
			if(num[i] > num[i-1])
				break;
		}
		if(i==0) {
			sort(num.begin(), num.end());
			return;
		}
		else {
			small_value = num[i-1];
			pos = i;
			while(pos < num.size()){
				if(num[pos] <= small_value)
					break;
				pos++;
			}
			temp_value = num[i-1];
			num[i-1] = num[pos-1];
			num[pos-1] = temp_value;
			sort(num.begin()+i,num.end());
			return;
		}
	}
};

int main() {
	vector<int> input;
	Solution solu;

	input.push_back(1);
	input.push_back(1);
	input.push_back(1);

	solu.nextPermutation(input);
	for(int i=0; i<input.size(); ++i) {
		cout<<input[i]<<" ";
	}
	cout<<endl;

	return 0;
}
