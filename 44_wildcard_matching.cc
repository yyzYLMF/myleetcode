/*
@yang 2015/3/11

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/
#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
	public:
	bool isMatch(const char *s, const char *p) {

		if(*s=='\0' && *p=='\0')
			return true;
		if(*p=='\0' && *s!='\0')
			return false;
		if(*s == '\0') {
			while(*p != '\0') {
				if(*p != '*')
					break;
				p++;
			}
			if(*p == '\0')
				return true;
			else
				return false;
		}

		while(*s!='\0' && *p!='\0') {
			if(*p == '*') {
				if(*(p+1) == '*') {
					p++;
					continue;
				}
				if(isMatch(s+1,p))
					return true;
				else
					return isMatch(s,p+1);
			}
			else {
				if(*s==*p || *p=='?') {
					s++;
					p++;
				}
				else
					break;
			}
		}
		if(*s=='\0' && *p=='\0')
			return true;
		else
			return false;
	}
};

class Solution2 {
	public:
	bool isMatch(const char *s, const char *p) {
		const char *star=NULL;
		const char *next=s;

		while(*s!='\0') {
			if(*s==*p || *p=='?') {
				s++;
				p++;
				continue;
			}
			if(*p=='*') {
				star=p;
				p++;
				next=s;
				continue;
			}
			if(star != NULL) {
				p=star+1;
				s=next+1;
				next++;
				continue;
			}
			return false;
		}
		while(*p!='\0') {
			if(*p!='*')
				break;
			p++;
		}
		if(*p!='\0')
			return false;
		else
			return true;
	}
};

int main() {
	char s[]="aa";
	char p[]="*";
	Solution2 solu;

	cout<<solu.isMatch(s,p)<<endl;
	return 0;
}
