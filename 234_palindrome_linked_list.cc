/*
 * @yang 2015/7/26
 *
 * Given a singly linked list, determine if it is a palindrome.
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
    bool isPalindrome(ListNode* head) {
        ListNode *slow,*fast,*newhead,*next;
        if(head == NULL)
            return true;
        if(head->next == NULL)
            return true;
        slow = head;
        fast = head;
        while(fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        newhead = NULL;
        while(slow!=NULL) {
            next = slow->next;
            slow->next = newhead;
            newhead = slow;
            slow = next;
        }
        slow = head;
        fast = newhead;
        while(slow!=NULL && fast!=NULL) {
            if(slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};

int main() {
    Solution solu;
    return 0;
}
