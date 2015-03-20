/*
 * @yang 2015/3/20
 *
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 */
#include <iostream>
#include <cstdlib>
using namespace std;

class ListNode {
	public:
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution {
	public:
	ListNode *partition(ListNode *head, int x) {
		ListNode *lhead,*ltail,*rhead,*rtail,*p;

		if(head==NULL || head->next==NULL)
			return head;
		lhead=ltail=NULL;
		rhead=rtail=NULL;
		p=head;
		while(p!=NULL) {
			if(p->val < x) {
				if(lhead==NULL) {
					lhead=p;
					ltail=p;
				}
				else {
					ltail->next=p;
					ltail=ltail->next;
				}
			}
			else {
				if(rhead==NULL) {
					rhead=p;
					rtail=p;
				}
				else {
					rtail->next=p;
					rtail=rtail->next;
				}
			}
			p=p->next;
		}
		if(lhead!=NULL) 
			ltail->next=rhead;
		if(rhead!=NULL)
			rtail->next=NULL;
		if(lhead!=NULL)
			return lhead;
		else
			return rhead;
	}
};

int main() {
	Solution solu;
	return 0;
}
