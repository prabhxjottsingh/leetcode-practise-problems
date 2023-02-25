//tc: O(E + V log E)
//sc: O(N * M)

class Solution {
private:
    static const int N = 2e4 + 7;
    static const int mod = 1e9 + 7;
    vector<int> distanceToLastNode;
    int dp[N];

    void djisktra(vector<pair<int, int>> graph[], int n){
        priority_queue<pair<int, int>, vector<pair<int, int>>,
            greater<pair<int, int>>> pq;
        distanceToLastNode.resize(n);
        for(int i = 0; i < n; i++){
            distanceToLastNode[i] = 2e9;
        }
        distanceToLastNode[n - 1] = 0;
        pq.push({0, n - 1});
        while( !pq.empty() ){
            auto front = pq.top();
            pq.pop();
            int node = front.second;
            int dist = front.first;
            for(auto &child : graph[node]){
                int newDist = child.second;
                int cNode = child.first;
                if( distanceToLastNode[cNode] > dist + newDist ){
                    distanceToLastNode[cNode] = dist + newDist;
                    pq.push({distanceToLastNode[cNode], cNode});
                }
            }
        }
    }

    int memo(int node, int par, vector<pair<int, int>> graph[]){
        if( node == 0 ) return 1;
        int &ans = dp[node];
        if( ans != -1 ) return ans;
        int count = 0;
        for(auto &a : graph[node]){
            if( a.first == par || distanceToLastNode[a.first] <= distanceToLastNode[node] ) continue;
            count += memo(a.first, node, graph);
            count %= mod;
        }
        return ans = count;
    }

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        memset(dp, -1, sizeof(dp));
        vector<pair<int, int>> graph[n];
        for(auto &a : edges){
            graph[a[0] - 1].push_back({a[1] - 1, a[2]});
            graph[a[1] - 1].push_back({a[0] - 1, a[2]});
        }
        djisktra(graph, n);
        int countPaths = memo(n - 1, -1, graph);
        return countPaths;
    }
};
