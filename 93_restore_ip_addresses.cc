/*
 * @yang 2015/3/23
 *
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 *
 * For example:
 * Given "25525511135",
 *
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
    void myfun(vector<string> &result, string &s, vector<char> temp, int index, int status) {
        int len,i;
        len=s.size();
        if(status==0 && index==len) {
            result.push_back(string(temp.begin(),temp.end()));
            return;
        }
        if(len-index>status*3 || len-index<status)
            return;
        if(len-index==status) {
            for(i=index;i<len;++i) {
                temp.push_back('.');
                temp.push_back(s[i]);
            }
            result.push_back(string(temp.begin(),temp.end()));
            return;
        }
        i=index;
        if(s[i]=='0' ) {
            temp.push_back('.');
            temp.push_back(s[i]);
            myfun(result,s,temp,i+1,status-1);
            return;
        }
        temp.push_back('.');
        temp.push_back(s[i]);
        myfun(result,s,temp,i+1,status-1);
        if(i+1<len-status+1) {
            temp.push_back(s[i+1]);
            myfun(result,s,temp,i+2,status-1);
        }
        if(i+2<len-status+1) {
            if(s[i]=='1' || s[i]=='2') {
                if(s[i]=='1') {
                    temp.push_back(s[i+2]);
                    myfun(result,s,temp,i+3,status-1);
                }
                if(s[i]=='2' && (s[i+1]<='4' || (s[i+1]=='5' && s[i+2]<='5'))) {
                    temp.push_back(s[i+2]);
                    myfun(result,s,temp,i+3,status-1);
                }
            }
        }
        return;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<char> temp;
        int len,i=0;

        len=s.size();
        if(len>12 || len<4)
            return result;
        i=0;
        if(s[i] == '0' ) {
            temp.push_back(s[i]);
            myfun(result,s,temp,i+1,3);
            return result;
        }
        temp.push_back(s[i]);
        myfun(result,s,temp,i+1,3);
        if(i+1<len-3) {
            temp.push_back(s[i+1]);
            myfun(result,s,temp,i+2,3);
        }
        if(i+2<len-3) {
            if(s[i]=='1' || s[i]=='2') {
                if(s[i]=='1') {
                    temp.push_back(s[i+2]);
                    myfun(result,s,temp,i+3,3);
                }
                if(s[i]=='2' && (s[i+1] <= '4' || (s[i+1]=='5' && s[i+2]<='5'))) {
                    temp.push_back(s[i+2]);
                    myfun(result,s,temp,i+3,3);
                }
            }
        }

        return result;
    }
};

int main() {
    Solution solu;
    string s;
    vector<string> result;
    cin>>s;
    result=solu.restoreIpAddresses(s);
    for(int i=0;i<result.size(); ++i) {
        cout<<result[i]<<endl;
    }
    return 0;
}
