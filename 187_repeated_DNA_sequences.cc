/*
 * @yang 2015/4/9
 *
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
 *
 * Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
 *
 * For example,
 Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

 Return:
 ["AAAAACCCCC", "CCCCCAAAAA"].
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

//Memory Limit Exceeded
class Solution {
    public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> smap;
        vector<string> ret;
        int len=s.size(),i;
        map<string,int>::iterator pos;
        string temp;
        if(len<=10)
            return ret;
        for(i=0;i<=len-10;++i) {
            temp=s.substr(i,10);
            smap[temp]++;
        }
        pos = smap.begin();
        while(pos!=smap.end()) {
            if(pos->second > 1)
                ret.push_back(pos->first);
            pos++;
        }
        return ret;
    }
};

//AC, the code can be optimized
class Solution2 {
    public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<char,int> mymap;
        set<int> presented;
        set<int> hasStored;
        vector<string> ret;
        int len=s.size(),i,hash;
        if(len <= 10)
            return ret;
        mymap['A']=0;
        mymap['T']=1;
        mymap['C']=2;
        mymap['G']=3;
        hash=0;
        for(i=0;i<9;++i)
            hash=(hash<<2)+mymap[s[i]];
        for(;i<len;++i) {
            hash=((hash<<2)+mymap[s[i]]) & 0x000fffff;
            if(presented.count(hash) && !hasStored.count(hash)) {
                ret.push_back(s.substr(i-9,10));
                hasStored.insert(hash);
            }
            if(!presented.count(hash))
                presented.insert(hash);
        }
        return ret;
    }
};

int main() {
    Solution solu;
    return 0;
}
