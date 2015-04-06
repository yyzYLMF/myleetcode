/*
 * @yang 2015/4/6
 *
 * Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
 *
 * If the fractional part is repeating, enclose the repeating part in parentheses.
 *
 * For example,
 *
 * Given numerator = 1, denominator = 2, return "0.5".
 * Given numerator = 2, denominator = 1, return "2".
 * Given numerator = 2, denominator = 3, return "0.(6)".
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <set>
using namespace std;

class Solution {
    public:
    string fractionToDecimal(int numerator, int denominator) {
        set<int> si;
        string ret="",temp="";
        long remainder,quotient,denom,sign;
        int len;
        int neg=0;
        
        if(numerator < 0) {
            neg++;
            remainder = 0-(long)numerator;
        }
        else
            remainder = numerator;
        if(denominator < 0) {
            neg++;
            denom = 0-(long)denominator;
        }
        else
            denom = denominator;
            
        quotient = remainder/denom;
        remainder = remainder-quotient*denom;
        if(quotient<10)
            ret.insert(ret.end(),quotient+'0');
        else {
            while(quotient!=0) {
                ret.insert(ret.begin(),quotient%10+'0');
                quotient=quotient/10;
            }
        }
        if(remainder == 0) {
            if(ret[0] !='0' && neg==1)
                ret.insert(ret.begin(),'0');
            return ret;
        }
        else
            ret = ret+'.';
        si.insert(remainder);
        while(remainder!=0) {
            remainder*=10;
            quotient = remainder/denom;
            remainder = remainder-quotient*denom;
            ret.insert(ret.end(),quotient+'0');
            if(si.count(remainder)) {
                sign = remainder;
                remainder*=10;
                quotient = remainder/denom;
                remainder = remainder - quotient*denom;
                temp.insert(temp.end(),quotient+'0');
                while(remainder != sign) {
                    remainder*=10;
                    quotient = remainder/denom;
                    remainder = remainder - quotient*denom;
                    temp.insert(temp.end(),quotient+'0');
                }
                len = temp.size();
                ret.erase(ret.size()-len,len);
                ret=ret+'(';
                ret.insert(ret.end(),temp.begin(),temp.end());
                ret=ret+')';
                break;
            }
            else 
                si.insert(remainder);
        }
        if(neg==1)
            ret.insert(ret.begin(),'-');
        return ret;
    }
};

int main() {
    Solution solu;
    int a,b;
    while(cin>>a>>b)
        cout<<solu.fractionToDecimal(a,b)<<endl;
    return 0;
}
