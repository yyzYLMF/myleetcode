/*
 * @yang 2015/4/1
 *
 * Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
 *
 * Return all such possible sentences.
 *
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 *
 * A solution is ["cats and dog", "cat sand dog"].
 */
#include <iostream>
#include <cstdlib>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
    int *dp;
    vector<vector<string> > store;
    bool myfun(string s, int pos, unordered_set<string> &dict) {
        int i,j,len;
        string addString;
        string temp;
        len = s.size();
        if(pos>=len)
            return true;
        if(dp[pos] != -1)
            return dp[pos]==1? true:false;
        for(i=len-1;i>=pos;--i) {
            if(dict.count(s.substr(pos,i+1-pos))) {
                temp=s.substr(pos,i+1-pos);
                if(myfun(s,i+1,dict)) {
                    if(i+1 < len) {
                        for(j=0;j<store[i+1].size();++j) {
                            addString = temp+" "+store[i+1][j];
                            store[pos].push_back(addString);
                        }
                    }
                    else {
                        addString = temp;
                        store[pos].push_back(addString);
                    }
                }
            }
        }
        dp[pos] = store[pos].size()==0? false:true;
        return dp[pos];
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int i,j,len;
        vector<string> empty;
        string temp;
        string addString;
        len = s.size();
        if(len == 0)
            return empty;
        for(i=0;i<len;++i)
            store.push_back(empty);
        dp = new int[len];
        for(i=0;i<len;++i)
            dp[i] = -1;
        for(i=len-1;i>=0;--i) {
            if(dict.count(s.substr(0,i+1))) {
                temp = s.substr(0,i+1);
                if(myfun(s,i+1,dict)) {
                    if(i+1 < len) {
                        for(j=0;j<store[i+1].size();++j) {
                            addString = temp+" "+store[i+1][j];
                            store[0].push_back(addString);
                        }
                    }
                    else {
                        addString = temp;
                        store[0].push_back(addString);
                    }
                }
            }
        }
        return store[0];
    }
};

int main() {
    Solution solu;
    string s("catsanddog");
    unordered_set<string> dict;
    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("dog");
    vector<string> result = solu.wordBreak(s,dict);
    for(int i=0;i<result.size();++i)
        cout<<result[i]<<endl;
    return 0;
}
