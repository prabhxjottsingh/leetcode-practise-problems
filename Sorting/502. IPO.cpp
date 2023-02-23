//tc: O(n * log N)
//sc: O(n)

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& pro, vector<int>& cap) {
        vector<pair<int, int>> pr;
        int n = pro.size();
        for(int i = 0; i < n; i++)
            pr.emplace_back(cap[i], pro[i]);
        sort(pr.begin(), pr.end());
        int i = 0;
        long long maxProfit = 0;
        priority_queue<int> maxPro;
        while( k-- ){
            while( i < n && w >= pr[i].first ){
                maxPro.push(pr[i].second);
                i += 1;
            }
            if( maxPro.empty() ) break;
            w += maxPro.top();
            maxPro.pop();
        }
        return w;
    }
};
