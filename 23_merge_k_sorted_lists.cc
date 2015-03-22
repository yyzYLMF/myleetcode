/*
@yang 2015/3/6

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

*/
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode(int x): val(x), next(NULL) {}
};

class Solution {
    public:
    typedef vector<ListNode*>::size_type mytype;

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head, *end;
        ListNode *p=l1, *q=l2;

        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;

        if(p->val <= q->val) {
            head = p;
            end = p;
            p=p->next;
        }
        else {
            head = q;
            end = q;
            q=q->next;
        }
        while(p!=NULL && q!=NULL) {
            if(p->val <= q->val) {
                end->next = p;
                end=p;
                p=p->next;
            }
            else {
                end->next = q;
                end=q;
                q=q->next;
            }
        }
        if(p == NULL)
            end->next = q;
        else if(q == NULL)
            end->next = p;
        return head;
    }

    ListNode *mymerge(vector<ListNode *> &lists, mytype head, mytype end) {
        mytype mid;
        ListNode *left,*right,*result;

        if(head == end)
            return lists[head];
        else if(head+1 == end)
            return mergeTwoLists(lists[head],lists[end]);
        else {
            mid = (head+end)/2;
            left = mymerge(lists, head, mid);
            right = mymerge(lists, mid+1, end);
            result = mergeTwoLists(left,right);
            return result;
        }
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        mytype head,end,mid;
        ListNode *left, *right,*result=NULL;

        if(lists.size() == 0)
            return result;
        else if(lists.size() == 1)
            return lists[0];
        head = 0;
        end = lists.size()-1;
        mid = (head+end)/2;
    
        left = mymerge(lists, head, mid);
        right = mymerge(lists, mid+1, end);
        result = mergeTwoLists(left,right);
        return result;
    }
};
