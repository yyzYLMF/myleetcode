/*
 * @yang 2015/7/10
 *
 * Implement a basic calculator to evaluate a simple expression string.
 *
 * The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
 *
 * You may assume that the given expression is always valid.
 *
 * Some examples:
 * "3+2*2" = 7
 * " 3/2 " = 1
 * " 3+5 / 2 " = 5
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <vector>
#include <ctime>
using namespace std;

//AC
class Solution {
    public:
    vector<long> convert2postfix(const string &s)
    {
        stack<char> op;
        vector<long> postfix;
        int tmp = 0,isPreNum = 0;
        for(int i = 0; i < s.length(); i++)
        {
            switch(s[i])
            {
                case ' ':
                    continue;
                case '*':
                case '/':
                    while(!op.empty() && (op.top() == '*' || op.top() == '/'))
                    {
                        postfix.push_back(op.top());
                        op.pop();
                    }
                    op.push(s[i]);
                    break;
                case '+':
                case '-':
                    while(!op.empty())
                    {
                        postfix.push_back(op.top());
                        op.pop();
                    }

                    op.push(s[i]);
                    break;
                default:
                    if(isPreNum)
                        tmp = tmp*10 + s[i] - '0';
                    else
                    {
                        tmp = s[i] - '0';
                        isPreNum = 1;
                    }

                    if(i+1 ==s.length() || (i < s.length() && (s[i+1] >'9' || s[i+1] < '0')))
                    {
                        postfix.push_back(-tmp); 
                        isPreNum = 0;
                    }
            }
        } 
        while(!op.empty())
        {
            postfix.push_back(op.top());
            op.pop();
        }

        return postfix;
    }
    int calculate(string s) {
        vector<long> postfix = convert2postfix(s);

        if(postfix.size() == 0)
            return 0;

        stack<long> st;
        long a,b;
        for(int i = 0; i < postfix.size(); i++)
        {
            switch(postfix[i])
            {
                case '+':
                    a = st.top();st.pop();
                    b = st.top();st.pop();
                    st.push(b+a);
                    break;
                case '-':
                    a = st.top();st.pop();
                    b = st.top();st.pop();
                    st.push(b-a);
                    break;
                case '*':
                    a = st.top();st.pop();
                    b = st.top();st.pop();
                    st.push(b*a);
                    break;
                case '/':
                    a = st.top();st.pop();
                    b = st.top();st.pop();
                    if(a == 0) return 0;
                    st.push(b/a);
                    break;
                default:
                    st.push(-postfix[i]);
            }
        }
        return st.top();
    }
};

//TLE
class Solution2 {
    public:
    int strToint(string s, int m, int n) {
        int ret=0;
        for(int i=m; i<n; ++i) {
            if(s[i]>='0' && s[i]<='9')
                ret = ret*10+s[i]-'0';
        }
        return ret;
    }
    int calculate(string s) {
        stack<char> sc;
        stack<int> si;
        int i,j,start,len,val1,val2;
        len = s.size();
        start = 0;
        i = 0;
        while(i<s.size()) {
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
                break;
            i++;
        }
        val1 = strToint(s,start,i);
        start = i+1;
        si.push(val1);
        while(i<s.size()) {
            switch(s[i]) {
                case '+':
                case '-':
                    sc.push(s[i]);
                    i++;
                    while(i<s.size()) {
                        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
                            break;
                        i++;
                    }
                    val1 = strToint(s,start,i);
                    si.push(val1);
                    start = i+1;
                    break;
                case '*':
                    val1 = si.top();
                    si.pop();
                    i++;
                    while(i<s.size()) {
                        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
                            break;
                        i++;
                    }
                    val2 = strToint(s,start,i);
                    start = i+1;
                    val1 = val1*val2;
                    si.push(val1);
                    break;
                case '/':
                    val1 = si.top();
                    si.pop();
                    i++;
                    while(i<s.size()) {
                        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
                            break;
                        i++;
                    }
                    val2 = strToint(s,start,i);
                    start = i+1;
                    val1 = val1/val2;
                    si.push(val1);
                    break;
                default:
                    i++;
            }
        }
        while(!sc.empty()) {
            val2 = si.top();
            si.pop();
            val1 = si.top();
            si.pop();
            if(sc.top()=='+') {
                si.push(val1+val2);
            }
            else {
                si.push(val1-val2);
            }
            sc.pop();
        }
        return si.top();
    }
};

int main() {
    Solution solu;
    Solution2 solu2;
    string s;
    getline(cin,s);
    time_t start=clock();
    solu.calculate(s);
    time_t end = clock();
    cout<<end-start<<endl;
    start = clock();
    solu2.calculate(s);
    end = clock();
    cout<<end-start<<endl;
    return 0;
}
