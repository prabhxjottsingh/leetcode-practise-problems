// Problem Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    void helperFunction(TreeNode *root, priority_queue<int> &pq, int k)
    {
        if (root == NULL)
            return;
        pq.push(root->val);
        if (pq.size() > k)
            pq.pop();
        if (root->left)
            helperFunction(root->left, pq, k);
        if (root->right)
            helperFunction(root->right, pq, k);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        priority_queue<int> pq;
        helperFunction(root, pq, k);
        return pq.top();
    }
};