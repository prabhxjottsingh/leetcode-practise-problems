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
    bool rootToNode(TreeNode *root, TreeNode *p, vector<TreeNode *> &res)
    {

        if (!root)
            return false;

        res.push_back(root);

        if (root == p)
            return true;

        if (rootToNode(root->left, p, res) || rootToNode(root->right, p, res))
            return true;

        res.pop_back();

        return false;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> pathP;
        rootToNode(root, p, pathP);
        vector<TreeNode *> pathQ;
        rootToNode(root, q, pathQ);
        int n = min(pathP.size(), pathQ.size());
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (pathP[i] == pathQ[i])
                idx = i;
        }
        return pathP[idx];
    }
};

// Different Method
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
    map<TreeNode *, TreeNode *> parentNode;
    set<TreeNode *> st;

    void mapWithParent(TreeNode *root, TreeNode *parent = NULL)
    {
        if (!root)
            return;
        parentNode[root] = parent;
        mapWithParent(root->left, root);
        mapWithParent(root->right, root);
    }

    TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!parentNode[p] && !parentNode[q])
            return root;
        if (!parentNode[p])
            p = root;
        if (!parentNode[q])
            q = root;
        if (p != root && st.count(p) || p == q)
            return p;
        if (q != root && st.count(q))
            return q;
        st.insert(q);
        st.insert(p);
        TreeNode *resNode = lca(root, parentNode[p], parentNode[q]);
        return resNode;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        mapWithParent(root);
        TreeNode *resNode = lca(root, p, q);
        return resNode;
    }
};