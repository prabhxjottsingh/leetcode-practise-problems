vector<int> leftView(Node *root)
{
    queue<Node *> q;
    vector<int> res;
    if (root == NULL)
        return res;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        int rightNum = -1;
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            if (rightNum == -1)
                rightNum = node->data;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        res.push_back(rightNum);
    }
    return res;
}