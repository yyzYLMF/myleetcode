/*
@yang 2015/3/3

Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        vector<char> cvec;
        int i, result=0;
        vector<char>::iterator iter;

        for(i=0; i<s.size(); ++i) {
            iter = find(cvec.begin(), cvec.end(), s[i]);
            if(iter == cvec.end()) {
                cvec.push_back(s[i]);
            }
            else {
                if(cvec.size() > result)
                    result = cvec.size();
                cvec.erase(cvec.begin(), iter+1);
                cvec.push_back(s[i]);
            }
        }
        if(cvec.size() > result)
            result = cvec.size();
        return result;
    }
};

int main() {
    Solution solu;
    int result;
    string s1("abcabcbb"), s2("bbbb");

    result = solu.lengthOfLongestSubstring(s1);
    cout<<"s1: "<<result<<endl;
    result = solu.lengthOfLongestSubstring(s2);
    cout<<"s2: "<<result<<endl;

    return 0;
}
