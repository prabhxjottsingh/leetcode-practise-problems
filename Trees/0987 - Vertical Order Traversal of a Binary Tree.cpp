// Problem Links: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> mp;      // vertical, level, its nodes values, multiset is used bcs we need the same level and verticalpos nodes in ascending order
        queue<pair<TreeNode *, pair<int, int>>> q; // nodes, vertical, level
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            int verticalPos = node.second.first;
            int level = node.second.second;
            mp[verticalPos][level].insert(node.first->val);
            if (node.first->left)
                q.push({node.first->left, {verticalPos - 1, level + 1}});
            if (node.first->right)
                q.push({node.first->right, {verticalPos + 1, level + 1}});
        }
        vector<vector<int>> res;
        for (auto &a : mp)
        {
            vector<int> againTemp;
            map<int, multiset<int>> temp = a.second;
            for (auto &b : temp)
            {
                for (auto &c : b.second)
                {
                    againTemp.push_back(c);
                }
            }
            res.push_back(againTemp);
        }
        return res;
    }
};