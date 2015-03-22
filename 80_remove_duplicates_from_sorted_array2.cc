/*
 * @yang 2015/3/19
 *
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example,
 * Given sorted array A = [1,1,1,2,2,3],
 *
 * Your function should return length = 5, and A is now [1,1,2,2,3].
 */
#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
    public:
    int removeDuplicates(int A[], int n) {
        int i,pos,count;
        
        if(n<=2)
            return n;
        pos=0;
        count=1;
        for(i=1;i<n;++i) {
            if(A[i] != A[pos]) {
                pos++;
                swap(A[pos],A[i]);
                count=1;
            }
            else if(count < 2) {
                count++;
                pos++;
                swap(A[pos],A[i]);
            }
            else
                count++;
        }
        return pos+1;
    }
};

int main() {
    int a[]={1,1,1,2,2,3};
    int len;
    Solution solu;

    len=solu.removeDuplicates(a,6);
    for(int i=0; i<len; ++i) {
        cout<<a[i]<<" ";
    }
    cout<<endl<<len<<endl;
    return 0;
}

