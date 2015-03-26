/*
 * @yang 2015/3/26
 *
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example,
 * Given
 *
 1
 / \
 2   5
 / \   \
 3   4   6
 *The flattened tree should look like:
 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
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
    void traverse(TreeNode *&tail, TreeNode *root) {
        TreeNode *left,*right;
        left=root->left;
        right=root->right;

        if(tail==NULL) {
            tail=root;
        }
        else {
            tail->right = root;
            tail->left = NULL;
            tail = tail->right;
        }
        if(left!=NULL)
            traverse(tail,left);
        if(right!=NULL)
            traverse(tail,right);
        return;
    }

    void flatten(TreeNode *root) {
        TreeNode *tail=NULL;
        if(root==NULL)
            return;
        traverse(tail,root);
        return;
    }
};

int main() {
    Solution solu;
    TreeNode *a=new TreeNode(1);
    TreeNode *b=new TreeNode(2);
    TreeNode *c=new TreeNode(3);
    a->right=b;
    a->left=c;
    solu.flatten(a);
    cout<<a->val<<" "<<a->right->val<<endl;
    return 0;
}
