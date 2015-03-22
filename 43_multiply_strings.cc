/*
@yang 2015/3/11

Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
    public:
    string myadd(string num1, string num2) {
        int i,j,carry;
        string result(num1);
        int a,b;
        
        if(num1.size() < num2.size())
            return myadd(num2, num1);
        i=num1.size()-1;
        j=num2.size()-1;
        carry=0;
        while(j>=0) {
            a=num1[i]-'0';
            b=num2[j]-'0';
            result[i] = (a+b+carry)%10+'0';
            carry = (a+b+carry)/10;
            i--;
            j--;
        }
        while(i>=0 && carry!=0) {
            a=num1[i]-'0';
            result[i] = (a+carry)%10+'0';
            carry = (a+carry)/10;
            i--;
        }
        if(carry > 0)
            result.insert(result.begin(), carry+'0');
        return result;
    }

    string multiply(string num1, string num2) {
        int i,j,carry;
        int a,b;
        string result("0"),temp;
        
        if(num1.empty() || num2.empty())
            return result;
        if(num1=="0" || num2=="0")
            return "0";
        for(i=0; i<num2.size(); ++i) {
            if(i!=0)
                result.insert(result.end(),'0');
            temp = num1;
            carry = 0;
            b = num2[i]-'0';
            for(j=temp.size()-1; j>=0; --j) {
                a = temp[j] - '0';
                temp[j] = (a*b+carry)%10+'0';
                carry = (a*b+carry)/10;
            }
            if(carry > 0)
                temp.insert(temp.begin(), carry+'0');
            result = myadd(result, temp);
        }
        return result;
    }
};

int main() {
    string s1,s2;
    string result;
    Solution solu;
    
    while(cin>>s1>>s2) {
        result = solu.multiply(s1,s2);
        cout<<result<<endl;
    }
    return 0;
}
