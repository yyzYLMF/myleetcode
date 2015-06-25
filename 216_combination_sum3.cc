/*
 * @yang 2015/6/25
 *
 * Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 * Ensure that numbers within the set are sorted in ascending order.
 *
 * Example 1:
 * Input: k = 3, n = 7
 * Output:
 * [[1,2,4]]
 *
 * Example 2:
 * Input: k = 3, n = 9
 * Output:
 * [[1,2,6], [1,3,5], [2,3,4]]
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    void mydfs(int pos, vector<int> temp, int k, int n) {
        int i;
        if(k==0 && n==0) {
            ret.push_back(temp);
            return;
        }
        if(n<k*pos || n>k*9 || pos>9)
            return;
        for(i=pos; i<=9; ++i) {
            temp.push_back(i);
            mydfs(i+1,temp,k-1,n-i);
            temp.pop_back();
        }
        return;
    }

    vector<vector<int> > combinationSum3(int k, int n) {
        vector<int> temp;
        int i;
        if(n < k || n > 9*k)
            return ret;
        for(i=1; i<=9; ++i) {
            temp.push_back(i);
            mydfs(i+1,temp,k-1,n-i);
            temp.pop_back();
        }
        return ret;
    }
    private:
    vector<vector<int> > ret;
};

int main() {
    Solution solu;
    return 0;
}
