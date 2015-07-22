/*
 * @yang 2015/7/22
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 */

#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    int traverse(TreeNode* root, TreeNode* p, TreeNode* q) {
        int ret,left=0,right=0;
        if(root == NULL)
            return 0;
        if(sign.find(root) != sign.end())
            return sign[root];
        if(root==p || root==q)
            ret = 1;
        else 
            ret = 0;
        if(root->left)
            left = traverse(root->left,p,q);
        if(root->right)
            right = traverse(root->right,p,q);
        ret = ret+left+right;
        sign[root] = ret;
        return ret;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int left,right;
        TreeNode* pos = root;
        if(p == q)
            return p;
        while(pos->val!=p->val && pos->val!=q->val) {
            left = traverse(pos->left,p,q);
            if(left == 2)
                pos = pos->left;
            else if(left == 0)
                pos = pos->right;
            else 
                break;
        }
        return pos;
    }
    private:
    map<TreeNode*,int> sign;
};

int main() {
    Solution solu;
    return 0;
}
