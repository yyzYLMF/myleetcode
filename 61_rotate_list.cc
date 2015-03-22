/*
 * @yang 2015/3/14
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 *
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 */
#include <iostream>
#include <cstdlib>
using namespace std;

class ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *q;
        int i,size=1;
        
        if(head==NULL || head->next==NULL || k==0)
            return head;
        q=head;
        while(q->next != NULL) {
            size++;
            q=q->next;
        }
        k=k%size;
        q->next = head;
        i=0;
        while(i<size-k) {
            q=q->next;
        }
        head = q->next;
        q->next=NULL;
        return head;
    }
};
