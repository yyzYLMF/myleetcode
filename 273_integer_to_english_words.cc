#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;

class Solution {
    public:
    void myadd(string &ret, int num) {
        int temp;
        temp = num/100;
        if(temp > 0) {
            ret += sign1[temp]+" "+"Hundred ";
            num = num - temp*100;
        }
        if(num == 0)
            return;
        if(num<=19) {
            ret+=sign1[num]+" ";
        }
        else {
            if(num%10 == 0)
                ret += sign2[num/10]+" ";
            else
                ret += sign2[num/10]+" "+sign1[num%10]+" ";
        }
    }

    string numberToWords(int num) {
        int myconst[3];
        myconst[0] = 1000000000;
        myconst[1] = 1000000;
        myconst[2] = 1000;
        myconst[3] = 1;
        string ret="";
        
        sign1[1] = "One";
        sign1[2] = "Two";
        sign1[3] = "Three";
        sign1[4] = "Four";
        sign1[5] = "Five";
        sign1[6] = "Six";
        sign1[7] = "Seven";
        sign1[8] = "Eight";
        sign1[9] = "Nine";
        sign1[10] = "Ten";
        sign1[11] = "Eleven";
        sign1[12] = "Twelve";
        sign1[13] = "Thirteen";
        sign1[14] = "Fourteen";
        sign1[15] = "Fifteen";
        sign1[16] = "Sixteen";
        sign1[17] = "Seventeen";
        sign1[18] = "Eighteen";
        sign1[19] = "Nineteen";
        sign2[2] = "Twenty";
        sign2[3] = "Thirty";
        sign2[4] = "Forty";
        sign2[5] = "Fifty";
        sign2[6] = "Sixty";
        sign2[7] = "Seventy";
        sign2[8] = "Eighty";
        sign2[9] = "Ninety";

        if(num == 0) {
            ret = "Zero";
            return ret;
        }

        int i=0,temp;
        for(i=0;i<4;++i) {
            temp = num/myconst[i];
            if(temp > 0) {
                myadd(ret,temp);
                switch(i) {
                    case 0:
                        ret +="Billion ";
                        break;
                    case 1:
                        ret +="Million ";
                        break;
                    case 2:
                        ret +="Thousand ";
                        break;
                    default:
                        break;
                }
                num = num - temp*myconst[i];
            }
        }
        ret.erase(ret.end()-1);
        return ret;
    }
    private:
    map<int,string> sign1;
    map<int,string> sign2;
};

int main() {
    Solution solu;
    int input;
    cin>>input;
    cout<<solu.numberToWords(input)<<endl;
    return 0;
}
