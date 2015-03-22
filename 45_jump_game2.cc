/*
@yang 2015/3/11

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/
#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
    public:
    int jump(int A[], int n) {
        int i,j;
        int *step;
        step = new int[n];

        if(n==1)
            return 0;
        for(i=0; i<n; ++i)
            step[i]=-1;
        step[0]=0;
        for(i=0; i<n; ++i) {
            for(j=1; j<=A[i]; ++j) {
                if(step[i+j]==-1)
                    step[i+j]=step[i]+1;
                if(i+j == n-1)
                    return step[n-1];
            }
        }
    }
};

class Solution2 {
    public:
    int jump(int A[], int n) {
        int i,j,max,max_index,step;

        if(n<=1)
            return 0;
        i=0;
        step=0;
        while(i<n) {
            max = 0;
            step++;
            if(i+A[i] >= n-1)
                return step;
            for(j=1; j<=A[i]; ++j) {
                if(i+j+A[i+j] > max) {
                    max = i+j+A[i+j];
                    max_index = j;
                }
            }
            i=i+max_index;
        }
    }
};

int main() {
    int a[] = {1,1,1,1};
    Solution2 solu;
    int result;

    result = solu.jump(a,4);
    cout<<result<<endl;
    return 0;
}
