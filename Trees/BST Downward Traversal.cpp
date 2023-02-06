//problem Link: https://practice.geeksforgeeks.org/problems/c85e3a573a7de6dfd18398def16d05387852b319/1

//tc: O(log N + N)
//sc: O(1)

class Solution{
private:
    Node* dfs(Node* root, int tar){
        if( !root ) return NULL;
        if( root->data < tar )
            return dfs(root->right, tar);
        else if( root->data > tar )
            return dfs(root->left, tar);
        return root;
    }

    long long int findSum(Node* node, int hd){
        if( !node ) return 0ll;
        if( hd == 0 )
            return node->data + findSum(node->left, hd - 1) + findSum(node->right, hd + 1);
        return findSum(node->left, hd - 1) + findSum(node->right, hd + 1);
    }

public:
    long long int verticallyDownBST(Node *root,int target){
        Node* tNode = dfs(root, target);
        if( !tNode ) return -1;
        long long int rSum = findSum(tNode, 0) - tNode->data;
        return rSum;
    }
};
