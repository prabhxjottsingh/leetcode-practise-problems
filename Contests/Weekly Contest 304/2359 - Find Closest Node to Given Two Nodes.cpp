//Problem Link: https://leetcode.com/problems/find-closest-node-to-given-two-nodes/
//space Complexity: O(N)
//Time Complexity: O(N * 2)

class Solution {
private:
    map<int, int> useBFS(int n, vector<int> graph[], int node1){
        queue<pair<int, int>> q;
        q.push({node1, 0});
        vector<int> isVis(n, 0);
        map<int, int> distFromSRC;
        while( !q.empty() ){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                pair<int, int> front = q.front();
                int dist = front.second;
                int node = front.first;
                isVis[node] = 1;
                q.pop();
                distFromSRC[node] = dist;
                for(auto &child : graph[node]){
                    if( !isVis[child] )
                        q.push({child, dist + 1});
                }
            }
        }
        return distFromSRC;
    }
    
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> graph[n];
        for(int i = 0; i < n; i++){
            if( edges[i] == -1 )
                continue;
            graph[i].push_back(edges[i]);
        }    
        map<int, int> nodesFromNodeOne = useBFS(n, graph, node1);
        map<int, int> nodesFromNodeTwo = useBFS(n, graph, node2);
        int maxDist = 1e9;
        for(auto &a : nodesFromNodeOne){
            if( nodesFromNodeTwo.count(a.first) )
                maxDist = min(maxDist, max(nodesFromNodeTwo[a.first], a.second));
        }
        for(auto &a : nodesFromNodeOne){
            if( nodesFromNodeTwo.count(a.first) ){
                if( maxDist == max(a.second, nodesFromNodeTwo[a.first]) )
                    return a.first;
            }
        }
        return -1;
    }
};