/*
@yang 2015/3/5

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    typedef vector<int>::iterator index;
    
    bool ispush(vector<vector<int> > &vec, int a, int b, int c) {
        int i;
        for(i=0; i<vec.size(); ++i) {
            if(vec[i][0]==a && vec[i][1]==b)
                break;
        }
        if(i==vec.size())
            return true;
        else
            return false;
    }

    vector<vector<int> > twoSum(index head, index tail, int target) {
        int value;
        vector<vector<int> > vec_temp;
        vector<int> triplet;

        while(head < tail) {
            value = *head + *tail;
            if(value == target) {
                if(ispush(vec_temp, -target, *head, *tail)){
                    triplet.clear();
                    triplet.push_back(-target);
                    triplet.push_back(*head);
                    triplet.push_back(*tail);
                    vec_temp.push_back(triplet);
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

    vector<vector<int> > threeSum(vector<int> &num) {
        vector<int> copy(num);
        vector<vector<int> > temp;
        vector<vector<int> > result;
        index iter;

        if(num.empty() == 1)
            return result;
        sort(copy.begin(), copy.end());
        for(iter=copy.begin(); iter<=copy.end()-3; ++iter) {
            if(iter!=copy.begin() && *iter==*(iter-1))
                continue;
            temp = twoSum(iter+1,copy.end()-1,(-(*iter)));
            for(int i=0; i<temp.size(); ++i)
                result.push_back(temp[i]);
        }
        return result;
    }
};

int main() {
    Solution solu;
    vector<int> ivec;
    vector<vector<int> > vvec;
    /*
    ivec.push_back(-1);
    ivec.push_back(0);
    ivec.push_back(1);
    ivec.push_back(2);
    ivec.push_back(-1);
    ivec.push_back(-4);
*/
    vvec = solu.threeSum(ivec);
    for(int i=0; i<vvec.size(); ++i) {
        for(int j=0; j<vvec[i].size(); ++j) {
            cout<<vvec[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
