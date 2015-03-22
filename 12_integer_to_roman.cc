/*
@yang 2015/3/4

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
    string intToRoman(int num) {
        vector<string> svec[4];
        vector<string> temp;
        string result="";

        svec[0].push_back("");
        svec[0].push_back("I");
        svec[0].push_back("II");
        svec[0].push_back("III");
        svec[0].push_back("IV");
        svec[0].push_back("V");
        svec[0].push_back("VI");
        svec[0].push_back("VII");
        svec[0].push_back("VIII");
        svec[0].push_back("IX");

        svec[1].push_back("");
        svec[1].push_back("X");
        svec[1].push_back("XX");
        svec[1].push_back("XXX");
        svec[1].push_back("XL");
        svec[1].push_back("L");
        svec[1].push_back("LX");
        svec[1].push_back("LXX");
        svec[1].push_back("LXXX");
        svec[1].push_back("XC");

        svec[2].push_back("");
        svec[2].push_back("C");
        svec[2].push_back("CC");
        svec[2].push_back("CCC");
        svec[2].push_back("CD");
        svec[2].push_back("D");
        svec[2].push_back("DC");
        svec[2].push_back("DCC");
        svec[2].push_back("DCCC");
        svec[2].push_back("CM");

        svec[3].push_back("");
        svec[3].push_back("M");
        svec[3].push_back("MM");
        svec[3].push_back("MMM");

        int copy;
        int i=0;
        while(num!=0){
            copy=num%10;
            temp.push_back(svec[i][copy]);
            num=num/10;
            i++;
        }
        for(i=temp.size()-1; i>=0; --i)
            result+=temp[i];
        return result;
    }
};

int main() {
    Solution solu;
    int num;
    string result;

    while(cin>>num) {
        result = solu.intToRoman(num);
        cout<<result<<endl;
    }
    return 0;
}
