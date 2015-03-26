/*
 * @yang 2015/3/26
 *
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    TreeNode *build(vector<int> &num, int low, int high) {
        TreeNode *tempNode;
        int mid;
        if(low>high)
            return NULL;
        if(low==high) {
            tempNode = new TreeNode(num[low]);
            return tempNode;
        }
        mid=(low+high)/2;
        tempNode = new TreeNode(num[mid]);
        tempNode->left = build(num,low,mid-1);
        tempNode->right = build(num,mid+1,high);
        return tempNode;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int len;
        len=num.size();
        if(len==0)
            return NULL;
        return build(num,0,len-1);
    }
};

int main() {
    Solution solu;
    return 0;
}
