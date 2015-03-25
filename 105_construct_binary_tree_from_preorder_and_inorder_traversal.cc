/*
 * @yang 2015/3/25
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
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
    TreeNode *build(vector<int> &preorder, int &num, index begin, index end) {
        int key=preorder[num];
        TreeNode *tempNode;
        index pos;
        
        if(begin>end)
            return NULL;
        num++;
        if(begin==end) {
            tempNode=new TreeNode(key);
            return tempNode;
        }
        tempNode=new TreeNode(key);
        pos=find(begin,end+1,key);
        tempNode->left = build(preorder,num,begin,pos-1);
        tempNode->right = build(preorder,num,pos+1,end);
        return tempNode;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int num=0;
        if(preorder.size()==0 || inorder.size()==0 || preorder.size()!=inorder.size())
            return NULL;
        return build(preorder,num,inorder.begin(),inorder.end()-1);
    }
};

int main() {
    Solution solu;
    return 0;
}
