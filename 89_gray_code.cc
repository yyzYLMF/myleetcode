/*
 * @yang 2015/3/21
 *
 * The gray code is a binary numeral system where two successive values differ in only one bit.
 *
 * Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
 *
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 00 - 0
 01 - 1
 11 - 3
 10 - 2
 * Note:
 * For a given n, a gray code sequence is not uniquely defined.
 *
 * For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
 *
 * For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
 */
#include <iostream>
#include <cstdlib>
#include <bitset>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> grayCode(int n) {
        vector<bitset<32> > store;
        vector<int> result;
        int i,j;

        if(n<=0) {
            result.push_back(0);
            return result;
        }
        bitset<32> temp0(0),temp1(1);
        store.push_back(temp0);
        store.push_back(temp1);
        for(i=2;i<=n;++i) {
            for(j=store.size()-1; j>=0; --j) {
                bitset<32> tmp(store[j]);
                tmp.set(i-1);
                store.push_back(tmp);
            }
        }
        for(i=0; i<store.size(); ++i) {
            result.push_back(store[i].to_ulong());
        }
        return result;
    }
};

int main() {
    vector<int> result;
    int n;
    Solution solu;

    while(cin>>n) {
        result = solu.grayCode(n);
        for(int i=0; i<result.size(); ++i)
            cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
