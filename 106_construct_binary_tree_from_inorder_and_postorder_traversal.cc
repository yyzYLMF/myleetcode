/*
 * @yang 2015/3/25
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    typedef vector<int>::iterator index;
    TreeNode *build(vector<int> &postorder, int &num, index begin, index end) {
        int key=postorder[num];
        TreeNode *tempNode;
        index pos;
        if(begin>end)
            return NULL;
        num--;
        if(begin==end) {
            tempNode = new TreeNode(key);
            return tempNode;
        }
        tempNode = new TreeNode(key);
        pos = find(begin,end+1,key);
        tempNode->right = build(postorder,num,pos+1,end);
        tempNode->left = build(postorder,num,begin,pos-1);
        return tempNode;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int num=inorder.size()-1;
        if(inorder.size()==0 || postorder.size()==0 || inorder.size()!=postorder.size())
            return NULL;
        return build(postorder,num,inorder.begin(),inorder.end()-1);
    }
};

int main() {
    Solution solu;
    return 0;
}
