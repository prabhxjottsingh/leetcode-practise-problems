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
    string intToString(int x)
    {
        string res;
        bool minus = false;
        if (x < 0)
            minus = true;
        if (minus)
        {
            x *= (-1);
        }
        while (x)
        {
            res.push_back(x % 10 + '0');
            x /= 10;
        }
        if (minus)
            res.push_back('-');
        reverse(res.begin(), res.end());
        return res;
    }

    bool isLeaf(TreeNode *root)
    {
        if (!root->left && !root->right)
            return true;
        return false;
    }

    void func(TreeNode *root, string temp, vector<string> &res)
    {

        if (root == NULL)
            return;

        if (!temp.empty())
            temp += "->";

        if (isLeaf(root))
        {
            temp += (intToString(root->val));
            res.push_back(temp);
            return;
        }

        temp += (intToString(root->val));
        func(root->left, temp, res);
        func(root->right, temp, res);
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        string temp;
        if (!root)
            return res;
        func(root, temp, res);
        return res;
    }
};