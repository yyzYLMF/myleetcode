/*
@yang 2015/3/9

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;

class Solution {
	public:
	typedef string::iterator index;
	int mylength(index head, index end) {
		index p=head, q=end;
		stack<char> sc_temp;
		int length=0;

		while(q >= p) {
			if(*q==')') {
				sc_temp.push(*q);
				length++;
			}
			else {
				if(!sc_temp.empty()) {
					sc_temp.pop();
					length++;
				}
				else
					break;
			}
			q--;
		}
		return length;
	}

	int longestValidParentheses(string s) {
		index i,j;
		int result = 0, temp;
		stack<char> sc;
		
		if(s.empty())
			return 0;

		for(i=s.begin(),j=s.begin(); i!=s.end(); ++i) {
			if(*i == '(') {
				sc.push(*i);
			}
			else if(*i == ')') {
				if(!sc.empty()) {
					temp = mylength(j, i);
					if(temp > result)
						result = temp;
					sc.pop();
				}
				else {
					while(!sc.empty())
						sc.pop();
					j = i+1;
				}
			}
		}
		return result;
	}
};

//greed algorithm
class Solution2 {
	public:
	stack<char> st;
	stack<int> pos;
	int ret = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			st.push(s[i]);
			pos.push(i);
		} else {
			if (!st.empty() && st.top() == '(') {
				st.pop();
				pos.pop();
				ret = max(ret, (st.empty() ? i + 1 : i - pos.top()));
			} else {
				st.push(s[i]);
				pos.push(i);
			}
		}
	}
	return ret;
};

int main() {
	string s;
	int result;
	Solution solu;

	while(cin>>s) {
		result = solu.longestValidParentheses(s);
		cout<<result<<endl;
	}

	return 0;
}
