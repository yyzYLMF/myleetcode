/*
 * @yang 2015/3/19
 *
 * Given a set of distinct integers, S, return all possible subsets.
 *
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If S = [1,2,3], a solution is:
 [
 [3],
 [1],
 [2],
 [1,2,3],
 [1,3],
 [2,3],
 [1,2],
 []
 ]
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
	void myfun(vector<vector<int> > &result, vector<int> temp, vector<int> copy, int head, int remain) {
		int i;
		int len=copy.size();
		if(remain == 0) {
			result.push_back(temp);
			return;
		}
		if(head+remain-1 == len-1) {
			for(i=head; i<len; ++i)
				temp.push_back(copy[i]);
			result.push_back(temp);
			return;
		}
		for(i=head; i<len-remain+1; ++i) {
			temp.push_back(copy[i]);
			myfun(result,temp,copy,i+1,remain-1);
			temp.pop_back();
		}
		return;
	}
	vector<vector<int> > subsets(vector<int> &S) {
		vector<vector<int> > result;
		vector<int> temp;
		vector<int> copy(S);
		int len;
		result.push_back(temp);
		if(S.empty())
			return result;
		sort(copy.begin(), copy.end());
		len = copy.size();
		for(int i=1; i<=len; ++i) {
			for(int j=0; j<len-i+1; ++j) {
				temp.push_back(copy[j]);
				myfun(result,temp,copy,j+1,i-1);
				temp.pop_back();
			}
		}
		return result;
	}
};

int main() {
	vector<int> input;
	vector<vector<int> > result;
	Solution solu;

	input.push_back(1);
	input.push_back(2);
	input.push_back(3);
	
	result = solu.subsets(input);
	for(int i=0; i<result.size(); ++i) {
		for(int j=0; j<result[i].size(); ++j) {
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
