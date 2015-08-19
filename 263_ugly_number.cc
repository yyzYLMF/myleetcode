#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
    public:
    bool isUgly(int num) {
        if(num <= 0)
            return false;
        if(num == 1)
            return true;
        while(num%2 == 0) 
            num = num/2;
        while(num%3 == 0)
            num = num/3;
        while(num%5 == 0)
            num = num/5;
        if(num == 1)
            return true;
        else
            return false;
    }
};

int main() {
    Solution solu;
    return 0;
}
