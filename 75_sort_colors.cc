/*
 * @yang 2015/3/18
 *
 * Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 *
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 *
 * click to show follow up.
 *
 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
 *
 * Could you come up with an one-pass algorithm using only constant space?
 */
#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
    public:
    void sortColors(int A[], int n) {
        int left,right,cur;
        left=0;
        right=n-1;
        for(cur=0; cur<=right;) {
            if(A[cur]==0) {
                swap(A[cur],A[left]);
                left++;
                cur++;
            }
            else if(A[cur]==2) {
                swap(A[cur],A[right]);
                right--;
            }
            else
                cur++;
        }
    }
};

int main() {
    int A[]={0,1,2,0,1,2};
    Solution solu;

    solu.sortColors(A,6);
    for(int i=0; i<6; ++i)
        cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}
