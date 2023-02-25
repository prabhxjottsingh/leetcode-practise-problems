//tc: O ( V + E l o g V )
//sc: O(n * m)

class Solution {
  public:
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        vector<pair<int, pair<int, int>>> graph[n];
        a -= 1;
        b -= 1;
        for(auto &a : edges){
            a[0] -= 1;
            a[1] -= 1;
            graph[a[0]].push_back({a[1], {a[2], a[3]}});
            graph[a[1]].push_back({a[0], {a[2], a[3]}});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                            greater<pair<int, int>>> pq;
        int dist[n][2];
        for(int i = 0; i < n; i++)
            dist[i][0] = 1e9, dist[i][1] = 1e9;
        dist[a][0] = 0;
        dist[a][1] = 0;
        pq.push({0, a});
        while( !pq.empty() ){
            auto front = pq.top();
            pq.pop();
            int par = front.second;
            int newDist = front.first;
            for(auto &child : graph[par]){
                int cNode = child.first;
                int curve = child.second.second;
                int st = child.second.first;
                if( dist[cNode][0] > dist[par][1] + curve ){
                    dist[cNode][0] = dist[par][1] + curve;
                    pq.push({dist[cNode][0], cNode});
                }
                if( dist[cNode][0] > dist[par][0] + st ){
                    dist[cNode][0] = dist[par][0] + st;
                    pq.push({dist[cNode][0], cNode});
                }
                if( dist[cNode][1] > dist[par][1] + st ){
                    dist[cNode][1] = dist[par][1] + st;
                    pq.push({dist[cNode][1], cNode});
                }
            }
        }
        int resDist = min(dist[b][0], dist[b][1]);
        if( resDist == 1e9 ) return -1;
        return resDist;
    }
};
