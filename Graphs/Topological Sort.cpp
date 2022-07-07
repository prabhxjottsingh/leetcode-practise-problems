//Using DFS
class Solution{
private:
    void dfs(int node, stack<int> &st, vector<bool> &isVis, vector<int> adj[]){
        if( isVis[node] )
            return;
        isVis[node] = 1;
        for(auto &child : adj[node])
            dfs(child, st, isVis, adj);
        st.push(node);
    }

public:
    vector<int> topoSort(int V, vector<int> adj[]) 
    {
        vector<bool> isVis(V, 0);
        vector<int> topo;
        stack<int> st;
        for(int i = 0; i < V; i++){
            if( !isVis[i] )
                dfs(i, st, isVis, adj);
        }
        while( !st.empty() ){
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};

//Using BFS also called Kahn's Algorithm.
//InDegree of a node is the number of the edges directed towards it.
