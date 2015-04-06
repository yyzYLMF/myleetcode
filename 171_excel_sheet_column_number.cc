/*
 * @yang 2015/4/6
 *
 * Related to question Excel Sheet Column Title
 *
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 *
 * For example:
 A -> 1
 B -> 2
 C -> 3
 ...
 Z -> 26
 AA -> 27
 AB -> 28 
 */
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
    public:
    int titleToNumber(string s) {
        int ret=0;
        int i;
        for(i=0;i<s.size();++i) {
            ret=ret*26+(s[i]-'A')+1;
        }
        return ret;
    }
};

int main() {
    Solution solu;
    string s;
    while(cin>>s)
        cout<<solu.titleToNumber(s)<<endl;
    return 0;
}
