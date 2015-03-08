/*
@yang 2015/3/6

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

*/
#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

class ListNode {
	public:
		int val;
		ListNode* next;
		ListNode(int x): val(x), next(NULL) {}
};

class Solution {
	public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		ListNode *p, *q, *last1, *last2, *pNext, *sublist, *last1Next;
		int i;

		if(k<=1)
			return head;
		else if(head == NULL)
			return head;
		else if(head->next == NULL)
			return head;

		p=head;
		q=head;
		last1=head;
		last2=head;
		while(q!=NULL) {
			for(i=1;i<k;++i){
				q=q->next;
				if(q==NULL)
					break;
			}
			if(i!=k)
				return head;

			last2 = q->next;

			sublist = last2;
			last1Next = p;
			while(p!=q) {
				pNext = p->next;
				p->next = sublist;
				sublist = p;
				p = pNext;
			}
			q->next = sublist;

			if(last1 == head){
				head = q;
			}
			else {
				last1->next = q;
			}

			p=last2;
			q=p;
			last1 = last1Next;
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
	temp = new ListNode(5);
	head->next = temp;
	head = temp;
	
	result = solu.reverseKGroup(rhead,2);
	while(result!=NULL){
		cout<<result->val<<" ";
		result = result->next;
	}
	return 0;
}
