#include <iostream>
#include <cstdlib>
using namespace std;

bool isBadVersion(int version) {
    if(version >= 1702766719)
        return true;
    else
        return false;
}

class Solution {
    public:
    int firstBadVersion(int n) {
        long low,high,mid;
        low = 1;
        high = n;
        while(low <= high) {
            mid = (low+high)/2;
            if(isBadVersion(mid)) {
                if(mid>low && isBadVersion(mid-1))
                    high = mid-1;
                else
                    return mid;
            }
            else {
                low = mid+1;
            }
        }
        return -1;
    }
};

int main() {
    Solution solu;
    cout<<solu.firstBadVersion(2126753390)<<endl;
    return 0;
}
