/*
 * @yang 2015/4/2
 *
 * Sort a linked list using insertion sort.
 */
#include <iostream>
#include <cstdlib>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL) {}
};

class Solution {
    public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *nextNode,*temp,*p,*q;
        if(head == NULL || head->next==NULL)
            return head;
        nextNode = head->next;
        head->next = NULL;
        while(nextNode) {
            temp = nextNode;
            nextNode = nextNode->next;
            p=head;
            q=NULL;
            while(p!=NULL && p->val < temp->val) {
                if(q==NULL)
                    q=p;
                else
                    q=q->next;
                p=p->next;
                    
            }
            if(p==head){
                temp->next = head;
                head = temp;
            }
            else if(p!=NULL) {
                temp->next = p;
                q->next = temp;
            }
            else {
                q->next=temp;
                temp->next=NULL;
            }
        }
        return head;
    }
};

int main() {
    Solution solu;
    ListNode *a=new ListNode(3);
    ListNode *b=new ListNode(2);
    ListNode *c=new ListNode(4);
    a->next = b;
    b->next = c;
    solu.insertionSortList(a);
    return 0;
}
