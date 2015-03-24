/*
 * @yang 2015/3/24
 *
 * Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 *
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//iterative method use stack, O(n) space
class Solution {
    public:
    void recoverTree(TreeNode *root) {
        TreeNode *first=NULL,*second=NULL;
        TreeNode *tempNode=NULL,*p;
        int tempval,pval;
        stack<TreeNode *> s;
        
        if(root==NULL)
            return;
        p=root;
        while(p) {
            s.push(p);
            p=p->left;
        }
        while(!s.empty()) {
            p=s.top();
            s.pop();
            if(tempNode==NULL) {
                tempNode=p;
                tempval=p->val;
            }
            else {
                if(p->val > tempval) {
                    tempNode=p;
                    tempval=p->val;
                }
                else {
                    if(first==NULL) {
                        first=tempNode;
                        second=p;
                        tempNode=p;
                        tempval=p->val;
                    }
                    else {
                        second=p;
                        break;
                    }
                }
            }
            if(p->right) {
                p=p->right;
                while(p) {
                    s.push(p);
                    p=p->left;
                }
            }
        }
        if(first!=NULL && second!=NULL)
            swap(first->val,second->val);
        return;


    }
};

//recursive method, O(1) space
class Solution2 {
    public:
    void traverse(TreeNode *root, TreeNode *&first, TreeNode *&second) {
        if(root==NULL)
            return;
        if(root->left)
            traverse(root->left,first,second);
        if(tempNode==NULL) {
            tempNode=root;
            tempval=root->val;
        }
        else {
            if(root->val > tempval) {
                tempNode = root;
                tempval = root->val;
            }
            else {
                if(first==NULL) {
                    first=tempNode;
                    second=root;
                    tempNode=root;
                    tempval=root->val;
                }
                else {
                    second=root;
                }
            }
        }
        if(root->right)
            traverse(root->right,first,second);
        return;
    }
    void recoverTree(TreeNode *root) {
        TreeNode *first=NULL,*second=NULL;

        tempNode=NULL;
        traverse(root,first,second);
        if(first!=NULL && second!=NULL) {
            swap(first->val,second->val);
        }
        return;
    }
    private:
    TreeNode *tempNode;
    int tempval;
};

int main() {
    Solution solu;
    Solution2 solu2;
    TreeNode *head=new TreeNode(0);
    TreeNode *next=new TreeNode(1);
    head->left=next;
    
    solu2.recoverTree(head);
    cout<<head->val<<endl;
    return 0;
}
