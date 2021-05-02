// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
   public:
    vector<vector<int>> dp;
    //recursive
    int maxGold(int n, int m, vector<vector<int>> M) {
        if (n > M.size()) return 0;
        if (m == 0 || n == 0) return 0;
        return M[n - 1][m - 1] + max(maxGold(n, m - 1, M), max(maxGold(n - 1, m - 1, M), maxGold(n + 1, m - 1, M)));
    }
    //recursive with memo
    int util(int n, int m, vector<vector<int>> M) {
        // code here
        if (n > M.size() || m > M[0].size()) return 0;
        if (m == 0 || n == 0) return 0;
        if (dp[n][m] != -1) return dp[n][m];
        dp[n][m] = M[n - 1][m - 1] + max(util(n, m + 1, M), max(util(n - 1, m + 1, M), util(n + 1, m + 1, M)));
        return dp[n][m];
    }
    int maxGold(int n, int m, vector<vector<int>> M) {
        // code here
        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, util(i, 1, M));
        }
        return ans;
    }
    //iterative
    int maxGold(int n, int m, vector<vector<int>> M) {
        //Iterative
        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i < n; i++) dp[i][0] = 0;
        for (int i = 0; i < m; i++) dp[0][i] = 0;
        int ans = INT_MIN;
        for (int j = 1; j <= m; j++)
            for (int i = 1; i <= n; i++) {
                dp[i][j] = M[i - 1][j - 1] + max(dp[i][j - 1], max((i == n) ? 0 : dp[i + 1][j - 1], dp[i - 1][j - 1]));
                ans = max(ans, dp[i][j]);
            }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> M[i][j];
        }

        Solution ob;
        cout << ob.maxGold(n, m, M) << "\n";
    }
    return 0;
}   // } Driver Code Ends