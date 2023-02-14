//tc: O(n * m * log(n * m))
//sc: O(n * m)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    map<ListNode*, map<TreeNode*, bool>> dp;
    bool f(ListNode* head, TreeNode* root, ListNode* startAgain){
        if( !head ) return true;
        if( !root ) return false;
        if( dp.count(head) && dp[head].count(root) ) return dp[head][root];
        bool isPos = false;
        if( root->val == head->val )
            isPos |= f(head->next, root->left, startAgain) || f(head->next, root->right, startAgain);
        if( startAgain->val == root->val )
            isPos |= f(startAgain->next, root->left, startAgain) || f(startAgain->next, root->right, startAgain);
        isPos |= f(startAgain, root->left, startAgain) || f(startAgain, root->right, startAgain);
        return dp[head][root] = isPos;
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        ListNode* startAgain = head;
        return f(head, root, startAgain);
    }
};

//tc: (n * n)
//sc: O(n)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfs(ListNode* head, TreeNode* root){
        if( !head ) return true;
        if( !root ) return false;
        if( head->val != root->val ) return false;
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if( !head )
            return true;
        if( !root )
            return false;
        return dfs(head, root)|| isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
