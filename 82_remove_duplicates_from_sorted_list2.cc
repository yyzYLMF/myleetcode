/*
 * @yang 2015/3/20
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
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
	ListNode *deleteDuplicates(ListNode *head) {
		ListNode *last,*p,*q,*first;
		if(head == NULL || head->next==NULL)
			return head;
		first=NULL;
		last=NULL;
		p=head;
		q=head->next;
		while(q!=NULL) {
			if(p->val != q->val) {
				if(p->next == q) {
					if(last==NULL) {
						first = p;
						last = p;
					}
					else {
						last->next = p;
						last=last->next;
					}
				}
				p=q;
				q=q->next;
			}
			else {
				q=q->next;
			}
		}
		if(p->next == q) {
			if(last==NULL)
				first=p;
			else
				last->next=p;
		}
		else {
			if(last!=NULL)
				last->next=NULL;
		}
		return first;
	}
};

int main() {
	Solution solu;
	return 0;
}
