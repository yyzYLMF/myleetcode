/*
 * @yang 2015/3/24
 *
 * Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 *
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
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
    vector<TreeNode *> myfun(vector<vector<vector<TreeNode *> > > dp, int p, int r) {
        vector<TreeNode *> result;
        vector<TreeNode *> left;
        vector<TreeNode *> right;
        int i,j,k;
        if(p>r) 
            return result;
        if(dp[p-1][r-1].size() != 0)
            return dp[p-1][r-1];
        if(p==r) {
            TreeNode *tempNode;
            tempNode = new TreeNode(p);
            dp[p-1][r-1].push_back(tempNode);
            return dp[p-1][r-1];
        }
        for(i=p;i<=r;++i) {
            left=myfun(dp,p,i-1);
            right=myfun(dp,i+1,r);
            if(left.size()==0)
                left.push_back(NULL);
            if(right.size()==0)
                right.push_back(NULL);
            for(j=0;j<left.size();++j) {
                for(k=0;k<right.size();++k) {
                    TreeNode *tempNode;
                    tempNode =new TreeNode(i);
                    tempNode->left=left[j];
                    tempNode->right=right[k];
                    result.push_back(tempNode);
                }
            }
        }
        dp[p-1][r-1] = result;
        return dp[p-1][r-1];
    }

    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> result;
        vector<vector<vector<TreeNode *> > > dp;
        vector<vector<TreeNode *> > temp;
        vector<TreeNode *> left;
        vector<TreeNode *> right;
        int i,j,k;
        for(i=0;i<n;++i)
            temp.push_back(left);
        for(i=0;i<n;++i)
            dp.push_back(temp);
        if(n==0) {
            result.push_back(NULL);
            return result;
        }

        for(i=1;i<=n;++i) {
            left=myfun(dp,1,i-1);
            right=myfun(dp,i+1,n);
            if(left.size()==0)
                left.push_back(NULL);
            if(right.size()==0)
                right.push_back(NULL);
            for(j=0;j<left.size();++j) {
                for(k=0;k<right.size();++k) {
                    TreeNode *tempNode;
                    tempNode = new TreeNode(i);
                    tempNode->left=left[j];
                    tempNode->right=right[k];
                    result.push_back(tempNode);
                }
            }
        }
        return result;
    }
};

class Solution2 {
    public:
    vector<TreeNode *> GenTree(int l, int r) {
        vector<TreeNode *> ans;
        if (l > r) {
            ans.push_back(NULL);
            return ans;
        }
        for (int i = l; i <= r; i++) {
            vector<TreeNode *> Ltree = GenTree(l, i - 1);
            vector<TreeNode *> Rtree = GenTree(i + 1, r);
            for (int j = 0; j < Ltree.size(); j++) {
                for (int k = 0; k < Rtree.size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = Ltree[j];
                    root->right = Rtree[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode *> generateTrees(int n) {
        return GenTree(1, n);
    }
};

int main() {
    Solution solu;
    int n;
    while(cin>>n) {
        cout<<(solu.generateTrees(n)).size()<<endl;
    }
    return 0;
}
