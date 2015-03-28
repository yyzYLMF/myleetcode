/*
 * @yang 2015/3/27
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    int maxProfit(vector<int> &prices) {
        int profit=0;
        int in,temp,len,i;
        len = prices.size();
        if(len<=1)
            return profit;
        in = prices[0];
        for(i=1;i<len;++i) {
            if(in > prices[i]) {
                in = prices[i];
            }
            else {
                temp = prices[i]-in;
                if(temp>profit)
                    profit=temp;
            }
        }
        return profit;   
    }
};

int main() {
    Solution solu;
    return 0;
}
