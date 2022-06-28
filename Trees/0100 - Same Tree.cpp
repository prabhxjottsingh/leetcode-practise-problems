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
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if( p == NULL || q == NULL)
            return (p == q);
        bool flagOne = true;
        flagOne = isSameTree(p->left, q->left);
        bool flagTwo = true;
        flagTwo = isSameTree(p->right, q->right);
        return (p->val == q->val && flagOne && flagTwo);
    }
};