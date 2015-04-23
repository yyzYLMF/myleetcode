/*
 * @yang 2015/4/23
 *
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 *
 * Example: 19 is a happy number
 *
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 */
#include <iostream>
#include <cstdlib>
#include <set>
using namespace std;

class Solution {
    public:
    bool isHappy(int n) {
        set<long> store;
        long temp_sum,temp;

        temp_sum = n;
        store.insert(temp_sum);
        while(1) {
            temp = temp_sum;
            temp_sum=0;
            while(temp!=0) {
                temp_sum += (temp%10)*(temp%10);
                temp = temp/10;
            }
            if(temp_sum==1)
                return true;
            if(store.count(temp_sum))
                return false;
            store.insert(temp_sum);
        }
    }
};

int main() {
    Solution solu;
    int n;
    while(cin>>n)
        cout<<solu.isHappy(n)<<endl;
    return 0;
}
