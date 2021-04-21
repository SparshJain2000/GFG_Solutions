// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    //recursive
    vector<vector<int>> dp;
    int util(string s, string t, int x, int y) {
        if (x == 0 && y == 0) return 0;
        if (x == 0) return y;
        if (y == 0) return x;
        if (dp[x][y] != -1) return dp[x][y];
        if (s[x - 1] == t[y - 1])
            dp[x][y] = util(s, t, x - 1, y - 1);
        else
            dp[x][y] = 1 + min(util(s, t, x, y - 1), min(util(s, t, x - 1, y), util(s, t, x - 1, y - 1)));
        return dp[x][y];
    }
    int editDistance(string s, string t) {
        // Code here
        int x = s.length();
        int y = t.length();
        dp = vector<vector<int>>(x + 1, vector<int>(y + 1, -1));
        return util(s, t, x, y);
    }
    //iterative
    int editDistance(string s, string t) {
        int x = s.length();
        int y = t.length();
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));
        dp[0][0] = 0;
        for (int i = 0; i <= x; i++) dp[i][0] = i;
        for (int i = 0; i <= y; i++) dp[0][i] = i;
        for (int i = 1; i <= x; i++)
            for (int j = 1; j <= y; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        return dp[x][y];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends