// Problem Link: https://leetcode.com/problems/find-duplicate-subtrees/

// Time Complexity: O(N)
// Space Complexity: O(n * m)

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
    vector<TreeNode *> vec;
    map<string, int> freq;

    string func(TreeNode *root)
    {
        if (!root)
            return "";
        string leftSubtree = func(root->left);
        string rightSubtree = func(root->right);
        string str = to_string(root->val) + "," + leftSubtree + "," + rightSubtree;
        if (freq[str] == 1)
            vec.push_back(root);
        freq[str] += 1;
        return str;
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        func(root);
        return vec;
    }
};