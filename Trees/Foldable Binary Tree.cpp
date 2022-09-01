bool isSymmetric(Node *leftTree, Node *rightTree)
{
    if (!leftTree && !rightTree)
        return true;
    if (!leftTree || !rightTree)
        return false;
    return isSymmetric(leftTree->left, rightTree->right) && isSymmetric(leftTree->right, rightTree->left);
}

bool IsFoldable(Node *root)
{
    if (!root)
        return true;
    return isSymmetric(root->left, root->right);
}