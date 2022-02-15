// Problem Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/

// Time Complexity: O(n)
// Space Complexity: Constant

//Done with the help of depth first Search (DFS)
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};