// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    vector<vector<long long>> dp;
    long long int count(int S[], int m, int n) {
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i][j - 1];
                if (S[j - 1] == i)
                    dp[i][j] = dp[i][j - 1] + 1LL;
                else if (S[j - 1] < i)
                    dp[i][j] = dp[i - S[j - 1]][j] + dp[i][j - 1];
            }
        }
        return dp[n][m];
        // if (n == 0 || m == 0) return 0;
        // if (S[m - 1] <= n) {
        //     if (S[m - 1] == n) return count(S, m - 1, n) + 1LL;
        //     return count(S, m, n - S[m - 1]) + count(S, m - 1, n);
        // }
        // return count(S, m - 1, n);
    }
    //Recursive
    long long int util(int S[], int m, int n) {
        if (n == 0 || m == 0) return 0;
        if (dp[n][m] != -1) return dp[n][m];
        if (S[m - 1] <= n) {
            if (S[m - 1] == n)
                dp[n][m] = util(S, m - 1, n) + 1LL;
            else
                dp[n][m] = util(S, m, n - S[m - 1]) + util(S, m - 1, n);
        } else
            dp[n][m] = util(S, m - 1, n);
        return dp[n][m];
    }
    long long int countRec(int S[], int m, int n) {
        dp = vector<vector<long long>>(n + 1, vector<long long>(m + 1, -1));
        return util(S, m, n);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}   // } Driver Code Ends