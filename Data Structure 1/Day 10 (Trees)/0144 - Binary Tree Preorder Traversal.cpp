// Problem Link: https://leetcode.com/problems/binary-tree-preorder-traversal/

// Iterative solution using stack --- O(n) time and O(n) space;
// Recursive solution --- O(n) time and O(n) space (function call stack);
// Morris traversal --- O(n) time and O(1) space.

// Using Depth First Search

class Solution
{
private:
    void preOrderTransversal(vector<int> &v, TreeNode *root)
    {
        if (root == NULL)
            return;
        v.push_back(root->val);
        preOrderTransversal(v, root->left);
        preOrderTransversal(v, root->right);
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        preOrderTransversal(ans, root);
        return ans;
    }
};

//Using Stacks

