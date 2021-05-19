// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
   public:
    int util(int n) {
        if (n == 0 || n == 1) return dp[n] = n;
        if (dp[n] != -1) return dp[n];
        return dp[n] = max(n, util(n / 2) + util(n / 3) + util(n / 4));
    }
    vector<int> dp;
    int maxSum(int n) {
        dp = vector<int>(n + 1, -1);
        return util(n);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.maxSum(n) << "\n";
    }
    return 0;
}   // } Driver Code Ends