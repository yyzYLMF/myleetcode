/*
@yang 2015/3/3

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    public:
    int reverse(int x) {
        int copy, temp, neg=0;
        vector<int> ivec;
        long result=0;

        if(x < 0) {
            copy = 0 - x;
            neg = 1;
        }
        else
            copy = x;

        while(copy!=0) {
            temp = copy%10;
            ivec.push_back(temp);
            copy = copy/10;
        }
        
        for(int i=0; i<ivec.size(); ++i) {
            result=result*10+ivec[i];
        }
        if(neg == 1)
            result = 0-result;
        if(result > INT_MAX || result < INT_MIN)
            return 0;
        else
            return result;
    }
};

int main() {
    Solution solu;
    int result;

    result = solu.reverse(1000000003);
    cout<<result<<endl;
    result = solu.reverse(-123);
    cout<<result<<endl;
    
    return 0;
}
