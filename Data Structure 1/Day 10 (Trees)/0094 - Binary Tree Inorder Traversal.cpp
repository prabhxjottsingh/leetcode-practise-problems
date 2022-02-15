// Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

class Solution
{
private:
    void inOrderTransversal(vector<int> &ans, TreeNode *root)
    {
        if (root == NULL)
            return;
        inOrderTransversal(ans, root->left);
        ans.push_back(root->val);
        inOrderTransversal(ans, root->right);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        inOrderTransversal(ans, root);
        return ans;
    }
};