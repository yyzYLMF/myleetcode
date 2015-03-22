#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

class Solution {
    public:
        void reverseWords(string &s) {
            istringstream is(s);
            string tmp="";
            string out="";
            while(is>>tmp){
                tmp+=" ";
                tmp+=out;
                out=tmp;
            }
            s=out.substr(0,out.length()-1);
            cout<<"s: "<<s.length()<<endl;
        }
};

int main()
{
    string s;
    Solution solu;
    getline(cin,s);

    solu.reverseWords(s);
    return 0;
}
