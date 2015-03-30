/*
 * @yang 2015/3/30
 *
 * Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:
 *
 * Only one letter can be changed at a time
 * Each intermediate word must exist in the dictionary
 * For example,
 *
 * Given:
 * start = "hit"
 * end = "cog"
 * dict = ["hot","dot","dog","lot","log"]
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 *
 * Note:
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 */
#include <iostream>
#include <cstdlib>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <tr1/unordered_map>
#include <utility>
#include <queue>
#include <string>
using namespace std;

//TLE
class Solution {
    public:
    bool near(string s1, string s2) {
        int i;
        for(i=0;i<s1.size();++i) {
            if(s1[i]!=s2[i]) {
                if(s1.substr(i+1) == s2.substr(i+1))
                    return true;
                else
                    return false;
            }
        }
        return true;
    }

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<pair<string,int> > qp;
        unordered_set<string>::iterator pos;
        pair<string,int> temp;
        int count=0;
        if(start==end)
            return 1;
        
        qp.push(make_pair(start,1));
        dict.insert(end);
        while(!qp.empty()) {
            temp = qp.front();
            qp.pop();
            count++;
            for(pos = dict.begin(); pos!=dict.end();) {
                if(near(temp.first,*pos)) {
                    if(*pos == end)
                        return temp.second+1;
                    qp.push(make_pair(*pos,temp.second+1));
                    pos=dict.erase(pos);
                }
                else
                    pos++;
            }
        }
        return 0;
    }
};

class Solution2 {
    public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> q;
        queue<int> dep;
        unordered_map<string, int> hm;
        q.push(start);
        dep.push(1);
        hm[start] = 1;
        dict.insert(end);
        string str, nxt;
        int cntStep;
        while (!q.empty()) {
            str = q.front();
            q.pop();
            cntStep = dep.front();
            dep.pop();
            if (str == end)
                return cntStep;
            for (int i = 0; i < str.length(); i++)
                for (char j = 'a'; j <= 'z'; j++) {
                    if (str[i] == j)
                        continue;
                    nxt = str;
                    nxt[i] = j;
                    if (dict.count(nxt) && hm[nxt] == 0) {
                        hm[nxt] = 1;
                        q.push(nxt);
                        dep.push(cntStep + 1);
                    }
                }
        }
        return 0;
    }
};

int main() {
    clock_t c1,c2;
    Solution solu;
    Solution2 solu2;
    string start,end;
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("cog");
    dict.insert("dog");
    dict.insert("pot");
    dict.insert("dot");
    cin>>start>>end;
    c1=clock();
    solu.ladderLength(start,end,dict);
    c2=clock();
    cout<<"1 "<<c2-c1<<endl;
    c1=clock();
    solu2.ladderLength(start,end,dict);
    c2=clock();
    cout<<"2 "<<c2-c1<<endl; 

    return 0;
}
