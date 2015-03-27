/*
 * @yang 2015/3/27
 *
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1].
 *
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> getRow(int rowIndex) {
        int i,j;
        vector<int> empty;
        vector<int> result(rowIndex+1,1);

        if(rowIndex<0)
            return empty;
        
        if(rowIndex+1<=2)
            return result;
        for(i=3;i<=rowIndex+1;++i) {
            for(j=1;j<i-1;++j) {
                if(result[0]==1) {
                    result[0] = result[j]+result[j-1];
                }
                else {
                    result[i-1] = result[j]+result[j-1];
                    result[j-1] = result[0];
                    result[0] = result[i-1];
                }
            }
            result[j-1] = result[0];
            result[0]=1;
            result[i-1]=1;
        }
        return result;
    }
};

int main() {
    Solution solu;
    int n;
    vector<int> result;
    while(cin>>n) {
        result = solu.getRow(n);
        for(int i=0; i<result.size(); ++i)
            cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
