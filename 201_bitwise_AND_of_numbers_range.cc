/*
 * @yang 2015/4/16
 *
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
 *
 * For example, given the range [5, 7], you should return 4.
 */
#include <iostream>
#include <cstdlib>
#include <bitset>
#include <cmath>
using namespace std;

class Solution {
    public:
    int rangeBitwiseAnd(int m, int n) {
        int len,i;
        bitset<31> ret(m);
        int max_bit=0,temp; 
        if(m==0)
            return 0;
        if(m==n)
            return m;
        
        for(i=0;i<31;++i) {
            temp = 1<<i;
            if(((m&temp)==0) && ((n&temp)!=0))
                max_bit = i;
        }
        for(i=0;i<=max_bit;++i)
            ret.reset(i);

        return ret.to_ulong();
    }
};

int main() {
    Solution solu;
    int m,n;
    while(cin>>m>>n) {
        cout<<solu.rangeBitwiseAnd(m,n)<<endl;
    }
    return 0;
}
