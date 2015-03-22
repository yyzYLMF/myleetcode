/*
   @yang 2015/3/5

   Given a linked list, remove the nth node from the end of list and return its head.

   For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/
#include <iostream>
#include <cstdlib>
using namespace std;

class ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL){}
};

class Solution {
    public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p,*q,*temp;
        int i;
        
        if(head == NULL || n<1)
            return head;
        temp=head;
        for(i=1;i<n;++i){
            temp=temp->next;
        }
        p=head;
        q=head;
        if(temp->next == NULL)
            return head->next;
        else {
            q=head->next;
            temp=temp->next;
            while(temp->next!=NULL){
                temp=temp->next;
                q=q->next;
                p=p->next;
            }
            p->next=q->next;
            return head;
        }
    }
};
