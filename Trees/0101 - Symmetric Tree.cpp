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
    bool func(TreeNode *tree1, TreeNode *tree2)
    {

        if (!tree1 || !tree2)
            return (tree1 == tree2);

        bool flagOne = (tree1->val == tree2->val);
        bool flagTwo = ((func(tree1->left, tree2->right) && func(tree1->right, tree2->left)));

        return (flagOne && flagTwo);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (!(root))
            return true;
        return func(root->left, root->right);
    }
};