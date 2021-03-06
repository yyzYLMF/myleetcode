/*
 * @yang 2015/4/4
 *
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 *
 * The array may contain duplicates.
 * duplicates are allowed
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    public:
    int findMin(vector<int> &num) {
        int low,high,mid,min=INT_MAX;
        if(num.size()==1)
            return num[0];
        low = 0;
        high = num.size()-1;
        while(low<=high) {
            mid = (low+high)/2;
            if(num[mid] < min)
                min = num[mid];
            if(num[low] < num[mid]) {
                if(num[mid] > num[high])
                    low = mid+1;
                else if(num[mid] <= num[high])
                    high = mid-1;
            }
            else if(num[low] > num[mid])
                high = mid-1;
            else
                low++;
        }
        return min;
    }
};

int main() {
    Solution solu;
    return 0;
}
