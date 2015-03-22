/*
@yang 2015/3/7

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int removeDuplicates(int A[], int n) {
        int *end_unique, *begin=A;
        int result;
        
        if(A==NULL)
            return 0;
        else if(n==0 || n==1)
            return n;

        end_unique = unique(A,A+n);
        for(result = 0; result<n,begin!=end_unique; ++result)
            begin++;
        return result;
    }
};

int main() {
    int a[10];
    int result,i;
    Solution solu;

    for(i=0;i<10;++i) {
        a[i] = i/2;
    }

    result = solu.removeDuplicates(a,10);

    for(i=0;i<result;++i)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
