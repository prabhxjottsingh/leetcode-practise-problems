// Problem Link: https://leetcode.com/problems/path-sum/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        bool flag = false;
        if (root == NULL)
        {
            return false;
        }
        if (!root->left && !root->right)
        {
            if (targetSum == root->val)
                return true;
            return false;
        }
        if (root->left)
            flag |= hasPathSum(root->left, targetSum - root->val);
        if (root->right)
            flag |= hasPathSum(root->right, targetSum - root->val);
        return flag;
    }
};