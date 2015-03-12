/*
@yang 2015/3/12

Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/
#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
	vector<string> anagrams(vector<string> &strs) {
		map<string, vector<string> > store;
		int i;
		string temp;
		vector<string> result;

		for(i=0; i<strs.size(); ++i) {
			temp = strs[i];
			sort(temp.begin(), temp.end());
			store[temp].push_back(strs[i]);
		}
		map<string, vector<string> >::iterator index=store.begin();
		while(index!=store.end()) {
			if((index->second).size() > 1)
				result.insert(result.end(), (index->second).begin(), (index->second).end());
			index++;
		}
		return result;
	}
};

int main() {
	vector<string> input;
	vector<string> result;
	Solution solu;

	input.push_back("tea");
	input.push_back("ate");
	input.push_back("and");
	input.push_back("eat");
	input.push_back("den");

	result = solu.anagrams(input);
	for(int i=0; i<result.size(); ++i) {
		cout<<result[i]<<endl;
	}
	return 0;
}
