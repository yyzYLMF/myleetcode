/*
@yang 2015/3/12

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    void rotate(vector<vector<int> > &matrix) {
        int n=matrix.size();
        int i,j;

        if(n==1)
            return;
        for(i=0; i<n; ++i) {
            for(j=i+1; j<n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(j=0; j<n; ++j) {
            if(n-1-j <= j)
                break;
            for(i=0; i<n; ++i) {
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
        return;
    }
};

int main() {
    vector<vector<int> > result;
    vector<int> input1(3,1);
    vector<int> input2(3,2);
    vector<int> input3(3,3);
    Solution solu;

    result.push_back(input1);
    result.push_back(input2);
    result.push_back(input3);
    solu.rotate(result);
    for(int i=0; i<result.size(); ++i) {
        for(int j=0; j<result[i].size(); ++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
