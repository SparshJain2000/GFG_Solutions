// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    int util(vector<int>& A, int i, int n) {
        if (i > n) return 0;
        if (dp[i][n] != -1) return dp[i][n];
        return dp[i][n] = max(
                   A[i] + min(util(A, i + 2, n), util(A, i + 1, n - 1)),
                   A[n] + min(util(A, i + 1, n - 1), util(A, i, n - 2)));
    }
    vector<vector<int>> dp;
    int maxCoins(vector<int>& A, int n) {
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        return util(A, 0, n - 1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends