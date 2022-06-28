class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            Node* temp = node.first;
            int line = node.second;
            if(!mp.count(line))
                mp[line] = temp->data;
            if(temp->left)
                q.push({temp->left, line - 1});
            if(temp->right)
                q.push({temp->right, line + 1});
        }
        vector<int> res;
        for(auto &a : mp)
            res.push_back(a.second);
        return res;
    }

};