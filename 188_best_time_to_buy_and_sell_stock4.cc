/*
 * @yang 2015/4/8
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most k transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

//Memory Limit Exceeded
class Solution {
    public:
    int maxProfit(int k, vector<int> &prices) {
        int ***dp;
        int i,j,p,q,len=prices.size();
        int max,profit,ret,temp;
        if(len<=1 || k==0)
            return 0;
        dp=new int**[len];
        for(i=0;i<len;++i) {
            dp[i] = new int*[len];
        }
        for(i=0;i<len;++i) {
            for(j=0;j<len;++j) {
                dp[i][j] = new int[k];
            }
        }
        for(i=0;i<len;++i)
            for(j=0;j<k;++j)
                dp[i][i][j] = 0;
        for(j=len-1;j>0;--j) {
            max = prices[j];
            profit = 0;
            for(i=j-1;i>=0;--i) {
                if(max-prices[i] > profit) {
                    dp[i][j][0] = max-prices[i];
                    profit = max-prices[i];
                }
                else {
                    dp[i][j][0] = profit;
                }
                if(prices[i] > max)
                    max = prices[i];
            }
        }
        for(p=1;p<k;++p) {
            for(i=0;i<len;++i) {
                for(j=i+1;j<len;++j) {
                    temp = 0;
                    for(q=i;q<=j;++q) {
                        if(dp[i][q][0]+dp[q][len-1][p-1] > temp)
                            temp = dp[i][q][0] + dp[q][len-1][p-1];
                    }
                    dp[i][j][p] = temp;
                }
            }
        }
        return dp[0][len-1][k-1];
    }
};

//Also Memory Limit Exceeded
class Solution2 {
    public:
    int maxProfit(int k, vector<int> &prices) {
        int **dp;
        //int *dp_temp;
        int i,j,p,len=prices.size();
        int minp,profit,temp,temp_max;
        if(len<=1 || k==0)
            return 0;
        if(k > len)
            k=len;
        dp = new int*[len];
        for(i=0;i<len;++i)
            dp[i] = new int[k+1];
        for(i=0;i<len;++i)
            dp[i][0] = 0;
        for(i=0;i<=k;++i)
            dp[len-1][i] = 0;
        
        for(j=1;j<=k;++j) {
            for(i=0;i<len;++i) {
                minp=prices[i];
                profit=0;
                temp_max=0;
                for(p=i;p<len;++p) {
                    if(prices[p]-minp>profit)
                        profit=prices[p]-minp;
                    if(prices[p]<minp)
                        minp=prices[p];
                    if(profit+dp[p][j-1] > temp_max)
                        temp_max = profit+dp[p][j-1];
                }
                dp[i][j]=temp_max;
            }
        }
        return dp[0][k];
    }
};

//AC,perfect
class Solution3 {
    public:
    int maxProfit(int k, vector<int> &prices) {
        if(prices.empty() || k == 0)
            return 0;

        if(k >= prices.size())
            return solveMaxProfit(prices);

        vector<int> global(k + 1, 0);
        vector<int> local(k + 1, 0);

        for(int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i - 1];
            for(int j = k; j >= 1; j--) {
                local[j] = max(local[j] + diff, global[j - 1] + max(diff, 0));
                global[j] = max(global[j], local[j]);
            }
        }

        return global[k];
    }
    private:
    int solveMaxProfit(vector<int> &prices) {
        int res = 0;
        for(int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i - 1];
            if(diff > 0)
                res += diff;
        }
        return res;
    }
};


int main() {
    Solution2 solu;
    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    cout<<solu.maxProfit(1000,input)<<endl;
    return 0;
}
