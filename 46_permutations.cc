/*
@yang 2015/3/11

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
	public:
	void myfun(vector<vector<int> > &result, vector<int> &num, vector<int> sign, vector<int> temp, int n) {
		if(n == 0) {
			result.push_back(temp);
			return;
		}
		for(int i=0; i<num.size(); i++) {
			if(sign[i] == 0)
				continue;
			temp.push_back(num[i]);
			sign[i]=0;
			myfun(result, num, sign, temp, n-1);
			temp.pop_back();
			sign[i]=1;
		}
	}

	vector<vector<int> > permute(vector<int> &num) {
		vector<int> sign(num.size(),1);
		vector<vector<int> > result;
		vector<int> temp;

		for(int i=0; i<num.size(); ++i) {
			temp.push_back(num[i]);
			sign[i]=0;
			myfun(result, num, sign, temp, num.size()-1);
			temp.pop_back();
			sign[i]=1;
		}
		return result;
	}
};

int main() {
	Solution solu;
	vector<vector<int> > result;
	vector<int> input;

	input.push_back(1);
	input.push_back(2);
	input.push_back(3);

	result = solu.permute(input);
	for(int i=0; i<result.size(); ++i) {
		for(int j=0; j<result[i].size(); ++j) {
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
