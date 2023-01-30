// sc: O(n)
// tc: O(n)

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
    pair<int, int> func(TreeNode *root, int &count)
    {
        if (!root)
            return {0, 0};
        if (!root->left && !root->right)
        {
            count++;
            return {root->val, 1};
        }
        pair<int, int> left = func(root->left, count);
        pair<int, int> right = func(root->right, count);
        int avgVal = (root->val + left.first + right.first) / (left.second + right.second + 1);
        if (avgVal == root->val)
            count++;
        // cout << root->val << " " << avgVal << endl;
        return {root->val + left.first + right.first, left.second + right.second + 1};
    }

public:
    int averageOfSubtree(TreeNode *root)
    {
        int count = 0;
        func(root, count);
        return count;
    }
};