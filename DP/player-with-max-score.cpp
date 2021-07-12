// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
   public:
    int util(int arr[], int i, int n) {
        if (i > n) return 0;
        if (dp[i][n] != -1) return dp[i][n];
        return dp[i][n] = max(arr[i] + min(util(arr, i + 1, n - 1), util(arr, i + 2, n)),
                              arr[n - 1] + min(util(arr, i, n - 2), util(arr, i + 1, n - 1)));
    }
    int dp[1001][1001];
    bool is1winner(int N, int arr[]) {
        memset(dp, -1, sizeof(dp));

        // code here
        int x = util(arr, 0, N);
        int sum = accumulate(arr, arr + N, 0);
        // cout<<x<<endl;
        return x > (sum / 2);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, X;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.is1winner(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends