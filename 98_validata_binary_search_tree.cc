/*
 * @yang 2015/3/24
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
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

class Solution {
    public:
    bool isValidBST(TreeNode *root) {
        TreeNode *temp;
        if(root==NULL)
            return true;
        if(root->left!=NULL) {
           if(!isValidBST(root->left))
               return false;
           temp = root->left;
           while(temp!=NULL) {
               if(temp->val >= root->val)
                   return false;
               temp=temp->right;
           }
        }
        if(root->right!=NULL) {
            if(!isValidBST(root->right))
                return false;
            temp=root->right;
            while(temp) {
                if(temp->val <= root->val)
                    return false;
                temp = temp->left;
            }
        }
        return true;
    }
};

int main() {
    Solution solu;
    return 0;
}
