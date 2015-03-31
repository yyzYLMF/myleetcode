/*
 * @yang 2015/3/31
 *
 * There are N children standing in a line. Each child is assigned a rating value.
 *
 * You are giving candies to these children subjected to the following requirements:
 *
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

//Wrong Answer
class Solution {
    public:
    int candy(vector<int> &ratings) {
        int i,left,right,sum,last,len,height;
        bool dec=false;
        len = ratings.size();
        if(len<=1)
            return len;
        left=0;
        right=0;
        last = ratings[0];
        sum=0;
        for(i=1;i<len;++i) {
            if(last < ratings[i]) {
                if(dec) {
                    height = left>right ? left:right;
                    sum+=height;
                    sum+= (1+left-1)*(left-1)/2;
                    sum+= right==0 ? 0:(1+right-1)*(right-1)/2-1;
                    right = 2;
                    left = 0;
                    dec = false;
                }
                else {
                    left = left==0 ? 2:left+1;
                }
            }
            else if(last > ratings[i]) {
                dec = true;
                right = right==0? 2:right+1;
            }
            else {
                if(left==0 && right==0) 
                    sum+=1;
                else {
                    height = left>right ? left:right;
                    sum+=height;
                    sum+=left==0? 0:(1+left-1)*(left-1)/2;
                    sum+=right==0? 0:(1+right-1)*(right-1)/2;
                    right = 0;
                    left = 0;
                    dec = false;
                }
            }
            last = ratings[i];
        }
        if(right==0 && left==0)
            sum+=1;
        else {
            height = left>right?left:right;
            sum+=height;
            sum+=left==0? 0:(1+left-1)*(left-1)/2;
            sum+=right==0? 0:(1+right-1)*(right-1)/2;
        }
        return sum;
    }
};

//AC,perfect
class Solution2 {
    public:
        int candy(vector<int> &ratings) {
            int ret = 0;
            if (ratings.size() == 0)
                return ret;
            vector<int> dp(ratings.size(), 1);
            for (int i = 1; i < ratings.size(); i++)
                if (ratings[i] > ratings[i - 1])
                    dp[i] = dp[i - 1] + 1;

            ret = dp[ratings.size() - 1];
            for (int i = ratings.size() - 2; i >= 0; i--) {
                if (ratings[i] > ratings[i + 1]) {
                    dp[i] = max(dp[i], dp[i + 1] + 1);
                }
                ret += dp[i];
            }
            return ret;
        }
};

int main() {
    Solution solu;
    vector<int> input(3,1);
    input.push_back(3);
    input.push_back(4);
    input.push_back(2);
    input.push_back(3);
    cout<<solu.candy(input)<<endl;
    return 0;
}
