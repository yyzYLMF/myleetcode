/*
 * @yang 2015/3/17
 *
 * Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
 *
 * You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 *
 * Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
 *
 * For the last line of text, it should be left justified and no extra space is inserted between words.
 *
 * For example,
 * words: ["This", "is", "an", "example", "of", "text", "justification."]
 * L: 16.
 Return the formatted lines as:
 [
 "This    is    an",
 "example  of text",
 "justification.  "
 ]
 * Note: Each word is guaranteed not to exceed L in length.
 * Corner Cases:
 * A line other than the last line might contain only one word. What should you do in this case?
 * In this case, that line should be left-justified.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        int i=0,j,k,surplus,space,extra,add_more,count;
        string temp;

        while(i<words.size()) {
            surplus=L;
            space=0;
            temp="";
            for(j=i; j<words.size(); ++j) {
                if(j==i) {
                    temp = words[j];
                    space=1;
                    surplus = surplus - words[j].size();
                }
                else {
                    temp=temp + " " + words[j];
                    space++;
                    surplus = surplus - words[j].size()-1;
                }
                if(j+1 == words.size()) {
                    temp.insert(temp.end(), surplus, ' ');
                    break;
                }
                if(words[j+1].size()+1 > surplus) {
                    if(space > 1)
                        space--;
                    else if(space == 1) {
                        temp.insert(temp.end(), surplus, ' ');
                        break;
                    }
                    add_more = surplus%space;
                    extra = surplus/space;
                    count=0;
                    for(k=0;k<temp.size();++k) {
                        if(temp[k] == ' ') {
                            count++;
                            if(count<=add_more) {
                                temp.insert(k,extra+1,' ');
                                k+=extra+1;
                            }
                            else {
                                temp.insert(k,extra,' ');
                                k+=extra;
                            }
                        }
                    }
                    break;
                }
            }
            result.push_back(temp);
            j++;
            i=j;
        }
        return result;
    }
};

int main() {
    Solution solu;
    vector<string> input,input2;
    vector<string> result;
    input.push_back("this");
    input.push_back("is");
    input.push_back("hello");
    input.push_back("vector++string");
    input.push_back("hello");
    input2.push_back("");
    result = solu.fullJustify(input2,2);
    for(int i=0; i<result.size(); ++i)
        cout<<result[i]<<"|"<<result[i].size()<<endl;
    return 0;
}
