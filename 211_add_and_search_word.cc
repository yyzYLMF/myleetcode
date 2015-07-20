/*
 * @yang 2015/7/20
 *
 * Design a data structure that supports the following two operations:
 *
 * void addWord(word)
 * bool search(word)
 * search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
 *
 * For example:
 *
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 */

#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

class WordDictionary {
public:
    class Trie {
        public:
        bool isTrue;
        map<char,Trie*> store;
        
        Trie():isTrue(false){}
    };
    
    WordDictionary() {
        root = new Trie();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        int i;
        if(word.size() == 0)
            return;
        Trie* pos = root;
        for(i=0;i<word.size();++i) {
            if(pos->store.find(word[i]) != pos->store.end()) {
                pos = pos->store[word[i]];
            }
            else {
                Trie* add = new Trie();
                pos->store[word[i]] = add;
                pos = pos->store[word[i]];
            }
            if(i == word.size()-1)
                pos->isTrue = true;
        }
        return;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if(word.size() == 0)
            return true;
        return mysearch(word,0,root);
    }

    bool mysearch(string &word, int n, Trie* root) {
        int i;
        Trie* pos=root;
        if(n >= word.size()) {
            if(pos->isTrue)
                return true;
            else 
                return false;
        }
        for(i=n;i<word.size();++i) {
            if(word[i]!='.') {
                if(pos->store.find(word[i]) != pos->store.end()) {
                    pos = pos->store[word[i]];
                }
                else
                    return false;
            }
            else {
                map<char,Trie*>::iterator iter = pos->store.begin();
                while(iter != pos->store.end()) {
                    if(mysearch(word,i+1,iter->second))
                        return true;
                    iter++;
                }
                return false;
            }
        }
        if(pos->isTrue)
            return true;
        else
            return false;
    }
private:
    Trie* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main() {
    WordDictionary wd;
    wd.addWord("wabd");
    cout<<wd.search("w..d")<<endl;

    return 0;
}
