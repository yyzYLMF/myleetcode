/*
@yang 2015/3/4

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

*/
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

//Time Limit Exceeded
class Solution {
    public:
    int maxArea(vector<int> &height) {
        int result=0;
        int i,j,k;
        int temp;

        for(i=0; i<height.size(); ++i) {
            if(height[i]==0)
                continue;
            j=0;
            k=height.size()-1;
            while(j<i) {
                if(height[j] >= height[i]) {
                    temp = height[i]*(i-j);
                    if(temp > result)
                        result = temp;
                    break;
                }
                else
                    j++;
            }
            while(k>i) {
                if(height[k] >= height[i]) {
                    temp = height[i]*(k-i);
                    if(temp > result)
                        result = temp;
                    break;
                }
                else
                    k--;
            }
        }
        return result;
    }
};

class Solution2 {
    public:
    int maxArea(vector<int> &height) {
        int result = 0;
        int i,j;
        int temp;

        i=0;
        j=height.size()-1;
        while(i<j) {
            if(height[i] <= height[j]) {
                temp = height[i]*(j-i);
                if(temp > result)
                    result = temp;
                i++;
            }
            else {
                temp = height[j]*(j-i);
                if(temp > result)
                    result = temp;
                j--;
            }
        }
        return result;
    }
};


int main() {
    Solution2 solu;
    vector<int> ivec;
    int result;

    ivec.push_back(1);
    ivec.push_back(2);
    ivec.push_back(3);
    ivec.push_back(4);
    result = solu.maxArea(ivec);
    cout<<"result: "<<result<<endl;
    
    return 0;
}
