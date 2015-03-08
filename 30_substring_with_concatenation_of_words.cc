/*
@yang 2015/3/7

You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
	public:
	vector<int> findSubstring(string S, vector<string> &L) {
		vector<string> copyl(L);
		int length,num,gap;
		string::iterator i;
		vector<string> templ;
		int pos,j;
		vector<int> result;

		if(S.empty())
			return result;
		else if(L.size() == 0)
			return result;

		sort(copyl.begin(),copyl.end());
		num = copyl.size();
		length = copyl[0].size();
		gap = num*length;
		for(i=S.begin(),pos=0; i+gap <= S.end();) {
			
			templ.clear();
			for(j=0; j<num;++j){
				templ.push_back(string(i+j*length,i+(j+1)*length));
			}
			sort(templ.begin(), templ.end());
			for(j=0; j<num; ++j) {
				if(templ[j] != copyl[j])
					break;
			}
			if(j!=num){
				i++;
				pos++;
			}
			else {
				result.push_back(pos);
				i = i+length;
				pos = pos+length;
			}
		}
		return result;
	}
};

int main() {
	string s("barfoothefoobarman");
	vector<string> input;
	vector<int> result;
	Solution solu;

	input.push_back("foo");
	input.push_back("bar");

	result = solu.findSubstring(s, input);
	for(int i=0; i<result.size(); ++i) {
		cout<<result[i]<<" ";
	}
	cout<<endl;
	return 0;
}
