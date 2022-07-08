class Solution
{
    public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        st.insert({0, S});
        dist[S] = 0;
        vector<bool> isVis(V, false);
        while( !st.empty() ){
            auto node = *st.begin();
            st.erase(node);
            int vertex = node.second;
            int vertex_dist = node.first;
            if( isVis[vertex] )
                continue;
            isVis[vertex] = 1;
            for(auto &child : adj[vertex]){
                int child_v = child[0];
                int wt = child[1];
                if( dist[child_v] > dist[vertex] + wt ){
                    dist[child_v] = dist[vertex] + wt;
                    st.insert({dist[child_v], child_v});
                }
            }
        }
        return dist;
    }
};