// Problem Link: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
// Space Complexity: O(2 * N)
// Time Complexity: O(N)

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
    int countNodes(TreeNode *root)
    {
        int count = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            count += q.size();
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto front = q.front();
                q.pop();
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
        }
        return count;
    }

    void treeToArray(int arr[], TreeNode *root, int n)
    {
        queue<TreeNode *> q;
        q.push(root);
        int x = 0;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto front = q.front();
                q.pop();
                arr[x] = front->val;
                x++;
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
        }
        sort(arr, arr + n);
    }

    map<int, int> mappingFunc(int arr[], int n)
    {
        map<int, int> mp;
        mp[arr[n - 1]] = 0;
        for (int i = n - 2; i > -1; i--)
        {
            mp[arr[i]] = arr[i + 1];
            arr[i] += arr[i + 1];
        }
        return mp;
    }

public:
    TreeNode *bstToGst(TreeNode *root)
    {
        int count = countNodes(root);
        int arr[count];
        treeToArray(arr, root, count);
        map<int, int> sumMap = mappingFunc(arr, count);
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto front = q.front();
                q.pop();
                front->val = sumMap[front->val] + front->val;
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
        }
        return root;
    }
};