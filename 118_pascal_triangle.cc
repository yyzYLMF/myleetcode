/*
 * @yang 2015/3/27
 *
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 * Return
 [
 [1],
 [1,1],
 [1,2,1],
 [1,3,3,1],
 [1,4,6,4,1]
 ]
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<vector<int> > generate(int numRows) {
       vector<vector<int> > result;
       int i,j;
        
       if(numRows==0)
           return result;
       for(i=1;i<=numRows;++i) {
           vector<int> temp(i,1);
           result.push_back(temp);
       }
       if(numRows<=2)
           return result;
       for(i=3;i<=numRows;++i) {
           for(j=1;j<i-1;++j)
               result[i-1][j]=result[i-2][j-1]+result[i-2][j];
       }
       return result;
    }
};

int main() {
    Solution solu;
    int n;
    vector<vector<int> > result;
    while(cin>>n) {
        result=solu.generate(n);
        for(int i=0;i<result.size();++i) {
            for(int j=0;j<result[i].size();++j)
                cout<<result[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
