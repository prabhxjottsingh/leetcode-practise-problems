// Problem Link: https://leetcode.com/problems/path-sum-iii/

// Time Complexity: O(N * log N)
// space Complexity: O(N)

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
    void func(TreeNode *root, long long &sum, int targetSum, map<long long, int> &sumSet, int &count)
    {
        if (!root)
            return;
        sum += root->val;
        if (sumSet.count(sum - targetSum))
            count += sumSet[sum - targetSum];
        sumSet[sum] += 1;
        func(root->left, sum, targetSum, sumSet, count);
        func(root->right, sum, targetSum, sumSet, count);
        sumSet[sum] -= 1;
        sum -= root->val;
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        map<long long, int> sumSet;
        int count = 0;
        long long sum = 0;
        sumSet[0] = 1;
        func(root, sum, targetSum, sumSet, count);
        return count;
    }
};