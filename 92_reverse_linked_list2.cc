/*
 * @yang 2015/3/23
 *
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *preHead=NULL,*p,*q,*nextNode=NULL;
        ListNode *reverse,*temp,*nexttemp;
        int count;

        if(m==n)
            return head;
        count=1;
        q=head;
        while(count<n) {
            if(count+1 == m)
                preHead=q;
            if(count == m)
                p=q;
            count++;
            q=q->next;
        }
        nextNode=q->next;
        temp=p;
        reverse=NULL;
        while(temp!=q) {
            nexttemp=temp->next;
            temp->next=reverse;
            reverse=temp;
            temp=nexttemp;
        }
        q->next=reverse;
        if(preHead==NULL)
            head = q;
        else
            preHead->next = q;
        p->next = nextNode;
        return head;
    }
};

int main() {
    Solution solu;
    return 0;
}
