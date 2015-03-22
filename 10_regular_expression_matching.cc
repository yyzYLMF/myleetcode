/*
@yang 2015/3/4

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

*/
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//wrong answer, can't deal with {"abbc" ".*bc"}, the basic reason is can't decide how many times the * is used.
class Solution {
    public:
    bool isMatch(const char *s, const char *p) {
        string str(s);
        string exp(p);
        int i=0,j=0;

        while(i!=str.size() && j!=exp.size()) {
            if(str[i]==exp[j] || exp[j]=='.') {
                if(j+1!=exp.size() && exp[j+1]=='*') {
                    i++;
                }
                else {
                    i++;
                    j++;
                }
            }
            else {
                if(j+1!=exp.size() && exp[j+1]=='*') {
                    j+=2;
                }
                else {
                    break;
                }
            }
        }
        if(i!=str.size()) 
            return false;
        
        if(j!=exp.size()) {
            while(j!=exp.size()) {
                if(j+1!=exp.size() && exp[j+1]=='*')
                    j+=2;
                else 
                    break;
            }
        }

        if(j!=exp.size())
            return false;
        else
            return true;
    }
};

//use recursive function can deal with the problem faced above.
class Solution2 {
    public:
    bool isMatch(const char *s, const char *p) {
        if(*p == '\0')
            return *s == '\0';

        if(*(p+1) == '*') {
            while(*s!='\0') {
                if(*s==*p || *p=='.'){
                    if(isMatch(s,p+2))
                        return true;
                    else
                        s++;
                }
                else
                    break;
            }
            return isMatch(s,p+2);
        }
        else {
            if(*s!='\0') {
                if(*s==*p || *p=='.') {
                    if(isMatch(s+1,p+1))
                        return true;
                    else
                        return false;
                }
                else
                    return false;
            }
            return false;
        }
    }
};

int main() {
    const char *s1="aa", *p1="a";
    const char *s2="ab", *p2=".*";
    const char *s3="aab", *p3="c*a*b";
    Solution2 solu;

    cout<<solu.isMatch(s1,p1)<<endl;
    cout<<solu.isMatch(s2,p2)<<endl;
    cout<<solu.isMatch(s3,p3)<<endl;

    return 0;
}
