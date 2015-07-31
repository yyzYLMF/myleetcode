/*
 * @yang 2015/7/31
 *
 * Invert a binary tree.
 * This problem was inspired by this original tweet by Max Howell:
 * Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *temp;
        if(root == NULL)
            return root;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        if(root->left != NULL)
            root->left = invertTree(root->left);
        if(root->right != NULL)
            root->right = invertTree(root->right);
        return root;
    }
};

int main() {
    Solution solu;
    return 0;
}
