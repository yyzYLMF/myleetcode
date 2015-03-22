/*
 @yang 2015/3/14

 Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

 For example,
 Given n = 3,

 You should return the following matrix:
 [
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
 ]
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result;
        vector<int> temp;
        int **sign, **value;
        int i,j,count,direct;
        
        if(n==0)
            return result;
        sign = new int*[n];
        value = new int*[n];
        for(i=0; i<n; ++i) {
            sign[i] = new int[n];
            value[i] = new int[n];
        }
        for(i=0; i<n; ++i)
            for(j=0; j<n; ++j)
                sign[i][j] = 0;
        i=0;
        j=0;
        count=1;
        direct=0;
        while(count<=n*n) {
            value[i][j] = count;
            sign[i][j] = 1;
            count++;
            if(direct == 0) {
                j++;
                if(j>=n || sign[i][j] == 1) {
                    j--;
                    i++;
                    direct = 1;
                }
            }
            else if(direct == 1) {
                i++;
                if(i>=n || sign[i][j] == 1) {
                    i--;
                    j--;
                    direct = 2;
                }
            }
            else if(direct == 2) {
                j--;
                if(j<0 || sign[i][j] == 1) {
                    j++;
                    i--;
                    direct = 3;
                }
            }
            else {
                i--;
                if(i<0 || sign[i][j] == 1) {
                    i++;
                    j++;
                    direct = 0;
                }
            }
        }
        for(i=0; i<n; ++i) {
            for(j=0; j<n; ++j) {
                temp.push_back(value[i][j]);
            }
            result.push_back(temp);
            temp.clear();
        }
        return result;
    }
};

int main() {
    int input;
    vector<vector<int> > result;
    Solution solu;

    while(cin>>input) {
        result = solu.generateMatrix(input);
        for(int i=0; i<result.size(); ++i) {
            for(int j=0; j<result[i].size(); ++j) {
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
