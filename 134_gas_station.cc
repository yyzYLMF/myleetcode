/*
 * @yang 2015/3/31
 *
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 *
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 *
 * Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 *
 * Note:
 * The solution is guaranteed to be unique.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int i,start,len,index=-1,count,temp_gas,limit;
        len = gas.size();
        if(len<=0)
            return -1;
        i=0;
        start=0;
        count=1;
        temp_gas=gas[0];
        limit = 0;
        while(limit<len) {
            if(temp_gas>=cost[i]) {
                count++;
                if(count==len+1) {
                    index = start;
                    break;
                }
                temp_gas=temp_gas-cost[i];
                i=(i+1)%len;
                temp_gas+=gas[i];
            }
            else {
                i=(i+1)%len;
                start = i;
                limit += count;
                count=1;
                temp_gas=gas[i];
            }
        }
        if(index!=-1)
            return index;

        i=0;
        start=0;
        count=1;
        temp_gas=gas[0];
        limit = 0;
        while(limit<len) {
            if(temp_gas>= cost[(i-1+len)%len]) {
                count++;
                if(count==len+1) {
                    index = start;
                    break;
                }
                temp_gas = temp_gas-cost[(i-1+len)%len];
                i=(i-1+len)%len;
                temp_gas+=gas[i];
            }
            else {
                i=(i-1+len)%len;
                start = i;
                limit += count;
                count=1;
                temp_gas=gas[i];
            }
        }
        return index;
    }
};

int main() {
    Solution solu;
    vector<int> g(1,4);
    vector<int> c(1,5);
    cout<<solu.canCompleteCircuit(g,c)<<endl;
    return 0;
}
