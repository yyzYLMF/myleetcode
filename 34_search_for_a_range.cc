/*
@yang 2015/3/9

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> searchRange(int A[], int n, int target) {
        int low, high, mid;
        vector<int> result;

        low = 0;
        high = n-1;
        while(low<=high) {
            mid = (low+high)/2;
            if(A[mid] == target) {
                if(A[low] == target && A[high] == target)
                    break;
                if(A[low] != target)
                    low++;
                if(A[high] != target)
                    high--;
            }
            else if(A[mid] > target) {
                high = mid-1;
            }
            else if(A[mid] < target) {
                low = mid+1;
            }
        }
        if(low<=high) {
            result.push_back(low);
            result.push_back(high);
        }
        else {
            result.push_back(-1);
            result.push_back(-1);
        }
        return result;
    }
};

int main() {
    int A[]={5,7,7,8,8,10};
    Solution solu;
    vector<int> result;

    result = solu.searchRange(A,6,9);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}
