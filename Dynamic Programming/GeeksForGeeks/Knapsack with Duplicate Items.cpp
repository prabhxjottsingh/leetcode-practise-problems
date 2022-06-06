// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int dp[1001][1001];
    int func(int idx, int W, int val[], int wt[]){
        if(idx == 0){
            return (int)((W/wt[0]) * val[0]);
        }
        if(dp[idx][W] != -1)
            return dp[idx][W];
        int notTake = func(idx - 1, W, val, wt);
        int take = 0;
        if(wt[idx] <= W)
            take = val[idx] + func(idx, W - wt[idx], val, wt);
        return dp[idx][W] = max(take, notTake);
    }

public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        memset(dp, -1, sizeof(dp));
        int countWays = func(N - 1, W, val, wt);
        return countWays;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends