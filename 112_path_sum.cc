/*
 * @yang 2015/3/26
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
     5
    / \
   4   8
  /   / \
 11  13  4
 /    \   \
7      2   1  
* return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    void traverse(TreeNode *root, int sum, int temp) {
        temp+=root->val;
        if(root->left==NULL && root->right==NULL) {
            if(temp==sum)
                sign=true;
            return;
        }
        if(root->left)
            traverse(root->left,sum,temp);
        if(root->right)
            traverse(root->right,sum,temp);
        return;
    }

    bool hasPathSum(TreeNode *root, int sum) {
        sign=false;
        if(root==NULL)
            return false;
        traverse(root,sum,0);
        return sign;
    }
    private:
        bool sign;
};

int main() {
    Solution solu;
    return 0;
}
