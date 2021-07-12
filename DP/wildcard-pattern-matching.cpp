// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    /*You are required to complete this method*/
    int wildCard(string p, string s) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, 0));
        int n = s.length();
        int m = p.length();
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++)
            if (p[i - 1] == '*') dp[0][i] = dp[0][i - 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                // cout<<dp[i][j]<<" ";
            }
        }
        return dp[n][m];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}
// } Driver Code Ends