/*
 * @yang 2015/7/13
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 *
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 *
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    int quick_sort(vector<int>& nums, int m, int n) {
        int i,j,key=nums[n];
        j = m-1;
        for(i=m;i<n;++i) {
            if(nums[i] > key) {
                j++;
                swap(nums[i],nums[j]);
            }
        }
        j++;
        swap(nums[j],nums[n]);
        return j+1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int i,j,len,temp,start,end;
        len = nums.size();
        if(len == 1)
            return nums[0];
        start = 0;
        end = len-1;
        while(k>0) {
            temp = quick_sort(nums,start,end);
            if(temp == k)
                return nums[temp-1];
            else if(temp > k) {
                end = temp-1-1;
            }
            else if(temp < k) {
                start = temp;
            }
        }
    }
};

int main() {
    Solution solu;
    vector<int> input;
    input.push_back(3);
    input.push_back(2);
    input.push_back(1);
    input.push_back(5);
    input.push_back(6);
    input.push_back(4);
    cout<<solu.findKthLargest(input,2)<<endl;
    return 0;
}
