/*
 * @yang 2015/7/27
 *
 * Given an integer, write a function to determine if it is a power of two.
 */

#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
    public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        while(n) {
            if((n&0x1) == 0) {
                n = n>>1;
            }
            else {
                n = n>>1;
                if(n == 0)
                    return true;
                else 
                    return false;
            }
        }
        return false;
    }
};

int main() {
    Solution solu;
    int n;
    if(2 &0x1 != 0)
        cout<<"OK"<<endl;
    cin>>n;
    cout<<solu.isPowerOfTwo(n)<<endl;
    return 0;
}
