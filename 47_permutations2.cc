/*
@yang 2015/3/12

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
	void myfun(vector<vector<int> > &result, vector<int> &num, vector<int> temp, vector<int> sign, int n) {
		if(n==0){
			result.push_back(temp);
			return;
		}
		for(int i=0; i<num.size(); ++i) {
			if(i!=0 && num[i] == num[i-1] && sign[i-1] != 0)
				continue;
			if(sign[i] == 0)
				continue;
			temp.push_back(num[i]);
			sign[i]=0;
			myfun(result,num,temp,sign,n-1);
			temp.pop_back();
			sign[i]=1;
		}
		return;
	}

	vector<vector<int> > permuteUnique(vector<int> &num) {
		vector<vector<int> > result;
		vector<int> sign(num.size(),1);
		vector<int> temp;
		vector<int> copy(num);

		if(num.size() == 0)
			return result;
		else if(num.size() == 1) {
			result.push_back(num);
			return result;
		}
		sort(copy.begin(), copy.end());
		for(int i=0; i<copy.size(); ++i) {
			if(i!=0 && copy[i-1] == copy[i])
				continue;
			temp.push_back(copy[i]);
			sign[i]=0;
			myfun(result, copy, temp, sign, copy.size()-1);
			temp.pop_back();
			sign[i]=1;
		}

	}
};

int main() {
	vector<int> input;
	vector<vector<int> > result;
	Solution solu;

	input.push_back(3);
	input.push_back(3);
	input.push_back(3);
	input.push_back(2);
	result = solu.permuteUnique(input);
	for(int i=0; i<result.size(); ++i) {
		for(int j=0; j<result[i].size(); ++j) {
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
