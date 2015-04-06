/*
 * @yang 2015/4/4
 *
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 * For example, the following two linked lists:
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
 * begin to intersect at node c1.
 *
 * Notes:
 *
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 */
#include <iostream>
#include <cstdlib>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p,*q;
        int count1,count2;
        if(headA==NULL || headB==NULL)
            return NULL;
        p=headA;
        count1=1;
        while(p->next) {
            p=p->next;
            count1++;
        }
        q=headB;
        count2=1;
        while(q->next) {
            q=q->next;
            count2++;
        }
        if(p!=q)
            return NULL;
        p=headA;
        q=headB;
        if(count1 > count2) {
            for(int i=0;i<count1-count2;++i)
                p=p->next;
        }
        else if(count1 < count2) {
            for(int i=0;i<count2-count1;++i)
                q=q->next;
        }
        while(p!=q) {
            p=p->next;
            q=q->next;
        }
        return p;
    }
};

int main() {
    Solution solu;
    return 0;
}
