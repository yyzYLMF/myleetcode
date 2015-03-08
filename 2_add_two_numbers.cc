/*
@yang 2015/3/2

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

*/

#include <iostream>
#include <cstdlib>
using namespace std;

//Definition for singly-linked list.
class ListNode {
	public:
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
	ListNode *myaddNode(ListNode *l, int val) {
		ListNode *p;
		p = new ListNode(val);
		p->next = l;
		return p;
	}

	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *result=NULL;
		int carry=0;
		ListNode *p,*q;

		p=l1;
		q=l2;
		while(p!=NULL && q!=NULL) {
			if(result == NULL) {
				result = new ListNode((p->val+q->val)%10);
				result->next = NULL;
				carry = (p->val+q->val)/10;
			}
			else {
				result = myaddNode(result, (p->val+q->val+carry)%10);
				carry = (p->val + q->val + carry)/10;
			}
			p=p->next;
			q=q->next;
		}
		if(p == NULL) {
			while(q!=NULL) {
				result = myaddNode(result, (q->val+carry)%10);
				carry = (q->val+carry)/10;
				q=q->next;
			}
		}
		else if(q == NULL) {
			while(p!=NULL) {
				result = myaddNode(result, (p->val+carry)%10);
				carry = (p->val+carry)/10;
				p=p->next;
			}
		}
		
		if(carry != 0)
			result = myaddNode(result, carry);

		ListNode *final_result=NULL;
		while(result!=NULL)
		{
			final_result = myaddNode(final_result, result->val);
			result = result->next;
		}
		return final_result;
	}
};

ListNode* addNode(ListNode *l, int val) {
	ListNode *p;
	p = new ListNode(val);
	p->next = l;
	return p;
}

int main()
{
	ListNode *l1=NULL, *l2=NULL;
	ListNode *result, *temp;
	Solution solu;

	l1=addNode(l1,1);
	l1=addNode(l1,8);
	//l1=addNode(l1,2);

	l2=addNode(l2,0);
	//l2=addNode(l2,6);
	//l2=addNode(l2,5);

	result = solu.addTwoNumbers(l1,l2);
	temp = result;
	while(temp!=NULL) {
		cout<<temp->val<<" ";
		temp = temp->next;
	}
	cout<<endl;
	return 0;
}
