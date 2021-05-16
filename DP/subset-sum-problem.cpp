// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    vector<vector<int>> dp;

   public:
    int util(int N, int arr[], int sum) {
        if (N == 0) return sum == 0;
        if (N == 0 && sum != 0) return 0;
        if (dp[sum][N] != -1) return dp[sum][N];
        if (arr[N - 1] <= sum) {
            dp[sum][N] = util(N - 1, arr, sum - arr[N - 1]) || util(N - 1, arr, sum);
        } else
            dp[sum][N] = util(N - 1, arr, sum);
        return dp[sum][N];
    }
    int equalPartition(int N, int arr[]) {
        // code here

        int sum = 0;
        for (int i = 0; i < N; i++) sum += arr[i];
        if (sum & 1 || N <= 1) return 0;
        dp = vector<vector<int>>(sum / 2 + 1, vector<int>(N + 1, -1));
        return util(N, arr, sum / 2);
        // vector<vector<int>> dp(sum / 2 + 1, vector<int>(N + 1, 0));
        //Iterative
        for (int i = 1; i <= sum / 2; i++) dp[i][0] = 0;
        for (int i = 0; i <= N; i++) dp[0][i] = 1;
        for (int i = 1; i <= sum / 2; i++)
            for (int j = 1; j <= N; j++) {
                if (i >= arr[j - 1])
                    dp[i][j] = dp[i - arr[j - 1]][j - 1] || dp[i][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        return dp[sum / 2][N];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}   // } Driver Code Ends