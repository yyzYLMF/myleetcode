/*
 * @yang 2015/3/24
 *
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==NULL) 
            return q==NULL;
        else if(q==NULL)
            return p==NULL;

        if(p->left && q->left){
            if(!isSameTree(p->left,q->left))
                return false;
        }
        else if((p->left!=NULL)^(q->left!=NULL))
            return false;
            
        if(p->val != q->val)
            return false;

        if(p->right && q->right) {
            if(!isSameTree(p->right,q->right))
                return false;
        }
        else if((p->right!=NULL)^(q->right!=NULL))
            return false;

        return true;
    }
};

int main() {
    Solution solu;
    return 0;
}
