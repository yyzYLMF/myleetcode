#include <iostream>
#include <stack>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};
bool IsPart(TreeNode *root1, TreeNode *root2)
{
    if (root2 == NULL)
        return root1==NULL?true:false;
    if (root1 == NULL)
        return root2==NULL?true:false;
    if (root1->val != root2->val)
        return false;
    return IsPart(root1->left, root2->left) &&
        IsPart(root1->right, root2->right);
}
bool IsPartTree(TreeNode *root1, TreeNode *root2)
{
    bool result = false;
    if (root1 != NULL && root2 != NULL)
    {
        if (root1->val == root2->val)
            result = IsPart(root1, root2);
        if (!result)
            result = IsPartTree(root1->left, root2);
        if (!result)
            result = IsPartTree(root1->right, root2);
    }
    return result;
}
TreeNode* createTree1()
{
    TreeNode *root = new TreeNode(5);
    TreeNode *p1 = new TreeNode(3);
    TreeNode *p2 = new TreeNode(7);
    TreeNode *p3 = new TreeNode(2);
    TreeNode *p4 = new TreeNode(4);
    TreeNode *p5 = new TreeNode(6);
    TreeNode *p6 = new TreeNode(5);
	root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    return root;
}
TreeNode* createTree2()
{
    TreeNode *root = new TreeNode(5);
    TreeNode *p1 = new TreeNode(3);
    TreeNode *p2 = new TreeNode(7);
    root->left = p1;
    root->right = p2;
    return root;
}

int main()
{
    TreeNode *root1 = createTree1();
    TreeNode *root2 = createTree2();
    if(IsPartTree(root1, root2)){
    	cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
}
