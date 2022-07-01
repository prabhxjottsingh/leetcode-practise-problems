void solve(Node *root, int k, int node, int &res, vector<int> path)
{
    if (!root || res != -1)
        return;
    path.push_back(root->data);
    solve(root->left, k, node, res, path);
    solve(root->right, k, node, res, path);
    if (path.back() == node)
    {
        if (k < path.size())
            res = path[path.size() - k - 1];
    }
    path.pop_back();
}

int kthAncestor(Node *root, int k, int node)
{
    vector<int> path;
    int res = -1;
    solve(root, k, node, res, path);
    return res;
}