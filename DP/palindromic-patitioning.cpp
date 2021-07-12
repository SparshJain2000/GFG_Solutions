// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
   public:
    bool isPalindrome(string &s, int i, int j) {
        while (i < j)
            if (s[i++] != s[j--]) return false;
        return true;
    }
    int util(string &s, int i, int j) {
        if (i >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (isPalindrome(s, i, j)) return dp[i][j] = 0;
        int ans = INT_MAX;
        for (int k = i; k < j; k++) ans = min(ans, 1 + util(s, i, k) + util(s, k + 1, j));

        return dp[i][j] = ans;
    }
    vector<vector<int>> dp;
    int palindromicPartition(string str) {
        // code here
        int N = str.length();
        dp = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));
        return util(str, 0, str.size() - 1);
    }
};
// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}   // } Driver Code Ends