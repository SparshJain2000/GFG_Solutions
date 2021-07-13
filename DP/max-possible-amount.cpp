// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int util(int arr[], int st, int end) {
        if (st > end) return 0;
        if (st == end) return arr[st];
        if (dp[st][end] != -1) return dp[st][end];
        dp[st][end] = max(
            min(util(arr, st + 2, end), util(arr, st + 1, end - 1)) + arr[st],
            min(util(arr, st, end - 2), util(arr, st + 1, end - 1)) + arr[end]);
        return dp[st][end];
    }
    vector<vector<int>> dp;
    int maxAmount(int arr[], int n) {
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        return util(arr, 0, n - 1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.maxAmount(a, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends