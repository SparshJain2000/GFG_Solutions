// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    int util(string X, string Y, int costX, int costY, int x, int y) {
        if (x == 0) return y * costY;
        if (y == 0) return x * costX;
        if (dp[x][y] != -1) return dp[x][y];
        if (X[x - 1] == Y[y - 1]) return dp[x][y] = util(X, Y, costX, costY, x - 1, y - 1);
        return dp[x][y] = min(costY + util(X, Y, costX, costY, x, y - 1), costX + util(X, Y, costX, costY, x - 1, y));
    }
    vector<vector<int>> dp;
    int findMinCost(string X, string Y, int costX, int costY) {
        int x = X.length();
        int y = Y.length();
        dp = vector<vector<int>>(x + 1, vector<int>(y + 1, 0));
        for (int i = 0; i < x; i++) dp[i + 1][0] += (i + 1) * costX;
        for (int i = 0; i < y; i++) dp[0][i + 1] += (i + 1) * costY;
        if (X[0] == Y[0]) dp[1][1] = 0;
        for (int i = 1; i <= X.length(); i++) {
            for (int j = 1; j <= Y.length(); j++) {
                if (X[i - 1] == Y[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(costX + dp[i - 1][j], costY + dp[i][j - 1]);
            }
        }
        return dp[x][y];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends