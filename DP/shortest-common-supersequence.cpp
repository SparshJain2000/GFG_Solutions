// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
   public:
    //Function to find length of shortest common supersequence of two strings.
    int util(string X, string Y, int m, int n) {
        //code here
        if (m == 0) return n;
        if (n == 0) return m;

        if (X[m - 1] == Y[n - 1]) return 1 + util(X, Y, m - 1, n - 1);
        return 1 + min(util(X, Y, m - 1, n), util(X, Y, m, n - 1));
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int i = 0; i <= n; i++) dp[0][i] = i;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (X[i - 1] == Y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        //printing the superseq
        int i = m, j = n;
        string ans = "";
        while (i > 0 && j > 0) {
            if (X[i - 1] == Y[j - 1]) {
                ans = X[i - 1] + ans;
                i--;
                j--;
            } else {
                if (dp[i - 1][j] < dp[i][j - 1])
                    ans = X[--i] + ans;
                else
                    ans = Y[--j] + ans;
            }
        }
        while (i > 0) ans = X[--i] + ans;
        while (j > 0) ans = Y[--j] + ans;
        cout << ans << endl;
        return dp[m][n];
    }
};

// { Driver Code Starts.

int main() {
    int t;

    //taking total testcases
    cin >> t;
    while (t--) {
        string X, Y;
        //taking String X and Y
        cin >> X >> Y;

        //calling function shortestCommonSupersequence()
        Solution obj;
        cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size()) << endl;
    }
    return 0;
}

// } Driver Code Ends