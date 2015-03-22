/*
@yang 2015/3/10

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    //find <= target    
    int findSmallIndex(vector<int> &candidates, int n, int target) {
        int low,high,mid;
        int i;

        if(n<0)
            return -1;

        low = 0;
        high = n;
        while(low+1 < high) {
            mid = (low+high)/2;
            if(candidates[mid] == target)
                return mid;
            else if(candidates[mid] > target)
                high = mid -1;
            else 
                low = mid + 1;
        }
        for(i=low; i<=high; ++i){
            if(candidates[i] == target)
                return i;
            else if(candidates[i] > target)
                return i-1;
        }
        return i-1;
    }
    
    void mycombine(vector<int> &candidates, vector<vector<int> > &result, vector<int> temp, int n, int target) {
        int pos;
        if(pos < 0)
            return;
        if(target == 0) {
            sort(temp.begin(), temp.end());
            result.push_back(temp);
            return;
        }
        pos = findSmallIndex(candidates, n, target);
        if(pos == -1)
            return;
        temp.push_back(candidates[pos]);
        mycombine(candidates, result, temp, pos, target-candidates[pos]);
        temp.pop_back();
        mycombine(candidates, result, temp, pos-1, target);
        return;
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        vector<int> temp;
        int pos;
        vector<int> copy(candidates);

        sort(copy.begin(), copy.end());
        pos = findSmallIndex(copy, copy.size()-1, target);
        if(pos == -1)
            return result;
        temp.push_back(copy[pos]);
        mycombine(copy, result, temp, pos, target-copy[pos]);
        temp.pop_back();
        mycombine(copy, result, temp, pos-1, target);
                
        return result;
    }
};

int main() {
    vector<int> input;
    vector<vector<int> > result;
    Solution solu;

    input.push_back(8);
    input.push_back(7);
    input.push_back(4);
    input.push_back(3);

    result = solu.combinationSum(input, 11);
    for(int i=0; i<result.size(); ++i){
        for(int j=0; j<result[i].size(); ++j){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
