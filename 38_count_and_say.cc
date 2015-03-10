/*
@yang 2015/3/10

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Solution {
	public:
	string mycountAndSay(string s) {
		char last='\0';
		int count=0;
		string result="";
		vector<char> temp_count;

		for(int i=0; i<s.size(); ++i) {
			if(last == '\0'){
				last = s[i];
				count = 1;
			}
			else {
				if(last == s[i])
					count++;
				else {
					while(count!=0){
						temp_count.push_back(char('0'+count%10));
						count=count/10;
					}
					for(int j=temp_count.size()-1; j>=0; --j)
						result.insert(result.end(), temp_count[j]);
					temp_count.clear();
					result.insert(result.end(),last);
					last = s[i];
					count = 1;
				}
			}
		}
		while(count!=0){
			temp_count.push_back(char('0'+count%10));
			count=count/10;
		}
		for(int j=temp_count.size()-1; j>=0; --j)
			result.insert(result.end(), temp_count[j]);
		result.insert(result.end(), last);
		return result;
	}
	string countAndSay(int n) {
		string result("1");
		if(n < 1)
			return "";
		if(n == 1)
			return "1";
		for(int i=1; i<n; ++i){
			result = mycountAndSay(result);
		}
		return result;
	}
};
int main() {
	int n;
	Solution solu;
	string result;

	while(cin>>n) {
		result = solu.countAndSay(n);
		cout<<result<<endl;
	}
	return 0;
}
