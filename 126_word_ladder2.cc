/*
 * @yang 2015/3/30
 *
 * Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:
 *
 * Only one letter can be changed at a time
 * Each intermediate word must exist in the dictionary
 * For example,
 *
 * Given:
 * start = "hit"
 * end = "cog"
 * dict = ["hot","dot","dog","lot","log"]
 * Return
 [
 ["hit","hot","dot","dog","cog"],
 ["hit","hot","lot","log","cog"]
 ]
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    public:
    class Node {
        public:
        string str;
        int len;
        Node(string s, int x): str(s), len(x) {}
    };
    void myfun(vector<vector<string> > &result, unordered_map<string, vector<Node> > &hm, vector<string> temp, string start, string end) {
        int i;
        if(end == start) {
            reverse(temp.begin(),temp.end());
            result.push_back(temp);
            return;
        }
        for(i=0;i<hm[end].size();++i) {
            temp.push_back(hm[end][i].str);
            myfun(result,hm,temp,start,hm[end][i].str);
            temp.pop_back();
        }
        return;
    }
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > result;
        vector<string> temp;
        queue<string> q;
        queue<int> dep;
        unordered_map<string, vector<Node> > hm;
        
        if(start.size() == 0)
            return result;
        q.push(start);
        dep.push(1);
        hm[start].push_back(Node(start,1));
        dict.insert(end);
        string str, nxt;
        int cntStep;
        
        while (!q.empty()) {
            str = q.front();
            q.pop();
            cntStep = dep.front();
            dep.pop();
            if (str == end) {
                temp.push_back(end);
                myfun(result,hm,temp,start,end);
                break;
            }
            for (int i = 0; i < str.length(); i++) {
                for (char j = 'a'; j <= 'z'; j++) {
                    if (str[i] == j)
                        continue;
                    nxt = str;
                    nxt[i] = j;
                    if (dict.count(nxt)) {
                        if(hm[nxt].size()==0) {
                            Node mynode(str,cntStep+1);
                            hm[nxt].push_back(mynode);
                            q.push(nxt);
                            dep.push(cntStep + 1);
                        }
                        else if(cntStep+1 <= hm[nxt][0].len) {
                            Node mynode(str,cntStep+1);
                            hm[nxt].push_back(mynode);
                        }
                    }

                }
            }
        }
        return result;
    }
};

int main() {
    Solution solu;
    unordered_set<string> dict;
    string start("hit");
    string end("cog");
    vector<vector<string> > result;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    result = solu.findLadders(start,end,dict);
    for(int i=0;i<result.size();++i) {
        for(int j=0;j<result[i].size();++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
