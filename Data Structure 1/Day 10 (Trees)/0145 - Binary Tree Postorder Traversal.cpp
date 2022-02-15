// Problem Link: https://leetcode.com/problems/binary-tree-postorder-traversal/

class Solution
{
private:
    void postOrderTransversal(vector<int> &ans, TreeNode *root)
    {
        if (root == NULL)
            return;
        postOrderTransversal(ans, root->left);
        postOrderTransversal(ans, root->right);
        ans.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        postOrderTransversal(ans, root);
        return ans;
    }
};