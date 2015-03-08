/*
@yang 2015/3/4

mplement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <climits>
using namespace std;

class Solution {
	public:
	int atoi(string str) {
		int i, neg=0, temp;
		long long result=0;
		int whitespace = 1;

		for(i=0; i<str.size(); ++i) {
			if(whitespace == 1 && str[i] == ' ')
				continue;
			else if(whitespace == 1 && str[i] != ' ') {
				whitespace = 0;
				if(str[i] == '-') {
					neg = 1;
					continue;
				}
				else if(str[i] == '+') {
					neg = 0;
					continue;
				}
			}

			if(str[i] < '0' || str[i] > '9')
				break;
			else {
				temp = str[i] - '0';
				result = result*10+temp;
				//This is the point
				if(result > INT_MAX) {
					result = INT_MAX;
					result++;
					break;
				}
			}
		}
		
		if(neg == 1) 
			result = 0 - result;

		if(result > INT_MAX)
			return INT_MAX;
		else if(result < INT_MIN)
			return INT_MIN;

		return (int)result;
	}
};

int main() {
	Solution solu;
	string s1("   123456789");
	string s2("   -12a3");
	string s3("123asdfas123");
	string s4("9223372036854775809");
	int result;

	result = solu.atoi(s1);
	cout<<result<<endl;
	result = solu.atoi(s2);
	cout<<result<<endl;
	result = solu.atoi(s3);
	cout<<result<<endl;
	result = solu.atoi(s4);
	cout<<result<<endl;

	return 0;
}
