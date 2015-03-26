/*
 * @yang 2015/3/26
 *
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 */
#include <iostream>
#include <cstdlib>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL) {}
};

class Solution {
    public:
    TreeNode *build(ListNode *head, int num) {
        TreeNode *tempNode;
        ListNode *p;
        int mid,count;
        if(num<=0)
            return NULL;
        if(num==1) {
            tempNode = new TreeNode(head->val);
            return tempNode;
        }
        mid = num/2;
        p=head;
        count=0;
        while(p) {
            p=p->next;
            count++;
            if(count==mid)
                break;
        }
        tempNode =new TreeNode(p->val);
        tempNode->left = build(head,num/2);
        if(num%2==1)
            tempNode->right = build(p->next,num/2);
        else
            tempNode->right = build(p->next,num/2-1);
        return tempNode;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        int count=0;
        ListNode *p=head;
        while(p) {
            count++;
            p=p->next;
        }
        if(count==0)
            return NULL;
        return build(head,count);
    }
};

int main() {
    Solution solu;
    return 0;
}
