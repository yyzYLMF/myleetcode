/*
@yang 2015/3/6

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/
#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

class Solution {
    public:
    bool isValid(string s) {
        stack<char> sc;
        stack<char>::size_type i;

        if(s.empty())
            return true;
        for(i=0; i<s.size(); ++i) {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                sc.push(s[i]);
            else if(!sc.empty()) {
                if(s[i] == ')') {
                    if(sc.top() == '(')
                        sc.pop();
                    else
                        break;
                }
                else if(s[i] == ']') {
                    if(sc.top() == '[')
                        sc.pop();
                    else
                        break;
                }
                else if(s[i] == '}') {
                    if(sc.top() == '{')
                        sc.pop();
                    else
                        break;
                }
                else {
                    break;
                }
            }
            else {
                break;
            }
        }
        if(i==s.size()) {
            if(sc.empty())
                return true;
            else
                return false;
        }
        else
            return false;
    }
};

int main() {
    Solution solu;
    string s;
    bool result;

    while(cin>>s) {
        result = solu.isValid(s);
        cout<<result<<endl;
    }
    return 0;
}
