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

// Using BFS, This uses less time as well as less memory
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
    map<TreeNode *, TreeNode *> mappingWithParent(TreeNode *root)
    {
        map<TreeNode *, TreeNode *> parentTreeNode;
        queue<pair<TreeNode *, TreeNode *>> q;
        q.push({root, NULL});
        while (!q.empty())
        {
            auto TreeNode = q.front();
            q.pop();
            parentTreeNode[TreeNode.first] = TreeNode.second;
            if (TreeNode.first->left)
                q.push({TreeNode.first->left, TreeNode.first});
            if (TreeNode.first->right)
                q.push({TreeNode.first->right, TreeNode.first});
        }
        return parentTreeNode;
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        map<TreeNode *, TreeNode *> parentTreeNode = mappingWithParent(root);
        queue<TreeNode *> q;
        queue<pair<TreeNode *, int>> resQ;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp == target)
            {
                resQ.push({temp, 0});
                break;
            }
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        vector<int> resVec;
        const int N = 1e4 + 7;
        vector<bool> isVis(N, 0);
        while (!resQ.empty())
        {
            auto node = resQ.front();
            resQ.pop();
            TreeNode *tempNode = node.first;
            int dist = node.second;
            // cout << dist << " ";
            if (dist > k || isVis[tempNode->val])
                continue;
            if (dist == k)
                resVec.push_back(tempNode->val);
            isVis[tempNode->val] = 1;
            if (tempNode->left)
                resQ.push({tempNode->left, dist + 1});
            if (tempNode->right)
                resQ.push({tempNode->right, dist + 1});
            if (parentTreeNode[tempNode])
                resQ.push({parentTreeNode[tempNode], dist + 1});
        }
        sort(resVec.begin(), resVec.end());
        return resVec;
    }
};