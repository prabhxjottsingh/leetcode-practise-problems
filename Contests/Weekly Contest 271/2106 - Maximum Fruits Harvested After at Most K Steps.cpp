//tc: O(N)
//sc: O(N)

class Solution {
private:
    int caseOne(int strt, vector<int> &pre, int k){
        int maxFr = 0;
        int x = 0;
        for(int i = strt; x <= k && i < pre.size(); ++x, ++i){
            int y = strt - max(0, (k - (x * 2)));
            int currFr = pre[i] + pre[max(0, y)];
            maxFr = max(maxFr, currFr);
        }
        return maxFr;
    }

    int caseTwo(int strt, vector<int> &pre, int k){
        int maxFr = 0;
        int mx = pre.size();
        int x = 0;
        for(int i = strt; x < k && i > -1; --i, ++x){
            int y = strt + max(0, (k - (x * 2)));
            int currFr = pre[i] + pre[min(mx - 1, y)];
            maxFr = max(maxFr, currFr);
        }
        return maxFr;
    }

public:
    int maxTotalFruits(vector<vector<int>>& fr, int strt, int k) {
        int n = fr.size();
        int mx = max(fr[n - 1][0], strt) + 1;
        vector<int> pre(mx, 0);
        int extra = 0;
        for(auto &a : fr){
            if( strt == a[0] ){
                extra = a[1];
                continue;
            }
            pre[a[0]] = a[1];
        }
        for(int i = strt - 1; i > -1; i--)
            pre[i] += pre[i + 1];
        for(int i = strt + 1; i < mx; i++)
            pre[i] += pre[i - 1];
        int maxFr = max(caseOne(strt, pre, k), caseTwo(strt, pre, k));
        maxFr += extra;
        return maxFr;
    }
};
