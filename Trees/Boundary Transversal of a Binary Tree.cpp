class Solution
{
private:
    bool isLeaf(Node *root)
    {
        if (!root->left && !root->right)
            return true;
        return false;
    }

    void addLeft(Node *root, vector<int> &res)
    {
        Node *curr = root->left;
        while (curr)
        {
            if (!isLeaf(curr))
                res.push_back(curr->data);
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void addRight(Node *root, vector<int> &res)
    {
        Node *curr = root->right;
        vector<int> temp;
        while (curr)
        {
            if (!isLeaf(curr))
                temp.push_back(curr->data);
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        reverse(temp.begin(), temp.end());
        for (auto &a : temp)
            res.push_back(a);
    }

    void addLeafs(Node *root, vector<int> &res)
    {
        if (isLeaf(root))
        {
            res.push_back(root->data);
            return;
        }
        if (root->left)
            addLeafs(root->left, res);
        if (root->right)
            addLeafs(root->right, res);
    }

public:
    vector<int> boundary(Node *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;
        if (!isLeaf(root))
            res.push_back(root->data);
        addLeft(root, res);
        addLeafs(root, res);
        addRight(root, res);
        return res;
    }
};