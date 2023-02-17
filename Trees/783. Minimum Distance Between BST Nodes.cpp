//tc: O(n)
//sc: O(n) -> because of the use of the array

class Solution {
private:
    void inorderTraversal(TreeNode* root, vector<int> &arr){
        if( !root ) return;
        inorderTraversal(root->left, arr);
        arr.push_back(root->val);
        inorderTraversal(root->right, arr);
    }

public:
    int minDiffInBST(TreeNode* root) {
        vector<int> arr;
        inorderTraversal(root, arr);
        int minDiff = 1e9;
        int n = arr.size();
        for(int i = 0; i < n - 1; i++){
            minDiff = min(minDiff, arr[i + 1] - arr[i]);
        }
        return minDiff;
    }
};


//O(n * log N)
//O(1) ignore recursion stack space

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int funcNxt(TreeNode* root, int key, TreeNode* orgNode){

        if( !root ) return 1e9;

        if( root->val < key )
            return funcNxt(root->right, key, orgNode);
        int maxVal = 1e9;
        if( root->val >= key && root != orgNode )
            maxVal = root->val;
        return min({maxVal, funcNxt(root->right, key, orgNode), funcNxt(root->left, key, orgNode)});

    }

    void func(TreeNode* curr, int &minDiff, TreeNode* strNode){
        if( !curr ) return;

        int nxtGreater = funcNxt(strNode, curr->val, curr);

        minDiff = min(minDiff, nxtGreater - curr->val);
        cout << curr->val << " " << nxtGreater << endl;
        func(curr->left, minDiff, strNode);
        func(curr->right, minDiff, strNode);

    }

public:
    int minDiffInBST(TreeNode* root) {
        int minDiff = 1e9;
        func(root, minDiff, root);
        return minDiff;
    }
};
