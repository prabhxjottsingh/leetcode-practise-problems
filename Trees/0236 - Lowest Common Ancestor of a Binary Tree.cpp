/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool rootToNode(TreeNode *root, TreeNode* p, vector<TreeNode*> &res){
        
        if( !root )
            return false;
        
        res.push_back(root);
        
        if( root == p )
            return true;
        
        if( rootToNode(root->left, p, res) || rootToNode(root->right, p, res) )
            return true;
        
        res.pop_back();
        
        return false;
        
    } 
        
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP;
        rootToNode(root, p, pathP);
        vector<TreeNode*> pathQ;
        rootToNode(root, q, pathQ);
        int n = min(pathP.size(), pathQ.size());
        int idx = 0;
        for(int i = 0; i < n; i++){
            if(pathP[i] == pathQ[i])
                idx = i;
        }
        return pathP[idx];
    }
};