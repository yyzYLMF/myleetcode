/*
 * @yang 2015/7/26
 *
 * Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
 *
 * For example:
 * Given n = 13,
 * Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 */
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
    public:
    int myCom(int n, int m) {
        int i,temp1,temp2;
        if(n == m) 
            return 1;
        if(m == 0)
            return 1;
        temp2 = 1;
        for(i=m;i>=1;--i)
            temp2 = temp2*i;
        temp1 = 1;
        for(i=1;i<=m;++i)
            temp1 = temp1*(n-i+1);
        return temp1/temp2;
    }
    int myCount(int &n) {
        int i,temp,count,high,ret=0;
        if(n < 10) {
            temp = n==0 ? 0:1;
            n = 0;
            return temp;
        }
        temp = n;
        count = 0;
        while(temp>0) {
            count++;
            high =temp%10;
            temp = temp/10;
        }
        if(high == 1) {
            temp = n - pow(10,count-1);
            ret = ret + temp + 1;
        }
        else 
            ret = ret + pow(10,count-1);
        for(i=1;i<=count-1;++i) {
            ret = ret + high*i*myCom(count-1,i)*pow(9,count-1-i);
        }
        n = n - pow(10,count-1)*high;
        return ret;
    }
    int countDigitOne(int n) {
        int ret=0;
        if(n<=0)
            return 0;
        while(n>0) {
            ret += myCount(n);
        }
        return ret;
    }
};

int main() {
    Solution solu;
    int n;
    cin>>n;
    cout<<solu.countDigitOne(n)<<endl;
    return 0;
}
