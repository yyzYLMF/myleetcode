/*
 * @yang 2015/4/6
 *
 * Rotate an array of n elements to the right by k steps.
 *
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 *
 * Note:
 * Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 */
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

//Use more time
class Solution1 {
    public:
    void rotate(int nums[], int n, int k) {  
        int temp;  
        for (int step = 0; step < k; step++) {  
            temp = nums[n-1];  
            for (int i = n-1; i > 0; --i)  
            {  
                nums[i] = nums[i-1];  
            }  
            nums[0] = temp;  
        }  
    }  
};

//Use more space
class Solution2 {
    public:
    void rotate(int nums[], int n, int k) { 
        k = k % n;      
        if (k == 0) return;  
        int *temp = new int[n];  
        memcpy(temp, nums+(n-k), sizeof(int)*k);  
        memcpy(temp+k, nums, sizeof(int)*(n-k));  
        memcpy(nums, temp, sizeof(int)*n);  
        delete[] temp;  
    }
};

//AC,Perfect
class Solution3 {
    public:
    void rotate(int nums[], int n, int k) {  
        int step,first,new_first,last,next;
        step = k%n;
        if(step==0 || n<=1)
            return;
        first = 0;
        new_first = n-step;
        last = n;
        next = new_first;
        while(first != next) {
            swap(*(nums+first),*(nums+next));
            first++;
            next++;
            if(next == last)
                next = new_first;
            else if(first == new_first)
                new_first = next;
        }
        return;
    }
};

int main() {
    Solution3 solu;
    int a[]={1,2};
    solu.rotate(a,2,2);
    cout<<a[0]<<a[1]<<endl;
    return 0;
}
