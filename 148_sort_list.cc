/*
 * @yang 2015/4/2
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode *mymerge(ListNode *left, ListNode *right) {
        ListNode *head=NULL,*tail,*p,*q;
        p=left;
        q=right;
        while(p!=NULL && q!=NULL) {
            if(p->val <= q->val) {
                if(head==NULL) {
                    head = p;
                    tail = p;
                }
                else {
                    tail->next = p;
                    tail = p;
                }
                p = p->next;
            }
            else {
                if(head == NULL) {
                    head = q;
                    tail = q;
                }
                else {
                    tail->next = q;
                    tail = q;
                }
                q=q->next;
            }
        }
        if(p==NULL) 
            tail->next = q;
        else
            tail->next = p;
        return head;
    }

    ListNode *sortList(ListNode *head) {
        ListNode *temp,*left,*right;
        int count,i;
        if(head==NULL || head->next==NULL)
            return head;
        temp = head;
        count = 1;
        while(temp->next) {
            temp = temp->next;
            count++;
        }
        if(count == 2) {
            if(head->val < head->next->val) {
                temp = head->next;
                temp->next = head;
                head->next = NULL;
                return temp;
            }
            else
                return head;
        }
        //right is find the last one in the left part, temp is the head in right part
        right=head;
        for(i=1;i<count/2;++i)
            right = right->next;
        temp = right->next;
        right->next = NULL;

        left = sortList(head);
        right = sortList(temp);
        return mymerge(left,right);
    }
};

int main() {
    Solution solu;
    return 0;
}
