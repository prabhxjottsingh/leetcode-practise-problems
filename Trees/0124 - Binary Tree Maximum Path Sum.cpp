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
private:
    int func(TreeNode* root, int &maxPath){
        if(root == NULL)
            return 0;
        
        int left = root->val + func(root->left, maxPath);
        int right = root->val + func(root->right, maxPath);
        
        maxPath = max(maxPath, left + right - root->val);
        
        return max(0, max(left, right));
        
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        int temp = func(root, maxPath);
        return maxPath;
    }
};