/*
 * @yang 2015/3/17
 *
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x.
 */
#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
    public:
    int sqrt(int x) {
        int low,high,mid;
        unsigned long copy(x),temp,i;

        if(x==0)
            return 0;
        else if(x==1)
            return 1;
        low=1;
        if(x>65536)
            high=65537;
        else
            high=x;
        while(low+1<high) {
            mid=(low+high)/2;
            temp=mid*mid;
            if(temp == copy)
                return mid;
            else if(temp > copy)
                high = mid-1;
            else
                low = mid+1;
        }
        for(i=low;i<=high;++i) {
            temp = i*i;
            if(temp > copy)
                break;
        }
        return i-1;
    }
};

int main() {
    Solution solu;
    int x;

    while(cin>>x) {
        cout<<solu.sqrt(x)<<endl;
    }
    return 0;
}
