class Solution
{
public:
    // Function to find the least absolute difference between any node
    // value of the BST and the given integer.
    int minDiff(Node *root, int K)
    {
        if (!root)
            return K;
        int minDiff = 1e9;
        while (root)
        {
            minDiff = min(minDiff, abs(K - root->data));
            if (root->data < K)
                root = root->right;
            else
                root = root->left;
        }
        return minDiff;
    }
};