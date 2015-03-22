/*
 * @yang 2015/3/14
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * For example, 
 * Given s = "Hello World",
 * return 5.
 */
#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
    public:
        int lengthOfLastWord(const char *s) {
            const char *p=s;
            int length=0,temp=0;

            if(*s == '\0')
                return 0;
            while(*p != '\0') {
                if(*p == ' ') {
                    if(length>0)
                        temp =length;
                    length = 0;
                }
                else 
                    length++;
                p++;
            }
            return length ? length:temp;
        }
};

int main() {
    char s[]="Helo ";
    Solution solu;

    cout<<solu.lengthOfLastWord(s)<<endl;
    return 0;
}
