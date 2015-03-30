/*
 * @yang 2015/3/30
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *
 * Find the total sum of all root-to-leaf numbers.
 *
 * For example,
    1
   / \
  2   3
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 *
 * Return the sum = 12 + 13 = 25.
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
    void traverse(int &result, TreeNode *root, int last) {
        if(root==NULL)
            return;
        last = last*10 + root->val;
        if(root->left==NULL && root->right==NULL) {
            result += last;
            return;
        }
        if(root->left)
            traverse(result,root->left,last);
        if(root->right)
            traverse(result,root->right,last);
        return;
    }

    int sumNumbers(TreeNode *root) {
        int result=0, last=0;
        traverse(result, root, last);
        return result;
    }
};

int main() {
    Solution solu;
    return 0;
}
