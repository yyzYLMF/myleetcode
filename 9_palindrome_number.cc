/*
@yang 2015/3/4

Determine whether an integer is a palindrome. Do this without extra space.

*/
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    bool isPalindrome(int x) {
        vector<int> ivec;
        int temp;
        vector<int>::iterator head,tail;

        if(x<0)
            return false;
        
        temp=x;
        while(temp!=0) {
            ivec.push_back(temp%10);
            temp = temp/10;
        }
        if(ivec.size() == 0)
            ivec.push_back(0);

        head = ivec.begin();
        tail = ivec.end()-1;
        while(head<=tail) {
            if(*head != *tail)
                break;
            head++;
            tail--;
        }
        if(head <= tail)
            return false;
        else 
            return true;
    }
};

int main() {
    Solution solu;
    int a=12321, b=0, c=-1;

    cout<<solu.isPalindrome(a)<<endl;
    cout<<solu.isPalindrome(b)<<endl;
    cout<<solu.isPalindrome(c)<<endl;

    return 0;
}
