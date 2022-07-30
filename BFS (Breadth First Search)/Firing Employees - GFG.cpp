//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
private:
    bool isPrime(int n){
        if( n == 1 )
            return false;
        for(int i = 2; i <= sqrt(n); i++){
            if( n % i == 0 )
                return false;
        }
        return true;
    }

public:
    int firingEmployees(vector<int> &arr, int n){
        queue<int> q;
        int ansCount = 0;
        int countParents = 1;
        vector<int> tree[n + 1];
        int src = 0;
        for(int i = 0; i < n; i++){
            if( arr[i] > 0 )
                tree[arr[i]].push_back(i + 1);
            if( arr[i] == 0 )
                src = i + 1;
        }
        q.push(src);
        while( !q.empty() ){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                int frnt = q.front();
                q.pop();
                for(auto &child : tree[frnt]){
                    if( isPrime((child) + countParents) ){
                        // cout << child << " " /<< countParents << endl;
                        ansCount++;
                    }
                    q.push(child);
                }
            }
            countParents += 1;
        }
        return ansCount;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n,0);
        
        for(int i=0; i<n; i++)
            cin >> arr[i];

        Solution obj;
        cout << obj.firingEmployees(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends