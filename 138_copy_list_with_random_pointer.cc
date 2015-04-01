/*
 * @yang 2015/4/1
 *
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 */
#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
    public:
    map<RandomListNode*,int> sign;
    map<RandomListNode*,RandomListNode*> store;
    
    void traverse(RandomListNode *head, RandomListNode *&copy) {
        copy = new RandomListNode(head->label);
        sign[head] = 1;
        store[head] = copy;

        RandomListNode *tempNode;
        if(head->next) {
            if(sign[head->next])
                tempNode = store[head->next];
            else
                traverse(head->next,tempNode);
        }
        else
            tempNode = NULL;
        copy->next = tempNode;

        RandomListNode *tempRandom;
        if(head->random) {
            if(sign[head->random])
                tempRandom = store[head->random];
            else
                traverse(head->random,tempRandom);
        }
        else
            tempRandom = NULL;
        copy->random = tempRandom;
        return;
    }

    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *copy;
        if(head==NULL)
            return NULL;
        traverse(head,copy);
        return copy;
    }
};

int main() {
    Solution solu;
    return 0;
}
