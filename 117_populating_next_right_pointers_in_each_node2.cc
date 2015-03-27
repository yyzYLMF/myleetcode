/*
 * @yang 2015/3/27
 *
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 *
 * What if the given tree could be any binary tree? Would your previous solution still work?
 */
#include <iostream>
#include <cstdlib>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
    public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *tempNode=NULL;
        TreeLinkNode *nextRoot=NULL;
        TreeLinkNode *nextNode=NULL;
        if(root==NULL)
            return;
        else if(root->left==NULL && root->right==NULL)
            return;
        if(root->left!=NULL && root->right!=NULL) {
            root->left->next = root->right;
            tempNode = root->right;
        }
        else 
            tempNode = root->left ? root->left:root->right;
        nextRoot = root->next;
        while(nextRoot) {
            if(nextRoot->left!=NULL && nextRoot->right!=NULL) {
                tempNode->next = nextRoot->left;
                nextRoot->left->next = nextRoot->right;
                tempNode = nextRoot->right;
            }
            else if(nextRoot->left!=NULL || nextRoot->right!=NULL) {
                nextNode = nextRoot->left ? nextRoot->left:nextRoot->right;
                tempNode->next = nextNode;
                tempNode = nextNode;
            }
            nextRoot=nextRoot->next;
        }
        if(root->left)
            connect(root->left);
        if(root->right)
            connect(root->right);
        return;
    }
};

int main() {
    Solution solu;
    return 0;
}
