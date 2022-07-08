class Solution {
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto &child : adj[i])
                inDegree[child]++;
        }
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        while ( !q.empty() ) {
            int node = q.front();
            q.pop();
            count++;
            for (auto &child : adj[node]) {
                inDegree[child]--;
                if ( inDegree[child] == 0 )
                    q.push(child);
            }
        }
        return count != V;
    }
};