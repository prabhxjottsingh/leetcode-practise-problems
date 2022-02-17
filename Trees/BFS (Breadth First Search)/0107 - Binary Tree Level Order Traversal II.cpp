// Problem Link: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

// Time Complexity: O(n)
// Space Complexity: O(n + (n/2))

class Solution
{
private:
    void reverseTheOrder(vector<vector<int>> &v)
    {
        int n = v.size();
        for (int i = 0; i < n / 2; i++)
        {
            vector<int> temp = v[i];
            v[i] = v[n - i - 1];
            v[n - i - 1] = temp;
        }
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        reverseTheOrder(ans);
        return ans;
    }
};