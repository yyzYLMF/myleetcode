/*
 * @yang 2015/4/2
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *
 * Some examples:
 * ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
    public:
    int calculate(int a, int b, string s) {
        int result;
        if(s=="+")        
            result = a+b;
        else if(s=="-")        
            result = a-b;
        else if(s=="*")        
            result = a*b;
        else if(s=="/")        
            result = a/b;
        return result;
    }

    int toNum(string s) {
        int num=0,i;
        bool sign=true;
        for(i=0;i<s.size();++i) {
            if(s[i]=='-' && i==0) {
                sign=false;
                continue;
            }
            num = num*10+(s[i]-'0');
        }
        if(sign)
            return num;
        else
            return -num;
    }

    int evalRPN(vector<string> &tokens) {
        stack<int> si;
        int tempa,tempb,i,result;
        int len=tokens.size();
        if(len==1)
            return toNum(tokens[0]);
        for(i=0;i<len;++i) {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/") {
                tempa = si.top();
                si.pop();
                tempb = si.top();
                si.pop();
                result = calculate(tempb,tempa,tokens[i]);
                si.push(result);
            }
            else {
                result = toNum(tokens[i]);
                si.push(result);
            }
        }
        return si.top();
    }
};

int main() {
    Solution solu;
    return 0;
}
