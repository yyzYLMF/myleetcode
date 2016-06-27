#include <iostream>
#include <cstdlib>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL) {}
};

class Solution2 {
    public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newlist,*p,*next;
        if(head == NULL || head->next == NULL)
            return head;
        p = head;
        newlist = NULL;
        while(p!=NULL) {
            next = p->next;
            p->next = newlist;
            newlist = p;
            p = next;
        }
        return newlist;
    }
};

class Solution {
    public:
    ListNode* reverseList(ListNode* head) {
        ListNode *sublist,*p,*q;
        if(head==NULL || head->next==NULL)
            return head;
        p = head;
        q = p->next;
        p->next = NULL;
        sublist = NULL;
        if(q != NULL) 
            sublist = reverseList(q);
        if(sublist != NULL) {
            q->next = p;
            return sublist;
        }
        else {
            return p;
        }
    }
};

int main() {
    Solution solu;
    return 0;
}
