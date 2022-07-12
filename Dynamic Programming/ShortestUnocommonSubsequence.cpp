// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
	int dp[501][501];
	int func(int i, int j, string &S, string &T) {

		if ( i >= S.size() )
			return 1e9;
		if ( j >= T.size() )
			return 1;

		if ( dp[i][j] != -1 )
			return dp[i][j];

		int k = j;
		for ( ; k < (int)T.size(); k++ ) {
			if ( S[i] == T[k] )
				break;
		}
		if ( k == T.size() )
			return 1;
		int caseOne = func(i + 1, j, S, T);
		int caseTwo = 1 + func(i + 1, k + 1, S, T);
		return dp[i][j] = min(caseOne, caseTwo);

	}

public:
	int shortestUnSub(string S, string T) {
		memset(dp, -1, sizeof(dp));
		int count = func(0, 0, S, T);
		if ( count >= 1e9 )
			return -1;
		return count;
	}
};

// { Driver Code Starts.
int main() {
	int t;
	cin >> t;
	while (t--) {
		string S, T;
		cin >> S >> T;

		Solution ob;
		cout << ob.shortestUnSub(S, T) << endl;
	}
	return 0;
}  // } Driver Code Ends