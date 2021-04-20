// { Driver Code Starts

// Driver Code
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

// Complete this function
// (1) Naīve Recursive method : long long int util(int S[], int m, long long int n) {
//     if (n == 0 || m == 0) return 0;
//     if (S[m - 1] <= n) {
//         if (S[m - 1] == n) return util(S, m - 1, n) + 1LL;
//         return util(S, m, n - S[m - 1]) + util(S, m - 1, n);
//     }
//     return util(S, m - 1, n);
// }

// long long int count(long long int n) {
//     int S[] = {3, 5, 10};
//     return util(S, 3, n);
// }

// (2) Recursive with memoization : O(n) space, O(n) time;
// vector<vector<long long>> dp;
// long long int util(int S[], int m, int n) {
//     if (n == 0 || m == 0) return 0;
//     if (dp[n][m] != -1) return dp[n][m];
//     if (S[m - 1] <= n) {
//         if (S[m - 1] == n)
//             dp[n][m] = util(S, m - 1, n) + 1LL;
//         else
//             dp[n][m] = util(S, m, n - S[m - 1]) + util(S, m - 1, n);
//     } else
//         dp[n][m] = util(S, m - 1, n);
//     return dp[n][m];
// }
// long long int count(long long int n) {
//     dp = vector<vector<long long>>(n + 1, vector<long long>(4, -1));
//     int S[] = {3, 5, 10};
//     return util(S, 3, n);
// }

// (3) Iterative(top - down) : O( n) space, O(n) time;
long long int count(long long int n) {
    vector<vector<long long>> dp(n + 1, vector<long long>(4, 0));
    int S[] = {3, 5, 10};
    int m = 3;
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
}
// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << count(n) << endl;
    }
    return 0;
}   // } Driver Code Ends