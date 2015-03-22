/*
 * @yang 2015/3/18
 *
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 *
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 *
 * Note:
 * If there is no such window in S that covers all characters in T, return the emtpy string "".
 *
 * If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 */
#include <iostream>
#include <cstdlib>
#include <map>
#include <climits>
#include <string>
#include <list>
using namespace std;

//use findHead to find the first element's index, but Time Limit Exceeded
class Solution {
    public:    
    int findHead(map<char,list<int> > mymap) {
        map<char,list<int> >::iterator iter=mymap.begin();
        list<int>::iterator it;
        int index=INT_MAX;
        while(iter!=mymap.end()) {
            it=iter->second.begin();
            while(it!=iter->second.end()) {
                if(*it < index)
                    index=*it;
                it++;
            }
            iter++;
        }
        return index;
    }

    string minWindow(string S, string T) {
        int m,n,i,head,min=INT_MAX,num;
        map<char,list<int> > mymap;
        map<char,int> copy;
        string result;

        m=S.size();
        n=T.size();
        if(m<n || m==0 || n==0)
            return "";
        for(i=0; i<n; ++i) 
            copy[T[i]]++;
        num=0;
        for(i=0; i<m; ++i) {
            if(T.find(S[i]) != string::npos) {
                if(mymap[S[i]].size() < copy[S[i]]) {
                    num++;
                    mymap[S[i]].push_back(i);
                }
                else {
                    mymap[S[i]].pop_front();
                    mymap[S[i]].push_back(i);
                }
                if(num == n) {
                    head = findHead(mymap);
                    if(i-head+1 < min) {
                        min = i-head+1;
                        result=S.substr(head,min);
                    }
                }
            }
        }
        return result;
    }
};

class Solution2 {
    public:
    string minWindow(string S, string T) {
        int m,n,i,head,min=INT_MAX,num;
        map<char,int> mymap;
        map<char,int> copy;
        string result;

        m=S.size();
        n=T.size();
        if(m<n || m==0 || n==0)
            return "";
        for(i=0; i<n; ++i) 
            copy[T[i]]++;
        num=0;
        head=0;
        for(i=0; i<m; ++i) {
            if(T.find(S[i]) != string::npos) {
                if(mymap[S[i]] < copy[S[i]]) {
                    num++;
                    mymap[S[i]]++;
                }
                else {
                    mymap[S[i]]++;
                }
                if(num == n) {
                    while(head<=i && mymap[S[head]] > copy[S[head]]) {
                        mymap[S[head]]--;
                        head++;
                    }
                    if(i-head+1 < min) {
                        min = i-head+1;
                        result=S.substr(head,min);
                    }
                    num--;
                    mymap[S[head]]--;
                    head++;
                }
            }
            else
                mymap[S[i]]++;
        }
        return result;
    }    
};

int main() {
    string s1,s2;
    Solution2 solu;

    while(cin>>s1>>s2) {
        cout<<solu.minWindow(s1,s2)<<endl;
    }
    return 0;
}
