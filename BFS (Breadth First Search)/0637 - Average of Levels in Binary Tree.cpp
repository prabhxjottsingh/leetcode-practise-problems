// Problem Link: https://leetcode.com/problems/average-of-levels-in-binary-tree/

// time Complexity: O(N)
// Space Complexity: O(1)

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
    vector<double> averageOfLevels(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        vector<double> res;
        while (!q.empty())
        {
            double sum = 0;
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto front = q.front();
                sum += (double)front->val;
                q.pop();
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            res.push_back(sum / (double)sz);
        }
        return res;
    }
};