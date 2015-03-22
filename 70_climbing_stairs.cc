/*
 * @yang 2015/3/17
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */
#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
    public:
    int climbStairs(int n) {
        int *step;

        if(n==1)
            return 1;
        step = new int[n+1];
        step[0]=1;
        step[1]=1;
        for(int i=2; i<=n; ++i) {
            step[i] = step[i-1] + step[i-2];
        }
        return step[n];
    }
};

int main() {
    int n;
    Solution solu;

    while(cin>>n) {
        cout<<solu.climbStairs(n)<<endl;
    }
    return 0;
}
