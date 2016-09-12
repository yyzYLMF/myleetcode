#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestPrefixPalindrome(string s) {
		int len = s.length();
		if (len < 2)
			return len;
		int longest = 1, start, end;
		for (int begin = 0; begin <= len / 2;) {
			start = end = begin;
			while (end < len - 1 && s[end + 1] == s[end])
				++end;
			begin = end + 1;
			while (end < len - 1 && start > 0 && s[end + 1] == s[start - 1]) {
				++end;
				--start;
			}
			if (start == 0 && longest < end - start + 1)
				longest = end - start + 1;
		}
		return longest;
    }
};

int main() {
	Solution solu;
	string str;
	cin>>str;
	cout<<solu.longestPrefixPalindrome(str)<<endl;
	return 0;
}
