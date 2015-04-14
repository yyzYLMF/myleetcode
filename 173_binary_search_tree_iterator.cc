/*
 * @yang 2015/4/14
 *
 * mplement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 *
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 */
#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    public:
    BSTIterator(TreeNode *root) {
        if(root==NULL)
            return;
        traverse(root);
        return;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(store.empty())
            return false;
        else
            return true;
    }

    /** @return the next smallest number */
    int next() {
        int temp;
        temp = store.front();
        store.pop();
        return temp;
    }
    private:
    queue<int> store;
    void traverse(TreeNode *root) {
        if(root->left)
            traverse(root->left);
        store.push(root->val);
        if(root->right)
            traverse(root->right);
        return;
    }

};

/**
 *  Your BSTIterator will be called like this:
 *  BSTIterator i = BSTIterator(root);
 *  while (i.hasNext()) cout << i.next();
 *  */
