/*
 * @yang 2015/3/26
 *
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 * return its bottom-up level order traversal as:
 [
 [15,7],
 [9,20],
 [3]
 ]
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
       vector<vector<int> > result;
       vector<int> temp;
       queue<TreeNode*> q;
       TreeNode *tempNode;

       if(root==NULL)
           return result;
       q.push(root);
       q.push(NULL);
       while(!q.empty()) {
           tempNode = q.front();
           q.pop();
           if(tempNode == NULL) {
               result.push_back(temp);
               temp.clear();
               if(q.empty())
                   break;
               else
                   q.push(NULL);
               continue;
           }
           temp.push_back(tempNode->val);
           if(tempNode->left)
               q.push(tempNode->left);
           if(tempNode->right)
               q.push(tempNode->right);
       }
       reverse(result.begin(),result.end());
       return result;   
    }
};

int main() {
    Solution solu;
    return 0;
}
