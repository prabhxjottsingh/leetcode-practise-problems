// Problem Link: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
private:
    //     TreeNode* dfs(TreeNode* original, TreeNode* cloned, TreeNode* target){

    //     }

public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        if (original == NULL)
            return NULL;
        if (original == target)
        {
            return cloned;
        }
        auto Left = getTargetCopy(original->left, cloned->left, target);
        auto Right = getTargetCopy(original->right, cloned->right, target);
        if (Left)
            return Left;
        if (Right)
            return Right;
        return NULL;
    }
};