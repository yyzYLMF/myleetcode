/*
 * @yang 2015/7/17
 * Implement a trie with insert, search, and startsWith methods.
 */

#include <iostream>
#include <cstdlib>
#include <map>
#include <set>
using namespace std;

class TrieNode {
    public:
    // Initialize your data structure here.
    TrieNode() : isTrue(false){

    }
    bool isTrue;
    set<char> search;
    map<char,TrieNode*> sign;
};

class Trie {
    public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int i,len;
        TrieNode *pos;
        len = word.size();
        if(len == 0)
            return;
        pos = root;
        for(i=0;i<len;++i) {
            if(pos->search.count(word[i]) != 0) {
                pos = pos->sign[word[i]];
            }
            else {
                TrieNode *temp = new TrieNode();
                pos->search.insert(word[i]);
                pos->sign[word[i]] = temp;
                pos = pos->sign[word[i]];
            }
            if(i == len-1)
                pos->isTrue = true;
        }
        return;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int i,len;
        TrieNode *pos;
        len = word.size();
        if(len == 0)
            return true;
        pos = root;
        for(i=0;i<len;++i) {
            if(pos->search.count(word[i]) != 0) {
                pos = pos->sign[word[i]];
            }
            else {
                return false;
            }
        }
        if(pos->isTrue == true)
            return true;
        else 
            return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int i,len;
        TrieNode *pos;
        len = prefix.size();
        if(len == 0)
            return true;
        pos = root;
        for(i=0;i<len;++i) {
            if(pos->search.count(prefix[i]) != 0) {
                pos = pos->sign[prefix[i]];
            }
            else {
                return false;
            }
        }
        return true;
    }

    private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main() {
    Trie myTrie;
    return 0;
}
