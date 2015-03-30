/*
 * @yang 2015/3/30
 *
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 *
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 *
 * Your algorithm should run in O(n) complexity.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;

class Solution {
    public:
    int longestConsecutive(vector<int> &num) {
        set<int> copy;
        int i,count=0,val,max=0;
        set<int>::iterator pos;

        if(num.size()==0)
            return 0;
        for(i=0;i<num.size();++i)
            copy.insert(num[i]);
        for(pos=copy.begin(); pos!=copy.end(); pos++) {
            if(pos==copy.begin()) {
                count=1;
                val=*pos;
            }
            else {
                if(*pos == val)
                    continue;
                else if(*pos == val+1) {
                    count++;
                    val++;
                }
                else {
                    if(count > max)
                        max = count;
                    count=1;
                    val = *pos;
                }
            }
        }
        if(count > max)
            max = count;
        return max; 
    }
};

int main() {
    Solution solu;
    vector<int> input;
    input.push_back(4);
    input.push_back(-4);
    input.push_back(-2);
    input.push_back(-1);
    input.push_back(-3);
    input.push_back(-2);
    cout<<solu.longestConsecutive(input)<<endl;
    return 0;
}
