/*
 * @yang 2015/3/21
 *
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 *
 * Note:
 * You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
 */
#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
    public:
    void merge(int A[], int m, int B[], int n) {
        int count,i,j;

        count=m+n-1;
        i=m-1;
        j=n-1;
        while(i>=0 && j>=0) {
            if(A[i]>=B[j]) {
                A[count]=A[i];
                i--;
            }
            else {
                A[count]=B[j];
                j--;
            }
            count--;
        }
        if(i<0) {
            while(j>=0) {
                A[count] = B[j];
                j--;
                count--;
            }
        }
        else if(j<0){
            while(i>=0) {
                A[count] = A[i];
                i--;
                count--;
            }
        }
    }
};

int main() {
    Solution solu;
    int A[]={1,3,5,7,9,0,0,0,0,0};
    int B[]={2,4,6,8,9};
    solu.merge(A,5,B,5);
    for(int i=0; i<10; ++i)
        cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}
