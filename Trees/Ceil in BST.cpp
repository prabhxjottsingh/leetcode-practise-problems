int findCeil(struct Node *root, int input)
{
    if (!root)
        return -1;
    int ceilNum = -1;
    while (root)
    {
        if (root->data == input)
        {
            return input;
        }
        else if (root->data < input)
            root = root->right;
        else
        {
            ceilNum = root->data;
            root = root->left;
        }
    }
    return ceilNum;
}