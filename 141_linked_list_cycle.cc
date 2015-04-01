/*
 * @yang 2015/4/1
 *
 * Given a linked list, determine if it has a cycle in it.
 *
 * Follow up:
 * Can you solve it without using extra space?
 */
#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//use map
class Solution {
    public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,int> sign;
        ListNode *p;
        if(head == NULL)
            return false;
        p=head;
        while(p) {
            if(sign[p])
                return true;
            sign[p]=1;
            p=p->next;
        }
        return false;
    }
};

//without extra space;
class Solution2 {
    public:
    bool hasCycle(ListNode *head) {
        ListNode *fast,*slow;
        fast=head;
        slow=head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};

int main() {
    Solution solu;
    return 0;
}
