/*
@yang 2015/3/6

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

*/
#include <iostream>
#include <cstdlib>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode(int x): val(x), next(NULL) {}
};

class Solution {
    public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *p, *q, *last;

        if(head == NULL)
            return head;
        else if(head->next == NULL)
            return head;
        p = head;
        q = head->next;
        last = head;
        while(q!=NULL) {
            p->next = q->next;
            q->next = p;
            if(last == head) {
                head = q;
                last = p;
            }
            else {
                last->next = q;
                last = p;
            }    

            p=p->next;
            if(p!=NULL)
                q=p->next;
            else
                break;
        }
        return head;
    }
};

int main() {
    ListNode *rhead,*temp,*head;
    Solution solu;
    ListNode *result;

    rhead = new ListNode(1);
    head = rhead;
    temp = new ListNode(2);
    head->next = temp;
    head = temp;
    temp = new ListNode(3);
    head->next = temp;
    head = temp;
    temp = new ListNode(4);
    head->next = temp;
    head = temp;

    result = solu.swapPairs(rhead);
    while(result!=NULL){
        cout<<result->val<<" ";
        result = result->next;
    }
    return 0;
}
