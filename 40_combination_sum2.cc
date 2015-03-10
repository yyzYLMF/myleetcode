/*
@yang 2015/3/10

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
	void mypush(vector<vector<int> > &result, vector<int> &temp) {
		int i,j;
		for(i=0;i<result.size();++i){
			if(result[i].size() != temp.size())
				continue;
			for(j=0; j<temp.size(); ++j) {
				if(temp[j] != result[i][j])
					break;
			}
			if(j == temp.size())
				break;
		}
		if(i == result.size())
			result.push_back(temp);
		return;
	}
				
	void mycombine(vector<int> &num, vector<vector<int> > &result, vector<int> temp, int n, int target) {
		int pos=n;

		if(target == 0) {
			sort(temp.begin(),temp.end());
			mypush(result,temp);
			return;
		}

		if(n<0)
			return;
		
		while(pos>=0) {
			if(num[pos] <= target)
				break;
			pos--;
		}
		if(pos<0)
			return;
		temp.push_back(num[pos]);
		mycombine(num,result,temp,pos-1,target-num[pos]);
		temp.pop_back();
		mycombine(num,result,temp,pos-1,target);
		return;
	}

	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		vector<int> copy(num);
		vector<vector<int> > result;
		vector<int> temp;
		vector<int>::iterator index;
		int pos;

		if(num.empty())
			return result;
		
		sort(copy.begin(), copy.end());

		pos = copy.size()-1;
		while(pos >= 0) {
			if(copy[pos] <= target)
				break;
			pos--;
		}
		if(pos<0)
			return result;
		temp.push_back(copy[pos]);
		mycombine(copy,result,temp,pos-1,target-copy[pos]);
		temp.pop_back();
		mycombine(copy,result,temp,pos-1,target);

		return result;
	}
};

int main() {
	vector<int> input;
	vector<vector<int> > result;
	Solution solu;

	input.push_back(10);
	input.push_back(1);
	input.push_back(2);
	input.push_back(7);
	input.push_back(6);
	input.push_back(1);
	input.push_back(5);

	result = solu.combinationSum2(input, 8);
	for(int i=0; i<result.size(); ++i) {
		for(int j=0; j<result[i].size(); ++j) {
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
