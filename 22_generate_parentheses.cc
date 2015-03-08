/*
@yang 2015/3/6

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
	public:
	void combination(vector<string> &result, stack<char> sc, string temp, char c, int n){
		
		if(c == '(') {
			sc.push(c);
			temp.insert(temp.end(),c);
		}
		else {
			if(!sc.empty()) {
				sc.pop();
				temp.insert(temp.end(),c);
			}
			else
				return;
		}

		if(n==0) {
			while(!sc.empty()) {
				temp.insert(temp.end(),')');
				sc.pop();
			}
			result.push_back(temp);
			return;
		}

		combination(result, sc, temp, '(', n-1);
		combination(result, sc, temp, ')', n);
		return;
	}

	vector<string> generateParenthesis(int n) {
		vector<string> result;
		string temp;
		stack<char> sc;

		if(n<1)
			return result;
		if(n==1) {
			result.push_back("()");
			return result;
		}

		sc.push('(');
		temp.insert(temp.end(),'(');
		
		combination(result, sc, temp, '(', n-2);
		combination(result, sc, temp, ')', n-1);
		return result;
	}
};

int main() {
	vector<string> result;
	Solution solu;
	int n;

	while(cin>>n) {
		result = solu.generateParenthesis(n);
		for(int i=0; i<result.size(); ++i) {
			cout<<result[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
