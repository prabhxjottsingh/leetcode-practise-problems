#include<bits/stdc++.h>
using namespace std;

void findTopoSort(int node, stack<int> &st, vector<bool> &isVis, vector<int> adj[]) {

	isVis[node] = 1;
	for (auto &child : adj[node]) {
		if ( !isVis[child.first] )
			findTopoSort(child.first, st, isVis, adj);
	}

	st.push(node);

}

void shortestPath(int src, int n, vector<int> adj[]) {

	vector<bool> isVis(n, 0);
	stack<int> st;
	for (int i = 0; i < n; i++) {
		if ( !isVis[i] )
			findTopoSort(i, st, isVis, adj);
	}
	int dist[n];
	for (int i = 0; i < n; i++)
		dist[i] = 1e9;
	dist[src] = 0;
	while ( !st.empty() ) {
		int node = st.top();
		st.pop();
		if ( dist[node] != 1e9 ) {
			for (auto &child : adj[node]) {
				if ( dist[node] + node.second < dist[child.first] )
					dist[child.first] = dist[node] + child.second;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if ( dist[i] == 1e9 )
			cout << "INF ";
		else
			cout << dist[i];
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> adj[n];
	for (int i = 0; i < m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		adj[u].push_back({v, wt});
	}

	shortestPath(0, n, adj);
	return 0;

}