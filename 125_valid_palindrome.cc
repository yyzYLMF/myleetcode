/*
 * @yang 2015/3/29
 *
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
    bool isPalindrome(string s) {
        vector<char> vc;
        int i,j;
        for(i=0;i<s.size();++i) {
            if(isalnum(s[i]))
                vc.push_back(tolower(s[i]));
        }
        if(vc.size()==0)
            return true;
        i=0;
        j=vc.size()-1;
        while(i<=j) {
            if(vc[i]!=vc[j])
                break;
            i++;
            j--;
        }
        if(i<=j)
            return false;
        else
            return true;
    }
};

int main() {
    Solution solu;
    string s;
    while(getline(cin,s)) {
        cout<<solu.isPalindrome(s)<<endl;
    }
    return 0;
}
