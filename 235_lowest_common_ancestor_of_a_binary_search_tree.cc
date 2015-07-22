/*
 * @yang 2015/7/22
 *
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* pos;
        pos = root;
        while(pos->val!=p->val && pos->val!=q->val) {
            if(pos->val < p->val && pos->val < q->val)
                pos = pos->right;
            else if(pos->val > p->val && pos->val > q->val)
                pos = pos->left;
            else
                break;
        }
        return pos;
    }
};

int main() {
    Solution solu;
    return 0;
}
