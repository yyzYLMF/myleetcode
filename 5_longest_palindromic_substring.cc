/*
   @yang 2015/3/3

   Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
   palindromic string is like "aa" "abc "abccba"

 */
#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            string::iterator left, right, pos;
            int longest=0, length;
            string result;

            for(pos=s.begin(); pos!=s.end(); ++pos) {
                length = 1;
                left = pos - 1;
                right = pos + 1;
                while(left >= s.begin() && right != s.end() && (*left) == (*right)) {
                    length = length+2;
                    left--;
                    right++;
                }
                if(length > longest) {
                    longest = length;
                    result = string(left+1,right);
                }

                if(pos+1 != s.end() && *pos == *(pos+1)) {
                    length = 2;
                    left = pos -1;
                    right = pos + 2;
                    while(left >= s.begin() && right != s.end() && *left == *right) {
                        length += 2;
                        left--;
                        right++;
                    }
                    if(length > longest) {
                        longest = length;
                        result = string(left+1, right);
                    }
                }
            }
            return result;
        }
};

//Manacher algorithm, add # is perfect
class Solution2 {
    public:
        string longestPalindrome(string s) {
            if (s.size() == 0) return s;
            int i, n = 2 * s.size() + 1;
            int f[n], mid, right, pos, len;
            char str[n];
            for (i = 0, str[n - 1] = '#'; i < s.size(); i++){
                str[i * 2] = '#';
                str[i * 2 + 1] = s[i];
            }
            f[0] = 0;
            mid = right = 0;
            pos = 0; len = 1;
            for (i = 1; i < n; i++){
                if (right > i){
                    f[i] = min(f[mid - i + mid], right - i);
                }else 
                    f[i] = 0;
                while (i - f[i] - 1 >= 0 && i + f[i] + 1 < n && str[i - f[i] - 1] == str[i + f[i] + 1]) 
                    f[i]++;
                if (len < f[i]){
                    len = f[i];
                    pos = (i - f[i]) / 2;
                }
                if (right < i + f[i]){
                    mid = i;
                    right = i + f[i];
                }
            }
            return s.substr(pos, len);
        }
};


int main() {
    string s("asdfasdfabcdefgfedcbaasdf");
    string result;
    Solution solu;
    Solution2 solu2;

    result = solu.longestPalindrome(s);
    cout<<"palindromic string: "<<result<<endl;
    result = solu2.longestPalindrome(s);
    cout<<"palindromic string: "<<result<<endl;
    return 0;
}
