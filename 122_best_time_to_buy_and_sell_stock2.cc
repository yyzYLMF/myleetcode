/*
 * @yang 2015/3/28
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    int maxProfit(vector<int> &prices) {
        int profit=0;
        int i,lastprice;

        if(prices.size() == 0)
            return profit;
        lastprice = prices[0];
        for(i=1;i<prices.size();++i) {
            if(prices[i] > lastprice) {
                profit += prices[i]-lastprice;
                lastprice = prices[i];
            }
            else
                lastprice = prices[i];
        }
        return profit;
    }
};

int main() {
    Solution solu;
    return 0;
}
