/*
 * @yang 2015/3/26
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    int subTreeHight(TreeNode *root) {
        int left,right;
        if(root==NULL)
            return 0;
        left = subTreeHight(root->left);
        right = subTreeHight(root->right);
        if(left==-1 || right==-1)
            return -1;
        if(abs(left-right) <= 1)
            return (max(left,right)+1);
        else
            return -1;
    }

    bool isBalanced(TreeNode *root) {
        int left,right;
        if(root==NULL)
            return true;
        left=subTreeHight(root->left);
        right=subTreeHight(root->right);
        if(left==-1 || right==-1)
            return false;
        if(abs(left-right) <= 1)
            return true;
        else
            return false;
    }
};

int main() {
    Solution solu;
    return 0;
}
