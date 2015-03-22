/*
@yang 2015/3/5

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
    typedef string::iterator index;

    void combination(vector<string> &result, map<char,string> &map, vector<char> stack, index head, index tail, char now) {
        
        stack.push_back(now);
        if(head == tail) {
            result.push_back(string(stack.begin(), stack.end()));
            return;
        }
        for(int i=0; i<map[*head].size(); ++i) {
            combination(result, map, stack, head+1, tail, map[*head][i]);
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        map<char,string> map;
        vector<string> result;
        index iter;
        vector<char> stack;

        map['2']=string("abc");
        map['3']=string("def");
        map['4']=string("ghi");
        map['5']=string("jkl");
        map['6']=string("mno");
        map['7']=string("pqrs");
        map['8']=string("tuv");
        map['9']=string("wxyz");

        if(digits.empty())
            return result;

        iter=digits.begin();
        for(int i=0; i<map[*iter].size(); ++i) {
            combination(result, map, stack, iter+1, digits.end(), map[*iter][i]);
        }
        return result;
    }
};

int main() {
    Solution solu;
    vector<string> result;
    string digits("23");

    result = solu.letterCombinations(digits);
    for(int i=0; i<result.size(); ++i){
        cout<<result[i]<<endl;
    }
    return 0;
}
