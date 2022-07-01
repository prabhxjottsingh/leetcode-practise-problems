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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        long long int maxWidth = 0;
        queue<pair<TreeNode *, long long int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            long long int size = q.size();
            long long int mmin = q.front().second;
            long long int first = 0;
            long long int last = 0;
            for (int i = 0; i < size; i++)
            {
                long long int curr_id = q.front().second - mmin;
                TreeNode *node = q.front().first;
                q.pop();
                if (i == 0)
                    first = curr_id;
                if (i == size - 1)
                    last = curr_id;
                if (node->left)
                    q.push({node->left, (curr_id * 2) + 1});
                if (node->right)
                    q.push({node->right, (curr_id * 2) + 2});
            }
            maxWidth = max(maxWidth, last - first + 1);
        }
        return maxWidth;
    }
};