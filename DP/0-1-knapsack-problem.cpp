// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
   public:
    vector<vector<int>> dp;
    int util(int W, int wt[], int val[], int n) {
        if (n <= 0 || W <= 0) return 0;
        if (dp[W][n] != -1) return dp[W][n];
        if (wt[n - 1] <= W)
            dp[W][n] = max(val[n - 1] + util(W - wt[n - 1], wt, val, n - 1), util(W, wt, val, n - 1));
        else
            dp[W][n] = util(W, wt, val, n - 1);
        return dp[W][n];
    }
    int knapSack(int W, int wt[], int val[], int n) {
        dp = vector<vector<int>>(W + 1, vector<int>(n + 1, -1));
        return util(W, wt, val, n);
    }
    int knapSackTOPDOWN(int W, int wt[], int val[], int n) {
        vector<vector<int>> dp(W + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= W; i++)
            for (int j = 1; j <= n; j++) {
                if (i >= wt[j - 1])
                    dp[i][j] = max(val[j - 1] + dp[i - wt[j - 1]][j - 1], dp[i][j - 1]);
                else
                    dp[i][j] = dp[i][j - 1];
            }
        return dp[W][n];
    }
};

// { Driver Code Starts.

int main() {
    //taking total testcases
    int t;
    cin >> t;
    while (t--) {
        //reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        //inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        //inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        //calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
}   // } Driver Code Ends