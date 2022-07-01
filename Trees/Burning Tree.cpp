// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
    void mappingWithParentNode(Node *root, int target, map<Node *, Node *> &mp, Node *&targetNode)
    {

        queue<Node *> q;
        q.push(root);
        mp[root] = NULL;

        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            if (node->data == target)
                targetNode = node;
            if (node->left)
            {
                mp[node->left] = node;
                q.push(node->left);
            }
            if (node->right)
            {
                mp[node->right] = node;
                q.push(node->right);
            }
        }
    }

    int timeCalc(Node *root, map<Node *, Node *> &parentNode)
    {
        int time = 0;
        queue<Node *> q;
        q.push(root);
        map<Node *, bool> isVis;
        // /isVis[root] = 1;
        while (!q.empty())
        {
            int size = q.size();
            int flag = 0;
            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();
                if (node->left && !isVis[node->left])
                {
                    flag = 1;
                    q.push(node->left);
                    isVis[node->left] = 1;
                }
                if (node->right && !isVis[node->right])
                {
                    flag = 1;
                    q.push(node->right);
                    isVis[node->right] = 1;
                }
                if (parentNode[node] && !isVis[parentNode[node]])
                {
                    flag = 1;
                    q.push(parentNode[node]);
                    isVis[parentNode[node]] = 1;
                }
            }
            time += flag;
        }
        return time;
    }

public:
    int minTime(Node *root, int target)
    {
        map<Node *, Node *> parentNode;
        Node *targetNode;
        mappingWithParentNode(root, target, parentNode, targetNode);
        int res = timeCalc(targetNode, parentNode);
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();
    }

    return 0;
}
// } Driver Code Ends