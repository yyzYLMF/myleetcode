/*
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 *
 * Note: Given n will be between 1 and 9 inclusive.
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
    string getPermutation(int n, int k) {
        int value=1;
        int i,j,temp;
        string result="";
        vector<char> copy;

        if(n==1)
            return "1";
        for(i=1; i<=n-1; ++i)
            value= value*i;
        for(i=1; i<=n; ++i)
            copy.push_back(char('0'+i));
        for(i=0; i<n; ++i) {
            if(k == 0) {
                for(j=copy.size()-1; j>=0; --j)
                    result.insert(result.end(), copy[j]);
                return result;
            }
            else if(k%value == 0)
                temp = k/value-1;
            else
                temp = k/value;
            result.insert(result.end(), copy[temp]);
            copy.erase(copy.begin()+temp);
            if(i != n-1){
                k = k-(k/value)*value;
                value = value/(n-1-i);
            }
        }
        return result;
    }
};

int main() {
    int n,k;
    Solution solu;

    while(cin>>n>>k) {
        cout<<solu.getPermutation(n,k)<<endl;
    }
    return 0;
}
