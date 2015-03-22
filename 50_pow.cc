/*
@yang 2015/3/12

Implement pow(x, n).
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
    public:
    double pow(double x, int n) {
        int length,i;
        double *value;
        int *sign;
        double result=1.0,tempx=x;
        long tempn;
        
        if(n==0 || x==1.0)
            return 1.0;
        if(n<0) {
            tempx=1/x;
            tempn = 0-(long)(n);
        }
        else {
            tempn = n;
        }
        length = (int)(log(tempn)/log(2))+1;
        value = new double[length];
        sign = new int[length];
        i=0;
        while(tempn!=0 && i<length) {
            value[i] = tempx;
            sign[i] = tempn%2;
            tempn=tempn/2;
            tempx = tempx*tempx;
            i++;
        }
        for(i=0; i<length; ++i) {
            if(sign[i] == 1)
                result = result*value[i];
        }
        return result;
    }
};

int main() {
    double x;
    int n;
    Solution solu;
    while(cin>>x>>n) {
        cout<<solu.pow(x,n)<<endl;
    }
    return 0;
}
