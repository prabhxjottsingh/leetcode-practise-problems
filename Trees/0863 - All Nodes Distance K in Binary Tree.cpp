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
    void mappingTheParentNode(TreeNode *root, map<TreeNode *, TreeNode *> &parentNode)
    {
        queue<TreeNode *> q;
        q.push(root);
        parentNode[root] = NULL;
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left)
            {
                q.push(node->left);
                parentNode[node->left] = node;
            }

            if (node->right)
            {
                q.push(node->right);
                parentNode[node->right] = node;
            }
        }
    }

    void solve(TreeNode *root, int dist, int k, vector<int> &res, map<TreeNode *, TreeNode *> parentNode, TreeNode *target, map<TreeNode *, bool> &isVis)
    {

        if (!root || dist > k || isVis[root])
            return;
        isVis[root] = 1;
        if ((dist == k && root->val != target->val))
        {
            res.push_back(root->val);
            return;
        }

        solve(root->left, dist + 1, k, res, parentNode, target, isVis);
        solve(root->right, dist + 1, k, res, parentNode, target, isVis);
        solve(parentNode[root], dist + 1, k, res, parentNode, target, isVis);
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> res;
        if (k == 0)
            res.push_back(target->val);
        map<TreeNode *, TreeNode *> parentNode;
        mappingTheParentNode(root, parentNode);
        map<TreeNode *, bool> isVis;
        solve(target, 0, k, res, parentNode, target, isVis);
        return res;
    }
};