// Problem Link: https://leetcode.com/problems/binary-tree-pruning/

// time Complexity: O(N)
// space Complexity: O(1)

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
private:
    bool isLeaf(TreeNode *root)
    {
        if (!root->left && !root->right)
            return true;
        return false;
    }

public:
    TreeNode *pruneTree(TreeNode *root)
    {
        if (!root)
            return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (isLeaf(root) && root->val == 0)
            return NULL;
        return root;
    }
};