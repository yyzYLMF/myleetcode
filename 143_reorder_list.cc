/*
 * @yang 2015/4/2
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode *head) {
        ListNode *end,*left,*right,*temp,*reorder=NULL;
        int i,count;
        if(head == NULL || head->next==NULL)
            return;
        end = head;
        count=0;
        while(end->next) {
            end = end->next;
            count++;
        }
        right = head;
        for(i=0;i<count/2;++i)
            right = right->next;
        temp = right->next;
        right->next = NULL;
        right = temp;
        while(right!=end) {
            temp = right->next;
            right->next = reorder;
            reorder = right;
            right = temp;
        }
        end->next = reorder;
        reorder=end;
        left = head;
        right = reorder;
        for(i=0;i<count;++i) {
            if(i%2==0) {
                temp = left->next;
                left->next = right;
                left = temp;
            }
            else {
                temp = right->next;
                right->next = left;
                right = temp;
            }
        }
        return;
    }
};

int main() {
    Solution solu;
    ListNode *a=new ListNode(1);
    ListNode *b=new ListNode(2);
    ListNode *c=new ListNode(3);
    a->next = b;
    b->next = c;
    solu.reorderList(a);
    cout<<a->next->val<<endl;
    return 0;
}
