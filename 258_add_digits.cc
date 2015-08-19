#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
    public:
    int addDigits(int num) {
        return (num-1)%9+1;
    }
};

class Solution2 {
    public:
    int addDigits(int num) {
        int ret,temp;
        if(num < 10)
            return num;
        ret = num;
        while(ret >= 10) {
            temp = ret;
            ret = 0;
            while(temp) {
                ret += temp%10;
                temp = temp/10;
            }
        }
        return ret;
    }
};

int main() {
    Solution solu;
    return 0;
}
