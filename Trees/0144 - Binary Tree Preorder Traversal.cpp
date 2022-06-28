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
    vector<int> res;
    
    void func(TreeNode *root){
        
        if(root == NULL)
            return;
        
        res.push_back(root->val);
        func(root->left);
        func(root->right);
        
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        func(root);
        return res;
    }
};