/*
 * @yang 2015/3/29
 *
 * Given a binary tree, find the maximum path sum.
 *
 * The path may start and end at any node in the tree.
 *
 * For example:
 * Given the below binary tree,
   1
  / \
 2   3
 * Return 6.
 */
#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    void traverse(TreeNode *root, int &max) {
        int left=0,right=0,temp,val;
        if(root==NULL)
            return;
        if(root->left) 
            traverse(root->left,max);
        if(root->right)
            traverse(root->right,max);

        left = root->left ? root->left->val:0;
        right = root->right ? root->right->val:0;
        //calculate the max sum
        temp=root->val;
        if(left>0)
            temp+=left;
        if(right>0)
            temp+=right;
        if(temp>max)
            max=temp;

        //update root->val
        val = root->val;
        temp=left>right? left:right;
        if(temp>0)
            val+=temp;
        root->val = val;
        return;
    }

    int maxPathSum(TreeNode *root) {
        int max=INT_MIN;
        if(root==NULL)
            return max;
        else if(root->left==NULL && root->right==NULL)
            return root->val;
        traverse(root,max);
        return max;
    }
};

int main() {
    Solution solu;
    TreeNode *a=new TreeNode(-1);
    TreeNode *b=new TreeNode(-2);
    TreeNode *c=new TreeNode(-3);
    a->left = b;
    a->right = c;
    cout<<solu.maxPathSum(a)<<endl;
    return 0;
}
