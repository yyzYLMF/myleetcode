/*
@yang 2015/3/6

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

*/
#include <iostream>
#include <cstdlib>
class ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL) {}
};

class Solution {
    public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head, *end;
        ListNode *p=l1, *q=l2;

        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;

        if(p->val <= q->val) {
            head = p;
            end = p;
            p=p->next;
        }
        else {
            head = q;
            end = q;
            q=q->next;
        }
        while(p!=NULL && q!=NULL) {
            if(p->val <= q->val) {
                end->next = p;
                end=p;
                p=p->next;
            }
            else {
                end->next = q;
                end=q;
                q=q->next;
            }
        }
        if(p == NULL)
            end->next = q;
        else if(q == NULL)
            end->next = p;
        return head;
    }
};
