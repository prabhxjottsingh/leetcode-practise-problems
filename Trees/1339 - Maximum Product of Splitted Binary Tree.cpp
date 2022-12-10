// Problem Link: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/

// Time Complexity: O(n)
// Space Complexity: O(n)

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
    const int mod = 1e9 + 7;
    long maxFinalProd = 0;

    long totalSum(TreeNode *root)
    {
        if (!root)
            return 0;
        return root->val + totalSum(root->left) + totalSum(root->right);
    }

    long func(TreeNode *root, long totSum)
    {
        if (!root)
            return 0;
        long sumUnderLeft = func(root->left, totSum);
        long sumUnderRight = func(root->right, totSum);
        maxFinalProd = max({maxFinalProd, sumUnderLeft * (totSum - sumUnderLeft), sumUnderRight * (totSum - sumUnderRight)});
        return sumUnderLeft + sumUnderRight + root->val;
    }

public:
    int maxProduct(TreeNode *root)
    {
        long totSum = totalSum(root);
        long maxProductVal = func(root, totSum);
        return maxFinalProd % mod;
    }
};