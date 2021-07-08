// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
   public:
    int util(string &s, int i, int j, bool b) {
        if (i > j) return 0;
        if (dp[i][j][b] != -1) return dp[i][j][b];
        if (i == j) return dp[i][j][b] = (b ? (s[i] == 'T') : (s[i] == 'F'));

        long long int ans = 0;
        for (int k = i + 1; k < j; k += 2) {
            int lT = util(s, i, k - 1, true);
            int lF = util(s, i, k - 1, false);
            int rT = util(s, k + 1, j, true);
            int rF = util(s, k + 1, j, false);
            if (s[k] == '&')
                ans += (b ? (lT * rT) : ((lT * rF) + (lF * rT) + (lF * rF)));
            else if (s[k] == '|')
                ans += (b ? ((lT * rT) + (lT * rF) + (lF * rT)) : (lF * rF));
            else if (s[k] == '^')
                ans += (b ? ((lT * rF) + (lF * rT)) : ((lT * rT) + (lF * rF)));
        }
        return dp[i][j][b] = ans % 1003;
    }
    int dp[202][202][2];
    int countWays(int N, string S) {
        // use memset instead of vector
        // dp=vector<vector<vector<int>>>(202,vector<vector<int>>(202,vector<int>(2,-1)));
        memset(dp, -1, sizeof(dp));
        return util(S, 0, N - 1, true);
        // return ans;
    }
};
// T & T | F
// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        string S;
        cin >> S;

        Solution ob;
        cout << ob.countWays(N, S) << "\n";
    }
    return 0;
}   // } Driver Code Ends