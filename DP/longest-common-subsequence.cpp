#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution {
   public:
    //recursive
    int lcsrec(int x, int y, string s1, string s2) {
        // your code here
        if (x == 0 || y == 0) return 0;
        if (s1[x - 1] == s2[y - 1]) return 1 + lcs(x - 1, y - 1, s1, s2);
        return max(lcs(x, y - 1, s1, s2), lcs(x - 1, y, s1, s2));
    }
    //recursive with memo
    vector<vector<int>> dp;
    int util(int x, int y, string s1, string s2) {
        if (x > s1.length() || y > s2.length()) return 0;
        if (dp[x][y] != -1) return dp[x][y];
        if (s1[x - 1] == s2[y - 1])
            dp[x][y] = 1 + util(x + 1, y + 1, s1, s2);
        else
            dp[x][y] = max(util(x, y + 1, s1, s2), util(x + 1, y, s1, s2));
        return dp[x][y];
    }
    int lcsrecmemo(int x, int y, string s1, string s2) {
        // your code here
        dp = vector<vector<int>>(x + 1, vector<int>(y + 1, -1));
        return util(1, 1, s1, s2);
    }
    //iterative
    int lcs(int x, int y, string s1, string s2) {
        auto dp = vector<vector<int>>(x + 1, vector<int>(y + 1, -1));
        for (int i = 0; i <= x; i++) dp[i][0] = 0;
        for (int i = 0; i <= y; i++) dp[0][i] = 0;
        for (int i = 1; i <= x; i++)
            for (int j = 1; j <= y; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        //Printing LCS
        int i = x, j = y;
        string ans = "";
        while (i > 0 && j > 0 && dp[i][j] != 0) {
            if (s1[i - 1] == s2[j - 1]) {
                ans = s1[i - 1] + ans;
                i--;
                j--;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1])
                    i--;
                else
                    j--;
            }
        }
        cout << ans << endl;
        return dp[x][y];
    }
};

// { Driver Code Starts.
int main() {
    int t, n, k, x, y;
    cin >> t;
    while (t--) {
        cin >> x >> y;   // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2;   // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends
/*
1
3 4
abcd
abec
*/