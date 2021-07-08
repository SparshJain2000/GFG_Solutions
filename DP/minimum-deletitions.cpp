// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
   public:
    int minimumNumberOfDeletions(string s) {
        // code here
        string p = s;
        reverse(p.begin(), p.end());
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // ans= LCS(s,reverse(s))
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == p[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return n - dp[n][n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}   // } Driver Code Ends