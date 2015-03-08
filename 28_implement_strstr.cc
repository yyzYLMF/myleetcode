/*
@yang 2015/3/7

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

*/
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
	public:
	int strStr(char *haystack, char *needle) {
		string s1(haystack);
		string s2(needle);
		string::size_type index;

		index = s1.find(s2);
		if(index == s1.npos)
			return -1;
		else
			return index;
	}
};

int main() {
	char a[]="asdfghjkl";
	char b[]="dfghasdfasdfa";
	Solution solu;
	int index;

	index = solu.strStr(a,b);
	cout<<index<<endl;
	return 0;
}
