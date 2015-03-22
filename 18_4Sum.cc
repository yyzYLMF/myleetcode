/*
    @yang 2015/3/5

    Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        typedef vector<int>::iterator index;

        bool ispushed(vector<vector<int> > &vec, int a, int b, int c) {
            int i;
            for(i=0; i<vec.size(); ++i) {
                if(vec[i][0]==a && vec[i][1]==b && vec[i][2]==c)
                    break;
            }
            if(i==vec.size())
                return true;
            else
                return false;
        }

        vector<vector<int> > twoSum(index head, index tail, int target, int a, int b) {
            int value;
            vector<vector<int> > vec_temp;
            vector<int> four;

            while(head < tail) {
                value = *head + *tail;
                if(value == target) {
                    if(ispushed(vec_temp, a, b, *head)){
                        four.clear();
                        four.push_back(a);
                        four.push_back(b);
                        four.push_back(*head);
                        four.push_back(*tail);
                        vec_temp.push_back(four);
                    }
                    tail--;
                    head++;
                }
                else if(value > target) {
                    tail--;
                }
                else if(value < target) {
                    head++;
                }
            }
            return vec_temp;
        }

        vector<vector<int> > fourSum(vector<int> &num, int target) {
            vector<int> copy(num);
            vector<vector<int> > temp;
            vector<vector<int> > result;
            index iter1,iter2;

            if(num.size() < 4)
                return result;
            sort(copy.begin(), copy.end());
            for(iter1=copy.begin(); iter1+4<=copy.end(); ++iter1) {
                if(iter1!=copy.begin() && *iter1 == *(iter1-1))
                    continue;
                for(iter2=iter1+1; iter2+3<=copy.end(); ++iter2) {
                    if(iter2!=iter1+1 && *iter2 == *(iter2-1))
                        continue;
                    temp = twoSum(iter2+1,copy.end()-1,(target-*iter1-*iter2),*iter1,*iter2);
                    for(int i=0; i<temp.size(); ++i)
                        result.push_back(temp[i]);
                }
            }
            return result;
        }
};

int main() {
    Solution solu;
    vector<int> ivec;
    vector<vector<int> > vvec;
    
       ivec.push_back(1);
       ivec.push_back(0);
       ivec.push_back(-1);
       ivec.push_back(0);
       ivec.push_back(-2);
       ivec.push_back(2);
     
    vvec = solu.fourSum(ivec,0);
    for(int i=0; i<vvec.size(); ++i) {
        for(int j=0; j<vvec[i].size(); ++j) {
            cout<<vvec[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
