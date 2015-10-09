#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include <set>
using namespace std;

class Solution {
    public:
    bool wordPattern(string pattern, string str) {
        map<char,string> sign;
        set<string> store;
        int len_p,len_str,i,start,end;
        len_p = pattern.size();
        len_str = str.size();
        if(len_p==0 || len_str==0)
            return len_p==len_str? true:false;
        start = 0;
        for(i=0;i<len_p && start<len_str;++i) {
            char alp = pattern[i];
            string temp;
            end = start;
            while(end<len_str && str[end] != ' ') {
                end++;
            }
            temp = str.substr(start,end-start);
            start = end+1;
            if(sign.find(alp)!=sign.end()) {
                if(temp != sign[alp])
                    break;
            }
            else {
                if(store.count(temp) >0)
                    break;
                store.insert(temp);
                sign[alp] = temp;
            }
        }
        if(i == len_p)
            return start>=len_str? true:false;
        else
            return false;
    }
};

int main() {
    Solution solu;
    return 0;
}
