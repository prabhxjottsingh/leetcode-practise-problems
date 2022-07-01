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
    int func(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left = func(root->left);

        if (left == -1)
            return -1;

        int right = func(root->right);

        if (right == -1)
            return -1;

        if (abs(left - right) > 1)
            return -1;

        return 1 + max(left, right);
    }

public:
    bool isBalanced(TreeNode *root)
    {
        int flag = func(root);
        return (flag != -1);
    }
};

// Second Approach
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
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        return (1 + max(height(root->left), height(root->right)));
    }

    bool helperFunc(TreeNode *root)
    {
        if (!root)
            return true;
        bool flag = true;
        int left = height(root->left);
        int right = height(root->right);

        if (abs(left - right) > 1)
            flag = false;
        return (flag && helperFunc(root->left) && helperFunc(root->right));
    }

public:
    bool isBalanced(TreeNode *root)
    {
        bool flag = helperFunc(root);
        return flag;
    }
};