//time Complexity: O(N * N * log N)
//sc: O(N)

//using djisktra for every city

class Solution {
private:
    int helperFunc(int n, int src, vector<pair<int, int>> graph[], int thrDist){
        vector<int> dist(n, 1e9);
        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
                greater<pair<int, int>>> pq;
        dist[src] = 0;
        pq.push({0, src});
        int count = 0;
        unordered_set<int> st;
        while( !pq.empty() && pq.top().first <= thrDist ){
            auto front = pq.top();
            pq.pop();
            int node = front.second;
            int newDist = front.first;
            st.insert(node);
            for(auto &a : graph[node]){
                int childNode = a.first;
                int childDist = a.second;
                if( dist[childNode] > dist[node] + childDist ){
                    dist[childNode] = dist[node] + childDist;
                    pq.push({dist[childNode], childNode});
                }
            }
        }
        // for(auto &a : dist)
        //     cout << a << " ";
        return st.size() - 1;
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int, int>> graph[n];
        for(auto &a : edges){
            graph[a[0]].emplace_back(a[1], a[2]);
            graph[a[1]].emplace_back(a[0], a[2]);
        }
        int rCity = -1;
        int minCities = 1e9;
        for(int i = 0; i < n; i++){
            // cout << i << " -> ";
            int currCities = helperFunc(n, i, graph, distanceThreshold);
            // cout << " = " << currCities << " = ";
            if( minCities >= currCities ){
                minCities = currCities;
                rCity = i;
            }
            // cout << endl;
        }
        return rCity;
    }
};


//Using Floyd Warshall
//tc: O(n ^ 3)
//sc: O(n * n)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threDist) {
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX / 2));
        for(int i = 0; i < n; i++)
            dist[i][i] = 0;
        for(auto &a : edges){
            dist[a[0]][a[1]] = a[2];
            dist[a[1]][a[0]] = a[2];
        }
        for(int k = 0; k < n; k++){
            for(int j = 0; j < n; j++){
                for(int i = 0; i < n; i++){
                    if( dist[i][j] > dist[i][k] + dist[k][j] )
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        int minCities = 1e9;
        int resCity = -1;
        for(int i = 0; i < n; i++){
            cout << i << " -> ";
            int count = 0;
            for(int j = 0; j < n; j++){
                if( i == j ) continue;
                if( dist[i][j] <= threDist ){
                    // cout << j << ", ";
                    count += 1;
                }
            }
            // cout << endl;
            if( count <= minCities ){
                minCities = count;
                resCity = i;
            }
            cout << count << endl;
        }
        return resCity;
    }
};
