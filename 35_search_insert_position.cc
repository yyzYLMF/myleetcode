/*
@yang 2015/3/9

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/
#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
    public:
    int searchInsert(int A[], int n, int target) {
        int low, high, mid;
        int i;

        if(n == 0)
            return 0;
        
        low = 0;
        high = n-1;
        
        if(n>2) {
            while(low+1 < high) {
                mid = (low+high)/2;
                if(A[mid] == target)
                    return mid;
                else if(A[mid] > target)
                    high = mid-1;
                else if(A[mid] < target)
                    low = mid+1;
            }
        }

        for(i=low; i<=high; ++i) {
            if(A[i] == target)
                return i;
            else if(A[i] > target)
                break;
        }
        return i;
    }
};

int main() {
    int A[]={1,3,5,6};
    Solution solu;
    int result;

    result = solu.searchInsert(A,4,0);
    cout<<result<<endl;
    return 0;
}
