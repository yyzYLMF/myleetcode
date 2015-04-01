/*
 * @yang 2015/4/1
 *
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 * Follow up:
 * Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
        int cyclenum;
        ListNode *fast,*slow;
        fast = head;
        slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                slow = slow->next;
                cyclenum = 1;
                while(slow!=fast) {
                    slow = slow->next;
                    cyclenum++;
                }
                break;
            }
        }
        if(fast==NULL || fast->next==NULL)
            return NULL;
        fast = head;
        slow = head;
        for(int i=0;i<cyclenum;++i)
            fast = fast->next;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main() {
    Solution solu;
    return 0;
}
