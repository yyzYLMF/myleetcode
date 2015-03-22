/*
@yang 2015/3/11

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
    public:
    int trap(int A[], int n) {
        int i,j;
        int max,max_index;
        int result=0;

        if(n <= 2)
            return 0;
        max = A[0];
        max_index = 0;
        for(i=1; i<n; ++i) {
            if(A[i] > max) {
                max = A[i];
                max_index = i;
            }
        }
        max = 0;
        for(i=0; i<max_index; ++i) {
            if(A[i] < max) {
                result += max-A[i];
            }
            else {
                max = A[i];
            }
        }
        max = 0;
        for(j=n-1; j>max_index; --j) {
            if(A[j] < max) {
                result += max-A[j];
            }
            else {
                max = A[j];
            }
        }
        return result;
    }
};

int main() {
    int a[]={0,1,0,2,1,0,1,3,2,1,2,1};
    Solution solu;
    int result;

    result = solu.trap(a,12);
    cout<<result<<endl;
    return 0;
}
