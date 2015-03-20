/*
 * @yang 2015/3/20
 *
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
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
		ListNode *last,*p,*q;

		if(head==NULL || head->next==NULL)
			return head;
		last=NULL;
		p=head;
		q=head->next;
		while(q!=NULL) {
			if(p->val != q->val) {
				if(last!=NULL) {
					last->next = p;
					last=last->next;
				}
				else 
					last=p;
				p=q;
				q=q->next;
			}
			else
				q=q->next;
		}
		if(last!=NULL) {
			last->next=p;
			last=last->next;
		}
		else
			last=p;
		last->next=NULL;
		return head;
	}
};

int main() {
	Solution solu;
	return 0;
}
