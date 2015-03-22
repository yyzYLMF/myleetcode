/*
 * @yang 2015/3/16
 *
 * Validate if a given string is numeric.
 *
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 */
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//endless wrong answer
class Solution {
    public:
    bool isNumber(string s) {
        int i,ispoint=0,head;
        if(s.empty())
            return false;
        
        for(i=0;i<s.size();++i)
            if(s[i]!=' ')
                break;
        if(i==s.size())
            return false;
        
        head=i;
        for(; i<s.size(); ++i) {
            if(s[i] >= '0' && s[i] <= '9')
                continue;
            else if(s[i] == '+' && i==0) {
                if(i+1==s.size() || s[i+1]=='e' || s[i+1]==' ')
                    break;
            }
            else if(s[i] == '-' && i==head) {
                if(i+1==s.size() || s[i+1]=='e' || s[i+1]==' ' || s[i+1]=='.')
                    break;
            }
            else if(s[i] == '.' && ispoint == 0) {
                ispoint=1;
                if(i==head && (i+1==s.size()||s[i+1]=='e'|| s[i+1]==' ') || s[i+1]=='-')
                    break;
            }
            else if(s[i] == 'e' && i!=head) {
                ispoint=0;
                head = i+1;
                if(i+1 == s.size() || s[i+1]=='e' ||s[i+1]==' ')
                    break;
            }
            else
                break;
        }
        while(i!=s.size()) {
            if(s[i]!=' ')
                break;
            ++i;
        }
        if(i == s.size())
            return true;
        else
            return false;
    }
};

class Solution2 {
    public:
    bool isNumber(string s) {
        int left = 0, right = s.size() - 1;
        while (left <= right && s[left] == ' ') {
            left++;
        }
        while (left <= right && s[right] == ' ') {
            right--;
        }
        if (left > right) {
            return false;
        }
        if (left < right && (s[left] == '+' || s[left] == '-')) {
            left++;
        }
        bool isDot = false;
        bool isExp = false;
        bool isLeft = false, isRight = false;
        for (int i = left; i <= right; i++) {
            if (s[i] == '.') {
                if (isDot || isExp) {
                    return false;
                }
                isDot = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (!isLeft || isExp) {
                    return false;
                }
                isExp = true;
            } else if (s[i] == '+' || s[i] == '-') {
                if (!(s[i - 1] == 'e' || s[i - 1] == 'E')) {
                    return false;
                }
            } else if (s[i] >= '0' && s[i] <= '9') {
                if (isExp) {
                    isRight = true;
                } else {
                    isLeft = true;
                }
            } else {
                return false;
            }
        }
        if (!isLeft || (isExp && !isRight)) {
            return false;
        }
        return true;
    }
};

int main() {
    string s;
    Solution2 solu;

    while(getline(cin,s)) {
        cout<<solu.isNumber(s)<<endl;
    }
    return 0;
}
