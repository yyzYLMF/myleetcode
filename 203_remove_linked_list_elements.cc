/*
 * @yang 2015/4/23
 *
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pos;
        if(head==NULL)
            return head;
        if(head->next==NULL) {
            if(head->val == val)
                return NULL;
            else 
                return head;
        }
        pos=head;
        while(pos!=NULL && pos->val == val)
            pos=pos->next;
        if(pos==NULL)
            return NULL;
        else
            head=pos;
        while(pos->next != NULL) {
            if(pos->next->val == val) {
                pos->next = pos->next->next;
            }
            else
                pos=pos->next;
        }
        return head;
    }
};

int main() {
    Solution solu;
    return 0;
}
