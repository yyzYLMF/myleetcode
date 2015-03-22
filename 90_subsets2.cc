/*
 * @yang 2015/3/21
 *
 * Given a collection of integers that might contain duplicates, S, return all possible subsets.
 *
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If S = [1,2,2], a solution is:
 [
 [2],
 [1],
 [1,2,2],
 [2,2],
 [1,2],
 []
 ]
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    void myfun(vector<vector<int> > &result, vector<int> &S, vector<int> temp, int index,int len) {
        int i;
        if(len == 0) {
            result.push_back(temp);
            return;
        }
        if(index+len == S.size()) {
            for(i=index;i<S.size();++i)
                temp.push_back(S[i]);
            
            result.push_back(temp);
            return;
        }
        for(i=index; i<=S.size()-len;++i) {
            if(i!=index && S[i] == S[i-1])
                continue;
            temp.push_back(S[i]);
            myfun(result,S,temp,i+1,len-1);
            temp.pop_back();
        }
        return;
    }

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > result;
        vector<int> temp;
        vector<int> copy(S);
        int i,j,len;

        result.push_back(temp);
        if(S.size()==0)
            return result;
        sort(copy.begin(),copy.end());
        len=copy.size();
        for(i=1;i<=len;++i) {
            for(j=0;j<=len-i;++j) {
                if(j!=0 && copy[j] == copy[j-1])
                    continue;
                temp.push_back(copy[j]);
                myfun(result,copy,temp,j+1,i-1);
                temp.pop_back();
            }
        }
        return result;
    }
};

int main() {
    Solution solu;
    vector<int> input;
    vector<vector<int> > result;
    input.push_back(1);
    input.push_back(2);
    input.push_back(2);

    result=solu.subsetsWithDup(input);
    for(int i=0;i<result.size();++i) {
        for(int j=0;j<result[i].size();++j) 
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
    
    return 0;
}
