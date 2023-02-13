//tc: O(n)
//sc: O(n)

#define ll long long

class Solution {
private:
    static const int N = 1e5 + 7;
    vector<int> graph[N];

    ll dfs(int curr, int par, int seats, ll &res){
        ll node = 1;
        for(auto &child : graph[curr]){
            if( child == par ) continue;
            ll newNode = dfs(child, curr, seats, res);
            res += (newNode / seats) + (newNode % seats != 0);
            node += newNode;
        }
        return node;
    }

public:
    ll minimumFuelCost(vector<vector<int>>& roads, int seats) {
        for(auto &a : roads){
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
        }
        ll res = 0;
        dfs(0, -1, seats, res);
        return res;
    }
};
