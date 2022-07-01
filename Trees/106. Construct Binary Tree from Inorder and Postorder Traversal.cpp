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
    int findPos(vector<int> &in, int element, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (in[i] == element)
                return i;
        }
        return -1;
    }
    TreeNode *solve(vector<int> &post, vector<int> &in, int &index, int inOrderStartIdx, int inOrderEndIdx, int n)
    {
        if (index < 0 || inOrderStartIdx > inOrderEndIdx)
            return NULL;
        int element = post[index];
        index--;
        TreeNode *root = new TreeNode(element);
        int position = findPos(in, element, n);
        root->right = solve(post, in, index, position + 1, inOrderEndIdx, n);
        root->left = solve(post, in, index, inOrderStartIdx, position - 1, n);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        int postOrderIndex = n - 1;
        TreeNode *res = solve(postorder, inorder, postOrderIndex, 0, n - 1, n);
        return res;
    }
};