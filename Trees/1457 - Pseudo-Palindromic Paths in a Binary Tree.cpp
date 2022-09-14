// Problem Link: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

// Method - 1
//  Time Complexity: O(N)
//  Space Complexity: O(10)

class Solution
{
private:
    bool isLeaf(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
            return true;
        return false;
    }

    void traverse(TreeNode *root, vector<int> &freq, int &count, int countOdd)
    {
        freq[root->val] += 1;
        if (freq[root->val] & 1)
            countOdd += 1;
        else if (freq[root->val] != 1)
            countOdd -= 1;
        if (isLeaf(root))
        {
            if (countOdd < 2)
            {
                count += 1;
            }
            if (freq[root->val] & 1)
                countOdd -= 1;
            else
                countOdd += 1;
            freq[root->val] -= 1;
            return;
        }
        if (root->left)
            traverse(root->left, freq, count, countOdd);
        if (root->right)
            traverse(root->right, freq, count, countOdd);

        if (freq[root->val] & 1)
            countOdd -= 1;
        else
            countOdd += 1;
        freq[root->val] -= 1;
    }

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        int count = 0;
        if (!root)
            return 0;
        vector<int> freq(10, 0);
        int countOdd = 0;
        traverse(root, freq, count, countOdd);
        return count;
    }
};

// Method 2: Using XOR Operator
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
class Solution
{
private:
    bool isLeaf(TreeNode *root)
    {
        if (!root->left && !root->right)
            return true;
        return false;
    }

    void func(TreeNode *root, int bitOpe, int &resCount)
    {
        int nodeVal = root->val;
        bitOpe ^= (1 << nodeVal);
        if (isLeaf(root))
        {
            if (__builtin_popcount(bitOpe) < 2)
                resCount += 1;
            return;
        }
        if (root->left)
            func(root->left, bitOpe, resCount);
        if (root->right)
            func(root->right, bitOpe, resCount);
    }

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        int resCount = 0;
        int bitOpe = 0;
        if (!root)
            return 0;
        func(root, bitOpe, resCount);
        return resCount;
    }
};