/*
 * @yang 2015/3/24
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
    bool isSameTree2(TreeNode *p, TreeNode *q) {
        if(p==NULL) 
            return q==NULL;
        else if(q==NULL)
            return p==NULL;


        if(p->left && q->right){
            if(!isSameTree2(p->left,q->right))
                return false;
        }
        else if((p->left!=NULL)^(q->right!=NULL)) {
            return false;
        }
        
        
        if(p->val != q->val)
            return false;
        
        if(p->right && q->left) {
            if(!isSameTree2(p->right,q->left))
                return false;
        }
        else if((p->right!=NULL)^(q->left!=NULL)) {
            return false;
        }

        return true;
    }
    bool isSymmetric(TreeNode *root) {
        if(root==NULL)
            return true;
        return isSameTree2(root->left,root->right);
    }
};

int main() {
    Solution solu;
    TreeNode *a1=new TreeNode(13);
    TreeNode *a12=new TreeNode(13);
    TreeNode *a2=new TreeNode(76);
    TreeNode *a22=new TreeNode(76);
    TreeNode *a3=new TreeNode(-42);
    TreeNode *a32=new TreeNode(-42);
    TreeNode *a4=new TreeNode(9);
    
    a2->right=a1;
    a22->right=a12;
    a3->right=a2;
    a32->left=a22;
    a4->left=a3;
    a4->right=a32;
    cout<<solu.isSymmetric(a4)<<endl;
    return 0;
}
