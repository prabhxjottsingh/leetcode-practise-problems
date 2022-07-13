// Problem Link: https://practice.geeksforgeeks.org/problems/bst-to-greater-sum-tree/1

// Approach: Sort the array and then with the help of prefix sum, map each value to the required answer
// Space Complexity: O(2 * N) -> Because of use of the array and the map
// Time Complexity: O(N) -> For each TC

class Solution
{
private:
    int countNodes(Node *root)
    {
        int count = 0;
        queue<Node *> q;
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

    void treeToArray(int arr[], Node *root, int n)
    {
        queue<Node *> q;
        q.push(root);
        int x = 0;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto front = q.front();
                q.pop();
                arr[x] = front->data;
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
    void transformTree(struct Node *root)
    {
        int count = countNodes(root);
        int arr[count];
        treeToArray(arr, root, count);
        map<int, int> sumMap = mappingFunc(arr, count);
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto front = q.front();
                q.pop();
                front->data = sumMap[front->data];
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
        }
    }
};

// Better Appraoch, since it is a Binary Search Tree (Every Node is greater than the node in its left, and node is smaller than the node in its right)
// Space Complexity: O(1), O(N) (Recursion Stack Space)
// Time Complexity: O(N)

class Solution
{
private:
    int func(Node *root, int sum)
    {
        if (!root)
            return 0;
        int right = func(root->right, sum);
        int left = func(root->left, root->data + sum + right);
        int tempVal = left + right + root->data;
        root->data = right + sum;
        return tempVal;
    }

public:
    void transformTree(struct Node *root)
    {
        func(root, 0);
    }
};