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
    int fincPos(vector<int> &in, int element, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (in[i] == element)
                return i;
        }
        return -1;
    }

    TreeNode *solve(vector<int> &pre, vector<int> &in, int &index, int inOrderStartIdx, int inOrderEndIdx, int n)
    {
        if (index >= n || inOrderStartIdx > inOrderEndIdx)
            return NULL;
        int element = pre[index++];
        TreeNode *root = new TreeNode(element);
        int pos = fincPos(in, element, n);
        root->left = solve(pre, in, index, inOrderStartIdx, pos - 1, n);
        root->right = solve(pre, in, index, pos + 1, inOrderEndIdx, n);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        int preOrderIndex = 0;
        TreeNode *res = solve(preorder, inorder, preOrderIndex, 0, n - 1, n);
        return res;
    }
};