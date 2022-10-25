{
    public :
        // Function to find sum of weights of edges of the Minimum Spanning Tree.
        int spanningTree(int V, vector<vector<int>> adj[]){
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> isVis(V, 0);
int sum = 0;
pq.push({0, 0});
while (!pq.empty())
{
    auto node = pq.top();
    pq.pop();
    int nd = node.second;
    int wt = node.first;
    if (isVis[nd])
        continue;
    isVis[nd] = 1;
    sum += wt;
    for (auto &child : adj[nd])
    {
        if (!isVis[child[0]])
        {
            pq.push({child[1], child[0]});
        }
    }
}
return sum;
}
}
;