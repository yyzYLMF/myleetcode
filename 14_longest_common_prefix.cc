/*
@yang 2015/3/4

Write a function to find the longest common prefix string amongst an array of strings.

*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
    string mycompare(string s1, string s2) {
        string::iterator i,j;
        for(i=s1.begin(),j=s2.begin(); i<s1.end() && j<s2.end(); ++i,++j) {
            if(*i != *j)
                break;
        }
        return string(s1.begin(),i);
    }

    string longestCommonPrefix(vector<string> &strs) {
        string result;
        int i;

        if(strs.empty())
            return string("");

        result = strs[0];
        for(i=1; i<strs.size(); ++i)
            result = mycompare(result, strs[i]);
        return result;
    }
};

int main() {
    vector<string> strs;
    string result;
    Solution solu;

    strs.push_back("asdfasdfabc");
    strs.push_back("asdfasfd");
    strs.push_back("asdasdasdfasdf");

    result = solu.longestCommonPrefix(strs);
    cout<<"result: "<<result<<endl;
    return 0;
}
