// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
   public:
    bool isSubsetSum(int n, int arr[], int s) {
        // code here
        vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));

        for (int i = 0; i <= n; i++) dp[i][0] = true;
        for (int i = 0; i <= s; i++) dp[0][i] = false;
        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= s; j++)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];

        return dp[n][s];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, sum;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0;
}
// } Driver Code Ends