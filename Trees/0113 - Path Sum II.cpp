// Problem Link: https://leetcode.com/problems/path-sum-ii/

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
    vector<vector<int>> res;

    void helperFunction(TreeNode *root, vector<int> &path, int targetSum)
    {
        if (root == NULL)
            return;
        path.push_back(root->val);

        if (!root->left && !root->right)
        {
            int n = path.size(), sum = 0;
            for (int i = 0; i < n; i++)
                sum += path[i];
            if (sum == targetSum)
                res.push_back(path);
            path.pop_back();
            return;
        }

        if (root->left)
            helperFunction(root->left, path, targetSum);
        if (root->right)
            helperFunction(root->right, path, targetSum);
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        helperFunction(root, path, targetSum);
        return res;
    }
};

// Second Method
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
    vector<vector<int>> resVec;
    bool isLeaf(TreeNode *root)
    {
        if (!root->right && !root->left)
            return true;
        return false;
    }

    void func(TreeNode *root, int &sum, int &targetSum, vector<int> &path)
    {
        sum += root->val;
        path.push_back(root->val);
        if (isLeaf(root))
        {
            if (sum == targetSum)
                resVec.push_back(path);
            sum -= root->val;
            path.pop_back();
            return;
        }
        if (root->left)
            func(root->left, sum, targetSum, path);
        if (root->right)
            func(root->right, sum, targetSum, path);
        sum -= root->val;
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        int sum = 0;
        if (!root)
            return resVec;
        vector<int> storePath;
        func(root, sum, targetSum, storePath);
        return resVec;
    }
};