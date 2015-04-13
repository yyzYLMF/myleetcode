/*
 * @yang 2015/4/12
 *
 * Given a list of non negative integers, arrange them such that they form the largest number.
 *
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 *
 * Note: The result may be very large, so you need to return a string instead of an integer.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    public:
    static bool cmp(const string &a, const string &b) {
        int i,j,m,n,temp;
        m=a.size();
        n=b.size();
        
        if(m < n) 
            return cmp(b,a)==true?false:true;
        i=0;
        j=0;
        while(i<m && j<n) {
            if(a[i] > b[j]) 
                return true;
            else if(a[i] < b[j]) {
                return false;
            }
            else {
                i++;
                j++;
            }
        }
        if(i==m)
            return false;
        return cmp(a.substr(i),b);
    }
    string largestNumber(vector<int> &num) {
        string ret="",temps;
        vector<string> store;
        int i,len=num.size(),tempv;
        
        if(len==0)
            return ret;
        for(i=0;i<len;++i) {
            tempv = num[i];
            temps = "";
            if(tempv == 0)
                temps.insert(temps.begin(),tempv+'0');
            else {
                while(tempv) {
                    temps.insert(temps.begin(),tempv%10+'0');
                    tempv = tempv/10;
                }
            }
            store.push_back(temps);
        }
        sort(store.begin(),store.end(),cmp);
        if(store[0]=="0")
            return "0";
        for(i=0;i<store.size();++i) {
            ret=ret+store[i];
        }
        return ret;
    }
};

int main() {
    Solution solu;
    vector<int> input(15,0);
    //input.push_back(3);
    //input.push_back(30);
    //input.push_back(34);
    //input.push_back(5);
    //input.push_back(9);
    cout<<solu.largestNumber(input)<<endl;
    return 0;
}
