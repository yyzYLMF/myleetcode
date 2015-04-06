/*
 * @yang 2015/4/6
 *
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 *
 * For example:
 1 -> A
 2 -> B
 3 -> C
 ...
 26 -> Z
 27 -> AA
 28 -> AB 
 */
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
    public:
    string convertToTitle(int n) {
        string ret="";
        int temp;
        while(n) {
            temp = n%26;
            if(temp == 0) {
                ret.insert(ret.begin(),'Z');
                n=n/26;
                n--;
            }
            else {
                ret.insert(ret.begin(),temp-1+'A');
                n=n/26;
            }
        }
        return ret;
    }
};

int main() {
    Solution solu;
    int n;
    while(cin>>n)
        cout<<solu.convertToTitle(n)<<endl;
    return 0;
}
