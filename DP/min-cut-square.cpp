// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    int minCut(int M, int N) {
        // Your code goes here
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        for (int i = 1; i <= N; i++) dp[1][i] = i;
        for (int i = 1; i <= M; i++) dp[i][1] = i;

        for (int i = 2; i <= M; i++) {
            for (int j = 2; j <= N; j++) {
                int x = INT_MAX;
                if (i == j)
                    x = 1;
                else {
                    for (int k = i - 1; k >= i / 2; k--)
                        x = min(dp[i - k][j] + dp[k][j], x);
                    for (int k = j - 1; k >= j / 2; k--)
                        x = min(dp[i][j - k] + dp[i][k], x);
                }
                dp[i][j] = x;
                // else{
                //     if(i<j) dp[i][j]=dp[i][i]+dp[i][j-i];
                //     else dp[i][j]=dp[j][j]+dp[i-j][j];
                // }
            }
        }
        return dp[M][N];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;

        Solution ob;
        cout << ob.minCut(m, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends