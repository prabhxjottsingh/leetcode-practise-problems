// Problem Link: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/

// Time Complexity: O(N)
// Space Complexity: O(N) //recursion stack space

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
    int maxAncestorDiff(TreeNode *root, TreeNode *par = NULL, int mini = 1e9, int maxi = -1e9)
    {
        if (!root)
            return 0;
        int currDiff = (par ? abs(root->val - mini) : 0);
        currDiff = (par ? max(currDiff, abs(root->val - maxi)) : currDiff);
        mini = min(mini, root->val);
        maxi = max(maxi, root->val);
        return max({currDiff, maxAncestorDiff(root->left, root, mini, maxi), maxAncestorDiff(root->right, root, mini, maxi)});
    }
};