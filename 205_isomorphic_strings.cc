/*
 * @yang 2015/4/30
 *
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 *
 * For example,
 * Given "egg", "add", return true.
 *
 * Given "foo", "bar", return false.
 *
 * Given "paper", "title", return true.
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;

class Solution {
    public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mapping;
        map<char,int> temp;
        int i,len=s.size();
        if(len==0)
            return true;
        for(i=0;i<len;++i) {
            if(mapping.count(s[i])) {
                if(mapping[s[i]]!=t[i])
                    break;
            }
            else {
                mapping[s[i]] = t[i];
                if(temp[t[i]]>0)
                    break;
                else
                    temp[t[i]]=1;
            }
        }
        if(i<len)
            return false;
        else
            return true;
    }
};

int main() {
    Solution solu;
    string s,t;
    while(cin>>s>>t) {
        cout<<solu.isIsomorphic(s,t)<<endl;
    }
    return 0;
}
