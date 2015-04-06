/*
 * @yang 2015/4/5
 *
 * A peak element is an element that is greater than its neighbors.
 *
 * Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 *
 * The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 *
 * You may imagine that num[-1] = num[n] = -∞.
 *
 * For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 *
 * click to show spoilers.
 *
 * Note:
 * Your solution should be in logarithmic complexity.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    int myfun(const vector<int> &num, int m, int n) {
        int low,high,mid,temp;
        if(m==n)
            return m;
        low = m;
        high = n;
        if(num[low] > num[low+1])
            return low;
        if(num[high] > num[high-1])
            return high;
        mid=(low+high)/2;
        if(num[mid]>num[mid+1] && num[mid]>num[mid-1])
            return mid;
        temp = mid-1;
        while(num[temp]<=num[temp+1] && temp>low)
            temp--;
        if(temp>low)
            return myfun(num,low,temp);
        temp = mid+1;
        while(num[temp]<=num[temp-1] && temp<high)
            temp++;
        if(temp<high)
            return myfun(num,temp,high);
    }
    int findPeakElement(const vector<int> &num) {
        if(num.size()==1)
            return num[0];
        return myfun(num,0,num.size()-1);
    }
};

int main() {
    Solution solu;
    return 0;
}
