/*
@yang 2015/3/7

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int removeElement(int A[], int n, int elem) {
        int *first,*temp;
        int result,num;
        int i;

        if(A==NULL || n==0)
            return 0;

        sort(A,A+n);
        num = count(A,A+n,elem);
        if(num == 0)
            return n;
        result = n - num;
        first = find(A,A+n,elem);
        
        temp = first;
        while((temp+num) < (A+n)){
            *temp = *(temp+num);
            temp++;
        }
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

    result = solu.removeElement(a, 10, 3);
    for(i=0;i<result;++i) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
