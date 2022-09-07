// Problem Link: https://leetcode.com/problems/construct-string-from-binary-tree/

// Time Complexity: O(N)
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
    string str;
    void func(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        if (!str.empty())
            str += '(';
        str += to_string(root->val);
        if (root->left)
            func(root->left);
        else if (root->right)
            str += '(', str += ')';
        if (root->right)
            func(root->right);
        str += ')';
    }

public:
    string tree2str(TreeNode *root)
    {
        func(root);
        str.pop_back();
        return str;
    }
};