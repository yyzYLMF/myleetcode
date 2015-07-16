/*
 * @yang 2015/7/16
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.
 *
 * For example, given the following matrix:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * Return 4.
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
using namespace std;

//Not a simple solution
class Solution {
    public:
    int calSquare(int *sign,int n) {
        stack<int> high;
        stack<int> pos;
        int i,ret,h,l,temp;
        high.push(sign[0]);
        pos.push(0);
        ret = 0;
        for(i=1;i<n;++i) {
            if(high.empty()) {
                high.push(sign[i]);
                pos.push(i);
                continue;
            }
            if(sign[i] > high.top()) {
                high.push(sign[i]);
                pos.push(i);
            }
            else {
                while(!high.empty() && high.top()>=sign[i]) {
                    h = high.top();
                    high.pop();
                    pos.pop();
                    l = pos.empty() ? i:i-pos.top()-1;
                    temp = min(h,l);
                    if(temp*temp > ret)
                        ret = temp*temp;
                }
                high.push(sign[i]);
                pos.push(i);
            }
        }
        while(!high.empty()) {
            h = high.top();
            high.pop();
            pos.pop();
            l = pos.empty() ? i:i-pos.top()-1;
            temp = min(h,l);
            if(temp*temp > ret)
                ret = temp*temp;
        }
        return ret;
    }

    int maximalSquare(vector<vector<char> >& matrix) {
        int m,n,i,j,ret,temp;
        int **sign;
        m = matrix.size();
        if(m == 0)
            return 0;
        n = matrix[0].size();
        if(n == 0)
            return 0;
        sign = new int*[m];
        for(i=0;i<m;++i)
            sign[i] = new int[n];
        ret = 0;
        for(i=0;i<m;++i) {
            for(j=0;j<n;++j) {
                if(matrix[i][j] == '0')
                    sign[i][j] = 0;
                else {
                    if(i == 0)
                        sign[i][j] = 1;
                    else 
                        sign[i][j] = sign[i-1][j] + 1;
                }
            }
            temp = calSquare(sign[i],n);
            if(temp > ret)
                ret = temp;
        }
        return ret;
    }
};

int main() {
    Solution solu;
    vector<vector<char> > input;
    vector<char> a1;
    vector<char> a2;
    a1.push_back('1');
    a1.push_back('1');
    a1.push_back('1');
    a1.push_back('0');
    a1.push_back('0');
    a2.push_back('1');
    a2.push_back('0');
    a2.push_back('1');
    a2.push_back('1');
    a2.push_back('0');
    input.push_back(a1);
    input.push_back(a2);
    input.push_back(a2);
    input.push_back(a1);
    cout<<solu.maximalSquare(input)<<endl;
    return 0;
}
