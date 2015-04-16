/*
 * @yang 2015/4/16
 *
 * Question:
 *
 * Given an input string, reverse the string word by word.
 *
 * For example,
 *
 * Given s = "the sky is blue",
 *
 * return "blue is sky the".
 *
 * No extra space.
 */
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
    public:
    void rotate(string &nums, int n, int k) {
        int step,first,new_first,last,next;
        step = k%n;
        //cout<<"rotate: "<<nums<<" "<<n<<" "<<k<<endl;
        if(step==0 || n<=1)
            return;
        first = 0;
        new_first = n-step;
        last = n;
        next = new_first;
        while(first != next) {
            swap((nums[first]),(nums[next]));
            first++;
            next++;
            if(next == last)
                next = new_first;
            else if(first == new_first)
                new_first = next;
        }
        return;
    }
    void reverseWords(string &s) {
        bool blank=true;
        int i,j,len=s.size(),newlen,count;
        for(i=0,j=0;i<len;++i) {
            if(s[i]==' ') {
                if(blank!=true){
                    s[j]=s[i];
                    blank = true;
                    j++;
                }
            }
            else {
                s[j]=s[i];
                j++;
                blank = false;
            }
        }
        if(s[j-1]!=' ') {
            if(j>=len)
                s.insert(s.end(),' ');
            else
                s[j]=' ';
        }
        else
            j--;
        s.erase(j+1);
        //cout<<"|"<<s<<endl;
        newlen=s.size();
        count=0;
        //cout<<"new len: "<<newlen<<endl;
        for(i=0;i<newlen-1;++i) {
            if(s[i]==' ') {
                if(count+i+1>=newlen)
                    break;
                rotate(s,newlen-count,newlen-count-i-1);
                //cout<<"Fin:|"<<s<<"|"<<i+1<<endl;
                count+=i+1;
                i=0;
                //cout<<"count "<<count<<endl;
            }
        }
        s.erase(newlen-1);
        return;
    }
};

int main() {
    string s;
    Solution solu;
    while(getline(cin,s)) {
        solu.reverseWords(s);
        cout<<s<<endl;
    }
    return 0;
}
