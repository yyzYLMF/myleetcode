/*
 * @yang 2015/3/28
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

//Time Limit Exceeded
class Solution {
    public:
    typedef vector<int>::iterator index;
    int oneMax(index start, index end) {
        int profit=0,temp,last;
        index pos;
        if(start == end)
            return profit;
        last=(*start);
        for(pos=start+1; pos<=end; ++pos) {
            if(last < *pos) {
                temp = *pos-last;
                if(temp>profit)
                    profit = temp;
            }
            else 
                last = *pos;
        }
        return profit;
    }

    int maxProfit(vector<int> &prices) {
        int profit=0,temp;
        index pos;

        if(prices.size() <= 1)
            return profit;
        for(pos=prices.begin(); pos<prices.end(); ++pos) {
            temp = oneMax(prices.begin(), pos) + oneMax(pos, prices.end()-1);
            if(temp > profit)
                profit = temp;
        }
        return profit;
    }
};

//Memory Limit Exceeded
class Solution2 {
    public:
    class Node {
        public:
        int max;
        int profit;
    };

    int maxProfit(vector<int> &prices) {
        int profit=0,temp,len,i,leftprice,leftprofit;
        Node *dp;

        len = prices.size();
        if(len <= 1)
            return profit;
        dp = new Node[len];
        dp[len-1].max = prices[len-1];
        dp[len-1].profit = 0;
        for(i=len-2;i>=0;--i) {
            temp = dp[i+1].max - prices[i];
            if(temp > dp[i+1].profit)
                dp[i].profit=temp;
            else
                dp[i].profit=dp[i+1].profit;
            if(prices[i] > dp[i+1].max)
                dp[i].max = prices[i];
            else
                dp[i].max = dp[i+1].max;
        }
        leftprice = prices[0];
        leftprofit = 0;
        temp=0;
        for(i=0;i<len;++i) {
            if(prices[i] > leftprice) {
                temp = prices[i]-leftprice;
                if(temp>leftprofit)
                    leftprofit=temp;
            }
            else
                leftprice = prices[i];
            if((leftprofit+dp[i].profit) > profit)
                profit = leftprofit+dp[i].profit;
        }
        return profit;
    }
};

int main() {
    Solution solu;
    Solution2 solu2;
    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    cout<<solu2.maxProfit(input)<<endl;
    return 0;
}
