// Problem Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/

// Time Complexity: O(N)

class Solution
{
private:
    void func(TreeNode *root, int maxVal, int &count)
    {
        if (!root)
            return;
        maxVal = max(maxVal, root->val);
        if (maxVal <= root->val)
            count += 1;
        func(root->left, maxVal, count);
        func(root->right, maxVal, count);
    }

public:
    int goodNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        int count = 0;
        int maxVal = root->val;
        func(root, maxVal, count);
        return count;
    }
};