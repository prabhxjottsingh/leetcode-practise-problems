// Problem Link: https://leetcode.com/problems/trim-a-binary-search-tree/

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
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (root == NULL)
            return NULL;
        if (root->val >= low && root->val <= high)
        {
            root->right = trimBST(root->right, low, high);
            root->left = trimBST(root->left, low, high);
            return root;
        }
        else if (root->val < low)
        {
            return trimBST(root->right, low, high);
        }
        else
        {
            return trimBST(root->left, low, high);
        }
        return NULL;
    }
};